//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 256
#define DIARY_FILE "diary.txt"

void add_entry();
void view_entries();
void delete_entry();
void display_menu();

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear the newline character from the buffer

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting the Diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1-4.\n");
                break;
        }
    }
    return 0;
}

void display_menu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry: ");
    fgets(entry, sizeof(entry), stdin);
    
    // Remove newline character from entry
    entry[strcspn(entry, "\n")] = 0;

    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        printf("Error opening file for reading. No entries found.\n");
        return;
    }

    char entry[MAX_ENTRY_LENGTH];
    printf("\n--- Diary Entries ---\n");
    while (fgets(entry, sizeof(entry), file)) {
        printf("%s", entry);
    }
    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        printf("Error opening file for reading. No entries to delete.\n");
        return;
    }

    char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH];
    int count = 0;
    while (fgets(entries[count], sizeof(entries[count]), file)) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("Choose an entry to delete (1 to %d):\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, entries[i]);
    }

    int entry_to_delete;
    scanf("%d", &entry_to_delete);
    
    if (entry_to_delete < 1 || entry_to_delete > count) {
        printf("Invalid entry number. Deletion failed.\n");
        return;
    }

    // Write back all entries except the one we want to delete
    file = fopen(DIARY_FILE, "w");
    for (int i = 0; i < count; i++) {
        if (i != entry_to_delete - 1) {
            fprintf(file, "%s", entries[i]);
        }
    }
    fclose(file);
    printf("Entry %d deleted successfully!\n", entry_to_delete);
}