//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

void add_entry();
void view_entries();
void delete_entry();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\nWelcome to your Digital Diary!\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Delete Diary Entry\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        
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
                printf("Thank you for using the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}

void add_entry() {
    char entry[MAX_LENGTH];
    FILE *file = fopen(DIARY_FILE, "a");

    if (file == NULL) {
        printf("Could not open diary file for writing.\n");
        return;
    }
    
    printf("Enter your diary entry (max 255 characters): ");
    fgets(entry, MAX_LENGTH, stdin);
    
    // Remove newline character
    entry[strcspn(entry, "\n")] = 0;

    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Entry added successfully!\n");
}

void view_entries() {
    char line[MAX_LENGTH];
    FILE *file = fopen(DIARY_FILE, "r");

    if (file == NULL) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    int count = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", count++, line);
    }
    
    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("Failed to open diary file.\n");
        return;
    }

    char entries[MAX_ENTRIES][MAX_LENGTH];
    int count = 0;

    while (fgets(entries[count], sizeof(entries[count]), file) && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, entries[i]);
    }
    
    int entry_to_delete;
    printf("Enter the entry number to delete: ");
    scanf("%d", &entry_to_delete);
    clear_buffer();

    if (entry_to_delete < 1 || entry_to_delete > count) {
        printf("Invalid entry number.\n");
        return;
    }

    FILE *temp_file = fopen("temp_diary.txt", "w");
    if (temp_file == NULL) {
        printf("Could not open temporary file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != entry_to_delete - 1) {
            fprintf(temp_file, "%s", entries[i]);
        }
    }
    
    fclose(temp_file);
    remove(DIARY_FILE);
    rename("temp_diary.txt", DIARY_FILE);
    printf("Entry deleted successfully!\n");
}

void clear_buffer() {
    while (getchar() != '\n');
}