//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

void add_entry(entry_t entries[], int *num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[*num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[*num_entries].number);
    (*num_entries)++;
}

void search_entry(entry_t entries[], int num_entries, char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n\n", entries[i].number);
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        printf("1. Add Entry\n2. Search Entry\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, &num_entries);
            break;
        case 2:
            printf("Enter name to search: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            search_entry(entries, num_entries, name);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}