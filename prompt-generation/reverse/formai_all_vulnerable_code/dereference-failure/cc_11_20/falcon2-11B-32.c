//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd, valread, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    int yes = 1;
    char buffer[1000];
    char msg[1000];
    FILE *fp;
    struct sigaction sa;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Bind the socket to a port
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    while (1) {
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Read from the socket
        bzero(buffer, 1000);
        valread = read(newsockfd, buffer, 1000);
        if (valread < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        // Check for spam keywords
        if (strstr(buffer, "viagra") || strstr(buffer, "cialis") || strstr(buffer, "penis") || strstr(buffer, "porn") || strstr(buffer, "viagra") || strstr(buffer, "cialis")) {
            fprintf(stderr, "Spam detected: %s\n", buffer);
            close(newsockfd);
            continue;
        }

        // Write response to client
        sprintf(msg, "Hello, client! This is the server.\n");
        write(newsockfd, msg, strlen(msg));
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}