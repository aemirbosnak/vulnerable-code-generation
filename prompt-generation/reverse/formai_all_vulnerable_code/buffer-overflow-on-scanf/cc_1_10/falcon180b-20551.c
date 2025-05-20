//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_NUMBER 15
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
    char search_name[MAX_NAME];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}