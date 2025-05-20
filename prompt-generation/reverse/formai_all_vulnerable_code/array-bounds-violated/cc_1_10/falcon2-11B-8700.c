//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, portno, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(5000);

    // Bind to local address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 3);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while ((n = recv(newsockfd, buffer, 1024, 0)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
            send(newsockfd, buffer, strlen(buffer), 0);
        }

        printf("Connection closed\n");
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}