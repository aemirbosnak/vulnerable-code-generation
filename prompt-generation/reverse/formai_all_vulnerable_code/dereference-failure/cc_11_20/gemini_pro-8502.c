//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <server IP address> <port number>\n", argv[0]);
        return 1;
    }

    // Convert the port number to an integer
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the USER command
    char buf[1024];
    sprintf(buf, "USER your_username\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check if the server's response is positive
    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Error: %s", buf);
        return 1;
    }

    // Send the PASS command
    sprintf(buf, "PASS your_password\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check if the server's response is positive
    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Error: %s", buf);
        return 1;
    }

    // Send the LIST command
    sprintf(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Print the server's response
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}