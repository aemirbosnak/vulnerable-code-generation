//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define POP3_PORT 110
#define POP3_TERMINATOR "\r\n"
#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    char *hostname = "pop.example.com";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Unable to resolve hostname '%s'\n", hostname);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Read the greeting message
    if (read(sockfd, buf, BUF_SIZE) == -1) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    // Send the USER command
    sprintf(buf, "USER yourusername" POP3_TERMINATOR);
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        exit(1);
    }

    // Read the USER response
    if (read(sockfd, buf, BUF_SIZE) == -1) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    // Send the PASS command
    sprintf(buf, "PASS yourpassword" POP3_TERMINATOR);
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        exit(1);
    }

    // Read the PASS response
    if (read(sockfd, buf, BUF_SIZE) == -1) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    // Send the LIST command
    sprintf(buf, "LIST" POP3_TERMINATOR);
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        exit(1);
    }

    // Read the LIST response
    while (1) {
        if (read(sockfd, buf, BUF_SIZE) == -1) {
            perror("read");
            exit(1);
        }

        printf("%s", buf);

        if (strcmp(buf, "." POP3_TERMINATOR) == 0) {
            break;
        }
    }

    // Send the QUIT command
    sprintf(buf, "QUIT" POP3_TERMINATOR);
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        exit(1);
    }

    // Read the QUIT response
    if (read(sockfd, buf, BUF_SIZE) == -1) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    close(sockfd);

    return 0;
}