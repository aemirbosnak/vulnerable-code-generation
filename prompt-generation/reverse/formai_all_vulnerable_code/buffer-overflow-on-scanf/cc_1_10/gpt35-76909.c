//FormAI DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_EMAIL 100

typedef struct contact {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    struct contact *next;
} Contact;

Contact *head = NULL;

void add_contact(char *name, char *email) {
    Contact *new_contact = (Contact *) malloc(sizeof(Contact));
    if (new_contact == NULL) {
        printf("Failed to allocate memory for new contact\n");
        return;
    }

    strncpy(new_contact->name, name, MAX_NAME);
    strncpy(new_contact->email, email, MAX_EMAIL);
    new_contact->next = head;
    head = new_contact;

    printf("%s added to mailing list with email address %s\n", name, email);
}

void remove_contact(char *name) {
    Contact *current_contact = head;
    Contact *previous_contact = NULL;

    while (current_contact != NULL) {
        if (strcmp(current_contact->name, name) == 0) {
            if (previous_contact == NULL) {
                head = current_contact->next;
            } else {
                previous_contact->next = current_contact->next;
            }
            printf("%s removed from mailing list\n", name);
            free(current_contact);
            return;
        }
        previous_contact = current_contact;
        current_contact = current_contact->next;
    }

    printf("%s not found in mailing list\n", name);
}

void display_contacts() {
    Contact *current_contact = head;
    if (current_contact == NULL) {
        printf("Mailing list is empty\n");
        return;
    }
    printf("Mailing list:\n");
    while (current_contact != NULL) {
        printf("%s <%s>\n", current_contact->name, current_contact->email);
        current_contact = current_contact->next;
    }
}

int main() {
    int choice;
    char name[MAX_NAME];
    char email[MAX_EMAIL];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Display contacts\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0; // remove trailing newline character
                printf("Enter email address: ");
                fgets(email, MAX_EMAIL, stdin);
                email[strcspn(email, "\n")] = 0; // remove trailing newline character
                add_contact(name, email);
                break;
            case 2:
                printf("Enter name: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0; // remove trailing newline character
                remove_contact(name);
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again\n");
                break;
        }
    }
    return 0;
}