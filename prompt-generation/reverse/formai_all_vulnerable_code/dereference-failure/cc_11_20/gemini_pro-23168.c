//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        return -1;
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return -1;
    }

    while (1) {
        struct sockaddr_in clientaddr;
        socklen_t len = sizeof(clientaddr);
        int connfd = accept(sockfd, (struct sockaddr *) &clientaddr, &len);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        char buf[1024];
        while (1) {
            int n = read(connfd, buf, sizeof(buf));
            if (n == -1) {
                perror("read");
                break;
            } else if (n == 0) {
                printf("Client closed connection\n");
                break;
            }

            printf("Received: %s\n", buf);
            
            char *msg = "Hello from server!\n";
            n = write(connfd, msg, strlen(msg));
            if (n == -1) {
                perror("write");
                break;
            }
        }

        close(connfd);
    }

    close(sockfd);

    return 0;
}