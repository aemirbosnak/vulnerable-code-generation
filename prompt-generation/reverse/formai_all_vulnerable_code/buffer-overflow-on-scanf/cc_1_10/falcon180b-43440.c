//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char number[15];
} contact;

void add_contact(contact* book, int count, char* name, char* number) {
    if (count >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(book[count].name, name);
    strcpy(book[count].number, number);

    printf("Contact added successfully.\n");
}

void view_contact(contact* book, int count, char* name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\n", book[i].name);
            printf("Number: %s\n", book[i].number);
            break;
        }
    }
}

void delete_contact(contact* book, int count, char* name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            memset(book[i].name, 0, sizeof(book[i].name));
            memset(book[i].number, 0, sizeof(book[i].number));
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    contact book[MAX_CONTACTS];
    int count = 0;

    printf("Phone Book\n");

    while (1) {
        printf("1. Add contact\n");
        printf("2. View contact\n");
        printf("3. Delete contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &count);

        switch (count) {
        case 1:
            printf("Enter name: ");
            scanf("%s", book[count].name);
            printf("Enter number: ");
            scanf("%s", book[count].number);
            add_contact(book, count, book[count].name, book[count].number);
            break;

        case 2:
            printf("Enter name to view: ");
            scanf("%s", book[count].name);
            view_contact(book, count, book[count].name);
            break;

        case 3:
            printf("Enter name to delete: ");
            scanf("%s", book[count].name);
            delete_contact(book, count, book[count].name);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}