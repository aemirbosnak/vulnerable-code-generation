//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server> <port> <email address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_name = argv[1];
    int port = atoi(argv[2]);
    char *email = argv[3];

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, server_name, &server_address.sin_addr) <= 0) {
        printf("Invalid address: %s\n", server_name);
        exit(EXIT_FAILURE);
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_SIZE];
    int bytes_received = recv(socket_fd, buffer, MAX_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    snprintf(buffer, MAX_SIZE, "EHLO %s\r\n", server_name);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(socket_fd, buffer, MAX_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    snprintf(buffer, MAX_SIZE, "MAIL FROM:<%s>\r\n", email);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(socket_fd, buffer, MAX_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    snprintf(buffer, MAX_SIZE, "RCPT TO:<%s>\r\n", email);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(socket_fd, buffer, MAX_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    snprintf(buffer, MAX_SIZE, "DATA\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(socket_fd, buffer, MAX_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    snprintf(buffer, MAX_SIZE, "From: <%s>\r\nTo: <%s>\r\nSubject: Test message\r\n\r\nHello, world!\r\n.\r\n", email, email);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(socket_fd, buffer, MAX_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    snprintf(buffer, MAX_SIZE, "QUIT\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(socket_fd, buffer, MAX_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    close(socket_fd);

    return 0;
}