//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct contact {
    char name[50];
    char number[15];
};

void addContact(struct contact *book, int size) {
    char name[50], number[15];

    printf("\nEnter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", number);

    strcpy(book[size - 1].name, name);
    strcpy(book[size - 1].number, number);
}

void searchContact(struct contact *book, int size, char *name) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("\nName: %s", book[i].name);
            printf("\nPhone number: %s", book[i].number);
            return;
        }
    }

    printf("\nContact not found!");
}

void deleteContact(struct contact *book, int *size, char *name) {
    int i;

    for (i = 0; i < *size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            *size -= 1;

            for (int j = i; j < *size; j++) {
                strcpy(book[j].name, book[j + 1].name);
                strcpy(book[j].number, book[j + 1].number);
            }

            return;
        }
    }

    printf("\nContact not found!");
}

void displayContacts(struct contact *book, int size) {
    printf("\nName\tPhone number\n");

    for (int i = 0; i < size; i++) {
        printf("%s\t%s\n", book[i].name, book[i].number);
    }
}

int main() {
    struct contact book[MAX];
    int size = 0;

    char choice;

    do {
        printf("\n1. Add contact");
        printf("\n2. Search contact");
        printf("\n3. Delete contact");
        printf("\n4. Display contacts");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (size == MAX) {
                printf("\nPhone book is full!");
            } else {
                addContact(book, size);
                size++;
            }
            break;

        case '2':
            printf("\nEnter name to search: ");
            char name[50];
            scanf("%s", name);

            searchContact(book, size, name);
            break;

        case '3':
            printf("\nEnter name to delete: ");
            char nameToDelete[50];
            scanf("%s", nameToDelete);

            deleteContact(book, &size, nameToDelete);
            break;

        case '4':
            displayContacts(book, size);
            break;

        case '5':
            printf("\nExiting program...");
            break;

        default:
            printf("\nInvalid choice!");
        }
    } while (choice!= '5');

    return 0;
}