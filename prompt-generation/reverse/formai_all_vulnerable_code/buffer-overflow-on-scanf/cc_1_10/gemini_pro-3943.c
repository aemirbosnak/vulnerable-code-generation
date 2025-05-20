//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main() {
    int sockfd, port;
    struct sockaddr_in servaddr;
    char *host, buf[MAX_BUF];
    
    // Get server host and port from user
    printf("Enter server host: ");
    scanf("%s", host);
    printf("Enter server port: ");
    scanf("%d", &port);
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }
    
    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }
    
    // Send IMAP commands and receive responses
    while (1) {
        printf("> ");
        fgets(buf, MAX_BUF, stdin);
        
        // Send command
        if (send(sockfd, buf, strlen(buf), 0) < 0) {
            perror("send");
            return EXIT_FAILURE;
        }
        
        // Receive response
        if (recv(sockfd, buf, MAX_BUF, 0) < 0) {
            perror("recv");
            return EXIT_FAILURE;
        }
        
        // Print response
        printf("%s", buf);
        
        // Exit on quit command
        if (!strcmp(buf, "* BYE\r\n")) {
            break;
        }
    }
    
    // Close socket
    close(sockfd);
    
    return EXIT_SUCCESS;
}