//FormAI DATASET v1.0 Category: Phone Book ; Style: decentralized
// Decentralized Phone Book Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct phone_entry {
    char name[50];
    char number[20];
};

void add_entry(struct phone_entry *entries, int *num_entries) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Phone book is full! Cannot add new entry.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[*num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[*num_entries].number);

    (*num_entries)++;
}

void search_entry(struct phone_entry *entries, int num_entries) {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("%s's number is %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Sorry, no entry found for %s\n", search_name);
}

void print_all_entries(struct phone_entry *entries, int num_entries) {
    if (num_entries == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s's number is %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    struct phone_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    while (1) {
        printf("\nDecentralized Phone Book Program\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Print all entries\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                search_entry(entries, num_entries);
                break;
            case 3:
                print_all_entries(entries, num_entries);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}