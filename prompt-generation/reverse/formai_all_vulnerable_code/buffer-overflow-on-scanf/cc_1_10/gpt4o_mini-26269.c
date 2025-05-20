//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILENAME "diary.txt"

void writeEntry() {
    FILE *file = fopen(DIARY_FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open diary file for writing");
        exit(EXIT_FAILURE);
    }

    char entry[MAX_LENGTH];
    printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH - 1);
    getchar();  // To capture the newline character from previous input
    fgets(entry, sizeof(entry), stdin);
    entry[strcspn(entry, "\n")] = 0; // Remove newline character from entry

    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Your entry has been saved!\n\n");
}

void readEntries() {
    FILE *file = fopen(DIARY_FILENAME, "r");
    if (file == NULL) {
        printf("No entries found. Start writing your first entry!\n\n");
        return;
    }

    char buffer[MAX_LENGTH];
    printf("Your Diary Entries:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf(" - %s", buffer);
    }
    fclose(file);
    printf("\n");
}

void deleteEntries() {
    if (remove(DIARY_FILENAME) == 0) {
        printf("All entries deleted successfully!\n\n");
    } else {
        perror("Error deleting diary file");
    }
}

void displayMenu() {
    printf("Welcome to Your Diary!\n");
    printf("=========================\n");
    printf("1. Write a new entry\n");
    printf("2. Read all entries\n");
    printf("3. Delete all entries\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeEntry();
                break;
            case 2:
                readEntries();
                break;
            case 3:
                deleteEntries();
                break;
            case 4:
                printf("Thank you for using your diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 4);

    return 0;
}