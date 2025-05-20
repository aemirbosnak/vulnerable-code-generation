//Falcon-180B DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    int n;
    char *host;
    char *port;

    // get hostname and port from command line arguments
    if (argc!= 4) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%s\n", host, port);

    while (1) {
        // read input from user
        printf("Enter message: ");
        fgets(buffer, MAX_LINE, stdin);

        // send message to server
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n == -1) {
            perror("send");
            exit(1);
        }

        // receive message from server
        n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n == -1) {
            perror("recv");
            exit(1);
        }
        buffer[n] = '\0';

        // print message from server
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}