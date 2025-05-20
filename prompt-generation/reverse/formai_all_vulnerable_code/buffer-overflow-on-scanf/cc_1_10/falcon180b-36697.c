//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUM_LEN - 1);
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("No entry found.\n");
}

int main() {
    int choice;
    do {
        printf("Phone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
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