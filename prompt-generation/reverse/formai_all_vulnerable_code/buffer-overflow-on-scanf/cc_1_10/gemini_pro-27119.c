//GEMINI-pro DATASET v1.0 Category: Networking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];

    /* Create a socket. */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Get the port number from the user. */
    printf("Enter the port number: ");
    scanf("%d", &portno);

    /* Set up the address structure. */
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Bind the socket to the address. */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Listen for incoming connections. */
    listen(sockfd, 5);

    /* Accept incoming connections. */
    clilen = sizeof(struct sockaddr_in);
    newsockfd = accept(sockfd, (struct sockaddr *) &clilen, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* Read data from the socket. */
    bzero(buffer, 256);
    int n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    /* Print the data to the console. */
    printf("Here is the message: %s\n", buffer);

    /* Close the socket. */
    close(newsockfd);
    close(sockfd);

    return 0;
}