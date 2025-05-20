//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    char number[15];
} Contact;

void createContact(Contact *contact, const char *name, const char *number) {
    strcpy(contact->name, name);
    strcpy(contact->number, number);
}

bool isFull(Contact contacts[], int size, int index) {
    return index == size;
}

int findEmptySlot(Contact contacts[], int size) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].name[0] == '\0') {
            return i;
        }
    }
    return -1;
}

void printContact(const Contact contact) {
    printf("%s : %s\n", contact.name, contact.number);
}

void addContact(Contact contacts[], int size, const char *name, const char *number) {
    int emptySlot = findEmptySlot(contacts, size);

    if (emptySlot == -1) {
        printf("Phonebook is full.\n");
        return;
    }

    createContact(&contacts[emptySlot], name, number);
    printf("Contact added successfully.\n");
}

void printPhoneBook(const Contact contacts[], int size) {
    printf("Phonebook:\n");

    for (int i = 0; i < size; ++i) {
        if (contacts[i].name[0] != '\0') {
            printContact(contacts[i]);
        }
    }
}

int main() {
    const int size = 10;
    Contact phoneBook[size];

    while (true) {
        printf("\n---Phonebook---");
        printf("\n1. Add a Contact");
        printf("\n2. Print Phonebook");
        printf("\n3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                char number[15];

                printf("Enter Name : ");
                scanf("%s", name);

                printf("Enter Number : ");
                scanf("%s", number);

                addContact(phoneBook, size, name, number);
                break;
            }

            case 2: {
                printPhoneBook(phoneBook, size);
                break;
            }

            case 3: {
                exit(0);
            }

            default: {
                printf("Invalid choice. Please choose from 1, 2 or 3.\n");
            }
        }
    }

    return 0;
}