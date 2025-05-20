//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char **argv) {
    // Variable initialization
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];
    
    // Check if hostname and port number are provided as arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Opening socket");
        exit(1);
    }
    
    // Resolve hostname to IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }
    
    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connecting to server");
        exit(1);
    }
    
    // Receive welcome message from server
    memset(buffer, 0, MAX_SIZE);
    if (recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Receiving data from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send EHLO command to server
    char ehlo_command[MAX_SIZE];
    sprintf(ehlo_command, "EHLO %s\r\n", argv[1]);
    if (send(sock, ehlo_command, strlen(ehlo_command), 0) < 0) {
        perror("Sending data to server");
        exit(1);
    }
    
    // Receive reply from server
    memset(buffer, 0, MAX_SIZE);
    if (recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Receiving data from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send MAIL FROM command to server
    char mail_from_command[MAX_SIZE];
    sprintf(mail_from_command, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sock, mail_from_command, strlen(mail_from_command), 0) < 0) {
        perror("Sending data to server");
        exit(1);
    }
    
    // Receive reply from server
    memset(buffer, 0, MAX_SIZE);
    if (recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Receiving data from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send RCPT TO command to server
    char rcpt_to_command[MAX_SIZE];
    sprintf(rcpt_to_command, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sock, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
        perror("Sending data to server");
        exit(1);
    }
    
    // Receive reply from server
    memset(buffer, 0, MAX_SIZE);
    if (recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Receiving data from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send DATA command to server
    char data_command[MAX_SIZE];
    sprintf(data_command, "DATA\r\n");
    if (send(sock, data_command, strlen(data_command), 0) < 0) {
        perror("Sending data to server");
        exit(1);
    }
    
    // Receive reply from server
    memset(buffer, 0, MAX_SIZE);
    if (recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Receiving data from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send email body to server
    char email_body[MAX_SIZE];
    sprintf(email_body, "Subject: Test email\r\nHello World!\r\n.\r\n");
    if (send(sock, email_body, strlen(email_body), 0) < 0) {
        perror("Sending data to server");
        exit(1);
    }
    
    // Receive reply from server
    memset(buffer, 0, MAX_SIZE);
    if (recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Receiving data from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send QUIT command to server
    char quit_command[MAX_SIZE];
    sprintf(quit_command, "QUIT\r\n");
    if (send(sock, quit_command, strlen(quit_command), 0) < 0) {
        perror("Sending data to server");
        exit(1);
    }
    
    // Receive reply from server
    memset(buffer, 0, MAX_SIZE);
    if (recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Receiving data from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // Close socket
    close(sock);
    
    return 0;
}