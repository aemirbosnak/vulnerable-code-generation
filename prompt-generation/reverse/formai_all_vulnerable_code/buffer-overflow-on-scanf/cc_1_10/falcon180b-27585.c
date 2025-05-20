//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} contact;

void add_contact(contact *book, int count, char *name, char *number) {
    strcpy(book[count].name, name);
    strcpy(book[count].number, number);
}

void display_contacts(contact *book, int count) {
    printf("Name\t\tNumber\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\n", book[i].name, book[i].number);
    }
}

int main() {
    contact book[100];
    int count = 0;

    printf("Enter contact name: ");
    scanf("%s", book[count].name);

    printf("Enter contact number: ");
    scanf("%s", book[count].number);

    count++;

    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter contact name: ");
            scanf("%s", book[count].name);

            printf("Enter contact number: ");
            scanf("%s", book[count].number);

            count++;
            break;

        case 2:
            display_contacts(book, count);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}