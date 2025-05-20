//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);

    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Error: Could not resolve host %s\n", host);
        return EXIT_FAILURE;
    }

    server_addr.sin_addr = *(struct in_addr *)host_info->h_addr_list[0];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Could not create socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char buf[MAX_BUF_SIZE];

    // Receive the greeting message from the server
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        fprintf(stderr, "Error: Could not receive greeting message: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the user command
    snprintf(buf, MAX_BUF_SIZE, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send user command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive the user response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        fprintf(stderr, "Error: Could not receive user response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the pass command
    snprintf(buf, MAX_BUF_SIZE, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send pass command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive the pass response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        fprintf(stderr, "Error: Could not receive pass response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the list command
    if (send(sockfd, "LIST\r\n", 6, 0) == -1) {
        fprintf(stderr, "Error: Could not send list command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive the list response
    while (recv(sockfd, buf, MAX_BUF_SIZE, 0) > 0) {
        printf("%s", buf);
    }

    // Send the quit command
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        fprintf(stderr, "Error: Could not send quit command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}