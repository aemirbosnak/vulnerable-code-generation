//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    int id;
} Contact;

Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

void addContact(char name[], char phone[], int *id) {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(phoneBook[numContacts].name, name);
    strcpy(phoneBook[numContacts].phone, phone);
    phoneBook[numContacts].id = *id;
    *id += 1;
    numContacts++;
}

void deleteContact(int id) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    int index = -1;
    for (int i = 0; i < numContacts; i++) {
        if (phoneBook[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < numContacts - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }

    numContacts--;
}

int searchContact(char name[]) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return phoneBook[i].id;
        }
    }

    printf("Contact %s not found.\n", name);
    return -1;
}

int main() {
    int id = 1001;
    char name[50], phone[20];
    int searchId;
    int choice;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                addContact(name, phone, &id);
                break;
            case 2:
                printf("Enter Contact ID: ");
                scanf("%d", &searchId);
                deleteContact(searchId);
                break;
            case 3:
                printf("Enter Name to search: ");
                scanf("%s", name);
                searchId = searchContact(name);
                if (searchId != -1) {
                    printf("Contact ID: %d\n", searchId);
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