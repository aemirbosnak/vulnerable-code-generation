//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_SIZE 50
#define MAX_VALUE_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char value[MAX_VALUE_SIZE];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].value, value);
    num_entries++;
}

void delete_entry(char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            return;
        }
    }

    printf("Error: entry not found.\n");
}

void search_entry(char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Value: %s\n", entries[i].value);
            return;
        }
    }

    printf("Error: entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", entries[num_entries].name);
                printf("Enter value: ");
                scanf("%s", entries[num_entries].value);
                num_entries++;
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", entries[num_entries-1].name);
                delete_entry(entries[num_entries-1].name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", entries[num_entries-1].name);
                search_entry(entries[num_entries-1].name);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}