//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000
#define FILENAME "emails.txt"

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

// Function prototypes
void composeEmail(Email *email);
void sendEmail(Email *email);
void displayEmails();
void clearScreen();

// Main program function
int main() {
    int choice;
    Email emails[MAX_EMAILS] = {0};
    int emailCount = 0;

    while (1) {
        clearScreen();
        printf("Simple Email Client\n");
        printf("1. Compose Email\n");
        printf("2. Display Emails\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                if (emailCount < MAX_EMAILS) {
                    composeEmail(&emails[emailCount]);
                    emailCount++;
                } else {
                    printf("Email limit reached! Cannot compose more emails.\n");
                }
                break;
            case 2:
                displayEmails();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to clear the screen
void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

// Function to compose a new email
void composeEmail(Email *email) {
    printf("Composing a new email:\n");
    
    printf("Enter subject: ");
    fgets(email->subject, MAX_SUBJECT_LEN, stdin);
    email->subject[strcspn(email->subject, "\n")] = 0; // Remove newline character

    printf("Enter body (max 1000 characters). Press CTRL+D to end:\n");
    size_t len = 0;
    char *body = malloc(MAX_BODY_LEN);
    if (body == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Read the body until EOF is reached
    while (fgets(body + len, MAX_BODY_LEN - len, stdin) && len < MAX_BODY_LEN) {
        len += strlen(body + len);
        if (len >= MAX_BODY_LEN - 1) break; // Avoid overflow
    }
    strncpy(email->body, body, MAX_BODY_LEN);
    email->body[MAX_BODY_LEN - 1] = '\0'; // Ensure null termination
    free(body);

    sendEmail(email);
}

// Function to simulate sending an email (save to file)
void sendEmail(Email *email) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }
    fprintf(file, "Subject: %s\nBody: %s\n\n", email->subject, email->body);
    fclose(file);
    printf("Email sent successfully!\n");
    getchar(); // Pause
}

// Function to display all sent emails
void displayEmails() {
    printf("Displaying all sent emails:\n");
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        getchar(); // Pause
        return;
    }
    
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    getchar(); // Pause
}