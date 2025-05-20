//Falcon-180B DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void send_email(char *to, char *subject, char *body);
void receive_email(char *from, char *subject, char *body);

int main() {
    char username[20];
    printf("Enter your email address: ");
    scanf("%s", username);

    while (1) {
        printf("\n");
        printf("1. Send email\n");
        printf("2. Check inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char to[50];
                char subject[50];
                char body[200];
                printf("\n");
                printf("Enter recipient email address: ");
                scanf("%s", to);
                printf("Enter email subject: ");
                scanf("%s", subject);
                printf("Enter email body: ");
                scanf("%[^\n]", body);
                send_email(to, subject, body);
                break;
            }
            case 2: {
                receive_email(username, "", "");
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}

// Function to send email
void send_email(char *to, char *subject, char *body) {
    printf("\n");
    printf("Sending email to %s with subject %s...\n", to, subject);
    printf("Email body:\n%s", body);
}

// Function to receive email
void receive_email(char *from, char *subject, char *body) {
    printf("\n");
    printf("You have received an email from %s with subject %s:\n", from, subject);
    printf("Email body:\n%s", body);
}