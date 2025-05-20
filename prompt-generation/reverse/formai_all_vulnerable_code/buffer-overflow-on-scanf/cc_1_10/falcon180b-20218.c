//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
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

void remove_entry(int index) {
    num_entries--;
    for (int i = index; i < num_entries; i++) {
        memcpy(&entries[i], &entries[i + 1], sizeof(entry_t));
    }
}

void search_entry() {
    printf("Enter name to search: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Number: %s\n", entries[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

void print_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Phone Book\n");
        printf("1. Add entry\n2. Remove entry\n3. Search entry\n4. Print all entries\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                printf("Enter index to remove: ");
                int index;
                scanf("%d", &index);
                remove_entry(index);
                break;
            case 3:
                search_entry();
                break;
            case 4:
                print_all_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}