//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024
#define MAX_MSG_SIZE 512

void connect_to_server(int *sockfd, const char *server_ip);
void login_to_pop3(int sockfd, const char *username, const char *password);
void retrieve_messages(int sockfd);
void cleanup(int sockfd);

int main() {
    int sockfd;
    char server_ip[16];
    char username[50];
    char password[50];

    printf("=== Galactic POP3 Client v2.0 ===\n");
    printf("Enter the POP3 server IP address: ");
    scanf("%15s", server_ip);
    
    printf("Enter your username: ");
    scanf("%49s", username);
    
    printf("Enter your password: ");
    scanf("%49s", password);

    connect_to_server(&sockfd, server_ip);
    login_to_pop3(sockfd, username, password);
    retrieve_messages(sockfd);
    cleanup(sockfd);

    return 0;
}

void connect_to_server(int *sockfd, const char *server_ip) {
    struct sockaddr_in server_addr;

    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    recv(*sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
}

void login_to_pop3(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE], response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, sizeof(response), 0);
    printf("Server: %s", response);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, sizeof(response), 0);
    printf("Server: %s", response);
}

void retrieve_messages(int sockfd) {
    char command[BUFFER_SIZE], response[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "LIST\r\n");
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, sizeof(response), 0);
    printf("Server: %s\n", response);

    int msg_count;
    sscanf(response, "+OK %d", &msg_count);
    
    for (int i = 1; i <= msg_count; i++) {
        snprintf(command, sizeof(command), "RETR %d\r\n", i);
        send(sockfd, command, strlen(command), 0);
        recv(sockfd, response, sizeof(response), 0);
        printf("Message %d:\n%s\n", i, response);
    }

    snprintf(command, sizeof(command), "QUIT\r\n");
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, sizeof(response), 0);
    printf("Server: %s", response);
}

void cleanup(int sockfd) {
    close(sockfd);
    printf("Connection closed. Galactic greetings until next time!\n");
}