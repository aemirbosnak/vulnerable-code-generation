//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char *http_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";
    char *index_html = "<!DOCTYPE html>\n<html>\n<head>\n<title>Welcome to my Server</title>\n</head>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>";
    int opt = TRUE;
    int addrlen = sizeof(struct sockaddr_in);

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
        if (conn_fd == -1) {
            perror("accept");
            exit(1);
        }

        send(conn_fd, http_response, strlen(http_response), 0);
        send(conn_fd, index_html, strlen(index_html), 0);
        close(conn_fd);
    }

    return 0;
}