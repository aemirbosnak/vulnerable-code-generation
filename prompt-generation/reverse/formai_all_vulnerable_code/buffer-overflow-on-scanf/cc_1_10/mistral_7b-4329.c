//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char name[50];
    char phone[20];
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX) {
        printf("Phone book is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*count].phone);
    (*count)++;
}

void displayContact(Contact contact) {
    printf("\nName: %s", contact.name);
    printf("\nPhone: %s", contact.phone);
}

void searchContact(Contact contacts[], int count) {
    char searchName[50];
    int i;

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            displayContact(contacts[i]);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    Contact phoneBook[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Display Contact\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &count);
                break;
            case 2:
                if (count > 0)
                    displayContact(phoneBook[count - 1]);
                else
                    printf("Phone book is empty.\n");
                break;
            case 3:
                if (count > 0) {
                    searchContact(phoneBook, count);
                } else {
                    printf("Phone book is empty.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}