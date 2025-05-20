//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_RECV_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd = 0, recv_size = 0;
    char *http_request = "GET /index.html HTTP/1.1\r\nHost:www.example.com\r\nConnection:close\r\n\r\n";
    char recv_buffer[MAX_RECV_BUF_SIZE];
    struct sockaddr_in server;

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket.");
        return EXIT_FAILURE;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    if (inet_pton(AF_INET, "93.184.216.34", &server.sin_addr) <= 0) {
        perror("Failed to convert address.");
        return EXIT_FAILURE;
    }

    if (connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server.");
        return EXIT_FAILURE;
    }

    if (send(sock_fd, http_request, strlen(http_request), 0) < 0) {
        perror("Failed to send data.");
        return EXIT_FAILURE;
    }

    printf("HTTP Request:\n%s\n", http_request);

    while ((recv_size = recv(sock_fd, recv_buffer, MAX_RECV_BUF_SIZE, 0)) > 0) {
        recv_buffer[recv_size] = '\0';
        printf("%s", recv_buffer);
    }

    if (recv_size < 0) {
        perror("Failed to receive data.");
        return EXIT_FAILURE;
    }

    close(sock_fd);

    return EXIT_SUCCESS;
}