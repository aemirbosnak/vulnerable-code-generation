//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_sock, client_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(listen_sock, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addrlen);

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUF_SIZE);
            if (recv(client_sock, buffer, BUF_SIZE, 0) <= 0) {
                printf("Error receiving data\n");
                break;
            }

            send(client_sock, buffer, strlen(buffer), 0);
        }

        close(client_sock);
    }

    close(listen_sock);
    return 0;
}