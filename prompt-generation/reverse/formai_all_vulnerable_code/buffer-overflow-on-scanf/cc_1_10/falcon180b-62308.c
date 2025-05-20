//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char number[15];
};

void add_entry(struct entry *book[], int *count) {
    printf("Enter name: ");
    scanf("%s", book[*count]->name);

    printf("Enter phone number: ");
    scanf("%s", book[*count]->number);

    (*count)++;
}

void search_entry(struct entry *book, int count, char *name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\n", book[i].name);
            printf("Phone number: %s\n", book[i].number);
        }
    }
}

int main() {
    struct entry *book[MAX_ENTRIES];
    int count = 0;

    printf("Phone book program\n");
    printf("-----------------\n");

    while (1) {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count >= MAX_ENTRIES) {
                printf("Phone book is full\n");
            } else {
                add_entry(book, &count);
            }
            break;

        case 2:
            printf("Enter name to search: ");
            char name[50];
            scanf("%s", name);

            search_entry(book, count, name);
            break;

        case 3:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}