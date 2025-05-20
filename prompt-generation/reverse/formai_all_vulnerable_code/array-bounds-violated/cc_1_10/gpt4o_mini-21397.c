//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "pop.example.com"
#define PORT 110
#define BUFFER_SIZE 1024

void handle_response(int sockfd);
void retrieve_message(int sockfd, int msg_num);
void authenticate(int sockfd, const char *username, const char *password);
void pop3_client(const char *username, const char *password, int sockfd);
void pop3_connect_and_run(const char *username, const char *password);

void handle_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0'; // Null-terminate the received data
    printf("%s", buffer);
}

void retrieve_message(int sockfd, int msg_num) {
    char command[BUFFER_SIZE];
    sprintf(command, "RETR %d\r\n", msg_num);
    send(sockfd, command, strlen(command), 0);
    handle_response(sockfd);
}

void authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // User command
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    handle_response(sockfd);
    
    // Pass command
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    handle_response(sockfd);
}

void pop3_client(const char *username, const char *password, int sockfd) {
    char command[BUFFER_SIZE];
    
    // Send stat command first
    send(sockfd, "STAT\r\n", 7, 0);
    handle_response(sockfd);
    
    // List command to retrieve all messages
    send(sockfd, "LIST\r\n", 7, 0);
    handle_response(sockfd);
    
    // Giving an option to user to retrieve messages
    printf("Retrieving messages...\n");
    for (int i = 1; i <= 5; i++) { // Limit to max 5 messages
        retrieve_message(sockfd, i);
    }
    
    // Quit command to close the session
    send(sockfd, "QUIT\r\n", 7, 0);
    handle_response(sockfd);
}

void pop3_connect_and_run(const char *username, const char *password) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to POP3 server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    handle_response(sockfd);
    
    authenticate(sockfd, username, password);
    pop3_client(username, password, sockfd);
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *username = argv[1];
    const char *password = argv[2];

    pop3_connect_and_run(username, password);

    return 0;
}