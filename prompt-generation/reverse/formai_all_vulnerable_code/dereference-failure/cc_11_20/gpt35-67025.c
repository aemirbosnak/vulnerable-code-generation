//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc != 3) {
        printf("Usage: %s <server_ip_address> <server_port_number>\n", argv[0]);
        return 1;
    }
    char *server_ip_address = argv[1];
    int server_port_number = atoi(argv[2]);

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket failed");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port_number);
    if (inet_pton(AF_INET, server_ip_address, &server_address.sin_addr) == -1) {
        perror("inet_pton failed");
        return 1;
    }
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("connect failed");
        return 1;
    }

    // Send the USER command
    char *user_command = "USER username\r\n";
    if (send(client_socket, user_command, strlen(user_command), 0) == -1) {
        perror("send failed");
        return 1;
    }

    // Receive the response to the USER command
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv failed");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send the PASS command
    char *pass_command = "PASS password\r\n";
    if (send(client_socket, pass_command, strlen(pass_command), 0) == -1) {
        perror("send failed");
        return 1;
    }

    // Receive the response to the PASS command
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv failed");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send the LIST command
    char *list_command = "LIST\r\n";
    if (send(client_socket, list_command, strlen(list_command), 0) == -1) {
        perror("send failed");
        return 1;
    }

    // Receive the response to the LIST command
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv failed");
        return 1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Close the socket
    close(client_socket);

    return 0;
}