//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

// Heartfelt definitions
#define SERVER_IP "ftp.example.com"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

// Function declarations
void greet();
void connect_to_server(int *sockfd);
void login_to_server(int sockfd);
void list_files(int sockfd);
void close_connection(int sockfd);
void send_command(int sockfd, const char *command, char *response);

int main() {
    // The meeting of souls
    int sockfd;
    
    greet();
    
    // The journey begins, laying the foundation of connection
    connect_to_server(&sockfd);
    
    // The embrace of trust, logging in
    login_to_server(sockfd);
    
    // The sweet moment of discovery
    list_files(sockfd);
    
    // Function ends, bittersweet goodbye on the horizon
    close_connection(sockfd);
    
    return 0;
}

void greet() {
    printf("🌹 Welcome, dear user, to your FTP Client! 🌹\n");
    printf("❤️ Let us embark on a journey to share files with grace and style! ❤️\n\n");
}

void connect_to_server(int *sockfd) {
    struct sockaddr_in server_addr;
    
    // Let us open our heart to new connections
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        perror("💔 Connection failed! The universe is cruel...");
        exit(EXIT_FAILURE);
    }
    
    // Setting up the scene
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    
    // Making the connection
    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("💔 Oh no! The connection was rejected by fate...");
        exit(EXIT_FAILURE);
    }
    
    printf("💞 Connected to the server at %s:%d 💞\n", SERVER_IP, SERVER_PORT);
}

void login_to_server(int sockfd) {
    char response[BUFFER_SIZE];
    char username[50];
    char password[50];
    
    // Gather romantic credentials
    printf("🌼 Please enter your FTP username: ");
    scanf("%s", username);
    printf("🌼 Please enter your FTP password: ");
    scanf("%s", password);
    
    // Sending login details
    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "USER %s\r\n", username);
    send_command(sockfd, login_command, response);
    printf("%s\n", response);
    
    snprintf(login_command, sizeof(login_command), "PASS %s\r\n", password);
    send_command(sockfd, login_command, response);
    printf("%s\n", response);
}

void list_files(int sockfd) {
    char response[BUFFER_SIZE];
    
    // Asking for the affection of the list of files
    send_command(sockfd, "PASV\r\n", response);
    printf("%s\n", response);
    
    // Receiving the list of files as a love letter
    send_command(sockfd, "LIST\r\n", response);
    printf("📜 Files in the server:\n%s\n", response);
}

void close_connection(int sockfd) {
    char response[BUFFER_SIZE];
    
    // With a heavy heart, we say goodbye
    send_command(sockfd, "QUIT\r\n", response);
    printf("%s\n", response);
    
    close(sockfd);
    printf("💔 Connection closed. Farewell, until we meet again. 💔\n");
}

void send_command(int sockfd, const char *command, char *response) {
    // The whispers of command sent to the server
    send(sockfd, command, strlen(command), 0);
    
    // Awaiting the tender response
    recv(sockfd, response, BUFFER_SIZE, 0);
}