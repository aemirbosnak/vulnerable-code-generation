//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int control_socket, data_socket, data_port, bytes_received;
    char buffer[BUFFER_SIZE], command[BUFFER_SIZE];
    struct sockaddr_in server_address, data_address;
    socklen_t data_address_length;
    FILE *file;

    // Check for IP address and port number arguments
    if(argc != 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 0;
    }

    // Create socket for control connection
    control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(control_socket < 0) {
        perror("Error creating control socket");
        return 0;
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to FTP server
    if(connect(control_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to FTP server");
        return 0;
    }

    // Receive welcome message
    bytes_received = recv(control_socket, buffer, BUFFER_SIZE, 0);
    if(bytes_received < 0) {
        perror("Error receiving welcome message");
        return 0;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Login to FTP server
    printf("Username: ");
    fgets(command, BUFFER_SIZE, stdin);
    command[strcspn(command, "\n")] = '\0';
    send(control_socket, command, strlen(command), 0);

    printf("Password: ");
    fgets(command, BUFFER_SIZE, stdin);
    command[strcspn(command, "\n")] = '\0';
    send(control_socket, command, strlen(command), 0);

    // Receive login response
    bytes_received = recv(control_socket, buffer, BUFFER_SIZE, 0);
    if(bytes_received < 0) {
        perror("Error receiving login response");
        return 0;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Enter passive mode
    send(control_socket, "PASV\n", strlen("PASV\n"), 0);
    bytes_received = recv(control_socket, buffer, BUFFER_SIZE, 0);
    if(bytes_received < 0) {
        perror("Error receiving data port number");
        return 0;
    }
    buffer[bytes_received] = '\0';
    sscanf(buffer, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d).\n", &data_port, &data_port);

    // Connect to data socket on server
    memset(&data_address, 0, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_addr.s_addr = server_address.sin_addr.s_addr;
    data_address.sin_port = htons(data_port);

    data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(data_socket < 0) {
        perror("Error creating data socket");
        return 0;
    }

    if(connect(data_socket, (struct sockaddr *)&data_address, sizeof(data_address)) < 0) {
        perror("Error connecting to data socket");
        return 0;
    }

    // Send list command to server over control socket
    send(control_socket, "LIST\n", strlen("LIST\n"), 0);

    // Receive list data over data socket
    bytes_received = recv(data_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        bytes_received = recv(data_socket, buffer, BUFFER_SIZE, 0);
    }

    // Close data socket
    close(data_socket);

    // Get file name from user
    printf("Enter file name to download: ");
    fgets(command, BUFFER_SIZE, stdin);
    command[strcspn(command, "\n")] = '\0';

    // Send RETR command to server
    send(control_socket, "RETR ", strlen("RETR "), 0);
    send(control_socket, command, strlen(command), 0);
    send(control_socket, "\n", strlen("\n"), 0);

    // Receive file over data socket
    file = fopen(command, "wb");
    bytes_received = recv(data_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_received > 0) {
        fwrite(buffer, 1, bytes_received, file);
        bytes_received = recv(data_socket, buffer, BUFFER_SIZE, 0);
    }
    fclose(file);

    // Close sockets
    close(control_socket);

    return 0;
}