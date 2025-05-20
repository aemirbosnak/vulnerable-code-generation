//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry *book[], int *size) {
    if (*size >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", book[*size]->name);

    printf("Enter phone number: ");
    scanf("%s", book[*size]->phone);

    (*size)++;
}

void search_entry(struct entry *book, int size, char *name) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\n", book[i].name);
            printf("Phone number: %s\n", book[i].phone);
            break;
        }
    }
}

void delete_entry(struct entry *book, int *size, char *name) {
    int i;

    for (i = 0; i < *size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            memmove(book + i, book + i + 1, sizeof(struct entry) * (*size - i - 1));
            (*size)--;
            break;
        }
    }
}

int main() {
    struct entry *book = malloc(MAX_ENTRIES * sizeof(struct entry));
    int size = 0;

    printf("Welcome to the phone book!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(book, &size);
            break;
        case 2:
            printf("Enter name to search: ");
            char name[50];
            scanf("%s", name);
            search_entry(book, size, name);
            break;
        case 3:
            printf("Enter name to delete: ");
            char name2[50];
            scanf("%s", name2);
            delete_entry(book, &size, name2);
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}