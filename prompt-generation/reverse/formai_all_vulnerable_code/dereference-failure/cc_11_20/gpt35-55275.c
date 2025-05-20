//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
/* 
* Romeo: "Oh Juliet, my love, I shall create for thee a Simple HTTP Proxy program, 
*         to help thee browse the web with ease, and to protect thy privacy."
*
* Juliet: "Oh Romeo, my beloved, thy chivalry and technical skills leave me in awe.
*          I cannot wait to see thy creation."
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int proxy_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (proxy_socket < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in proxy_address;
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(atoi(argv[1]));

    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(proxy_socket, 10) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            exit(1);
        }

        int remote_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (remote_socket < 0) {
            perror("socket");
            exit(1);
        }

        struct addrinfo hints;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        struct addrinfo *result;
        if (getaddrinfo(argv[1], "http", &hints, &result) != 0) {
            perror("getaddrinfo");
            exit(1);
        }

        if (connect(remote_socket, result->ai_addr, result->ai_addrlen) < 0) {
            perror("connect");
            exit(1);
        }

        char buffer[4096];
        memset(buffer, 0, sizeof(buffer));
        ssize_t read_length = recv(client_socket, buffer, sizeof(buffer), 0);
        if (read_length < 0) {
            perror("recv");
            exit(1);
        }

        if (send(remote_socket, buffer, read_length, 0) < 0) {
            perror("send");
            exit(1);
        }

        memset(buffer, 0, sizeof(buffer));
        read_length = recv(remote_socket, buffer, sizeof(buffer), 0);
        if (read_length < 0) {
            perror("recv");
            exit(1);
        }

        if (send(client_socket, buffer, read_length, 0) < 0) {
            perror("send");
            exit(1);
        }

        close(remote_socket);
        close(client_socket);
    }

    close(proxy_socket);

    return 0;
}

/*
* Juliet: "Oh Romeo, such brilliance! Thou art a true master of programming. 
*          This simple HTTP proxy shall serve us well."
* Romeo: "Anything for thee, my love. Anything for our online privacy." 
*/