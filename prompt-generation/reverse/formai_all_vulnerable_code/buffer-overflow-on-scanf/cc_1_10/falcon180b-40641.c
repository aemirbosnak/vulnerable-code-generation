//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

int num_entries = 0;
entry_t entries[MAX_ENTRIES];

void add_entry() {
    printf("Enter a name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", entries[num_entries].name);

    printf("Enter a phone number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void print_entry(int index) {
    printf("%s - %s\n", entries[index].name, entries[index].number);
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter a name to search for: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            print_entry(i);
        }
    }
}

int main() {
    printf("Phone Book\n");

    while (1) {
        printf("1. Add an entry\n2. Search for an entry\n3. Quit\n");
        int choice;
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
                printf("Invalid choice.\n");
        }
    }

    return 0;
}