//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char server_ip[INET_ADDRSTRLEN];
    char message[MAX_MSG_SIZE];
    char server_response[MAX_MSG_SIZE];
    
    if (argc != 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strcpy(server_ip, argv[1]);
    
    // create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }
    
    // connect to server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }
    
    // check server response
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        perror("Failed to receive server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);
    memset(server_response, 0, sizeof(server_response));
    
    // send HELO message
    strcpy(message, "HELO client\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Failed to send HELO message");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        perror("Failed to receive server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);
    memset(server_response, 0, sizeof(server_response));
    
    // send MAIL FROM message
    strcpy(message, "MAIL FROM: <sender@example.com>\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Failed to send MAIL FROM message");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        perror("Failed to receive server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);
    memset(server_response, 0, sizeof(server_response));
    
    // send RCPT TO message
    strcpy(message, "RCPT TO: <recipient@example.com>\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Failed to send RCPT TO message");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        perror("Failed to receive server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);
    memset(server_response, 0, sizeof(server_response));
    
    // send DATA message
    strcpy(message, "DATA\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Failed to send DATA message");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        perror("Failed to receive server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);
    memset(server_response, 0, sizeof(server_response));
    
    // send mail message
    strcpy(message, "From: sender@example.com\nTo: recipient@example.com\nSubject: Test email\n\nThis is a test email.\n.\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Failed to send mail message");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        perror("Failed to receive server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);
    memset(server_response, 0, sizeof(server_response));
    
    // send QUIT message
    strcpy(message, "QUIT\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Failed to send QUIT message");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        perror("Failed to receive server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);
    memset(server_response, 0, sizeof(server_response));
    
    // close socket
    close(client_socket);
    
    return 0;
}