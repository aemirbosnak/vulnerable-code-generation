//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char *dest = "www.google.com"; // Change this to desired destination host
    int dest_port = 80; // Change this to desired destination port
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("ERROR on fork");
            exit(1);
        }

        if (pid == 0) { // Child process
            close(sockfd);

            // Connect to destination server
            server = gethostbyname(dest);
            if (server == NULL) {
                fprintf(stderr, "ERROR, no such host\n");
                exit(0);
            }

            struct sockaddr_in dest_addr;
            memset(&dest_addr, 0, sizeof(dest_addr));
            dest_addr.sin_family = AF_INET;
            memcpy(&dest_addr.sin_addr.s_addr, server->h_addr, server->h_length);
            dest_addr.sin_port = htons(dest_port);

            int dest_sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (dest_sockfd < 0) {
                perror("ERROR opening socket");
                exit(1);
            }

            if (connect(dest_sockfd, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) < 0) {
                perror("ERROR connecting");
                exit(1);
            }

            // Forward client request to destination server
            memset(buffer, 0, BUFFER_SIZE);
            n = read(newsockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("Request from client:\n%s\n", buffer);

            // Manipulate request if necessary
            // Here you could do things like modify headers or request params to a certain API

            n = write(dest_sockfd, buffer, strlen(buffer));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            // Forward response from destination server to client
            memset(buffer, 0, BUFFER_SIZE);
            n = read(dest_sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("Response from server:\n%s\n", buffer);

            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            close(newsockfd);
            close(dest_sockfd);

            exit(0);
        } else { // Parent process
            close(newsockfd);
        }
    }

    return 0;
}