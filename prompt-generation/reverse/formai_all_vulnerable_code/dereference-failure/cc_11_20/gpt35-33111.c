//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    fd_set readset, writeset;
    char buffer[256];
    struct timeval timeout;

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Set non-blocking mode */
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    /* Fill server details */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        if (errno != EINPROGRESS) {
            perror("ERROR connecting");
            exit(1);
        }
    }

    /* Set up select() */
    FD_ZERO(&readset);
    FD_SET(sockfd, &readset);
    FD_ZERO(&writeset);
    FD_SET(sockfd, &writeset);

    /* Set timeout */
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    /* Wait for connection to establish */
    int res = select(sockfd + 1, &readset, &writeset, NULL, &timeout);
    if (res < 0) {
        perror("ERROR in select()");
        exit(1);
    } else if (res == 0) {
        perror("ERROR in select(): timed out");
        exit(1);
    }

    /* Check if connection was successful */
    int error;
    socklen_t len = sizeof(error);
    getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len);
    if (error != 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Clear buffer and read from server */
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Clear buffer and send message to server */
    printf("Please enter message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Clear buffer and read response from server */
    bzero(buffer, 256);
    FD_ZERO(&readset);
    FD_SET(sockfd, &readset);
    res = select(sockfd + 1, &readset, NULL, NULL, &timeout);
    if (res < 0) {
        perror("ERROR in select()");
        exit(1);
    } else if (res == 0) {
        perror("ERROR in select(): timed out");
        exit(1);
    }
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Close socket */
    close(sockfd);

    return 0;
}