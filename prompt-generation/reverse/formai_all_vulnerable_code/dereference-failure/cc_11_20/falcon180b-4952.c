//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[])
{
    int listen_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    char *host, *uri;
    int host_len, uri_len;
    int ret;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);
    host = argv[2];

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    ret = bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        close(listen_socket);
        return 1;
    }

    ret = listen(listen_socket, BACKLOG);
    if (ret == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        close(listen_socket);
        return 1;
    }

    fprintf(stdout, "Proxy server started on port %d\n", port);

    while (1) {
        socklen_t client_len;
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        memset(buffer, 0, MAX_LINE);
        ret = recv(client_socket, buffer, MAX_LINE, 0);
        if (ret <= 0) {
            fprintf(stderr, "Error receiving data from client: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }

        host_len = strlen(host);
        uri_len = strlen(buffer);
        if (uri_len < host_len || strncmp(buffer, host, host_len)!= 0 || buffer[host_len]!= '/') {
            fprintf(stderr, "Invalid request\n");
            close(client_socket);
            continue;
        }

        ret = send(client_socket, "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n", 45, 0);
        if (ret!= 45) {
            fprintf(stderr, "Error sending response: %s\n", strerror(errno));
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}