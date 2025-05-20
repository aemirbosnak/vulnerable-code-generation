//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define SUBJECT_LENGTH 100
#define BODY_LENGTH 500
#define EMAIL_FILENAME "emails.txt"

typedef struct {
    int id;
    char subject[SUBJECT_LENGTH];
    char body[BODY_LENGTH];
} Email;

// Function declarations
void displayMenu();
void createEmail();
void viewEmails();
void deleteEmail();
void saveEmail(Email email);
void loadEmails();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createEmail();
                break;
            case 2:
                viewEmails();
                break;
            case 3:
                deleteEmail();
                break;
            case 4:
                printf("Exiting the email client.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Email Client Menu ---\n");
    printf("1. Create New Email\n");
    printf("2. View Emails\n");
    printf("3. Delete Email\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void createEmail() {
    Email email;
    FILE *file;

    printf("Enter subject: ");
    getchar(); // to consume newline
    fgets(email.subject, SUBJECT_LENGTH, stdin);
    email.subject[strcspn(email.subject, "\n")] = '\0'; // remove newline

    printf("Enter body: ");
    fgets(email.body, BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = '\0'; // remove newline

    email.id = rand() % 1000; // Assign a random ID for simplicity

    saveEmail(email);
    printf("Email created successfully.\n");
}

void saveEmail(Email email) {
    FILE *file = fopen(EMAIL_FILENAME, "a");
    if (file != NULL) {
        fprintf(file, "%d\n%s\n%s\n", email.id, email.subject, email.body);
        fclose(file);
    } else {
        printf("Error saving email.\n");
    }
}

void viewEmails() {
    FILE *file = fopen(EMAIL_FILENAME, "r");
    if (file == NULL) {
        printf("No emails found.\n");
        return;
    }

    Email email;
    printf("\n--- Emails ---\n");
    while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n", &email.id, email.subject, email.body) != EOF) {
        printf("ID: %d\nSubject: %s\nBody: %s\n", email.id, email.subject, email.body);
    }
    
    fclose(file);
}

void deleteEmail() {
    int emailId;
    printf("Enter the ID of the email to delete: ");
    scanf("%d", &emailId);

    FILE *file = fopen(EMAIL_FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    Email email;
    int found = 0;

    while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n", &email.id, email.subject, email.body) != EOF) {
        if (email.id == emailId) {
            found = 1; // Found the email to delete
            continue; // Skip writing this email to temp file
        }
        fprintf(tempFile, "%d\n%s\n%s\n", email.id, email.subject, email.body);
    }

    fclose(file);
    fclose(tempFile);
    remove(EMAIL_FILENAME);
    rename("temp.txt", EMAIL_FILENAME);

    if (found) {
        printf("Email with ID %d deleted successfully.\n", emailId);
    } else {
        printf("Email with ID %d not found.\n", emailId);
    }
}