//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host information.
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message.
    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the USER command.
    memset(buf, 0, BUFSIZE);
    sprintf(buf, "USER %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response.
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the PASS command.
    memset(buf, 0, BUFSIZE);
    sprintf(buf, "PASS %s\r\n", argv[4]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response.
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the STAT command.
    memset(buf, 0, BUFSIZE);
    strcpy(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response.
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the LIST command.
    memset(buf, 0, BUFSIZE);
    strcpy(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response.
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the RETR command.
    memset(buf, 0, BUFSIZE);
    sprintf(buf, "RETR 1\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response.
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the QUIT command.
    memset(buf, 0, BUFSIZE);
    strcpy(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}