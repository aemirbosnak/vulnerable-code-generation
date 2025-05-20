//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} entry_t;

void print_entry(const entry_t *entry) {
    printf("%s: %s\n", entry->name, entry->value);
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to the Funky Fresh Database!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Print all entries\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Sorry, the database is full!\n");
            } else {
                printf("Enter the name of the entry: ");
                scanf("%s", entries[num_entries].name);
                printf("Enter the value of the entry: ");
                scanf("%s", entries[num_entries].value);
                num_entries++;
                printf("Entry added successfully!\n");
            }
            break;

        case 2:
            printf("Enter the name of the entry to search for: ");
            char search_name[MAX_NAME_LEN];
            scanf("%s", search_name);

            int found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].name, search_name) == 0) {
                    print_entry(&entries[i]);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Entry not found.\n");
            }
            break;

        case 3:
            printf("All entries:\n");
            for (int i = 0; i < num_entries; i++) {
                print_entry(&entries[i]);
            }
            break;

        case 4:
            printf("Exiting the Funky Fresh Database...\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}