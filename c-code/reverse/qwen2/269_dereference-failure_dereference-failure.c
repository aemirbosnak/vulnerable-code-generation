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
        fprintf(stderr, "Usage: %s <server_ip> <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    const char *file_path = argv[2];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        handle_error("Failed to create socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0)
        handle_error("Invalid address/ Address not supported");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        handle_error("Connection failed");

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received == -1)
        handle_error("Receive failed");

    close(sock);
    return EXIT_SUCCESS;
}
