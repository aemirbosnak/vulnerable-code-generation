//FormAI DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <string.h>

struct phonebook {
    char name[30];
    char phone[15];
};

void addContact(struct phonebook *book, int *size) {
    printf("Enter name: ");
    scanf("%s", book[*size].name);
    printf("Enter phone number: ");
    scanf("%s", book[*size].phone);

    printf("\nContact added successfully!\n");
    (*size)++;
}

void searchContact(struct phonebook *book, int size) {
    char searchName[30];

    printf("Enter name to search: ");
    scanf("%s", searchName);

    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, searchName) == 0) {
            printf("\nName: %s\nPhone: %s\n", book[i].name, book[i].phone);
            return;
        }
    }

    printf("\nContact not found!\n");
}

void printContacts(struct phonebook *book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("\nName: %s\nPhone: %s\n", book[i].name, book[i].phone);
    }
}

int main() {
    struct phonebook book[100];
    int size = 0;

    int option;
    do {
        printf("\n1. Add contact\n2. Search contact\n3. Print contacts\n0. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addContact(book, &size);
                break;

            case 2:
                searchContact(book, size);
                break;

            case 3:
                printContacts(book, size);
                break;
        }
    } while (option != 0);

    return 0;
}