//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sd, new_sd, client_len, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    char *message = "Welcome to the banking record system!\n";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", port);

    while (1) {
        client_len = sizeof(client_addr);
        new_sd = accept(sd, (struct sockaddr *) &client_addr, &client_len);
        if (new_sd == -1) {
            perror("accept");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (send(new_sd, message, strlen(message), 0) == -1) {
            perror("send");
            close(new_sd);
            continue;
        }

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(new_sd, buffer, BUFFER_SIZE, 0) == -1) {
                perror("recv");
                close(new_sd);
                break;
            }

            if (strcmp(buffer, "quit") == 0) {
                printf("Client disconnected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                close(new_sd);
                break;
            }

            printf("Received message from client: %s\n", buffer);

            if (send(new_sd, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                close(new_sd);
                break;
            }
        }
    }

    close(sd);

    return 0;
}