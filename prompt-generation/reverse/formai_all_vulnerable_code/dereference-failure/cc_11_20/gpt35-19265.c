//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER "pop.gmail.com"
#define PORT 995

int main() {
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    
    // Resolving hostname
    server = gethostbyname(SERVER);
    if (server == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }
    
    // Setting server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);
    
    // Connecting to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    // Reading welcome message from server
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);
    
    // Sending user credentials
    char *user = "USER <your_email>@gmail.com\r\n";
    n = write(sockfd, user, strlen(user));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);
    
    // Sending password credentials
    char *pass = "PASS <your_password>\r\n";
    n = write(sockfd, pass, strlen(pass));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);
    
    // Sending STAT command to get mailbox status
    char *stat = "STAT\r\n";
    n = write(sockfd, stat, strlen(stat));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);
    
    // Sending quit command to exit from server
    char *quit = "QUIT\r\n";
    n = write(sockfd, quit, strlen(quit));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);
    
    // Closing socket
    close(sockfd);

    return 0;
}