//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void display_entries() {
    printf("Name\t\tNumber\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\n", entries[i].name, entries[i].number);
    }
}

void search_entry() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
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

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                search_entry();
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