//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void add_entry(struct entry* entries, int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void display_entry(struct entry entry) {
    printf("%s: %s\n", entry.name, entry.number);
}

void search_entry(struct entry* entries, int num_entries, char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            display_entry(entries[i]);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        int choice;
        printf("1. Add entry\n2. Display entry\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, num_entries);
            break;
        case 2:
            printf("Enter name to display: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            search_entry(entries, num_entries, name);
            break;
        case 3:
            printf("Enter name to search: ");
            char search_name[MAX_NAME_LENGTH];
            scanf("%s", search_name);
            search_entry(entries, num_entries, search_name);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}