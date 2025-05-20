//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "pop.mailserver.com"
#define PORT 110
#define BUFFER_SIZE 1024

void print_welcome();
int connect_server(int *sockfd, const char *server, int port);
int authenticate(int sockfd, const char *username, const char *password);
int list_messages(int sockfd);
int retrieve_message(int sockfd, int message_number);
void close_connection(int sockfd);

int main() {
    int sockfd;
    char username[50], password[50];
    
    print_welcome();
    
    printf("Enter your email username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove trailing newline
  
    printf("Enter your email password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove trailing newline

    // Step 1: Connect to the POP3 server
    if (connect_server(&sockfd, SERVER, PORT) < 0) {
        fprintf(stderr, "Error connecting to server.\n");
        return EXIT_FAILURE;
    }

    // Step 2: Authenticate with the server
    if (authenticate(sockfd, username, password) < 0) {
        close_connection(sockfd);
        return EXIT_FAILURE;
    }
    
    // Step 3: List messages
    if (list_messages(sockfd) < 0) {
        close_connection(sockfd);
        return EXIT_FAILURE;
    }

    // User choice to retrieve message
    int msg_number;
    printf("Enter the message number to retrieve: ");
    scanf("%d", &msg_number);
    if (retrieve_message(sockfd, msg_number) < 0) {
        close_connection(sockfd);
        return EXIT_FAILURE;
    }
    
    // Step 4: Close connection
    close_connection(sockfd);
    return EXIT_SUCCESS;
}

void print_welcome() {
    printf("Welcome to the POP3 Client\n");
    printf("===========================\n");
}

int connect_server(int *sockfd, const char *server, int port) {
    struct sockaddr_in server_addr;

    // Create socket
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set server details
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    // Connect to server
    if (connect(*sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        return -1;
    }

    // Read server greeting
    char buffer[BUFFER_SIZE];
    recv(*sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    return 0;
}

int authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Response: %s", buffer);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Response: %s", buffer);

    // Check for successful authentication
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Authentication failed.\n");
        return -1;
    }

    printf("Authentication successful.\n");
    return 0;
}

int list_messages(int sockfd) {
    char command[] = "LIST\r\n";
    send(sockfd, command, strlen(command), 0);
    
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Response: %s", buffer);

    // Return messages status
    return strncmp(buffer, "+OK", 3) == 0 ? 0 : -1;
}

int retrieve_message(int sockfd, int message_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", message_number);
    send(sockfd, command, strlen(command), 0);
    
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Message Content:\n%s", buffer);
    
    return strncmp(buffer, "+OK", 3) == 0 ? 0 : -1;
}

void close_connection(int sockfd) {
    char command[] = "QUIT\r\n";
    send(sockfd, command, strlen(command), 0);
    close(sockfd);
    printf("Connection closed.\n");
}