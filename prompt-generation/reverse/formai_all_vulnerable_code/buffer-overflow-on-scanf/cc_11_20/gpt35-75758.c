//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT "110"
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    struct addrinfo hints, *result, *p;
    int sockfd, status;
    char buffer[MAX_BUF_SIZE];
    size_t bytes_rcvd;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s [server name] [username]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // set up hints struct
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // get server info
    if((status = getaddrinfo(argv[1], POP3_PORT, &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // loop through results to connect
    for(p = result; p != NULL; p = p->ai_next) {
        // create socket
        if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        // connect to server
        if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect error");
            continue;
        }

        break; // connected successfully
    }

    if(p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result); // no longer needed

    // receive hello message
    if((bytes_rcvd = recv(sockfd, buffer, MAX_BUF_SIZE-1, 0)) == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_rcvd] = '\0'; // null-terminate the string received

    printf("%s\n", buffer); // print greeting message

    // send username
    sprintf(buffer, "USER %s\r\n", argv[2]);
    if(send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive response to username
    if((bytes_rcvd = recv(sockfd, buffer, MAX_BUF_SIZE-1, 0)) == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_rcvd] = '\0';

    printf("%s\n", buffer); // print response

    // send password
    printf("Enter password: ");
    scanf("%s", buffer); // insecure, but this is just an example
    sprintf(buffer, "PASS %s\r\n", buffer);
    if(send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive response to password
    if((bytes_rcvd = recv(sockfd, buffer, MAX_BUF_SIZE-1, 0)) == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_rcvd] = '\0';

    printf("%s\n", buffer); // print response

    // quit
    if(send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive goodbye message
    if((bytes_rcvd = recv(sockfd, buffer, MAX_BUF_SIZE-1, 0)) == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_rcvd] = '\0';

    printf("%s\n", buffer); // print goodbye message

    close(sockfd); // close socket

    return 0;
}