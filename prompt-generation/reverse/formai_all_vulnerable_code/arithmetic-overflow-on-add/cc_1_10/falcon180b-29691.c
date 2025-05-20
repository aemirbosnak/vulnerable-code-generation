//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char buffer[1025];
    char *message = "Welcome to the Funny Server!";
    int n;
    struct timeval tv;
    fd_set readfds;

    FD_ZERO(&readfds);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(sockfd, 5);

    puts("Server is listening");

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        tv.tv_sec = 10;
        tv.tv_usec = 0;

        n = select(sockfd + 1, &readfds, NULL, NULL, &tv);

        if (FD_ISSET(sockfd, &readfds)) {
            newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);

            if (newsockfd < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            puts("New client connected");

            send(newsockfd, message, strlen(message), 0);

            close(newsockfd);
        }
    }

    return 0;
}