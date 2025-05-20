//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CONNECTIONS 5
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, port_num, n;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port_num = atoi(argv[1]);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_num);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Firewall is listening on port %d\n", port_num);

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, (socklen_t*)&n);
        if (conn_fd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (conn_fd == listen_fd) {
            continue;
        }

        char buffer[BUF_SIZE];
        int bytes_read = read(conn_fd, buffer, BUF_SIZE);
        if (bytes_read < 0) {
            perror("read");
            exit(1);
        }

        printf("Received %d bytes: %s\n", bytes_read, buffer);

        // Filtering based on certain criteria
        if (buffer[0] == 'P') {
            if (buffer[1] == 'O' && buffer[2] == 'S') {
                write(conn_fd, "Request denied\n", 14);
            } else {
                write(conn_fd, "Connection accepted\n", 21);
            }
        } else {
            write(conn_fd, "Connection denied\n", 18);
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}