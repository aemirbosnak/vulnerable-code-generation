//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, res;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUF_SIZE];
    char username[MAX_BUF_SIZE];
    char password[MAX_BUF_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Resolve the server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("gethostbyname() failed");
        exit(1);
    }

    // Set up the server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);

    // Connect to the server
    res = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (res < 0) {
        perror("connect() failed");
        exit(1);
    }

    // Send the username and password
    snprintf(buffer, MAX_BUF_SIZE, "USER %s\r\n", argv[2]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send() failed");
        exit(1);
    }
    snprintf(buffer, MAX_BUF_SIZE, "PASS %s\r\n", argv[3]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send() failed");
        exit(1);
    }

    // Read the server's response
    n = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}