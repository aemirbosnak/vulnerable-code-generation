//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s hostname port username\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Retrieve POP3 server information
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Error: cannot find POP3 server");
        exit(EXIT_FAILURE);
    }
    
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: cannot create socket");
        exit(EXIT_FAILURE);
    }
    
    // Connect to server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: cannot connect to POP3 server");
        exit(EXIT_FAILURE);
    }
    
    // Receive greeting message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    ssize_t bytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (bytes <= 0) {
        perror("Error: cannot receive from POP3 server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    
    // Login with username
    char username[256];
    snprintf(username, sizeof(username), "USER %s\r\n", argv[3]);
    if (send(sockfd, username, strlen(username), 0) < 0) {
        perror("Error: cannot send to POP3 server");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);
    bytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (bytes <= 0) {
        perror("Error: cannot receive from POP3 server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    
    // Prompt for password and login
    char password[256];
    printf("Enter password: ");
    scanf("%s", password);
    char password_cmd[256];
    snprintf(password_cmd, sizeof(password_cmd), "PASS %s\r\n", password);
    if (send(sockfd, password_cmd, strlen(password_cmd), 0) < 0) {
        perror("Error: cannot send to POP3 server");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);
    bytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (bytes <= 0) {
        perror("Error: cannot receive from POP3 server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    
    // Retrieve number of messages
    if (send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0) < 0) {
        perror("Error: cannot send to POP3 server");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);
    bytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (bytes <= 0) {
        perror("Error: cannot receive from POP3 server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    
    // Quit from server
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("Error: cannot send to POP3 server");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);
    bytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (bytes <= 0) {
        perror("Error: cannot receive from POP3 server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    
    // Close socket and exit
    close(sockfd);
    exit(EXIT_SUCCESS);
}