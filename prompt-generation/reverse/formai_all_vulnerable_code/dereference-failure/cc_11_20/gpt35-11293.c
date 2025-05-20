//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum message length
#define MAX_READ_LEN 5000

int main(int argc, char *argv[]) {
    // Check if user has provided 2 arguments, i.e., server name and port number
    if (argc != 3) {
        printf("Usage: %s [server name] [port number]\n", argv[0]);
        exit(1);
    }
    
    // Get the server name and port number from the user arguments and create struct for server information
    char *server_name = argv[1];
    char *port_number = argv[2];
    struct hostent *server = gethostbyname(server_name);
    if (server == NULL) {
        printf("Error: No such host '%s'\n", server_name);
        exit(1);
    }
    
    // Create a socket to connect with the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create a socket.\n");
        exit(1);
    }
    
    // Establish a connection with the server
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(port_number));
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Error: Failed to establish a connection with the server.\n");
        exit(1);
    }
    
    // Read the server's banner message
    char server_message[MAX_READ_LEN];
    bzero(server_message, MAX_READ_LEN);
    if (read(sockfd, server_message, MAX_READ_LEN) == -1) {
        printf("Error: Failed to read server's banner message.\n");
        exit(1);
    }
    printf("%s", server_message);
    
    // Send the USER command to server
    char user_command[MAX_READ_LEN];
    bzero(user_command, MAX_READ_LEN);
    printf("Enter your username: ");
    fgets(user_command, MAX_READ_LEN, stdin);
    user_command[strcspn(user_command, "\n")] = 0;
    strcat(user_command, "\r\n");
    if (write(sockfd, user_command, strlen(user_command)) == -1) {
        printf("Error: Failed to write command to server.\n");
        exit(1);
    }
    
    // Read the server's response to the USER command
    bzero(server_message, MAX_READ_LEN);
    if (read(sockfd, server_message, MAX_READ_LEN) == -1) {
        printf("Error: Failed to read server's response to the USER command.\n");
        exit(1);
    }
    printf("%s", server_message);
    
    // Send the PASS command to server
    char pass_command[MAX_READ_LEN];
    bzero(pass_command, MAX_READ_LEN);
    printf("Enter your password: ");
    fgets(pass_command, MAX_READ_LEN, stdin);
    pass_command[strcspn(pass_command, "\n")] = 0;
    strcat(pass_command, "\r\n");
    if (write(sockfd, pass_command, strlen(pass_command)) == -1) {
        printf("Error: Failed to write command to server.\n");
        exit(1);
    }
    
    // Read the server's response to the PASS command
    bzero(server_message, MAX_READ_LEN);
    if (read(sockfd, server_message, MAX_READ_LEN) == -1) {
        printf("Error: Failed to read server's response to the PASS command.\n");
        exit(1);
    }
    printf("%s", server_message);
    
    // Send the STAT command to server
    char stat_command[MAX_READ_LEN];
    bzero(stat_command, MAX_READ_LEN);
    strcpy(stat_command, "STAT\r\n");
    if (write(sockfd, stat_command, strlen(stat_command)) == -1) {
        printf("Error: Failed to write command to server.\n");
        exit(1);
    }
    
    // Read the server's response to the STAT command
    bzero(server_message, MAX_READ_LEN);
    if (read(sockfd, server_message, MAX_READ_LEN) == -1) {
        printf("Error: Failed to read server's response to the STAT command.\n");
        exit(1);
    }
    printf("%s", server_message);

    // Send the LIST command to server
    char list_command[MAX_READ_LEN];
    bzero(list_command, MAX_READ_LEN);
    strcpy(list_command, "LIST\r\n");
    if (write(sockfd, list_command, strlen(list_command)) == -1) {
        printf("Error: Failed to write command to server.\n");
        exit(1);
    }
    
    // Read the server's response to the LIST command
    bzero(server_message, MAX_READ_LEN);
    if (read(sockfd, server_message, MAX_READ_LEN) == -1) {
        printf("Error: Failed to read server's response to the LIST command.\n");
        exit(1);
    }
    printf("%s", server_message);
    
    // Send the RETR command to server
    char retr_command[MAX_READ_LEN];
    bzero(retr_command, MAX_READ_LEN);
    printf("Enter the email ID to retrieve: ");
    fgets(retr_command, MAX_READ_LEN, stdin);
    retr_command[strcspn(retr_command, "\n")] = 0;
    strcat(retr_command, "\r\n");
    if (write(sockfd, retr_command, strlen(retr_command)) == -1) {
        printf("Error: Failed to write command to server.\n");
        exit(1);
    }
    
    // Read the server's response to the RETR command
    bzero(server_message, MAX_READ_LEN);
    if (read(sockfd, server_message, MAX_READ_LEN) == -1) {
        printf("Error: Failed to read server's response to the RETR command.\n");
        exit(1);
    }
    printf("%s", server_message);

    // Close the socket and exit the program
    close(sockfd);
    return 0;
}