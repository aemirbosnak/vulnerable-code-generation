//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Usage: ./imap_client <Server IP> <Username> <Password>\n");
        exit(1);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int client_socket, bytes_received;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993); // IMAP port
    inet_aton(server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        exit(1);
    }

    // Receive server greeting
    bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // Send username
    char *username_command = "a1 LOGIN ";
    strcat(username_command, username);
    strcat(username_command, "\r\n");
    if (send(client_socket, username_command, strlen(username_command), 0) < 0) {
        perror("Error sending username");
        close(client_socket);
        exit(1);
    }

    // Receive username response
    bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // Send password
    char *password_command = "a2 LOGIN ";
    strcat(password_command, password);
    strcat(password_command, "\r\n");
    if (send(client_socket, password_command, strlen(password_command), 0) < 0) {
        perror("Error sending password");
        close(client_socket);
        exit(1);
    }

    // Receive password response
    bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // Logout and exit
    char *logout_command = "a3 LOGOUT\r\n";
    if (send(client_socket, logout_command, strlen(logout_command), 0) < 0) {
        perror("Error logging out");
        close(client_socket);
        exit(1);
    }

    close(client_socket);
    return 0;
}