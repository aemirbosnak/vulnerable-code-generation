//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[15];
};

void add_contact(struct contact* book, int size) {
    printf("Enter contact name: ");
    scanf("%s", book[size].name);
    printf("Enter contact phone number: ");
    scanf("%s", book[size].phone);
    printf("Contact added successfully.\n\n");
}

void display_contacts(struct contact* book, int size) {
    printf("Contacts in phone book:\n");
    if (size == 0) {
        printf("Phone book is empty.\n\n");
    }
    else {
        for (int i = 0; i < size; i++) {
            printf("%d. %s - %s\n", i + 1, book[i].name, book[i].phone);
        }
        printf("\n");
    }
}

void search_contact(struct contact* book, int size) {
    char search[50];
    printf("Enter contact name to search: ");
    scanf("%s", search);
    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].name, search) == 0) {
            printf("%s - %s\n\n", book[i].name, book[i].phone);
            return;
        }
    }
    printf("Contact not found.\n\n");
}

int main() {
    struct contact phonebook[50];
    int size = 0;
    int choice = 0;
    do {
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1: {
                add_contact(phonebook, size);
                size++;
                break;
            }
            case 2: {
                display_contacts(phonebook, size);
                break;
            }
            case 3: {
                search_contact(phonebook, size);
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n\n");
                break;
            }
        }
    } while (1);
    return 0;
}