//GEMINI-pro DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Client-side program to reverse a string on the server.
int main() {

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the string to the server.
    char str[100];
    printf("Enter the string to be reversed: ");
    scanf("%s", str);
    if (send(sockfd, str, strlen(str), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the reversed string from the server.
    char reversed[100];
    if (recv(sockfd, reversed, sizeof(reversed), 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the reversed string.
    printf("The reversed string is: %s\n", reversed);

    // Close the socket.
    close(sockfd);

    return 0;
}