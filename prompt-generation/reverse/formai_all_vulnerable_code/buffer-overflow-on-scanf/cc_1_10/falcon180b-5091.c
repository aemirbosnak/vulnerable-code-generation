//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

int compare_entries(const void *a, const void *b) {
    const entry *entry1 = a;
    const entry *entry2 = b;

    return strcmp(entry1->name, entry2->name);
}

void add_entry(entry entries[], int *num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[*num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[*num_entries].number);

    (*num_entries)++;
}

void print_entries(const entry entries[], int num_entries) {
    printf("Phone Book:\n");
    printf("=====================\n");

    qsort(entries, num_entries, sizeof(entry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    entry phonebook[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to the Phone Book!\n");
    printf("=============================\n");

    while (num_entries < MAX_ENTRIES) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Print phone book\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(phonebook, &num_entries);
            break;
        case 2:
            print_entries(phonebook, num_entries);
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}