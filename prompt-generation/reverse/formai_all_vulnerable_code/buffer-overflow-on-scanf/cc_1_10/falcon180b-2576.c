//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBERS 10

typedef struct {
    char name[MAX_NAME_LEN];
    char numbers[MAX_NUMBERS][20];
    int num_entries;
} Contact;

void add_contact(Contact *book) {
    char name[MAX_NAME_LEN];
    char number[20];
    int num_entries = 0;

    printf("Enter a name: ");
    scanf("%s", name);

    while (num_entries < MAX_NUMBERS) {
        printf("Enter a phone number: ");
        scanf("%s", number);
        strcpy(book->numbers[num_entries], number);
        num_entries++;
    }

    strcpy(book->name, name);
    book->num_entries = num_entries;
}

void search_contact(Contact *book) {
    char name[MAX_NAME_LEN];

    printf("Enter a name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(name, book->name) == 0) {
            printf("Found contact:\n");
            printf("Name: %s\n", book->name);
            for (int j = 0; j < book->num_entries; j++) {
                printf("Phone number %d: %s\n", j + 1, book->numbers[j]);
            }
            break;
        }
    }
}

int main() {
    Contact book;

    int choice;
    do {
        printf("Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact(&book);
            printf("Contact added successfully!\n");
            break;
        case 2:
            search_contact(&book);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}