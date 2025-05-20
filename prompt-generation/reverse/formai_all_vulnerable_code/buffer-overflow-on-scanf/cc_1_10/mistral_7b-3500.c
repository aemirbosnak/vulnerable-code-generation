//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addContact(char* name, char* phone) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phoneBook[numEntries].name, name);
    strcpy(phoneBook[numEntries].phone, phone);
    numEntries++;
}

void searchContact(char* name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    char command[10], name[NAME_LENGTH], phone[PHONE_LENGTH];
    int choice;

    while (1) {
        printf("\nPhone Book Application\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", command);

        choice = atoi(command);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addContact(name, phone);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}