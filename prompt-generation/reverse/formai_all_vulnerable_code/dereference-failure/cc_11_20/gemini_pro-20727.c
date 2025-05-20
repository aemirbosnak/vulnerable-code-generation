//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[1024];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the server's address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error resolving server address\n");
        exit(1);
    }

    // Set up the sockaddr_in struct
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the welcome message
    if ((n = recv(sockfd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buf);

    // Send the username
    snprintf(buf, sizeof(buf), "USER %s\r\n", argv[2]);
    if ((n = send(sockfd, buf, strlen(buf), 0)) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the username response
    if ((n = recv(sockfd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buf);

    // Send the password
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[3]);
    if ((n = send(sockfd, buf, strlen(buf), 0)) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the password response
    if ((n = recv(sockfd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buf);

    // Send the LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if ((n = send(sockfd, buf, strlen(buf), 0)) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the LIST response
    if ((n = recv(sockfd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if ((n = send(sockfd, buf, strlen(buf), 0)) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the QUIT response
    if ((n = recv(sockfd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}