//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

void add_entry(entry_t *book, int size, char *name, char *number) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            strcpy(book[i].number, number);
            return;
        }
    }
    strcpy(book[size].name, name);
    strcpy(book[size].number, number);
    size++;
}

void delete_entry(entry_t *book, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            strcpy(book[i].name, book[size - 1].name);
            strcpy(book[i].number, book[size - 1].number);
            size--;
            return;
        }
    }
}

void display_entries(entry_t *book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s: %s\n", book[i].name, book[i].number);
    }
}

int main() {
    int size = 0;
    entry_t *book = malloc(sizeof(entry_t) * 100);
    char command[100];

    while (1) {
        printf("Enter command (add, delete, display, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LENGTH], number[MAX_NUMBER_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            add_entry(book, size, name, number);
            size++;
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete_entry(book, size, name);
        } else if (strcmp(command, "display") == 0) {
            display_entries(book, size);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    free(book);
    return 0;
}