//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char input[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry:\n");
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    strncpy(entries[num_entries].entry, input, MAX_ENTRY_LENGTH);
    time_t now = time(NULL);
    entries[num_entries].timestamp = now;
    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries yet.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter search term:\n");
    fgets(search_term, MAX_ENTRY_LENGTH, stdin);
    search_term[strcspn(search_term, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)!= NULL) {
            printf("%s\n", entries[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found.\n");
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
        printf("Enter your choice:\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}