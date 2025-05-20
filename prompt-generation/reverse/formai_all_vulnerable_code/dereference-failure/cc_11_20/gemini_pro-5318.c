//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    // Check for the required arguments.
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server address and port.
    const char *server = argv[1];
    int port = atoi(argv[2]);

    // Create a socket and connect to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname(%s) failed\n", server);
        return EXIT_FAILURE;
    }
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command.
    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "USER %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the USER command.
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("USER response: %s", buf);

    // Send the PASS command.
    snprintf(buf, BUF_SIZE, "PASS %s\r\n", argv[4]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the PASS command.
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("PASS response: %s", buf);

    // Send the LIST command.
    snprintf(buf, BUF_SIZE, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the LIST command.
    while (1) {
        if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
        printf("%s", buf);
        if (strstr(buf, "\r\n.\r\n") != NULL) {
            break;
        }
    }

    // Send the QUIT command.
    snprintf(buf, BUF_SIZE, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response to the QUIT command.
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("QUIT response: %s", buf);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}