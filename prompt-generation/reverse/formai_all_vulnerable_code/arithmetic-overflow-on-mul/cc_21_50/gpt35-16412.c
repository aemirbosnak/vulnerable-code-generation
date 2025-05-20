//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 2048 // Buffer size for our program

int main(int argc, char *argv[]) {
    char* server_address = argv[1]; // Get the server address from command line arguments
    char* file_name = argv[2]; // Get the file name from command line arguments

    // Create a socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(21);
    if (inet_pton(AF_INET, server_address, &server.sin_addr) <= 0) {
        perror("Invalid address");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // Receive the response from the server
    char response[BUF_SIZE];
    if (recv(sock, response, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        return 1;
    }

    // Log in to the server
    char username[BUF_SIZE];
    printf("Enter your username: ");
    scanf("%s", username);
    char password[BUF_SIZE];
    printf("Enter your password: ");
    scanf("%s", password);
    char login_message[BUF_SIZE];
    sprintf(login_message, "USER %s\r\nPASS %s\r\n", username, password);
    if (send(sock, login_message, strlen(login_message), 0) < 0) {
        perror("Error sending login message");
        return 1;
    }
    if (recv(sock, response, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        return 1;
    }

    // Navigate to the correct directory
    if (send(sock, "CWD /\r\n", 7, 0) < 0) {
        perror("Error sending CWD message");
        return 1;
    }
    if (recv(sock, response, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        return 1;
    }

    // Send the PASV command to enter passive mode
    if (send(sock, "PASV\r\n", 6, 0) < 0) {
        perror("Error sending PASV message");
        return 1;
    }
    if (recv(sock, response, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        return 1;
    }

    // Parse the response to get the IP address and port number for the data channel
    char* response_ptr = strstr(response, "(") + 1;
    int ip_addr[4];
    sscanf(response_ptr, "%d,%d,%d,%d,", &ip_addr[0], &ip_addr[1], &ip_addr[2], &ip_addr[3]);
    int port_num[2];
    sscanf(response_ptr, "%*d,%*d,%*d,%*d,%d,%d", &port_num[0], &port_num[1]);
    int data_port = port_num[0] * 256 + port_num[1];

    // Connect to the data channel
    int data_sock;
    if ((data_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Data channel socket creation failed");
        return 1;
    }
    struct sockaddr_in data_server;
    data_server.sin_family = AF_INET;
    data_server.sin_port = htons(data_port);
    char ip_addr_str[BUF_SIZE];
    sprintf(ip_addr_str, "%d.%d.%d.%d", ip_addr[0], ip_addr[1], ip_addr[2], ip_addr[3]);
    if (inet_pton(AF_INET, ip_addr_str, &data_server.sin_addr) <= 0) {
        perror("Invalid data channel address");
        return 1;
    }
    if (connect(data_sock, (struct sockaddr *)&data_server, sizeof(data_server)) < 0) {
        perror("Data channel connection failed");
        return 1;
    }

    // Send the RETR command to retrieve the file
    char retr_message[BUF_SIZE];
    sprintf(retr_message, "RETR %s\r\n", file_name);
    if (send(sock, retr_message, strlen(retr_message), 0) < 0) {
        perror("Error sending RETR message");
        return 1;
    }
    if (recv(sock, response, BUF_SIZE, 0) < 0) {
        perror("Error receiving response");
        return 1;
    }
    if (response[0] != '1' && response[0] != '2') {
        printf("Error retrieving file: %s", response);
        return 1;
    }

    // Create a file to write the data to
    int fd;
    if ((fd = open(file_name, O_WRONLY | O_CREAT, 0644)) < 0) {
        perror("File creation failed");
        return 1;
    }

    // Receive the data and write it to the file
    char buf[BUF_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(data_sock, buf, BUF_SIZE, 0)) > 0) {
        if (write(fd, buf, bytes_received) < 0) {
            perror("Error writing to file");
            return 1;
        }
    }
    if (bytes_received < 0) {
        perror("Error receiving data");
        return 1;
    }

    // Close the file and sockets
    close(fd);
    close(data_sock);
    close(sock);

    printf("File \"%s\" has been downloaded.\n", file_name);

    return 0;
}