//FormAI DATASET v1.0 Category: Simple Web Server ; Style: visionary
//Welcome to My Visionary Web Server!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 4096

void handle_request(int sockfd) {
    char buf[BUFSIZE];
    int recv_len = recv(sockfd, buf, BUFSIZE-1, 0);
    if (recv_len == -1)
        perror("recv");
    else if (recv_len == 0)
        printf("connection closed\n");
    else {
        buf[recv_len] = '\0';
        printf("received:\n%s\n", buf);
        char *msg = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello World!\r\n";
        send(sockfd, msg, strlen(msg), 0);
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int yes = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("listening on port %d...\n", PORT);

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
        if (client_sockfd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char ipbuf[INET_ADDRSTRLEN];
        printf("accepted connection from %s\n", inet_ntop(AF_INET, &client_addr.sin_addr, ipbuf, INET_ADDRSTRLEN));

        pid_t child_pid = fork();
        if (child_pid == 0) {
            close(sockfd);
            handle_request(client_sockfd);
            close(client_sockfd);
            exit(EXIT_SUCCESS);
        } else {
            close(client_sockfd);
        }
    }

    return 0;
}