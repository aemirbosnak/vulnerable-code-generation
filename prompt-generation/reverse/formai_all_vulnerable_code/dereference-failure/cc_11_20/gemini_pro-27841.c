//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve server address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname failed: %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    // Create a socket address
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&sockaddr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive welcome message
    char buffer[MAX_LINE];
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    // Send USER command
    strcpy(buffer, "USER yourusername\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive USER response
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    // Send PASS command
    strcpy(buffer, "PASS yourpassword\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive PASS response
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    // Send LIST command
    strcpy(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive LIST response
    while (1) {
        if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }

        printf("%s", buffer);

        if (strstr(buffer, ".\r\n") != NULL) {
            break;
        }
    }

    // Send QUIT command
    strcpy(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}