//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phoneNumber[20];
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    fgets(contacts[*count].name, sizeof(contacts[*count].name), stdin);
    *strchr(contacts[*count].name, '\n') = '\0';

    printf("Enter phone number: ");
    fgets(contacts[*count].phoneNumber, sizeof(contacts[*count].phoneNumber), stdin);
    *strchr(contacts[*count].phoneNumber, '\n') = '\0';

    (*count)++;
}

void printContacts(Contact contacts[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phoneNumber);
    }
}

int main() {
    Contact phoneBook[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n");
        printf("2. Print Contacts\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &count);
                break;
            case 2:
                printContacts(phoneBook, count);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}