//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

void add_entry();
void view_entries();
void delete_entry();
void clear_screen();

int main() {
    int choice;

    do {
        clear_screen();
        printf("===== Digital Diary =====\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

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
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }

        if (choice != 4) {
            printf("Press Enter to continue...");
            getchar(); // Wait for user input
        }

    } while (choice != 4);

    return 0;
}

void add_entry() {
    char entry[MAX_LENGTH];
    FILE *file = fopen(DIARY_FILE, "a"); // Open the file in append mode

    if (file == NULL) {
        printf("Failed to open diary file!\n");
        return;
    }

    printf("Enter your diary entry: ");
    fgets(entry, sizeof(entry), stdin);
    
    // Write the entry to the file
    fprintf(file, "%s", entry);
    fclose(file); // Close the file
    
    printf("Entry added successfully!\n");
}

void view_entries() {
    char line[MAX_LENGTH];
    FILE *file = fopen(DIARY_FILE, "r"); // Open the file in read mode

    if (file == NULL) {
        printf("No entries found!\n");
        return;
    }

    printf("===== Diary Entries =====\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); // Print each line from the diary file
    }

    fclose(file); // Close the file
}

void delete_entry() {
    char line[MAX_LENGTH];
    FILE *file = fopen(DIARY_FILE, "r"); // Open the file in read mode
    FILE *temp_file = fopen("temp.txt", "w"); // Temporary file for writing

    if (file == NULL || temp_file == NULL) {
        printf("Failed to open diary file!\n");
        return;
    }

    printf("Enter the entry to delete: ");
    fgets(line, sizeof(line), stdin);

    int found = 0;
    while (!feof(file)) {
        char buffer[MAX_LENGTH];
        fgets(buffer, sizeof(buffer), file);
        if (strcmp(buffer, line) != 0) {
            fputs(buffer, temp_file); // Write to temp file if not matching
        } else {
            found = 1; // Mark entry as found
        }
    }

    fclose(file);
    fclose(temp_file);

    // Replace the original diary file with the temporary file
    remove(DIARY_FILE);
    rename("temp.txt", DIARY_FILE);

    if (found) {
        printf("Entry deleted successfully!\n");
    } else {
        printf("Entry not found!\n");
    }
}

void clear_screen() {
    // Clear the screen using ANSI escape codes
    printf("\033[H\033[J");
}