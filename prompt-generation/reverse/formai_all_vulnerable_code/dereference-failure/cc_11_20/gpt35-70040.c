//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char* argv[]) 
{
    char* hostname = "example.com";
    char* username = "myusername";
    char* password = "mypassword";

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct hostent* server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", hostname);
        exit(1);
    }

    // Construct server address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(110);

    // Connect to server
    int connect_result = connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connect_result < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Read initial response from server
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (bytes_received < 0) {
        perror("Failed to read initial response from server");
        exit(1);
    }

    // Send username to server
    char username_command[MAX_BUFFER_SIZE];
    snprintf(username_command, sizeof(username_command), "USER %s\r\n", username);
    int bytes_sent = write(sockfd, username_command, strlen(username_command));
    if (bytes_sent < 0) {
        perror("Failed to send username to server");
        exit(1);
    }

    // Read response from server after sending username
    bytes_received = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (bytes_received < 0) {
        perror("Failed to read response after sending username");
        exit(1);
    }

    // Send password to server
    char password_command[MAX_BUFFER_SIZE];
    snprintf(password_command, sizeof(password_command), "PASS %s\r\n", password);
    bytes_sent = write(sockfd, password_command, strlen(password_command));
    if (bytes_sent < 0) {
        perror("Failed to send password to server");
        exit(1);
    }

    // Read response from server after sending password
    bytes_received = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (bytes_received < 0) {
        perror("Failed to read response after sending password");
        exit(1);
    }

    // Send command to list messages
    char list_command[] = "LIST\r\n";
    bytes_sent = write(sockfd, list_command, strlen(list_command));
    if (bytes_sent < 0) {
        perror("Failed to send LIST command to server");
        exit(1);
    }

    // Read response from server after sending LIST command
    bytes_received = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (bytes_received < 0) {
        perror("Failed to read response after sending LIST command");
        exit(1);
    }

    // Print out response from server
    printf("Response from server:\n%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}