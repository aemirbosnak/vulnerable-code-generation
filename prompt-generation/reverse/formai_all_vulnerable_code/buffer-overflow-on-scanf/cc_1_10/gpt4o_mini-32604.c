//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_USERS 5
#define BUFFER_SIZE 1024
#define POP3_PORT 110

typedef struct {
    char username[50];
    char password[50];
} User;

void clearBuffer(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

void handleUserEmail(User *user) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to POP3 server failed");
        close(sockfd);
        return;
    }

    // Receive server greeting
    clearBuffer(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send USER command
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", user->username);
    send(sockfd, buffer, strlen(buffer), 0);
    clearBuffer(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send PASS command
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", user->password);
    send(sockfd, buffer, strlen(buffer), 0);
    clearBuffer(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send LIST command to get emails
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    clearBuffer(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Closing the connection
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    clearBuffer(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(sockfd);
}

int main() {
    User users[MAX_USERS];
    int user_count = 0;

    printf("Welcome to the Multiplayer POP3 Client! Please register up to %d users:\n", MAX_USERS);
    
    while (user_count < MAX_USERS) {
        printf("Enter username: ");
        scanf("%s", users[user_count].username);
        printf("Enter password: ");
        scanf("%s", users[user_count].password);
        user_count++;

        printf("User registered! Total Users: %d. Enter another user (y/n)? ", user_count);
        char choice;
        getchar();
        scanf("%c", &choice);
        if (choice != 'y') {
            break;
        }
    }

    printf("All users registered. Now fetching emails...\n");

    // Launch email fetch for each user in a separate process
    for (int i = 0; i < user_count; i++) {
        if (fork() == 0) { // Child process for each user
            handleUserEmail(&users[i]);
            exit(0);
        }
    }

    // Wait for all child processes to complete
    for (int i = 0; i < user_count; i++) {
        wait(NULL);
    }

    printf("Email fetching complete for all users. Exiting...\n");
    return 0;
}