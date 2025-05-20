//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 8080

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number\n");
        return 1;
    }

    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1)
        error("socket");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(listen_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error("bind");

    if (listen(listen_sock, 5) == -1)
        error("listen");

    printf("Proxy server started on port %d\n", port);

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        if (client_sock == -1) {
            if (errno == EINTR)
                continue;
            error("accept");
        }

        char host[NI_MAXHOST];
        char service[NI_MAXSERV];
        socklen_t addrlen = sizeof(struct sockaddr_in);
        if (getnameinfo((struct sockaddr*)&serv_addr, sizeof(serv_addr), host, sizeof(host), service, sizeof(service), 0) == 0)
            printf("Connection from %s:%s\n", host, service);

        int conn_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (conn_sock == -1)
            error("socket");

        struct sockaddr_in remote_addr;
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(port);
        inet_pton(AF_INET, host, &remote_addr.sin_addr);

        if (connect(conn_sock, (struct sockaddr*)&remote_addr, sizeof(remote_addr)) == -1)
            error("connect");

        char buffer[BUF_SIZE];
        while (1) {
            ssize_t bytes_received = recv(client_sock, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                if (bytes_received == 0)
                    printf("Connection closed by client\n");
                else if (errno!= EINTR)
                    error("recv");
                break;
            }

            ssize_t bytes_sent = send(conn_sock, buffer, bytes_received, 0);
            if (bytes_sent!= bytes_received) {
                if (errno!= EINTR)
                    error("send");
                break;
            }
        }

        close(conn_sock);
        close(client_sock);
    }

    return 0;
}