//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    
    // Parse the host and port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }
    
    // Get the username and password
    char username[MAX_LINE], password[MAX_LINE];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    
    // Send the username and password to the server
    if (send(sockfd, username, strlen(username), 0) < 0) {
        perror("send");
        exit(1);
    }
    if (send(sockfd, password, strlen(password), 0) < 0) {
        perror("send");
        exit(1);
    }
    
    // Get the response from the server
    char response[MAX_LINE];
    if (recv(sockfd, response, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    
    // Print the response from the server
    printf("%s\n", response);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}