//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100
#define FILENAME "emails.txt"

void display_menu();
void add_email(char emails[][EMAIL_LENGTH], int *count);
void remove_email(char emails[][EMAIL_LENGTH], int *count);
void view_emails(char emails[][EMAIL_LENGTH], int count);
void save_emails(char emails[][EMAIL_LENGTH], int count);
void load_emails(char emails[][EMAIL_LENGTH], int *count);
int email_exists(char emails[][EMAIL_LENGTH], int count, const char *email);
void clear_buffer();

int main() {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count = 0;
    
    load_emails(emails, &count);

    int choice;

    do {
        display_menu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        clear_buffer(); // Clear the newline

        switch (choice) {
            case 1: 
                add_email(emails, &count);
                break;
            case 2: 
                remove_email(emails, &count);
                break;
            case 3: 
                view_emails(emails, count);
                break;
            case 4: 
                save_emails(emails, count);
                break;
            case 0:
                printf("Exiting the mailing list manager. Stay in touch!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");

    } while (choice != 0);

    return 0;
}

void display_menu() {
    printf("***** Mailing List Manager *****\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. View Emails\n");
    printf("4. Save Emails to File\n");
    printf("0. Exit\n");
}

void add_email(char emails[][EMAIL_LENGTH], int *count) {
    if (*count >= MAX_EMAILS) {
        printf("Sorry! Mailing list is full.\n");
        return;
    }

    char email[EMAIL_LENGTH];
    printf("Enter the email address to add: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character

    if (email_exists(emails, *count, email)) {
        printf("This email is already in the list!\n");
    } else {
        strcpy(emails[*count], email);
        (*count)++;
        printf("Email %s added successfully!\n", email);
    }
}

void remove_email(char emails[][EMAIL_LENGTH], int *count) {
    if (*count == 0) {
        printf("The mailing list is empty! Nothing to remove.\n");
        return;
    }

    char email[EMAIL_LENGTH];
    printf("Enter the email address to remove: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character

    for (int i = 0; i < *count; i++) {
        if (strcmp(emails[i], email) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(emails[j], emails[j + 1]);
            }
            (*count)--;
            printf("Email %s removed successfully!\n", email);
            return;
        }
    }
    printf("Email %s not found in the list!\n", email);
}

void view_emails(char emails[][EMAIL_LENGTH], int count) {
    if (count == 0) {
        printf("No emails in the list to show!\n");
        return;
    }

    printf("Current Emails in the Mailing List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, emails[i]);
    }
}

void save_emails(char emails[][EMAIL_LENGTH], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", emails[i]);
    }
    
    fclose(file);
    printf("Emails saved to %s successfully!\n", FILENAME);
}

void load_emails(char emails[][EMAIL_LENGTH], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not load emails, starting fresh.\n");
        return;
    }

    while (*count < MAX_EMAILS && fgets(emails[*count], EMAIL_LENGTH, file)) {
        emails[*count][strcspn(emails[*count], "\n")] = 0; // Remove newline
        (*count)++;
    }
    
    fclose(file);
    printf("Loaded %d emails from file!\n", *count);
}

int email_exists(char emails[][EMAIL_LENGTH], int count, const char *email) {
    for (int i = 0; i < count; i++) {
        if (strcmp(emails[i], email) == 0) {
            return 1; // Email found
        }
    }
    return 0; // Not found
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}