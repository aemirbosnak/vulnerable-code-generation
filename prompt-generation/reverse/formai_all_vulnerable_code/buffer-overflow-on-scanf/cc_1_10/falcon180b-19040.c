//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // Maximum number of entries in the phone book

typedef struct {
    char name[30]; // Name of the person
    char number[15]; // Phone number
} entry_t;

entry_t entries[MAX_ENTRIES]; // Phone book array
int num_entries = 0; // Number of entries in the phone book

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void search_entry() {
    char search_name[30];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

void delete_entry() {
    char search_name[30];
    printf("Enter name to delete: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            memmove(&entries[i], &entries[i+1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Phone book menu:\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Print entries\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                print_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}