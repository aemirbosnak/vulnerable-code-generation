//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 100
#define MAX_PORTS 65536

struct connection {
    int sock;
    struct sockaddr_in addr;
    unsigned short port;
    int status;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 2;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    printf("Scanning port %s...\n", argv[1]);

    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);

    while (1) {
        select(sock + 1, &read_fds, NULL, NULL, &tv);

        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (FD_ISSET(sock, &read_fds)) {
                int client_sock = accept(sock, NULL, NULL);
                if (client_sock < 0) {
                    perror("accept() failed");
                    continue;
                }

                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                getsockname(client_sock, (struct sockaddr *)&client_addr, &client_addr_len);

                printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

                int status = 0;
                char buffer[1024];
                recv(client_sock, buffer, 1024, 0);
                if (strcmp(buffer, "HELLO") == 0) {
                    printf("Client sent HELLO\n");
                    status = 1;
                }

                send(client_sock, "WORLD", 5, 0);
                close(client_sock);

                if (status) {
                    printf("Connection established with %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                } else {
                    printf("Connection failed with %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                }
            }
        }
    }

    return 0;
}