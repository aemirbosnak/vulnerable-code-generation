//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 50

// Struct for holding email information
typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Email;

// Function declarations
void addEmail(Email *emails, int *count);
void viewEmails(Email *emails, int count);
void deleteEmail(Email *emails, int *count);
void saveEmails(Email *emails, int count);
void loadEmails(Email *emails, int *count);

int main() {
    Email emails[MAX_EMAILS];
    int count = 0;
    int choice;

    // Load saved emails from file
    loadEmails(emails, &count);

    // Main program loop
    do {
        printf("1. Add Email\n");
        printf("2. View Emails\n");
        printf("3. Delete Email\n");
        printf("4. Save Emails\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmail(emails, &count);
                break;
            case 2:
                viewEmails(emails, count);
                break;
            case 3:
                deleteEmail(emails, &count);
                break;
            case 4:
                saveEmails(emails, count);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function for adding a new email to the list
void addEmail(Email *emails, int *count) {
    char newEmail[MAX_EMAIL_LENGTH];

    // Check if list is full
    if (*count == MAX_EMAILS) {
        printf("Error: List is full!\n");
        return;
    }

    printf("Enter Email Address: ");
    scanf("%s", newEmail);

    // Check if email is already in the list
    for (int i = 0; i < *count; i++) {
        if (strcmp(emails[i].email, newEmail) == 0) {
            printf("Error: Email already in list!\n");
            return;
        }
    }

    // Add email to list
    strcpy(emails[*count].email, newEmail);
    (*count)++;

    printf("Email added successfully!\n");
}

// Function for viewing the current list of emails
void viewEmails(Email *emails, int count) {
    if (count == 0) {
        printf("No emails in list!\n");
        return;
    }

    printf("Current Emails:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i+1, emails[i].email);
    }
}

// Function for deleting an email from the list
void deleteEmail(Email *emails, int *count) {
    int index;

    if (*count == 0) {
        printf("No emails in list!\n");
        return;
    }

    viewEmails(emails, *count);

    printf("Enter index of email to delete: ");
    scanf("%d", &index);

    // Shift emails down in array and decrement count
    for (int i = index-1; i < *count-1; i++) {
        strcpy(emails[i].email, emails[i+1].email);
    }
    (*count)--;

    printf("Email deleted successfully!\n");
}

// Function for saving the current list of emails to a file
void saveEmails(Email *emails, int count) {
    FILE *file;

    file = fopen("emails.txt", "w");

    if (file == NULL) {
        printf("Error: Cannot open file to save emails!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", emails[i].email);
    }

    fclose(file);

    printf("Emails saved to file successfully!\n");
}

// Function for loading saved emails from a file
void loadEmails(Email *emails, int *count) {
    FILE *file;
    char email[MAX_EMAIL_LENGTH];

    file = fopen("emails.txt", "r");

    if (file == NULL) {
        printf("No saved emails found.\n");
        return;
    }

    while (fgets(email, MAX_EMAIL_LENGTH+1, file) != NULL && *count < MAX_EMAILS) {
        // Remove newline character from email
        email[strcspn(email, "\n")] = 0;

        // Add email to list
        strcpy(emails[*count].email, email);
        (*count)++;
    }

    fclose(file);

    printf("Saved emails loaded successfully!\n");
}