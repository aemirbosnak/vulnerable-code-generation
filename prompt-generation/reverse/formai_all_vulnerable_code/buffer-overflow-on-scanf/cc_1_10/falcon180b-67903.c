//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_NUM_LEN 16
#define MAX_NUM_COUNT 10

typedef struct {
    char name[MAX_NAME_LEN];
    char numbers[MAX_NUM_COUNT][MAX_NUM_LEN];
    int num_count;
} contact;

void add_contact(contact* book, char* name, char* number) {
    if (book->num_count >= MAX_NUM_COUNT) {
        printf("Error: Contact list is full.\n");
        return;
    }
    strcpy(book->numbers[book->num_count], number);
    strcpy(book->name, name);
    book->num_count++;
}

void search_contact(contact* book, char* name) {
    int i, j;
    for (i = 0; i < book->num_count; i++) {
        if (strcmp(book->name, name) == 0) {
            printf("Name: %s\n", book->name);
            for (j = 0; j < book->num_count; j++) {
                printf("Number %d: %s\n", j+1, book->numbers[j]);
            }
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    contact phonebook;
    phonebook.num_count = 0;
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    int choice;

    do {
        printf("Post-Apocalyptic Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_contact(&phonebook, name, number);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(&phonebook, name);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}