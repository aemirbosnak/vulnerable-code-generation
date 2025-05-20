#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return 1;
    }

    const char *request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char full_request[BUFFER_SIZE];
    snprintf(full_request, BUFFER_SIZE, request, argv[1]);

    send(sock, full_request, strlen(full_request), 0);

    char buffer[BUFFER_SIZE];
    while ((read(sock, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[BUFFER_SIZE - 1] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}
