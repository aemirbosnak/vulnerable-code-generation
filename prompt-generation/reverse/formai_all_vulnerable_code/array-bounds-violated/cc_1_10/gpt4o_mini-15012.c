//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: pop3_client <hostname> <username> <password>\n");
}

void connect_and_authenticate(char *hostname, char *username, char *password) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);  // POP3 default port
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Server: %s", buffer);
    }

    // Send USER command
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Send PASS command
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    if (strstr(buffer, "+OK") == NULL) {
        printf("Authentication failed!\n");
        close(sock);
        exit(EXIT_FAILURE);
    } else {
        printf("Authenticated successfully!\n");
    }

    // Request email list
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server response to LIST: %s", buffer);

    // Cleanup and close connection
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(sock, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    connect_and_authenticate(hostname, username, password);

    return EXIT_SUCCESS;
}