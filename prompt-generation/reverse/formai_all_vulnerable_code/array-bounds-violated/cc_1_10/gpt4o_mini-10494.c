//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

// A hidden treasure of constants
#define SERVER "ftp.example.com" // The mythical FTP server
#define PORT 21                     // The golden gate of communication
#define BUFFER_SIZE 1024            // The treasure chest for data

// A function to unveil the secrets of socket creation
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket!");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// A function to connect to the FTP server
void connect_to_server(int sockfd) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the FTP server failed!");
        exit(EXIT_FAILURE);
    }
    printf("Connected to the server: %s\n", SERVER);
}

// A function to unveil the response from the server
void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Server response: %s", buffer);
    }
}

// A function to send commands to the server
void send_command(int sockfd, const char* command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent command: %s", command);
    receive_response(sockfd);
}

// A function to play the FTP game
void ftp_client() {
    int sockfd = create_socket();
    connect_to_server(sockfd);

    // Unravel the mystery of login
    send_command(sockfd, "USER anonymous\r\n"); // Log in as anonymous user
    send_command(sockfd, "PASS guest@example.com\r\n"); // Give a fake password

    // Uncover the list of files
    send_command(sockfd, "PASV\r\n"); // Enter passive mode
    send_command(sockfd, "LIST\r\n"); // Get the list of files

    // A farewell to the server
    send_command(sockfd, "QUIT\r\n");

    close(sockfd); // Close the golden gate
    printf("Client disconnected.\n");
}

// The enigma solver - main
int main() {
    printf("Welcome to the FTP Client Puzzle!\n");
    ftp_client();
    return 0;
}