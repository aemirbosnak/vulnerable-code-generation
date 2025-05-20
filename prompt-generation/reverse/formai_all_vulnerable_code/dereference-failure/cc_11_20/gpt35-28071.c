//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, port;
    struct sockaddr_in server_address;
    char *server_ip, *from_email, *to_email, *subject, *body, buffer[MAX_BUFFER_SIZE];
    
    // Check for correct number of arguments
    if (argc != 6) {
        printf("Usage: smtp_client <server_ip> <port> <from_email> <to_email> <subject>\n");
        exit(1);
    }
    
    // Get command line arguments
    server_ip = argv[1];
    port = atoi(argv[2]);
    from_email = argv[3];
    to_email = argv[4];
    subject = argv[5];
    
    // Get message body from user
    printf("Enter message body:\n");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    body = strdup(buffer);
    
    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // Initialize server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(1);
    }
    
    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    // Send HELO command to server
    strcpy(buffer, "HELO\r\n");
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending HELO command");
        exit(1);
    }
    
    // Receive response from server
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        exit(1);
    }
    
    // Send MAIL FROM command to server
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_email);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }
    
    // Receive response from server
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        exit(1);
    }
    
    // Send RCPT TO command to server
    sprintf(buffer, "RCPT TO:<%s>\r\n", to_email);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }
    
    // Receive response from server
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        exit(1);
    }
    
    // Send DATA command to server
    strcpy(buffer, "DATA\r\n");
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending DATA command");
        exit(1);
    }
    
    // Receive response from server
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        exit(1);
    }
    
    // Send message headers and body to server
    sprintf(buffer, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n%s\r\n.\r\n", from_email, to_email, subject, body);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }
    
    // Receive response from server
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        exit(1);
    }
    
    // Close socket
    close(client_socket);
    
    printf("Message sent successfully!\n");
    
    // Free message body memory
    free(body);
    
    return 0;
}