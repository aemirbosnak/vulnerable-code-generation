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

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    const char *filename = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        handle_error("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0)
        handle_error("inet_pton");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        handle_error("connect");

    send(sockfd, "USER anonymous\r\n", 15, 0);
    send(sockfd, "PASS \r\n", 7, 0);
    send(sockfd, "CWD /\r\n", 8, 0);
    send(sockfd, "RETR ", 5, 0);
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "\r\n", 2, 0);

    FILE *file = fopen(filename, "wb");
    if (!file)
        handle_error("fopen");

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    close(sockfd);

    return EXIT_SUCCESS;
}
