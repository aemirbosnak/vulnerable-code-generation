//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int socket_desc;
    struct sockaddr_in server_addr;
    char username[50], password[50], file_name[50];
    char buffer[BUFFER_SIZE] = {0};
    int bytes_sent, bytes_received;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        printf("Socket creation failed!");
        exit(1);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(21);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed!");
        exit(1);
    }

    // Receive welcome message from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error receiving welcome message!");
        exit(1);
    }
    printf("%s", buffer);

    // Login
    printf("Username: ");
    scanf("%s", username);
    bytes_sent = send(socket_desc, username, strlen(username), 0);
    if (bytes_sent < 0) {
        printf("Error sending username!");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error receiving password prompt!");
        exit(1);
    }

    printf("%s", buffer);
    printf("Password: ");
    scanf("%s", password);
    bytes_sent = send(socket_desc, password, strlen(password), 0);
    if (bytes_sent < 0) {
        printf("Error sending password!");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error receiving login confirmation!");
        exit(1);
    }

    printf("%s", buffer);

    // Enter passive mode
    bytes_sent = send(socket_desc, "PASV\r\n", strlen("PASV\r\n"), 0);
    if (bytes_sent < 0) {
        printf("Error sending PASV command!");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error receiving PASV response!");
        exit(1);
    }

    // Parse PASV response
    int ip_1, ip_2, ip_3, ip_4, port_high, port_low, port;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
           &ip_1, &ip_2, &ip_3, &ip_4, &port_high, &port_low);
    port = (port_high * 256) + port_low;

    // Connect to data port
    struct sockaddr_in data_addr;
    int data_socket_desc;

    data_socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket_desc < 0) {
        printf("Data socket creation failed!");
        exit(1);
    }

    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(argv[1]);
    data_addr.sin_port = htons(port);

    if (connect(data_socket_desc, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0) {
        printf("Data connection failed!");
        exit(1);
    }

    // Download file
    printf("File name: ");
    scanf("%s", file_name);

    bytes_sent = send(socket_desc, "TYPE I\r\n", strlen("TYPE I\r\n"), 0);
    if (bytes_sent < 0) {
        printf("Error sending TYPE command!");
        exit(1);
    }
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error receiving TYPE confirmation!");
        exit(1);
    }
    printf("%s", buffer);

    char command[50] = {0};
    sprintf(command, "RETR %s\r\n", file_name);

    bytes_sent = send(socket_desc, command, strlen(command), 0);
    if (bytes_sent < 0) {
        printf("Error sending RETR command!");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    if (strstr(buffer, "550") != NULL) {
        printf("File not found!");
        exit(1);
    }

    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        printf("Can't create file!");
        exit(1);
    }

    while ((bytes_received = recv(data_socket_desc, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Logout
    bytes_sent = send(socket_desc, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    if (bytes_sent < 0) {
        printf("Error sending QUIT command!");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Close sockets
    close(socket_desc);
    close(data_socket_desc);

    return 0;
}