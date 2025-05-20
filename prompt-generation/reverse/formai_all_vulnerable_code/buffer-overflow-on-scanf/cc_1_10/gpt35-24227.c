//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure for the mailing list */
struct MailingList {
    char name[50];
    char email[50];
    struct MailingList *next;
};

/* Function prototypes */
void addContact(struct MailingList **, char *, char *);
void printList(struct MailingList *);
void deleteContact(struct MailingList **, char *);
void searchContact(struct MailingList *, char *);

/* Main function */
int main() {
    struct MailingList *head = NULL;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add contact\n");
        printf("2. Print list\n");
        printf("3. Delete contact\n");
        printf("4. Search for a contact\n");
        printf("5. Exit\n\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter email: ");
                char email[50];
                scanf("%s", email);

                addContact(&head, name, email);
                break;
            }

            case 2: {
                printf("Mailing list:\n");
                printList(head);
                break;
            }

            case 3: {
                printf("Enter email of contact to be deleted: ");
                char email[50];
                scanf("%s", email);

                deleteContact(&head, email);
                break;
            }

            case 4: {
                printf("Enter name or email of contact to be searched: ");
                char query[50];
                scanf("%s", query);

                searchContact(head, query);
                break;
            }

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

/* Function to add a new contact to the mailing list */
void addContact(struct MailingList **head, char *name, char *email) {
    struct MailingList *newContact = (struct MailingList *)malloc(sizeof(struct MailingList));
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    newContact->next = NULL;

    if (*head == NULL) {
        *head = newContact;
    } else {
        struct MailingList *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
    printf("Contact added successfully\n");
}

/* Function to print the mailing list */
void printList(struct MailingList *head) {
    if (head == NULL) {
        printf("Mailing list is empty\n");
    } else {
        struct MailingList *current = head;
        while (current != NULL) {
            printf("Name: %s, Email: %s\n", current->name, current->email);
            current = current->next;
        }
    }
}

/* Function to delete a contact from the mailing list */
void deleteContact(struct MailingList **head, char *email) {
    if (*head == NULL) {
        printf("Mailing list is already empty\n");
    } else if (strcmp((*head)->email, email) == 0) {
        struct MailingList *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Contact deleted successfully\n");
    } else {
        struct MailingList *current = *head;
        while (current->next != NULL && strcmp(current->next->email, email) != 0) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Contact not found\n");
        } else {
            struct MailingList *temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("Contact deleted successfully\n");
        }
    }
}

/* Function to search for a contact in the mailing list */
void searchContact(struct MailingList *head, char *query) {
    if (head == NULL) {
        printf("Mailing list is empty\n");
    } else {
        struct MailingList *current = head;
        int found = 0;
        while (current != NULL) {
            if (strcmp(current->name, query) == 0 || strcmp(current->email, query) == 0) {
                printf("Name: %s, Email: %s\n", current->name, current->email);
                found = 1;
            }
            current = current->next;
        }
        if (!found) {
            printf("Contact not found\n");
        }
    }
}