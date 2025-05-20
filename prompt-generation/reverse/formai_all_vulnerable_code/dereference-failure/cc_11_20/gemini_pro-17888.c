//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int sockfd, port;
    struct sockaddr_in servaddr;
    char *host, *username, *password, *command, *buffer;
    size_t len;

    // Prompt the user for the server, port, username, password, and command.
    printf("Enter the FTP server: ");
    scanf("%s", host);
    printf("Enter the FTP port: ");
    scanf("%d", &port);
    printf("Enter the FTP username: ");
    scanf("%s", username);
    printf("Enter the FTP password: ");
    scanf("%s", password);
    printf("Enter the FTP command: ");
    scanf("%s", command);

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server address.
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the username and password.
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the command.
    sprintf(buffer, "%s\r\n", command);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response.
    while ((len = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }
    if (len == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}