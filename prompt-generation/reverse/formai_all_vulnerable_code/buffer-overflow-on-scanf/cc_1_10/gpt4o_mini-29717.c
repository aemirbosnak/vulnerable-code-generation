//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define Command_SIZE 100

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        error("Error reading response");
    }
    buffer[n] = '\0'; // Null-terminate the string
    printf("Server: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Setup the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Define server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // Clear structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    printf("Connected to FTP server.\n");

    // Authentication and FTP process
    char command[Command_SIZE];
    
    // Read server greeting
    receive_response(sockfd);

    // User authentication
    printf("Please enter username: ");
    scanf("%s", command);
    strcat(command, "\r\n"); // FTP commands end with CRLF

    send_command(sockfd, command); // Send USER command
    receive_response(sockfd);

    printf("Please enter password: ");
    scanf("%s", command);
    strcat(command, "\r\n"); // FTP commands end with CRLF

    send_command(sockfd, command); // Send PASS command
    receive_response(sockfd);

    // Main loop for commands
    while (1) {
        printf("ftp> ");
        fgets(command, sizeof(command), stdin);
        if (strcmp(command, "quit\n") == 0) {
            break;
        }
        
        if (strlen(command) > 1) { // Ensure command is not empty
            send_command(sockfd, command); // Send command
            receive_response(sockfd);       // Get response
        }
    }

    printf("Logging out and closing the connection...\n");
    close(sockfd); // Close the socket
    printf("Connection closed.\n");
    return 0;
}