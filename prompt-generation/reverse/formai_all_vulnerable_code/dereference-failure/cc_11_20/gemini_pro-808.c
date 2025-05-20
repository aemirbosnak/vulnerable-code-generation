//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host and port from the command line arguments.
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        return EXIT_FAILURE;
    }
    memcpy(&serv_addr.sin_addr, hostent->h_addr, hostent->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command.
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "USER %s\r\n", "username");
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the USER command.
    if (recv(sockfd, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the PASS command.
    snprintf(buff, BUFF_SIZE, "PASS %s\r\n", "password");
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the PASS command.
    if (recv(sockfd, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the LIST command.
    snprintf(buff, BUFF_SIZE, "LIST\r\n");
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the LIST command.
    while (1) {
        if (recv(sockfd, buff, BUFF_SIZE, 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }

        if (strstr(buff, "\r\n.\r\n") != NULL) {
            break;
        }

        printf("%s", buff);
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}