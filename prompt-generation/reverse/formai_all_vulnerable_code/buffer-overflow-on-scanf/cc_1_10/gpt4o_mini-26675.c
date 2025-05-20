//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_MSG_SIZE 1024
#define SERVER_PORT 8080
#define BUFFER_SIZE 2048

void print_menu() {
    printf("========== Post-Apocalyptic Email Client ==========\n");
    printf("1. Send Message\n");
    printf("2. Read Messages\n");
    printf("3. Exit\n");
    printf("===================================================\n");
    printf("Choose an option: ");
}

void send_message(int sockfd) {
    char message[MAX_MSG_SIZE];
    printf("Enter recipient's address: ");
    char recipient[64];
    scanf("%s", recipient);

    printf("Enter your message: ");
    getchar(); // consume newline character
    fgets(message, sizeof(message), stdin);
    
    // Creating the final message format
    char full_msg[BUFFER_SIZE];
    snprintf(full_msg, sizeof(full_msg), "From: Survivor@dystopia\nTo: %s\nMessage: %s", recipient, message);

    // Send message to the server
    send(sockfd, full_msg, strlen(full_msg), 0);
    printf("Message sent to %s!\n", recipient);
}

void read_messages(int sockfd) {
    char buffer[BUFFER_SIZE];
    
    // Request messages from server
    send(sockfd, "READ", strlen("READ"), 0);
    
    // Receive messages from server
    int n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if (n > 0) {
        buffer[n] = '\0';
        printf("=== Received Messages ===\n%s", buffer);
    } else {
        printf("No new messages.\n");
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Local server for simplicity

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_message(sockfd);
                break;
            case 2:
                read_messages(sockfd);
                break;
            case 3:
                close(sockfd);
                printf("Exiting Email Client. Stay alive!\n");
                return 0;
            default:
                printf("Invalid choice. Try again!\n");
        }
    }

    close(sockfd);
    return 0;
}