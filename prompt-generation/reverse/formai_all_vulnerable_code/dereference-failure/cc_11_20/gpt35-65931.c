//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    
    // Resolve hostname to IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    char *ip_addr = inet_ntoa(*(struct in_addr*)server->h_addr_list[0]);
    
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(port);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    
    // Read welcome message from server
    char buf[BUF_SIZE] = {0};
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);
    
    // Send login command
    char user[BUF_SIZE];
    printf("Username: ");
    fgets(user, BUF_SIZE, stdin);
    user[strcspn(user, "\n")] = 0;  // Remove newline character
    char pass[BUF_SIZE];
    printf("Password: ");
    fgets(pass, BUF_SIZE, stdin);
    pass[strcspn(pass, "\n")] = 0;  // Remove newline character
    
    char login_cmd[BUF_SIZE];
    snprintf(login_cmd, BUF_SIZE, "LOGIN %s %s\r\n", user, pass);
    if (send(sockfd, login_cmd, strlen(login_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    
    // Read response from server
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);
    
    // Send logout command
    char logout_cmd[BUF_SIZE] = "LOGOUT\r\n";
    if (send(sockfd, logout_cmd, strlen(logout_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    
    // Read response from server
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);
    
    // Close socket
    if (close(sockfd) < 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}