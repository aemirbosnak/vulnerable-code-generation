//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your entry:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    entry[strcspn(entry, "\n")] = '\0';

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(entries[num_entries].date, 11, "%Y-%m-%d", tm);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries() {
    printf("Your entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter a search term:\n");
    fgets(search_term, MAX_ENTRY_LENGTH, stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    int matches = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}