//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMAILS 50

typedef struct {
    char email[50];
    struct Email *next;
} Email;

Email* head = NULL;

void addEmail(const char* email) {
    Email* newEmail = (Email*)malloc(sizeof(Email));

    if (newEmail == NULL) {
        printf("ERROR: Out of memory.\n");
        return;
    }

    strcpy(newEmail->email, email);

    newEmail->next = head;
    head = newEmail;
}

void viewEmails() {
    Email* current = head;

    while (current!= NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void removeEmail(const char* email) {
    Email* current = head;
    Email* prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }
}

int main() {
    char choice;
    char email[50];

    printf("Welcome to the retro Mailing list manager!\n");

    while (1) {
        printf("Select an option:\n");
        printf("1. Add email\n");
        printf("2. View emails\n");
        printf("3. Remove email\n");
        printf("4. Quit\n");

        printf("Enter your choice (1-4): ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter email: ");
                scanf("%s", email);
                addEmail(email);
                break;
            case '2':
                viewEmails();
                break;
            case '3':
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(email);
                break;
            case '4':
                printf("Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}