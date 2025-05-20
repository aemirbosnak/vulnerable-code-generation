//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILE_NAME "diary_entries.txt"

typedef struct {
    char date[MAX_LENGTH];
    char entry[MAX_LENGTH];
} DiaryEntry;

void displayMenu() {
    printf("\n========================\n");
    printf("       Digital Diary    \n");
    printf("========================\n");
    printf("1. Add a Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Search Diary Entries\n");
    printf("4. Delete a Diary Entry\n");
    printf("5. Exit\n");
    printf("========================\n");
}

void addEntry() {
    DiaryEntry entry;
    
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", entry.date);
    printf("Write your diary entry: ");
    getchar(); // clear the newline character
    fgets(entry.entry, MAX_LENGTH, stdin);
    
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Could not open diary file for writing.\n");
        return;
    }
    fprintf(file, "%s\n%s\n", entry.date, entry.entry);
    fclose(file);
    printf("Successfully added your diary entry.\n");
}

void viewEntries() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Diary file does not exist.\n");
        return;
    }
    
    char line[MAX_LENGTH];
    printf("\n=== Your Diary ===\n");
    while (fgets(line, MAX_LENGTH, file)) {
        printf("%s", line);
    }
    fclose(file);
}

void searchEntry() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Diary file does not exist.\n");
        return;
    }
    
    char searchDate[MAX_LENGTH];
    printf("Enter the date to search for (YYYY-MM-DD): ");
    scanf("%s", searchDate);
    
    char line[MAX_LENGTH];
    int found = 0;
    printf("\n=== Search Results ===\n");
    
    while (fgets(line, MAX_LENGTH, file)) {
        if (strstr(line, searchDate) != NULL) {
            printf("%s", line);
            fgets(line, MAX_LENGTH, file); // read the corresponding entry
            printf("%s", line);
            found = 1;
            printf("=====================\n");
        }
    }
    
    if (!found) {
        printf("No entries found for the date: %s\n", searchDate);
    }
    
    fclose(file);
}

void deleteEntry() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Diary file does not exist.\n");
        return;
    }
    
    char searchDate[MAX_LENGTH];
    printf("Enter the date to delete the entry for (YYYY-MM-DD): ");
    scanf("%s", searchDate);
    
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Could not open temporary file for writing.\n");
        fclose(file);
        return;
    }
    
    char line[MAX_LENGTH];
    int found = 0;
    
    while (fgets(line, MAX_LENGTH, file)) {
        if (strstr(line, searchDate) != NULL) {
            found = 1; // Entry found, skip writing it
            fgets(line, MAX_LENGTH, file); // Skip the entry
            printf("Deleted entry for date: %s\n", searchDate);
        } else {
            fprintf(tempFile, "%s", line);
            // Write the corresponding entry too
            fgets(line, MAX_LENGTH, file);
            fprintf(tempFile, "%s", line);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(FILE_NAME); // remove original diary file
    rename("temp.txt", FILE_NAME); // rename temporary file to original
    
    if (!found) {
        printf("No entries found for the date: %s\n", searchDate);
    }
}

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Exiting the Digital Diary. Take care of your thoughts!\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 5);
    
    return 0;
}