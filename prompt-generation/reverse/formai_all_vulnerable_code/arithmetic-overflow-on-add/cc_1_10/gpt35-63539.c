//FormAI DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <string.h>
#define MAX 100

struct contact {
    char name[50];
    char phone[15];
    char email[30];
};

struct contactlist {
    struct contact person[MAX];
    int numContacts;
};

void addContact(struct contactlist* list);
void removeContact(struct contactlist* list);
void displayContacts(struct contactlist* list);

int main() {
    struct contactlist myContacts;
    myContacts.numContacts = 0;
    int choice;
    do {
        printf("-----------------------------\n");
        printf("|        PHONE BOOK         |\n");
        printf("-----------------------------\n");
        printf("|  1. Add Contact           |\n");
        printf("|  2. Remove Contact        |\n");
        printf("|  3. Display Contacts      |\n");
        printf("|  4. Exit                  |\n");
        printf("-----------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact(&myContacts);
                break;
            case 2:
                removeContact(&myContacts);
                break;
            case 3:
                displayContacts(&myContacts);
                break;
            case 4:
                printf("Exiting Phone Book...\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 4);

    return 0;
}

void addContact(struct contactlist* list) {
    if (list->numContacts == MAX) {
        printf("Contact list is full. Unable to add new contact.\n\n");
        return;
    }

    printf("\nEnter contact name: ");
    scanf("%s", list->person[list->numContacts].name);
    printf("Enter contact phone number: ");
    scanf("%s", list->person[list->numContacts].phone);
    printf("Enter contact email address: ");
    scanf("%s", list->person[list->numContacts].email);

    printf("\nContact added successfully.\n\n");
    list->numContacts++;
}

void removeContact(struct contactlist* list) {
    if (list->numContacts == 0) {
        printf("\nContact list is empty. Nothing to remove.\n\n");
        return;
    }

    char name[50];
    printf("\nEnter contact name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < list->numContacts; i++) {
        if (strcmp(list->person[i].name, name) == 0) {
            list->numContacts--;
            list->person[i] = list->person[list->numContacts];
            printf("\n%s has been removed from contact list.\n\n", name);
            return;
        }
    }

    printf("\n%s not found in contact list.\n\n", name);
}

void displayContacts(struct contactlist* list) {
    if (list->numContacts == 0) {
        printf("\nContact list is empty.\n\n");
        return;
    }

    printf("\n%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    for (int i = 0; i < list->numContacts; i++) {
        printf("%-20s %-15s %-30s\n", list->person[i].name,
               list->person[i].phone, list->person[i].email);
    }
    printf("\n");
}