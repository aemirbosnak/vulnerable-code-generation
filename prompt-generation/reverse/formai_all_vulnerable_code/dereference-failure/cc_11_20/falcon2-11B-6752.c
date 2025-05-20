//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    char message[1024];

    // Server parameters
    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Create proxy socket
    newsockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (newsockfd < 0) {
        perror("ERROR opening proxy socket");
        exit(1);
    }

    // Set up proxy address struct
    bzero((char *) &cli_addr, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(0);
    bcopy((char *)server->h_addr, (char *)&cli_addr.sin_addr.s_addr, server->h_length);

    // Bind to proxy socket
    if (bind(newsockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) < 0) {
        perror("ERROR binding to proxy socket");
        exit(1);
    }

    // Listen on proxy socket
    if (listen(newsockfd, 5) < 0) {
        perror("ERROR listening on proxy socket");
        exit(1);
    }

    while (1) {
        // Accept connection
        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);
        if (n <= 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Client connected: %s\n", buffer);

        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1024);
        if (n <= 0) {
            perror("ERROR reading from proxy socket");
            exit(1);
        }

        printf("Proxy connected: %s\n", buffer);

        // Write to client
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        // Read from client
        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);
        if (n <= 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Client message: %s\n", buffer);

        // Write to proxy
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to proxy socket");
            exit(1);
        }

        // Read from proxy
        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1024);
        if (n <= 0) {
            perror("ERROR reading from proxy socket");
            exit(1);
        }

        printf("Proxy message: %s\n", buffer);

        // Write to client
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    close(sockfd);
    close(newsockfd);
    return 0;
}