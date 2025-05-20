//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT "110"

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <username> [<password>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = (argc >= 4) ? argv[3] : NULL;

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int status;
    if ((status = getaddrinfo(server, POP3_PORT, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    int sockfd;
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    char buffer[512];
    int n;

    // Receive welcome message
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }

    // Send username
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) < 0) {
        perror("send");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive username response
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }

    // Send password (if provided)
    if (password != NULL) {
        snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
        if ((n = send(sockfd, buffer, strlen(buffer), 0)) < 0) {
            perror("send");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        // Receive password response
        if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
            printf("%s", buffer);
        }
    }

    // Send STAT command to get message count and size
    snprintf(buffer, sizeof(buffer), "STAT\r\n");
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) < 0) {
        perror("send");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive STAT response
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }

    // Send LIST command to get message list
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) < 0) {
        perror("send");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive LIST response
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }

    // Send QUIT command to close connection
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) < 0) {
        perror("send");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}