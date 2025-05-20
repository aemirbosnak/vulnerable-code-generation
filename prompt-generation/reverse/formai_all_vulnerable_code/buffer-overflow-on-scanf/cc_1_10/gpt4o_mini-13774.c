//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_SUBJECT_LEN 100
#define EMAIL_BODY_LEN 500
#define EMAIL_FILENAME "emails.txt"

// Structure to hold an email
typedef struct {
    char subject[EMAIL_SUBJECT_LEN];
    char body[EMAIL_BODY_LEN];
} Email;

// Function to simulate sending an email
void send_email() {
    Email email;
    FILE *file = fopen(EMAIL_FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open email file");
        return;
    }

    // Get email subject
    printf("Enter email subject: ");
    fgets(email.subject, EMAIL_SUBJECT_LEN, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0; // Remove newline

    // Get email body
    printf("Enter email body:\n");
    fgets(email.body, EMAIL_BODY_LEN, stdin);
    email.body[strcspn(email.body, "\n")] = 0; // Remove newline

    // Write email to file
    fprintf(file, "Subject: %s\nBody: %s\n\n", email.subject, email.body);
    fclose(file);

    printf("Surprise! Your email has been sent and saved!\n");
}

// Function to simulate receiving emails
void receive_email() {
    FILE *file = fopen(EMAIL_FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open email file");
        return;
    }

    printf("Surprise! Here are your emails:\n\n");
    char buffer[EMAIL_SUBJECT_LEN + EMAIL_BODY_LEN + 50];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        printf("\n");
    }
    fclose(file);
}

// Main function
int main() {
    int choice;
    do {
        printf("Welcome to the Surprise Email Client!\n");
        printf("1. Send Email\n");
        printf("2. Receive Emails\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume trailing newline

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                receive_email();
                break;
            case 3:
                printf("Thank you for using the Surprise Email Client! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option!\n");
        }
    } while (choice != 3);

    return 0;
}