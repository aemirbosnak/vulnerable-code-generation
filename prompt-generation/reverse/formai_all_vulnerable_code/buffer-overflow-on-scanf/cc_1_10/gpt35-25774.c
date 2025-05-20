//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 1000

// Structure for storing emails
typedef struct Email {
    char name[50];
    char email[50];
} Email;

// Function to add a new email to the list
void addEmail(Email emails[], int *count) {
    if (*count < MAX_EMAILS) {
        printf("\nEnter name: ");
        scanf("%s", emails[*count].name);
        printf("Enter email: ");
        scanf("%s", emails[*count].email);
        (*count)++;
        printf("\nEmail added successfully!\n");
    } else {
        printf("\nError: Maximum number of emails reached.");
    }
}

// Function to remove an email from the list
void removeEmail(Email emails[], int *count) {
    char email[50];
    printf("\nEnter email to be removed: ");
    scanf("%s", email);
    for (int i = 0; i < *count; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            for (int j = i; j < (*count) - 1; j++) {
                strcpy(emails[j].name, emails[j+1].name);
                strcpy(emails[j].email, emails[j+1].email);
            }
            (*count)--;
            printf("\nEmail removed successfully!\n");
            return;
        }
    }
    printf("\nError: Email not found.\n");
}

// Function to print all emails in the list
void printEmails(Email emails[], int count) {
    printf("\n%-20s %-30s\n", "Name", "Email");
    printf("---------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-30s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    Email emails[MAX_EMAILS];
    int count = 0;
    int choice;
    while (1) {
        printf("\n---------------------------------------\n");
        printf("              Mailing List\n");
        printf("---------------------------------------\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print all emails\n");
        printf("4. Quit\n");
        printf("---------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmail(emails, &count);
                break;
            case 2:
                removeEmail(emails, &count);
                break;
            case 3:
                printEmails(emails, count);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nError: Invalid choice.\n");
        }
    }
    return 0;
}