//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    time_t timestamp;
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int current_entry = 0;

void display_menu() {
    printf("=== Digital Diary ===\n");
    printf("1. Add a new entry\n");
    printf("2. View entries\n");
    printf("3. Search entries\n");
    printf("4. Exit\n");
    printf("===================== \n");
    printf("Choose an option: ");
}

void add_entry() {
    if (current_entry >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry (max %d characters): ", MAX_LENGTH - 1);
    getchar(); // Consume any leftover newline
    fgets(diary[current_entry].entry, MAX_LENGTH, stdin);
    
    // Remove newline character if present
    diary[current_entry].entry[strcspn(diary[current_entry].entry, "\n")] = 0; 

    diary[current_entry].timestamp = time(NULL);
    current_entry++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (current_entry == 0) {
        printf("No entries in the diary yet.\n");
        return;
    }

    printf("--- Diary Entries ---\n");
    for (int i = 0; i < current_entry; i++) {
        printf("Entry %d: %s\n", i + 1, diary[i].entry);
        printf("Timestamp: %s\n", ctime(&diary[i].timestamp));
    }
    printf("---------------------\n");
}

void search_entries() {
    if (current_entry == 0) {
        printf("No entries to search through.\n");
        return;
    }

    char search[MAX_LENGTH];
    printf("Enter search term: ");
    getchar(); // Consume leftover newline
    fgets(search, MAX_LENGTH, stdin);
    search[strcspn(search, "\n")] = 0; // Remove newline character

    printf("--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < current_entry; i++) {
        if (strstr(diary[i].entry, search) != NULL) {
            found = 1;
            printf("Entry %d: %s\n", i + 1, diary[i].entry);
            printf("Timestamp: %s\n", ctime(&diary[i].timestamp));
        }
    }
    if (!found) {
        printf("No entries found containing: '%s'\n", search);
    }
    printf("-----------------------\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
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
                printf("Exiting the diary. Stay connected with your thoughts!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    return 0;
}