//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    
    // Check for valid number of arguments
    if(argc != 3) {
        printf("Usage: %s <Server IP> <Port>\n", argv[0]);
        exit(1);
    }
    
    const char *server_ip = argv[1];
    const int port = atoi(argv[2]);
    
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    
    // Connection parameters
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(port);
    
    // Connect to the server
    if(connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        exit(1);        
    }
    
    char buffer[BUF_SIZE];
    int bytes_received;
    
    // Receive server greeting
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if(bytes_received == -1) {
        perror("Error receiving server greeting");
        close(sock);
        exit(1);        
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // Send USER command
    char user_command[BUF_SIZE];
    printf("Enter your username: ");
    fgets(user_command, BUF_SIZE, stdin);
    user_command[strcspn(user_command, "\n")] = '\0';
    strcat(user_command, "\r\n");
    
    if(send(sock, user_command, strlen(user_command), 0) == -1) {
        perror("Error sending USER command");
        close(sock);
        exit(1);
    }
    
    // Receive user response
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if(bytes_received == -1) {
        perror("Error receiving user response");
        close(sock);
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // Send PASS command
    char pass_command[BUF_SIZE];
    printf("Enter your password: ");
    fgets(pass_command, BUF_SIZE, stdin);
    pass_command[strcspn(pass_command, "\n")] = '\0';
    strcat(pass_command, "\r\n");
    
    if(send(sock, pass_command, strlen(pass_command), 0) == -1) {
        perror("Error sending PASS command");
        close(sock);
        exit(1);
    }
    
    // Receive pass response
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if(bytes_received == -1) {
        perror("Error receiving pass response");
        close(sock);
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // Send STAT command
    char stat_command[BUF_SIZE];
    strcpy(stat_command, "STAT\r\n");
    if(send(sock, stat_command, strlen(stat_command), 0) == -1) {
        perror("Error sending STAT command");
        close(sock);
        exit(1);
    }
    
    // Receive STAT response
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if(bytes_received == -1) {
        perror("Error receiving STAT response");
        close(sock);
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // Send LIST command
    char list_command[BUF_SIZE];
    strcpy(list_command, "LIST\r\n");
    if(send(sock, list_command, strlen(list_command), 0) == -1) {
        perror("Error sending LIST command");
        close(sock);
        exit(1);
    }
    
    // Receive LIST response
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if(bytes_received == -1) {
        perror("Error receiving LIST response");
        close(sock);
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // Send QUIT command
    char quit_command[BUF_SIZE];
    strcpy(quit_command, "QUIT\r\n");
    if(send(sock, quit_command, strlen(quit_command), 0) == -1) {
        perror("Error sending QUIT command");
        close(sock);
        exit(1);
    }
    
    // Receive QUIT response
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if(bytes_received == -1) {
        perror("Error receiving QUIT response");
        close(sock);
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    
    // Close the socket
    close(sock);
    
    return 0;
}