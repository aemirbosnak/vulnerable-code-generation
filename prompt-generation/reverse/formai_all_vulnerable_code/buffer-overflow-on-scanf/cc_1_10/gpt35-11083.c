//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_ADDRESS "pop.example.com"
#define SERVER_PORT 110

int main() {
    int client_fd, bytes_recv;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server;
    
    // Create a socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        printf("Failed to create socket.\n");
        return 1;
    } else {
        printf("Socket created successfully!\n");
    }
    
    // Connect to the server
    server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    if (connect(client_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        return 1;
    } else {
        printf("Connected to server.\n");
    }
    
    // Receive the server's welcome message
    memset(buffer, 0, MAX_BUFFER_SIZE);
    bytes_recv = recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_recv < 0) {
        printf("Failed to receive welcome message.\n");
        return 1;
    } else {
        printf("Server message: %s\n", buffer);
    }
    
    // Send user credentials to authenticate
    char user[MAX_BUFFER_SIZE], pass[MAX_BUFFER_SIZE];
    printf("Enter your username: ");
    scanf("%s", user);
    printf("Enter your password: ");
    scanf("%s", pass);
    
    char user_msg[MAX_BUFFER_SIZE], pass_msg[MAX_BUFFER_SIZE];
    sprintf(user_msg, "USER %s\r\n", user);
    sprintf(pass_msg, "PASS %s\r\n", pass);
    
    send(client_fd, user_msg, strlen(user_msg), 0);
    recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);
    
    send(client_fd, pass_msg, strlen(pass_msg), 0);
    recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);
    
    // Retrieve email list
    send(client_fd, "LIST\r\n", strlen("LIST\r\n"), 0);
    recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    // Close the connection
    close(client_fd);
    printf("Disconnected from server.\n");
    
    return 0;
}