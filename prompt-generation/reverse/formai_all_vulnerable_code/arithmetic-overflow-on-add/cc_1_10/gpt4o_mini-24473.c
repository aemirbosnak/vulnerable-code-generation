//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define FILENAME "diary_entries.txt"

// Structure to hold a diary entry
typedef struct {
    char date[20];
    char content[ENTRY_LENGTH];
} DiaryEntry;

// Function to get the current date
void get_current_date(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

// Function to add a diary entry
void add_entry(DiaryEntry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    DiaryEntry new_entry;
    get_current_date(new_entry.date);
    
    printf("Enter your diary entry (max %d characters):\n", ENTRY_LENGTH - 1);
    fgets(new_entry.content, ENTRY_LENGTH, stdin);
    
    // Removing trailing newline
    new_entry.content[strcspn(new_entry.content, "\n")] = '\0';

    entries[*count] = new_entry;
    (*count)++;
    printf("Entry saved successfully!\n");
}

// Function to view diary entries
void view_entries(DiaryEntry entries[], int count) {
    if (count == 0) {
        printf("No entries found in the diary.\n");
        return;
    }
    
    printf("\nDiary Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n", entries[i].content);
        printf("---------------------------\n");
    }
}

// Function to save entries to a file
void save_entries(DiaryEntry entries[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for saving entries.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "Date: %s\n", entries[i].date);
        fprintf(file, "Entry: %s\n", entries[i].content);
        fprintf(file, "---------------------------\n");
    }
    
    fclose(file);
    printf("Entries saved to %s successfully!\n", FILENAME);
}

// Function to load entries from a file
void load_entries(DiaryEntry entries[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No existing diary file found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "Date: %[^\n]\nEntry: %[^\n]\n", entries[*count].date, entries[*count].content) != EOF) {
        (*count)++;
        if (*count >= MAX_ENTRIES) {
            break;
        }
    }
    
    fclose(file);
    printf("Entries loaded successfully! You have %d entries.\n", *count);
}

// Main function
int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    load_entries(entries, &count);

    do {
        printf("\n--- Digital Diary Menu ---\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Save Diary Entries to File\n");
        printf("4. Load Diary Entries from File\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                add_entry(entries, &count);
                break;
            case 2:
                view_entries(entries, count);
                break;
            case 3:
                save_entries(entries, count);
                break;
            case 4:
                load_entries(entries, &count);
                break;
            case 5:
                printf("Thank you for using the Digital Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}