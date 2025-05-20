//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define SERVER_PORT 110 
#define MAX_BUFFER 1024 

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        handle_error("Error creating socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Replace with your server's IP address or hostname
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) 
        handle_error("Invalid address/ Address not supported");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        handle_error("Connection failed");

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    char buffer[MAX_BUFFER];
    int n;

    snprintf(buffer, sizeof(buffer), "%s\r\n", cmd);
    send(sockfd, buffer, strlen(buffer), 0);

    // Read server response
    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n <= 0) 
        handle_error("Error reading from socket");

    buffer[n] = '\0';
    printf("%s", buffer);
}

void fetch_headers(int sockfd) {
    send_command(sockfd, "USER your_username"); // Replace with your username
    send_command(sockfd, "PASS your_password"); // Replace with your password
    send_command(sockfd, "LIST");
}

void close_connection(int sockfd) {
    send_command(sockfd, "QUIT");
    close(sockfd);
}

int main() {
    int sockfd;

    sockfd = create_socket();
    fetch_headers(sockfd);
    close_connection(sockfd);

    return 0;
}