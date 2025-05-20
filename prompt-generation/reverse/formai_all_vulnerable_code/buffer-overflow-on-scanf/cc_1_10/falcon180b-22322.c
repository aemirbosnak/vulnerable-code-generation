//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 200

typedef struct {
    char name[50];
    char number[15];
} entry_t;

void add_entry(entry_t entries[], int count) {
    printf("Enter a name: ");
    scanf("%s", entries[count].name);

    printf("Enter a phone number: ");
    scanf("%s", entries[count].number);

    count++;
}

void display_entries(entry_t entries[], int count) {
    printf("Phonebook:\n");
    printf("============\n");

    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

void search_entry(entry_t entries[], int count) {
    char search_name[50];

    printf("Enter a name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    printf("Welcome to the Phonebook!\n");
    printf("======================\n");

    while (count < MAX_ENTRIES) {
        int choice;

        printf("\n1. Add an entry\n2. Display all entries\n3. Search for an entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, count);
                break;
            case 2:
                display_entries(entries, count);
                break;
            case 3:
                search_entry(entries, count);
                break;
            case 4:
                printf("Exiting phonebook...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}