//FormAI DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[50];
    char number[20];
} Contact;

void addContact(Contact **book, int *count) {
    printf("Enter name: ");
    char name[50];
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter phone number: ");
    char number[20];
    fgets(number, 20, stdin);
    number[strcspn(number, "\n")] = 0;

    *book = realloc(*book, (*count + 1) * sizeof(Contact));
    Contact c = { .name = "", .number = "" };
    (*book)[*count] = c;

    strcpy((*book)[*count].name, name);
    strcpy((*book)[*count].number, number);

    (*count)++;
    printf("Contact added successfully!\n");
}

void search(Contact *book, int count) {
    printf("Enter name: ");
    char name[50];
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\n", book[i].name);
            printf("Phone Number: %s\n", book[i].number);
            return;
        }
    }

    printf("Contact not found!\n");
}

void printBook(Contact *book, int count) {
    printf("\nCONTACT LIST:\n");

    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s\n   Phone Number: %s\n", i+1, book[i].name, book[i].number);
    }
}

int main() {
    Contact *phoneBook = NULL;
    int count = 0;
    int choice;

    printf("\n\033[32mWelcome to your C Phone Book!\033[0m\n\n");

    while(1) {

        printf("\n1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Print Contact List\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(&phoneBook, &count);
                break;
            case 2:
                search(phoneBook, count);
                break;
            case 3:
                printBook(phoneBook, count);
                break;
            case 4:
                printf("\nGoodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
    }

    return 0;
}