//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

    printf("Enter your entry for %s:\n", date);
    fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    strcpy(diary[num_entries].date, date);

    num_entries++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Viewing entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter search term: ");
    fgets(search_term, MAX_ENTRY_LENGTH, stdin);

    int matches_found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, search_term)) {
            printf("%s: %s\n", diary[i].date, diary[i].entry);
            matches_found = 1;
        }
    }

    if (!matches_found) {
        printf("No matches found.\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
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
                search_entries();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}