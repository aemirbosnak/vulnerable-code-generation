//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

void send_email(int sockfd);
void receive_email(int sockfd);

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    int choice;
    while (1) {
        printf("\n------ Email Client ------\n");
        printf("1. Send Email\n");
        printf("2. Receive Emails\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                send_email(sockfd);
                break;
            case 2:
                receive_email(sockfd);
                break;
            case 3:
                close(sockfd);
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    close(sockfd);
    return 0;
}

void send_email(int sockfd) {
    char buffer[MAXLINE];
    char recipient[100], subject[100], message[MAXLINE];

    printf("Enter recipient email: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    getchar(); // consume newline
    fgets(message, sizeof(message), stdin);

    // Prepare the email format
    snprintf(buffer, sizeof(buffer), "SEND %s\nSubject: %s\n\n%s", recipient, subject, message);

    // Send email to the server
    send(sockfd, buffer, strlen(buffer), 0);
    printf("Email sent successfully!\n");
}

void receive_email(int sockfd) {
    char buffer[MAXLINE];

    // Request emails from server
    send(sockfd, "RECEIVE", strlen("RECEIVE"), 0);
    
    // Receive emails
    int n = recv(sockfd, buffer, MAXLINE, 0);
    if (n <= 0) {
        printf("No emails to receive or an error occurred.\n");
    } else {
        buffer[n] = '\0'; // Null-terminate the received string
        printf("Received Emails:\n%s\n", buffer);
    }
}