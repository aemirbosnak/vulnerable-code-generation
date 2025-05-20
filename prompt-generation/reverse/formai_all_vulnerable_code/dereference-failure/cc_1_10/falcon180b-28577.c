//Falcon-180B DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100

int main() {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    char *host;
    int len;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    puts("Socket created");

    // Set the server address
    host = "localhost";
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", host);
        exit(EXIT_FAILURE);
    }

    // Fill the server structure
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // Connect to the server
    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    puts("Connected to server");

    // Send data to server
    send(sockfd, "Hello, server!", strlen("Hello, server! "), 0);

    // Receive data from server
    len = sizeof(cli_addr);
    ret = recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr *)&cli_addr, &len);
    if (ret < 0) {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }

    buffer[ret] = '\0';
    printf("Received from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}