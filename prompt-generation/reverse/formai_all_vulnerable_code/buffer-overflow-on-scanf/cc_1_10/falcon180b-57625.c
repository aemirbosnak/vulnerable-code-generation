//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

void add_entry(entry_t *book, int count, char *name, char *number) {
    if (count >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(book[count].name, name);
    strcpy(book[count].number, number);
    count++;
}

void delete_entry(entry_t *book, int count, char *name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            memmove(&book[i], &book[i+1], (count - i - 1) * sizeof(entry_t));
            count--;
            break;
        }
    }
}

void search_entry(entry_t *book, int count, char *name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", book[i].name, book[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    entry_t book[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN], number[MAX_NUMBER_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(book, count, name, number);
                break;
            }
            case 2: {
                char name[MAX_NAME_LEN];
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_entry(book, count, name);
                break;
            }
            case 3: {
                char name[MAX_NAME_LEN];
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(book, count, name);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}