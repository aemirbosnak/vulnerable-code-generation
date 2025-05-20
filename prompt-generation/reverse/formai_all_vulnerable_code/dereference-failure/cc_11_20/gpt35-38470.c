//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *host_entity = gethostbyname(argv[1]);
    if (host_entity == NULL) {
        fprintf(stderr, "Failed to lookup host: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *(struct in_addr*)host_entity->h_addr_list[0];
    server_addr.sin_port = htons(80);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        close(sock);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\n" \
                    "Host: %s\r\n" \
                    "Connection: close\r\n" \
                    "User-Agent: minimalist-client/1.0\r\n\r\n", argv[1]);

    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send request");
        close(sock);
        return EXIT_FAILURE;
    }

    bool headers_complete = false;
    while (1) {
        ssize_t num_bytes = recv(sock, buffer, BUFFER_SIZE-1, 0);
        if (num_bytes == -1) {
            perror("Failed to receive response");
            close(sock);
            return EXIT_FAILURE;
        } else if (num_bytes == 0) {
            break;  // Server closed connection
        }

        buffer[num_bytes] = '\0';

        if (!headers_complete) {
            char *body_start = strstr(buffer, "\r\n\r\n");
            if (body_start) {
                *body_start = '\0';
                printf("%s\n", buffer);
                printf("\n\n*** BODY ***\n\n");
                printf("%s", body_start + 4);
                headers_complete = true;
            } else {
                printf("%s", buffer);
            }
        } else {
            printf("%s", buffer);
        }
    }

    close(sock);
    return EXIT_SUCCESS;
}