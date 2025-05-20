//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_email(int sockfd) {
    char buffer[BUFFER_SIZE];
    char recipient[100], subject[100], body[512];

    printf("Enter recipient email: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0; // Remove newline

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline

    printf("Enter email body:\n");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0; // Remove newline

    snprintf(buffer, sizeof(buffer), "To: %s\nSubject: %s\n\n%s", recipient, subject, body);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("Email sent successfully!\n");
}

void receive_email(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    printf("Receiving emails...\n");
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        error("Error reading from socket");
    }

    buffer[n] = '\0'; // Null-terminate buffer
    printf("Received Email:\n%s\n", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    printf("Welcome to the Sherlock Holmes Email Client!\n");
  
    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Send Email\n");
        printf("2. Receive Email\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Remove extra newline character

        switch (choice) {
            case 1:
                send_email(sockfd);
                break;
            case 2:
                receive_email(sockfd);
                break;
            case 3:
                close(sockfd);
                printf("Exiting the Sherlock Holmes Email Client. Farewell!\n");
                return 0;
            default:
                printf("Please select a valid option.\n");
        }
    }

    close(sockfd);
    return 0;
}