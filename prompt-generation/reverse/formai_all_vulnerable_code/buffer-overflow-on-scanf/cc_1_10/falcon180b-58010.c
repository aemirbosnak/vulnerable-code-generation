//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Number for %s: %s\n", search_name, entries[i].number);
            break;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}