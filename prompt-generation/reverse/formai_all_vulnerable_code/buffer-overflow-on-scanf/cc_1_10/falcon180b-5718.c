//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char number[15];
} Contact;

void addContact(Contact *phonebook, int count, char name[], char number[]) {
    if (count >= MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add contact.\n");
        return;
    }

    strcpy(phonebook[count].name, name);
    strcpy(phonebook[count].number, number);

    printf("Contact added successfully.\n");
}

void searchContact(Contact *phonebook, int count, char name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            break;
        }
    }

    if (i == count) {
        printf("Contact not found.\n");
    }
}

void deleteContact(Contact *phonebook, int count, char name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Contact deleted successfully.\n");
            memset(phonebook[i].name, '\0', strlen(phonebook[i].name));
            memset(phonebook[i].number, '\0', strlen(phonebook[i].number));
            break;
        }
    }

    if (i == count) {
        printf("Contact not found.\n");
    }
}

int main() {
    Contact phonebook[MAX_CONTACTS];
    int count = 0;

    printf("Phonebook Application\n");
    printf("----------------------\n");

    while (1) {
        printf("1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &count);

        switch (count) {
        case 1:
            printf("Enter name: ");
            scanf("%s", &phonebook[count].name);
            printf("Enter number: ");
            scanf("%s", &phonebook[count].number);
            addContact(phonebook, count + 1, phonebook[count].name, phonebook[count].number);
            break;

        case 2:
            printf("Enter name to search: ");
            scanf("%s", &phonebook[0].name);
            searchContact(phonebook, count, phonebook[0].name);
            break;

        case 3:
            printf("Enter name to delete: ");
            scanf("%s", &phonebook[0].name);
            deleteContact(phonebook, count, phonebook[0].name);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}