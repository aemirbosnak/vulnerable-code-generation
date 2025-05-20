#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *token;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        handle_error("socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
        handle_error("inet_pton");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        handle_error("connect");

    if (recv(sockfd, buffer, BUFFER_SIZE, 0) <= 0)
        handle_error("recv");

    send(sockfd, "USER anonymous\r\n", 16, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    send(sockfd, "PASS \r\n", 8, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    send(sockfd, "PASV\r\n", 6, 0);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) <= 0)
        handle_error("recv");

    token = strtok(buffer, "(");
    token = strtok(NULL, ",");
    int port1 = atoi(token);
    token = strtok(NULL, ",");
    int port2 = atoi(token);

    int data_port = (port1 << 8) | port2;

    close(sockfd);

    // Intentional buffer overflow vulnerability
    char vulnerable_buffer[10];
    snprintf(vulnerable_buffer, sizeof(vulnerable_buffer), "%d", data_port);

    return 0;
}
