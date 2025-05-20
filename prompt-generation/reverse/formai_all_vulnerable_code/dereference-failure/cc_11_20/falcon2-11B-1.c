//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
    int addrlen;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            if (read(new_socket, buffer, BUF_SIZE) < 0) {
                perror("read");
                exit(1);
            }

            if (strstr(buffer, "firewall")!= NULL) {
                close(new_socket);
                printf("Firewall detected\n");
                exit(0);
            }

            if (strstr(buffer, "end")!= NULL) {
                break;
            }

            if (send(new_socket, buffer, strlen(buffer), 0) < 0) {
                perror("write");
                exit(1);
            }
        }

        close(new_socket);
    }

    close(server_fd);
    return 0;
}