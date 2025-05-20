//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Create a socket address structure
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    serv_addr.sin_addr.s_addr = inet_addr("localhost");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send a POP3 request
    char command[100] = "USER testuser\r\n";
    send(sockfd, command, strlen(command), 0);

    // Receive the response
    int response_len = recv(sockfd, command, 100, 0);
    command[response_len] = '\0';

    // Check the response
    if (strcmp(command, "+OK") == 0) {
        printf("Authentication successful\n");
    } else {
        printf("Authentication failed\n");
    }

    // Send another POP3 request
    command[0] = '\0';
    strcat(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);

    // Receive the response
    response_len = recv(sockfd, command, 100, 0);
    command[response_len] = '\0';

    // Check the response
    if (strcmp(command, "+OK") == 0) {
        printf("Emails retrieved\n");
    } else {
        printf("Failed to retrieve emails\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}