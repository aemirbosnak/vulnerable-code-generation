//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

void printMenu() {
    printf("\n------ Phone Book ------\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n");
}

void addContact(Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s", contacts[*numContacts].name);

    printf("Enter Phone Number: ");
    scanf("%s", contacts[*numContacts].phone);

    (*numContacts)++;
}

int searchContact(Contact contacts[], int numContacts, char name[]) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void deleteContact(Contact contacts[], int *numContacts, int index) {
    for (int i = index; i < *numContacts; i++) {
        contacts[i] = contacts[i + 1];
    }

    (*numContacts)--;
}

void displayAllContacts(Contact contacts[], int numContacts) {
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    Contact phoneBook[MAX_ENTRIES];
    int numContacts = 0;

    while (1) {
        printMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2: {
                char name[50];
                printf("Enter name to search: ");
                scanf("%s", name);
                int index = searchContact(phoneBook, numContacts, name);
                if (index != -1) {
                    printf("Found: %s - %s\n", phoneBook[index].name, phoneBook[index].phone);
                } else {
                    printf("Not found.\n");
                }
                break;
            }
            case 3: {
                char name[50];
                printf("Enter name to delete: ");
                scanf("%s", name);
                int index = searchContact(phoneBook, numContacts, name);
                if (index != -1) {
                    deleteContact(phoneBook, &numContacts, index);
                    printf("Contact deleted successfully.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 4:
                displayAllContacts(phoneBook, numContacts);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}