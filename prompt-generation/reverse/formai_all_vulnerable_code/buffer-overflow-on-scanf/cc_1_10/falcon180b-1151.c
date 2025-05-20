//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

void add_entry(entry_t entries[], int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void display_entries(entry_t entries[], int num_entries) {
    printf("Name\t\tPhone Number\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\n", entries[i].name, entries[i].number);
    }
}

void search_entry(entry_t entries[], int num_entries, char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    printf("No entry found.\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n2. Display Entries\n3. Search Entry\n4. Exit\n");
        int choice = scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                display_entries(entries, num_entries);
                break;
            case 3:
                printf("Enter name to search: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);
                search_entry(entries, num_entries, name);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}