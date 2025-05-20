//FormAI DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // structure for phone book entry
    char name[50];
    char number[20];
} Entry;

void addEntry(Entry *book, int *count) { // function to add new entry
    printf("Enter name: ");
    fgets(book[*count].name, 50, stdin);
    printf("Enter number: ");
    fgets(book[*count].number, 20, stdin);
    (*count)++;
}

void search(Entry *book, int count) { // function to search for a name
    char name[50];
    printf("Enter name to search: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) { // compare names
            found = 1;
            printf("Name: %sNumber: %s\n", book[i].name, book[i].number);
        }
    }
    if (!found) {
        printf("Name not found.\n");
    }
}

int main() {
    Entry book[100];
    int count = 0;
    int choice;
    while (1) {
        printf("Phone Book\n");
        printf("1. Add New Entry\n");
        printf("2. Search By Name\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline character from buffer
        switch (choice) {
            case 1:
                addEntry(book, &count); // pass address of count for modification
                break;
            case 2:
                search(book, count);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}