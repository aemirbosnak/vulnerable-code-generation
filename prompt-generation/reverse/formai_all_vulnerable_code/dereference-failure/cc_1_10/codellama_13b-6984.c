//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int server_sock, client_sock, port, n;
    char buffer[256];
    struct sockaddr_in server, client;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(server_sock, 3);
    printf("Listening on port %d\n", port);

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client, &n);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        while (1) {
            n = read(client_sock, buffer, 256);
            if (n < 0) {
                perror("read failed");
                exit(1);
            }

            if (n == 0) {
                printf("Client disconnected\n");
                close(client_sock);
                break;
            }

            printf("Received %d bytes: %s\n", n, buffer);

            n = write(client_sock, buffer, n);
            if (n < 0) {
                perror("write failed");
                exit(1);
            }
        }
    }

    close(server_sock);
    return 0;
}