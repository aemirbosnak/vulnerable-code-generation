//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 30
#define MAX_LIST_SIZE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

Contact* list[MAX_LIST_SIZE];

int numContacts = 0;

int printMenu() {
    int choice;
    printf("\n\nMain Menu\n");
    printf("---------\n");
    printf("1. Add Contact\n");
    printf("2. Remove Contact\n");
    printf("3. Print Contacts\n");
    printf("4. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addContact() {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    printf("\n\nAdd Contact\n");
    printf("-----------\n");
    printf("Enter name: ");
    scanf("%s", newContact->name);
    printf("Enter email: ");
    scanf("%s", newContact->email);
    list[numContacts] = newContact;
    numContacts++;
    printf("Contact added successfully.\n");
}

void removeContact() {
    char emailToRemove[MAX_EMAIL_LENGTH];
    int found = 0;
    printf("\n\nRemove Contact\n");
    printf("--------------\n");
    printf("Enter email of contact to remove: ");
    scanf("%s", emailToRemove);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(list[i]->email, emailToRemove) == 0) {
            found = 1;
            free(list[i]);
            for (int j = i; j < numContacts - 1; j++) {
                list[j] = list[j+1];
            }
            numContacts--;
        }
    }
    if (found == 0) {
        printf("Contact not found.\n");
    } else {
        printf("Contact removed successfully.\n");
    }
}

void printContacts() {
    printf("\n\nContacts List\n");
    printf("--------------\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i+1, list[i]->name, list[i]->email);
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        choice = printMenu();
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                removeContact();
                break;
            case 3:
                printContacts();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}