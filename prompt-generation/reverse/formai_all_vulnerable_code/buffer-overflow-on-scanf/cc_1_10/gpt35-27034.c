//FormAI DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 50

char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
int num_emails = 0;

void print_menu() {
    printf("\n\n");
    printf("[1] Add email address\n");
    printf("[2] Display all email addresses\n");
    printf("[3] Search for an email address\n");
    printf("[4] Exit\n");
    printf("\nEnter your choice: ");
}

void add_email() {
    char email[MAX_EMAIL_LENGTH];
    printf("\nEnter email address: ");
    scanf("%s", email);
    strcpy(emails[num_emails], email);
    num_emails++;
    printf("\nEmail address added successfully.\n");
}

void display_emails() {
    int i;
    printf("\nEmail addresses:\n");
    for (i = 0; i < num_emails; i++) {
        printf("%d. %s\n", i + 1, emails[i]);
    }
    printf("\n");
}

void search_email() {
    char email[MAX_EMAIL_LENGTH];
    int i, found = 0;
    printf("\nEnter email address to search: ");
    scanf("%s", email);
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i], email) == 0) {
            found = 1;
            printf("\nEmail address found at index %d.\n", i + 1);
            break;
        }
    }
    if (!found) {
        printf("\nEmail address not found.\n");
    }
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                display_emails();
                break;
            case 3:
                search_email();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1);
    return 0;
}