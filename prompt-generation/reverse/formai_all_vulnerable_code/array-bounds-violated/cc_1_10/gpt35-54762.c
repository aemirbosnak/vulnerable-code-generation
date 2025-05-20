//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char* server_address;
    int port;
} POP3Config;

// Function to retrieve email from POP3 server
int retrieve_email(POP3Config config) {
    int sockfd;
    struct sockaddr_in server;
    
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket error");
        return 1;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(config.port);
    server.sin_addr.s_addr = inet_addr(config.server_address);
    
    // Connect to POP3 server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;
    
    // Receive welcome message from server
    if ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) == -1) {
        perror("Receive error");
        return 1;
    }
    
    buffer[bytes_received] = '\0';
    printf("[POP3 Server]: %s", buffer);
    
    // Send user information to server
    char user[MAX_BUFFER_SIZE];
    printf("Enter your username: ");
    fgets(user, MAX_BUFFER_SIZE, stdin);
    user[strcspn(user, "\r\n")] = 0;
    sprintf(buffer, "USER %s\r\n", user);
    send(sockfd, buffer, strlen(buffer), 0);
    
    // Receive response from server
    if ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) == -1) {
        perror("Receive error");
        return 1;
    }
    
    buffer[bytes_received] = '\0';
    printf("[POP3 Server]: %s", buffer);
    
    // Send password to server
    char password[MAX_BUFFER_SIZE];
    printf("Enter your password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    password[strcspn(password, "\r\n")] = 0;
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    
    // Receive response from server
    if ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) == -1) {
        perror("Receive error");
        return 1;
    }
    
    buffer[bytes_received] = '\0';
    printf("[POP3 Server]: %s", buffer);
    
    // List all emails on server
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    if ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) == -1) {
        perror("Receive error");
        return 1;
    }
    
    buffer[bytes_received] = '\0';
    printf("[POP3 Server]: %s", buffer);
    
    // Retrieve first email
    char email_number[MAX_BUFFER_SIZE];
    printf("Enter email number to retrieve: ");
    fgets(email_number, MAX_BUFFER_SIZE, stdin);
    email_number[strcspn(email_number, "\r\n")] = 0;
    sprintf(buffer, "RETR %s\r\n", email_number);
    send(sockfd, buffer, strlen(buffer), 0);
    
    // Receive email
    FILE* email_file = fopen("email.txt", "w");
    while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, email_file);
    }
    fclose(email_file);
    
    // Logout of server
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    if ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) == -1) {
        perror("Receive error");
        return 1;
    }
    
    buffer[bytes_received] = '\0';
    printf("[POP3 Server]: %s", buffer);
    
    // Close socket
    close(sockfd);
    
    return 0;
}

int main() {
    POP3Config config = {
        .server_address = "pop3.example.com",
        .port = 110
    };
    
    retrieve_email(config);
    
    return 0;
}