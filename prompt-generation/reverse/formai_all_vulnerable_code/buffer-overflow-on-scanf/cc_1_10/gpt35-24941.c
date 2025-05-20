//FormAI DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

// Function to read user input
char *readInput(char *message) {
    char *input = malloc(MAXLEN * sizeof(char));
    printf("%s", message);
    fgets(input, MAXLEN, stdin); // Get user input from console
    input[strlen(input) - 1] = '\0'; // Remove newline character from the input
    return input;
}

// Function to display menu
void displayMenu() {
    printf("-----C Email Client-----\n");
    printf("1. Compose an email\n");
    printf("2. View inbox\n");
    printf("3. View sent emails\n");
    printf("4. Exit\n");
}

// Struct to represent an email
typedef struct {
    char *to;
    char *cc;
    char *subject;
    char *body;
} Email;

// Add email to file
void saveEmailToFile(Email email) {
    FILE *file;
    file = fopen("emails.txt", "a"); // Append email to file
    fprintf(file, "To: %s\n", email.to);
    fprintf(file, "CC: %s\n", email.cc);
    fprintf(file, "Subject: %s\n", email.subject);
    fprintf(file, "Body: %s\n", email.body);
    fprintf(file, "------------------\n");
    fclose(file);
    printf("Email saved successfully to file\n");
}

// Function to compose an email
void composeEmail() {
    char *to = readInput("Enter email address of recipient: ");
    char *cc = readInput("Enter email address of CC recipient (optional): ");
    char *subject = readInput("Enter subject: ");
    char *body = readInput("Enter email body: ");
    Email email = {.to = to, .cc = cc, .subject = subject, .body = body};
    saveEmailToFile(email); // Save email to file
}

// Function to view inbox
void viewInbox() {
    FILE *file;
    file = fopen("emails.txt", "r");
    char line[MAXLEN];
    int count = 0;
    while (fgets(line, MAXLEN, file)) {
        if (strstr(line, "To:")) {
            printf("Email #%d\n", ++count);
            printf("%s", line); // Print email recipient
        }
    }
    if (count == 0) printf("No emails found in inbox\n");
    fclose(file);
}

// Function to view sent emails
void viewSentEmails() {
    FILE *file;
    file = fopen("emails.txt", "r");
    char line[MAXLEN];
    int count = 0;
    while (fgets(line, MAXLEN, file)) {
        if (strstr(line, "To:")) {
            count++;
        }
        if (strstr(line, "Subject:") && count > 0) {
            printf("Email #%d\n", count);
            printf("%s", line); // Print email subject
        }
    }
    if (count == 0) printf("No sent emails found\n");
    fclose(file);
}

int main() {
    int choice = 0;
    while (choice != 4) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer
        switch (choice) {
            case 1:
                composeEmail();
                break;
            case 2:
                viewInbox();
                break;
            case 3:
                viewSentEmails();
                break;
            case 4:
                printf("Exiting C Email Client...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}