//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define FILENAME "diary.txt"

void addEntry();
void viewEntries();
void clearEntries();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after integer input

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                clearEntries();
                break;
            case 4:
                printf("Exiting the diary. Have a great day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Clear All Entries\n");
    printf("4. Exit\n");
}

void addEntry() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening diary file!\n");
        return;
    }

    char entry[ENTRY_LENGTH];
    printf("Enter your diary entry (max %d characters): ", ENTRY_LENGTH);
    fgets(entry, ENTRY_LENGTH, stdin);
    
    // Remove newline character if present
    size_t len = strlen(entry);
    if (len > 0 && entry[len - 1] == '\n') {
        entry[len - 1] = '\0';
    }

    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No diary entries found!\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    char entry[ENTRY_LENGTH];
    while (fgets(entry, ENTRY_LENGTH, file) != NULL) {
        printf("* %s", entry);
    }
    fclose(file);
}

void clearEntries() {
    if (remove(FILENAME) == 0) {
        printf("All diary entries cleared successfully!\n");
    } else {
        printf("Error clearing diary entries!\n");
    }
}