//FormAI DATASET v1.0 Category: Phone Book ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

int count = 0;

struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void add_contact(struct contact *phone_book, char *name, char *number) {
    strcpy(phone_book[count].name, name);
    strcpy(phone_book[count].number, number);
    count++;
}

void search_contact(struct contact *phone_book, char *name) {
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("%s's phone number is %s\n", phone_book[i].name, phone_book[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("%s not found in phone book\n", name);
    }
}

void display_contacts(struct contact *phone_book) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%d. %s's phone number is %s\n", i+1, phone_book[i].name, phone_book[i].number);
    }
}

int main() {
    struct contact phone_book[100];
    printf("Welcome to Alan's Phone Book!\n\n");
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH], number[MAX_NUMBER_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_contact(phone_book, name, number);
                printf("%s added to phone book!\n", name);
                break;
            }
            case 2: {
                char name[MAX_NAME_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(phone_book, name);
                break;
            }
            case 3: {
                display_contacts(phone_book);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
        printf("\n");
    }
    return 0;
}