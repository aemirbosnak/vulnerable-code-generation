//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

// FTP Commands
#define USER "USER"
#define PASS "PASS"
#define RETR "RETR"
#define QUIT "QUIT"

// Buffer size for data transfer
#define BUFFER_SIZE 4096

// Function to set up a socket connection
int create_connection(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command and receive the response
void send_command(int sockfd, const char *command, char *response) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
    
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Server response: %s", response);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    char response[BUFFER_SIZE];

    printf("Connecting to %s...\n", hostname);
    
    int sockfd = create_connection(hostname, 21);
    
    // Fetch initial response from the server
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Server response: %s", response);
    
    // Send USER command
    snprintf(response, sizeof(response), "%s %s", USER, username);
    send_command(sockfd, response, response);
    
    // Send PASS command
    snprintf(response, sizeof(response), "%s %s", PASS, password);
    send_command(sockfd, response, response);
    
    // Now we can retrieve a file with RETR
    printf("Type the name of the file you wish to retrieve:\n");
    char filename[BUFFER_SIZE];
    scanf("%s", filename);
    
    snprintf(response, sizeof(response), "%s %s", RETR, filename);
    send_command(sockfd, response, response);
    
    // Processing response for file download
    if (strstr(response, "150") != NULL) {
        printf("Starting file transfer...\n");
        
        // Here would come the data connection logic, simplified
        // Assume we've opened a data connection
        FILE *fp = fopen(filename, "wb");
        if(fp == NULL) {
            perror("File open error");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        
        // Dummy read loop; realistically you'd set up a separate data socket.
        char data_buffer[BUFFER_SIZE];
        int bytes_received = 0;
        
        // Simulated loop; in practice you would manage data sockets
        while ((bytes_received = recv(sockfd, data_buffer, sizeof(data_buffer), 0)) > 0) {
            fwrite(data_buffer, sizeof(char), bytes_received, fp);
        }
        
        printf("File transfer complete.\n");
        fclose(fp);
    } else {
        printf("Could not retrieve file: %s", response);
    }

    // Cleanly terminate connection
    send_command(sockfd, QUIT, response);
    
    close(sockfd);
    printf("Exited gracefully.\n");
    return EXIT_SUCCESS;
}