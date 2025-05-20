//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to print error and exit
void print_error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// Function to connect to FTP server
int connect_ftp(char *ip_address, int port) {
    struct sockaddr_in server_address;
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        print_error("Failed to create socket");
    }

    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        print_error("Failed to connect to server");
    }

    return socket_fd;
}

// Main function
int main(int argc, char *argv[]) {
    int socket_fd, bytes_received = 0;
    char buffer[BUFFER_SIZE] = {0};
    char username[BUFFER_SIZE], password[BUFFER_SIZE], command[BUFFER_SIZE], filename[BUFFER_SIZE];
    char ip_address[BUFFER_SIZE];
    int port;

    // Check number of arguments
    if (argc != 3) {
        print_error("Usage: ./ftpclient <ip address> <port>");
    }

    strcpy(ip_address, argv[1]);
    port = atoi(argv[2]);

    // Connect to FTP server
    socket_fd = connect_ftp(ip_address, port);

    // Receive welcome message
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        print_error("Failed to receive welcome message");
    }
    printf("%s\n", buffer);

    // Get username and password
    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    // Send username
    strcpy(buffer, "USER ");
    strcat(buffer, username);
    strcat(buffer, "\r\n");
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        print_error("Failed to receive response");
    }

    // Send password
    strcpy(buffer, "PASS ");
    strcat(buffer, password);
    strcat(buffer, "\r\n");
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        print_error("Failed to receive response");
    }

    // Get command and filename
    printf("Command (get/put): ");
    scanf("%s", command);

    printf("Filename: ");
    scanf("%s", filename);

    // Send command and filename
    strcpy(buffer, command);
    strcat(buffer, " ");
    strcat(buffer, filename);
    strcat(buffer, "\r\n");
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        print_error("Failed to receive response");
    }
    printf("%s\n", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}