//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define DIARY_FILE "diary.txt"

void add_entry();
void view_entries();
void delete_entry();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Simple Diary Application ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

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
                printf("Exiting the diary application...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        printf("Error opening diary file!\n");
        return;
    }

    char entry[ENTRY_SIZE];
    printf("Enter your diary entry (max %d characters): ", ENTRY_SIZE - 1);
    fgets(entry, ENTRY_SIZE, stdin);
    fprintf(file, "%s", entry);
    fclose(file);
    printf("Diary entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("No entries found. Your diary is empty!\n");
        return;
    }

    char entry[ENTRY_SIZE];
    int entry_number = 1;
    printf("\n--- Your Diary Entries ---\n");
    while (fgets(entry, ENTRY_SIZE, file) != NULL) {
        printf("Entry %d: %s", entry_number++, entry);
    }
    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("No entries found. Your diary is empty!\n");
        return;
    }

    char entries[MAX_ENTRIES][ENTRY_SIZE];
    int count = 0;
    
    while (fgets(entries[count], ENTRY_SIZE, file) != NULL && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entry_to_delete;
    printf("Enter the entry number to delete (1 to %d): ", count);
    scanf("%d", &entry_to_delete);
    clear_buffer();

    if (entry_to_delete < 1 || entry_to_delete > count) {
        printf("Invalid entry number!\n");
        return;
    }

    // Write the remaining entries to the file, skipping the deleted one
    file = fopen(DIARY_FILE, "w");
    for (int i = 0; i < count; i++) {
        if (i != entry_to_delete - 1) {
            fprintf(file, "%s", entries[i]);
        }
    }
    fclose(file);
    printf("Entry number %d deleted successfully!\n", entry_to_delete);
}

void clear_buffer() {
    while (getchar() != '\n');
}