//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES] = { {.name = "",.number = "" } };
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    int choice = 0;
    while (choice!= 5) {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                delete_entry();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                print_entries();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}