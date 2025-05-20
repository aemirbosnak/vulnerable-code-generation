//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 110
#define MAX_BUF_SIZE 1024
#define USER "user"
#define PASS "password"

int main() {
    int sockfd, optval;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct protoent *proto;
    int n;
    char buf[MAX_BUF_SIZE];
    char command[100];

    // Initialize the server
    if ((server = gethostbyname("example.com")) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    if ((proto = getprotobyname("tcp")) == NULL) {
        fprintf(stderr, "Error, protocol not found\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy((char *) &serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, proto->p_proto)) < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Set the socket options
    optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(int)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    // Send the login command
    snprintf(command, sizeof(command), "USER %s\r\n", USER);
    send(sockfd, command, strlen(command), 0);

    // Read the response
    memset(buf, 0, sizeof(buf));
    n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n <= 0) {
        perror("Error reading response");
        exit(1);
    }

    // Check the response for success
    if (strcmp(buf, "+OK\r\n")!= 0) {
        printf("Error logging in: %s\n", buf);
        exit(1);
    }

    // Send the password command
    snprintf(command, sizeof(command), "PASS %s\r\n", PASS);
    send(sockfd, command, strlen(command), 0);

    // Read the response
    memset(buf, 0, sizeof(buf));
    n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n <= 0) {
        perror("Error reading response");
        exit(1);
    }

    // Check the response for success
    if (strcmp(buf, "+OK\r\n")!= 0) {
        printf("Error logging in: %s\n", buf);
        exit(1);
    }

    // Send the LIST command
    snprintf(command, sizeof(command), "LIST\r\n");
    send(sockfd, command, strlen(command), 0);

    // Read the response
    memset(buf, 0, sizeof(buf));
    n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n <= 0) {
        perror("Error reading response");
        exit(1);
    }

    // Check the response for success
    if (strcmp(buf, "+OK\r\n")!= 0) {
        printf("Error listing emails: %s\n", buf);
        exit(1);
    }

    // Read the emails
    while (1) {
        memset(buf, 0, sizeof(buf));
        n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
        if (n <= 0) {
            perror("Error reading response");
            exit(1);
        }

        printf("%s\n", buf);

        // Check for end of emails
        if (strcmp(buf, ".") == 0) {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}