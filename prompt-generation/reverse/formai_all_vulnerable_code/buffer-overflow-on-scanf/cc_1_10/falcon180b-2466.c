//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_NUMBER 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME];
    char number[MAX_NUMBER];
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

void search_entry() {
    printf("Enter name to search: ");
    char name[MAX_NAME];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i + 1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            found = 1;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}