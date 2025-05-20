//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, bytes_sent, bytes_recv;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    // check if hostname and port are provided
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // get server information
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host '%s'\n", argv[1]);
        exit(1);
    }

    // create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // clear server address
    memset(&server_addr, 0, sizeof(server_addr));

    // set server address attributes
    port = atoi(argv[2]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // get initial response from server
    bytes_recv = recv(sockfd, buffer, BUF_SIZE, 0);
    if (bytes_recv < 0) {
        perror("Error receiving data");
        exit(1);
    }
    buffer[bytes_recv] = '\0';
    printf("%s", buffer);

    // send HELO command to server
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending data");
        exit(1);
    }

    // get response from server
    bytes_recv = recv(sockfd, buffer, BUF_SIZE, 0);
    if (bytes_recv < 0) {
        perror("Error receiving data");
        exit(1);
    }
    buffer[bytes_recv] = '\0';
    printf("%s", buffer);

    // send QUIT command to server
    sprintf(buffer, "QUIT\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending data");
        exit(1);
    }

    // close socket file descriptor
    close(sockfd);

    return 0;
}