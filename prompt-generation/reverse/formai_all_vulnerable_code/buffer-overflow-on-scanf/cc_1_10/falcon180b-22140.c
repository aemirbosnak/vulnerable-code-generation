//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Cannot add more entries.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries() {
    printf("Viewing entries:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s:\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* search_term) {
    printf("Searching for entries containing '%s':\n", search_term);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)!= NULL) {
            printf("%s:\n%s\n\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                char date[20];
                char entry[MAX_ENTRY_SIZE];

                printf("Enter date (YYYY-MM-DD): ");
                scanf(" %s", date);

                printf("Enter entry:\n");
                fgets(entry, MAX_ENTRY_SIZE, stdin);
                entry[strcspn(entry, "\n")] = '\0';

                add_entry(date, entry);
                break;
            }
            case '2': {
                view_entries();
                break;
            }
            case '3': {
                char search_term[MAX_ENTRY_SIZE];

                printf("Enter search term: ");
                scanf(" %s", search_term);

                search_entries(search_term);
                break;
            }
            case '4': {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= '4');

    return 0;
}