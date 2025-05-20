//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 4096
#define BACKLOG 10
#define PORT 8080

int main(int argc, char *argv[])
{
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP_address>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "socket failed: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "bind failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "listen failed: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "HTTP proxy server started on %s:%d\n", argv[1], PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd == -1) {
            fprintf(stderr, "accept failed: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((n = read(conn_fd, buffer, MAX_LINE)) > 0) {
            write(STDOUT_FILENO, buffer, n);
        }

        close(conn_fd);
    }

    return 0;
}