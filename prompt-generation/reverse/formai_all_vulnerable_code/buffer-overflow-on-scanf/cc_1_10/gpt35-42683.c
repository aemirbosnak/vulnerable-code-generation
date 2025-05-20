//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_EMAIL_LEN 50
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    int count;
    Contact contacts[MAX_LIST_SIZE];
} MailingList;

void addContact(MailingList *list) {
    if (list->count < MAX_LIST_SIZE) {
        Contact newContact;
        printf("Enter name: ");
        scanf("%s", newContact.name);
        printf("Enter email: ");
        scanf("%s", newContact.email);
        list->contacts[list->count] = newContact;
        list->count++;
    } else {
        printf("Mailing list is full.\n");
    }
}

void removeContact(MailingList *list) {
    char nameToRemove[MAX_NAME_LEN];
    printf("Enter name of contact to remove: ");
    scanf("%s", nameToRemove);

    int indexToRemove = -1;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(nameToRemove, list->contacts[i].name) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Contact not found in mailing list.\n");
    } else {
        for (int i = indexToRemove; i < list->count - 1; i++) {
            list->contacts[i] = list->contacts[i + 1];
        }
        list->count--;
        printf("Contact removed from mailing list.\n");
    }
}

void printList(MailingList *list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s, %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main(void) {
    MailingList list = {0};
    int choice = -1;

    while (choice != 0) {
        printf("\nMailing list manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print list\n");
        printf("0. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&list);
                break;
            case 2:
                removeContact(&list);
                break;
            case 3:
                printList(&list);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}