//FormAI DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // check arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() error");
        return 2;
    }

    // bind socket to address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("bind() error");
        return 3;
    }

    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen() error");
        return 4;
    }

    // accept incoming connections and process data
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    char *blocked_sites[] = {"google.com", "facebook.com", "twitter.com"};

    while (1) {
        int connfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_len);
        if (connfd < 0) {
            perror("accept() error");
            continue;
        }

        // read data from client
        ssize_t recv_size = recv(connfd, buffer, BUFFER_SIZE - 1, 0);
        if (recv_size < 0) {
            perror("recv() error");
            close(connfd);
            continue;
        }

        // block access to certain websites
        buffer[recv_size] = '\0';
        for (int i = 0; i < sizeof(blocked_sites) / sizeof(char*); ++i) {
            char *blocked_site = blocked_sites[i];
            if (strstr(buffer, blocked_site) != NULL) {
                printf("Access to %s blocked\n", blocked_site);
                close(connfd);
                continue;
            }
        }

        // write data to client
        ssize_t send_size = send(connfd, buffer, recv_size, 0);
        if (send_size < 0) {
            perror("send() error");
        }

        // close connection
        close(connfd);
    }

    // close socket
    close(sockfd);

    return 0;
}