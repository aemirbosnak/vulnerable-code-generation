//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char date[20];
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", date);

    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your entry:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    entry[strcspn(entry, "\n")] = '\0';

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries() {
    printf("\nDigital Diary\n");
    printf("-------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

void search_entry() {
    char search_date[20];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, search_date) == 0) {
            printf("%s\n%s\n\n", entries[i].date, entries[i].entry);
            found = 1;
        }
    }

    if (!found) {
        printf("No entry found for the given date.\n");
    }
}

int main() {
    printf("\nWelcome to Digital Diary!\n");
    printf("---------------------------------\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n2. View all entries\n3. Search for an entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("\nExiting Digital Diary...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}