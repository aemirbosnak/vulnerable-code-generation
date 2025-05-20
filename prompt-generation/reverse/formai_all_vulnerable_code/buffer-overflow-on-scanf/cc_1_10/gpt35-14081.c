//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, bytes_recv;
    struct sockaddr_in server_addr;
    char buffer[BUFF_SIZE] = {0};
    char username[BUFF_SIZE] = {0};
    char password[BUFF_SIZE] = {0};
    char mailbox[BUFF_SIZE] = {0};

    // Check command-line arguments
    if (argc != 3) {
        printf("Usage: %s <server address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // Zeroing server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    
    // Configure the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    
    // Convert server IP Address to binary format
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) == -1) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connect failed");
        exit(EXIT_FAILURE);
    }
    
    // Prompt the user to enter their username and password
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);

    // Send the login command to IMAP server
    snprintf(buffer, BUFF_SIZE, "LOGIN %s %s\r\n", username, password);
    send(sock, buffer, strlen(buffer), 0);

    // Read response from IMAP server
    bytes_recv = recv(sock, buffer, BUFF_SIZE, 0);
    if (bytes_recv == -1) {
        perror("Could not read response from server");
        exit(EXIT_FAILURE); 
    }
    
    // Check if user has successfully logged in
    if (strncmp(buffer, "* OK", 4) != 0) {
        printf("Login failed. Response: %s\n", buffer);
        exit(EXIT_FAILURE);   
    }
    
    // Prompt the user to select a mailbox
    printf("Enter mailbox to select: ");
    scanf("%s", mailbox);

    // Send the select mailbox command to IMAP server
    snprintf(buffer, BUFF_SIZE, "SELECT %s\r\n", mailbox);
    send(sock, buffer, strlen(buffer), 0);

    // Read response from IMAP server
    bytes_recv = recv(sock, buffer, BUFF_SIZE, 0);
    if (bytes_recv == -1) {
        perror("Could not read response from server");
        exit(EXIT_FAILURE); 
    }

    // Check if mailbox has been successfully selected
    if (strncmp(buffer, "* OK", 4) != 0) {
        printf("Selecting mailbox failed. Response: %s\n", buffer);
        exit(EXIT_FAILURE);   
    }

    // Print the number of messages in the selected mailbox
    snprintf(buffer, BUFF_SIZE, "STATUS %s (MESSAGES)\r\n", mailbox);
    send(sock, buffer, strlen(buffer), 0);

    // Read response from IMAP server
    bytes_recv = recv(sock, buffer, BUFF_SIZE, 0);
    if (bytes_recv == -1) {
        perror("Could not read response from server");
        exit(EXIT_FAILURE); 
    }

    // Parse the response to extract the number of messages in the mailbox
    char *p = strstr(buffer, "MESSAGES");
    int num_messages = atoi(p + 9);
    printf("Number of messages in %s: %d\n", mailbox, num_messages);
    
    // Close the socket
    close(sock);
    
    return 0;
}