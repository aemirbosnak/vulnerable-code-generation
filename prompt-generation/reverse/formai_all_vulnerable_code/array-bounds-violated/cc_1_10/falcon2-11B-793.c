//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    /* Creating socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    /* Getting host details */
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Hostname lookup failed\n");
        exit(EXIT_FAILURE);
    }

    /* Filling server address details */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    /* Connecting to server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    /* Sending request to server */
    send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n", 50, 0);

    /* Receiving response from server */
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';

    /* Printing response from server */
    printf("Response from server: %s\n", buffer);

    /* Closing socket */
    close(sockfd);

    return 0;
}