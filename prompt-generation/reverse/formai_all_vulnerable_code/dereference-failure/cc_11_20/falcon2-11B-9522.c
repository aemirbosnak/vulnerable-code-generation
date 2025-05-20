//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd, portno, newsockfd, valread, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAXLINE], client_msg[MAXLINE];

    // create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // assign the port number
    portno = atoi(argv[1]);

    // set up the server's address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // bind the socket to the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Listening on port %d...\n", portno);

    while (1) {
        // accept the next connection
        if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen)) < 0) {
            perror("accept");
            exit(1);
        }

        // receive the client's message
        if ((valread = recv(newsockfd, buffer, MAXLINE, 0)) < 0) {
            perror("recv");
            exit(1);
        }

        // send back the client's message
        if (send(newsockfd, buffer, valread, 0) < 0) {
            perror("send");
            exit(1);
        }

        // receive the client's message again
        if ((valread = recv(newsockfd, client_msg, MAXLINE, 0)) < 0) {
            perror("recv");
            exit(1);
        }

        // send back the client's message again
        if (send(newsockfd, client_msg, valread, 0) < 0) {
            perror("send");
            exit(1);
        }

        // close the connection
        close(newsockfd);
    }

    return 0;
}