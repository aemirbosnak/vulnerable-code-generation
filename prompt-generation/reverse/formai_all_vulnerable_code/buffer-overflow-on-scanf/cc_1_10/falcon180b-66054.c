//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
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
} entry_t;

int num_entries = 0;
entry_t entries[MAX_ENTRIES];

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

void search_entry() {
    char search[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    printf("Phone Book\n");
    while (1) {
        printf("\n1. Add entry\n2. Print entries\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                print_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}