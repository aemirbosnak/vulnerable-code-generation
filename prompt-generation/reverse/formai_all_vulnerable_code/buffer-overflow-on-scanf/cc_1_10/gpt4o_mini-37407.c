//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 512
#define SERVER_PORT 12345
#define SERVER_IP "127.0.0.1"

void display_ui() {
    printf("\n====================================\n");
    printf("        CyberMail Client v0.1       \n");
    printf("====================================\n");
    printf("1. Send Email\n");
    printf("2. Read Inbox\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void send_email(int sockfd) {
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("Enter recipient email: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf(" %[^\n]s", subject);
    printf("Enter body: ");
    scanf(" %[^\n]s", body);

    // Send email format: RECIPIENT|SUBJECT|BODY
    char email_packet[MAX_EMAIL_LENGTH + MAX_SUBJECT_LENGTH + MAX_BODY_LENGTH + 3];
    snprintf(email_packet, sizeof(email_packet), "%s|%s|%s", recipient, subject, body);

    send(sockfd, email_packet, strlen(email_packet), 0);
    printf("Email sent to %s\n", recipient);
}

void read_inbox(int sockfd) {
    char buffer[1024];
    send(sockfd, "READ_INBOX", strlen("READ_INBOX"), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    
    printf("Your Inbox:\n");
    printf("%s\n", buffer);
}

int main() {
    struct sockaddr_in server_addr;
    int sockfd;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    int choice;
    while (1) {
        display_ui();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email(sockfd);
                break;
            case 2:
                read_inbox(sockfd);
                break;
            case 3:
                printf("Exiting CyberMail...\n");
                close(sockfd);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    close(sockfd);
    return 0;
}