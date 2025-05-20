//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

// Function to establish a connection to the FTP server
int create_socket(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Get server host by name
    if ((host = gethostbyname(hostname)) == NULL) {
        perror("Invalid hostname");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to receive data from the FTP server
void receive_data(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';  // Null-terminate the string
        printf("%s", buffer);  // Print received data
    }

    if (n < 0) {
        perror("Failed to receive data");
    }
}

// Function to send FTP commands to the server
void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);  // FTP commands require CRLF
}

// Function to log in to the FTP server
void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    receive_data(sockfd);

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    receive_data(sockfd);
}

// Function to retrieve a file from the FTP server
void ftp_retr(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %s", filename);
    send_command(sockfd, command);
    receive_data(sockfd);
}

// Function to close the FTP connection
void ftp_quit(int sockfd) {
    send_command(sockfd, "QUIT");
    receive_data(sockfd);
    close(sockfd);
}

// Main function demonstrating FTP client functionality
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *username = argv[3];
    const char *password = argv[4];

    // Create socket and connect to FTP server
    int sockfd = create_socket(hostname, port);
    
    // Receive server greeting
    receive_data(sockfd);
    
    // Log in to the FTP server
    ftp_login(sockfd, username, password);
    
    // Send RETR command to download a file
    const char *filename = "sample.txt";  // Example file to retrieve
    ftp_retr(sockfd, filename);
    
    // Close the FTP connection
    ftp_quit(sockfd);
    
    return 0;
}