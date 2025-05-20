//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char *msg = "Greetings from the cyberpunk matrix!";
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the server
    char buf[1024];
    int n;
    if ((n = recv(sockfd, buf, sizeof(buf), 0)) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the message from the server
    buf[n] = '\0';
    printf("Received: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}