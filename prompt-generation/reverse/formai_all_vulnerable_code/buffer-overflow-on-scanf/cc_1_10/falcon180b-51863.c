//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_SIZE 1000

typedef struct {
    char date[20];
    char entry[MAX_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void add_entry() {
    Entry new_entry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_entry.date);
    printf("Enter entry: ");
    scanf("%[^\n]", new_entry.entry);
    new_entry.entry[strcspn(new_entry.entry, "\n")] = '\0';
    strcat(new_entry.entry, "\n");
    if (num_entries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }
    entries[num_entries++] = new_entry;
}

void search_entry() {
    char search_date[20];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, search_date) == 0) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Print all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                print_entries();
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