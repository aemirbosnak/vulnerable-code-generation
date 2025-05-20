//FormAI DATASET v1.0 Category: Socket programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT "9000"
#define BACKLOG 10

int main() {
    struct addrinfo hints, *res;
    int sockfd, new_fd;
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    int yes = 1;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if(getaddrinfo(NULL, PORT, &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if(sockfd == -1) {
        perror("socket");
        return 1;
    }

    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        return 1;
    }

    if(bind(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("bind");
        return 1;
    }

    if(listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        return 1;
    }

    printf("Waiting for connections...\n");

    while(1) {
        addr_size = sizeof(their_addr);
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

        if(new_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Got connection from %s\n",inet_ntoa(((struct sockaddr_in *)&their_addr)->sin_addr));

        char msg[256];
        int msg_size = sizeof(msg);

        memset(msg, 0, msg_size);
        if(recv(new_fd, msg, msg_size, 0) == -1) {
            perror("recv");
            return 1;
        }

        printf("Received message: %s\n", msg);
        int len = strlen(msg);
        for(int i = 0; i < len; i++) {
            msg[i] = toupper(msg[i]);
        }

        printf("Sending uppercase message back to %s\n",inet_ntoa(((struct sockaddr_in *)&their_addr)->sin_addr));

        if(send(new_fd, msg, msg_size, 0) == -1) {
            perror("send");
            return 1;
        }

        close(new_fd);

        printf("Connection closed\n");
    }

    return 0;
}