//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv)
{
    // Validate arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get hostname and port
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    // Setup socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send USER command
    char buf[MAX_BUF_SIZE];
    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive response
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        fprintf(stderr, "recv() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("USER response: %s", buf);

    // Send PASS command
    char password[MAX_BUF_SIZE];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    snprintf(buf, sizeof(buf), "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive response
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        fprintf(stderr, "recv() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("PASS response: %s", buf);

    // Send LIST command
    if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive response
    while (1) {
        if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
            fprintf(stderr, "recv() failed: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
        printf("%s", buf);
        if (strstr(buf, ".\r\n") != NULL) {
            break;
        }
    }

    // Send QUIT command
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}