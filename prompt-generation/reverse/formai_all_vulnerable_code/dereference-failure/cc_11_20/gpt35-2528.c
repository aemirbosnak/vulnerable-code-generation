//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER_SIZE];
    int n;

    if(argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        fprintf(stderr, "Error: cannot open socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: cannot connect\n");
        exit(1);
    }

    // Wait for server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: cannot read from socket\n");
        exit(1);
    }

    // Check if server is ready
    if(strncmp(buffer, "+OK", strlen("+OK")) != 0) {
        fprintf(stderr, "Error: server is not ready\n");
        exit(1);
    }

    // Send user command
    printf("Enter user name: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    sprintf(buffer, "USER %s", buffer);
    write(sockfd, buffer, strlen(buffer));

    // Wait for server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: cannot read from socket\n");
        exit(1);
    }

    // Check if user command was successful
    if(strncmp(buffer, "+OK", strlen("+OK")) != 0) {
        fprintf(stderr, "Error: user command was not successful\n");
        exit(1);
    }

    // Send password command
    printf("Enter password: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    sprintf(buffer, "PASS %s", buffer);
    write(sockfd, buffer, strlen(buffer));

    // Wait for server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: cannot read from socket\n");
        exit(1);
    }

    // Check if password command was successful
    if(strncmp(buffer, "+OK", strlen("+OK")) != 0) {
        fprintf(stderr, "Error: password command was not successful\n");
        exit(1);
    }

    // Send list command
    sprintf(buffer, "LIST");
    write(sockfd, buffer, strlen(buffer));

    // Wait for server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: cannot read from socket\n");
        exit(1);
    }

    // Check if list command was successful
    if(strncmp(buffer, "+OK", strlen("+OK")) != 0) {
        fprintf(stderr, "Error: list command was not successful\n");
        exit(1);
    }

    // Print list of messages
    printf("List of Messages:\n%s", buffer);

    // Send quit command
    sprintf(buffer, "QUIT");
    write(sockfd, buffer, strlen(buffer));

    // Wait for server response
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: cannot read from socket\n");
        exit(1);
    }

    // Check if quit command was successful
    if(strncmp(buffer, "+OK", strlen("+OK")) != 0) {
        fprintf(stderr, "Error: quit command was not successful\n");
        exit(1);
    }

    close(sockfd);
    return 0;
}