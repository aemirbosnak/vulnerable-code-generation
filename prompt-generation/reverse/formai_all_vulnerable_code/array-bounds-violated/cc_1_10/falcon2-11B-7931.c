//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &portno);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        printf("Connected with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        while ((n = recv(newsockfd, buffer, 1024, 0)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
            send(newsockfd, buffer, n, 0);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}