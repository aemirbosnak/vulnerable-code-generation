//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter your entry: ");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    entries[num_entries].timestamp = time(NULL);
    num_entries++;
}

void view_entries() {
    printf("Your entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter search term: ");
    fgets(search_term, MAX_ENTRY_LENGTH, stdin);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)) {
            printf("%s\n", entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to your digital diary!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
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
                printf("Invalid choice.\n");
        }
    }
    return 0;
}