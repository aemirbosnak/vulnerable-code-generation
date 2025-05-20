//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 2048

struct entry {
    char *date;
    char *text;
};

int entry_count = 0;
struct entry entries[MAX_ENTRIES];

void add_entry(char *date, char *text) {
    if (entry_count >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    struct entry *new_entry = &entries[entry_count];
    new_entry->date = strdup(date);
    new_entry->text = strdup(text);

    entry_count++;
}

void print_entries() {
    for (int i = 0; i < entry_count; i++) {
        struct entry *entry = &entries[i];
        printf("%s\n%s\n\n", entry->date, entry->text);
    }
}

void search_entries(char *query) {
    for (int i = 0; i < entry_count; i++) {
        struct entry *entry = &entries[i];

        if (strcmp(entry->date, query) == 0 || strcmp(entry->text, query) == 0) {
            printf("Found entry:\n");
            printf("%s\n%s\n\n", entry->date, entry->text);
        }
    }
}

int main() {
    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Print all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");

        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                char date[32];
                char text[2048];

                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", date);

                printf("Enter your entry:\n");
                fgets(text, sizeof(text), stdin);

                add_entry(date, text);
                break;
            }

            case '2': {
                print_entries();
                break;
            }

            case '3': {
                char query[2048];

                printf("Enter your search query: ");
                fgets(query, sizeof(query), stdin);

                search_entries(query);
                break;
            }

            case '4': {
                printf("Goodbye!\n");
                return 0;
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}