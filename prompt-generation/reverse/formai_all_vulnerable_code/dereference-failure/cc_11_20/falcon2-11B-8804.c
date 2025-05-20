//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <ctype.h>

int main() {
    int socket_fd, ret;
    struct addrinfo hints, *servinfo, *p;
    char recv_buf[1024];
    char command[1024];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((ret = getaddrinfo("mail.example.com", "pop3", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(socket_fd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(socket_fd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to POP3 server\n");
        return 1;
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_KEEPALIVE, &(int){1}, sizeof(int)) == -1) {
        perror("setsockopt");
        return 1;
    }

    if (send(socket_fd, "USER username\r\n", strlen("USER username\r\n"), 0) == -1) {
        perror("send");
        return 1;
    }

    if (send(socket_fd, "PASS password\r\n", strlen("PASS password\r\n"), 0) == -1) {
        perror("send");
        return 1;
    }

    if (send(socket_fd, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        perror("send");
        return 1;
    }

    if (recv(socket_fd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("Message Count: %s\n", recv_buf);

    return 0;
}