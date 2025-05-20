//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

void add_entry(entry_t entries[], int *num_entries) {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", entries[*num_entries].name);
    printf("Enter number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", entries[*num_entries].number);
    (*num_entries)++;
}

void search_entry(entry_t entries[], int num_entries, char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char name[MAX_NAME_LENGTH];

    printf("Phone Book\n");
    printf("=========\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &num_entries);

        switch (num_entries) {
        case 1:
            add_entry(entries, &num_entries);
            break;
        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entry(entries, num_entries, name);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}