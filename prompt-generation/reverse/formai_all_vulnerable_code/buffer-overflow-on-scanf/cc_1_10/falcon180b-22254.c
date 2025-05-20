//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone_number[20];
} entry_t;

void add_entry(entry_t entries[], int num_entries) {
    char name[50];
    char phone_number[20];

    printf("Enter the name: ");
    scanf("%s", name);

    printf("Enter the phone number: ");
    scanf("%s", phone_number);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].phone_number, phone_number);

    num_entries++;
}

void search_entry(entry_t entries[], int num_entries) {
    char name[50];

    printf("Enter the name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].phone_number);
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        int choice;

        printf("1. Add Entry\n2. Search Entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, num_entries);
            break;
        case 2:
            search_entry(entries, num_entries);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}