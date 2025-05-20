//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    int sockfd; // socket file descriptor
    struct sockaddr_in servaddr; // server address
    struct hostent *host;
    char buffer[BUFFER_SIZE];

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // get the server host by name
    host = gethostbyname(argv[1]);

    if (host == NULL) {
        printf("Failed to resolve hostname %s: %s", argv[1], hstrerror(h_errno));
        return 1;
    }

    // set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // send a request
    char *request_message = "GET / HTTP/1.1\nHost: %s\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:40.0) Gecko/20100101 Firefox/40.0\nAccept: text/html,application/xhtml+xml\nAccept-Language: en-US,en;q=0.5\nAccept-Encoding: gzip, deflate\nConnection: keep-alive\n\n";

    char request[BUFFER_SIZE];
    sprintf(request, request_message, argv[1]);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Request sending failed");
        return 1;
    }

    // receive response
    int nbytes;
    while ((nbytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[nbytes] = '\0';
        printf("%s", buffer);
    }

    if (nbytes < 0) {
        perror("Response receiving failed");
        return 1;
    }

    // close the socket
    close(sockfd);

    return 0;
}