//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(listen_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(NULL, port, &hints, &servinfo) == -1) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int client_socket = accept(listen_socket, (struct sockaddr *)&p->ai_addr, (socklen_t*)p->ai_addrlen);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        char buffer[256];
        bzero(buffer, sizeof(buffer));
        ssize_t nread = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (nread == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }
        buffer[nread] = '\0';

        printf("Received request: %s\n", buffer);

        if (strcmp(buffer, "GET / HTTP/1.1\r\n") == 0) {
            char response[256];
            snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>\r\n");
            ssize_t nwrite = send(client_socket, response, strlen(response), 0);
            if (nwrite == -1) {
                perror("send");
                close(client_socket);
                continue;
            }
        } else {
            close(client_socket);
        }
        close(client_socket);
    }

    freeaddrinfo(servinfo);
    close(listen_socket);

    return 0;
}