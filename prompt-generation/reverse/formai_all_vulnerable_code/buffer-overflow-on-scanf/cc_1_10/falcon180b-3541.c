//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LEN];
} diary_entry;

int num_entries = 0;
diary_entry diary[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);
    printf("Enter your entry:\n");
    fgets(diary[num_entries].entry, MAX_ENTRY_LEN, stdin);
    num_entries++;
    printf("Entry added successfully.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries yet.\n");
        return;
    }
    printf("Diary:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LEN];
    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("%s - %s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    printf("Welcome to Digital Diary!\n");
    while (1) {
        printf("1. Add entry\n");
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}