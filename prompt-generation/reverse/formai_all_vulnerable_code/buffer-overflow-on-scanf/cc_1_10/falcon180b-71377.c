//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

void add_entry(Entry entries[], int num_entries) {
    Entry new_entry;
    printf("Enter name: ");
    scanf("%s", new_entry.name);
    printf("Enter number: ");
    scanf("%s", new_entry.number);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, "") == 0) {
            strcpy(entries[i].name, new_entry.name);
            strcpy(entries[i].number, new_entry.number);
            return;
        }
    }

    printf("Phone book is full.\n");
}

void search_entry(Entry entries[], int num_entries) {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(Entry entries[], int num_entries) {
    char delete_name[MAX_NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, delete_name) == 0) {
            strcpy(entries[i].name, "");
            strcpy(entries[i].number, "");
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void print_entries(Entry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, "")!= 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        int choice;
        printf("\nPhone Book\n");
        printf("1. Add Entry\n2. Search Entry\n3. Delete Entry\n4. Print Entries\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LEN];
                scanf("%s", search_name);
                search_entry(entries, num_entries);
                break;
            case 3:
                printf("Enter name to delete: ");
                char delete_name[MAX_NAME_LEN];
                scanf("%s", delete_name);
                delete_entry(entries, num_entries);
                break;
            case 4:
                print_entries(entries, num_entries);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}