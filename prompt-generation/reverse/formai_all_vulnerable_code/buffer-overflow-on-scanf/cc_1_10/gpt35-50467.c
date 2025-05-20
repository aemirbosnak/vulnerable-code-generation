//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum length for diary entry and date string
#define MAX_ENTRY_LENGTH 1000
#define DATE_STR_LENGTH 11

// Define a structure to represent a diary entry
struct DiaryEntry {
    char date[DATE_STR_LENGTH];
    char entry[MAX_ENTRY_LENGTH];
};

// Declare functions
void addEntry();
void readEntries();
void deleteEntry();

int main() {
    
    // Variable to hold user input choice
    int choice;
    
    // Show menu
    printf("Digital Diary\n\n");
    printf("1. Add a new entry\n");
    printf("2. Read all entries\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n\n");
    
    // Loop until user chooses to exit
    while(choice != 4) {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        fflush(stdin);  // Flush buffer to prevent unwanted input
        
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                readEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }
    
    return 0;
}

// Function to add a new diary entry
void addEntry() {
    // Variables to hold date, time, and entry text
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[DATE_STR_LENGTH], entry[MAX_ENTRY_LENGTH];
    
    // Format date string as yyyy-mm-dd
    strftime(date, DATE_STR_LENGTH, "%Y-%m-%d", t);
    
    // Prompt user for entry text
    printf("\nEnter your diary entry:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);  // Use fgets() to allow spaces in entry
    entry[strcspn(entry, "\n")] = '\0';  // Remove trailing newline character
    
    // Create diary entry struct and write to file
    struct DiaryEntry newEntry = {date, entry};
    FILE *file = fopen("diary.txt", "a");
    
    if(file) {
        fprintf(file, "%s\n%s\n", newEntry.date, newEntry.entry);
        fclose(file);
        printf("\nEntry added successfully.\n\n");
    } else {
        printf("\nError opening file. Entry not added.\n\n");
    }
}

// Function to read all diary entries
void readEntries() {
    // Variables to hold current line and diary entry
    char line[MAX_ENTRY_LENGTH + DATE_STR_LENGTH + 2], date[DATE_STR_LENGTH], entry[MAX_ENTRY_LENGTH];
    
    // Open and read diary file
    FILE *file = fopen("diary.txt", "r");
    
    if(file) {
        printf("\nAll diary entries:\n\n");
        
        while(fgets(line, sizeof(line), file)) {
            // Remove trailing newline character
            line[strcspn(line, "\n")] = '\0';
            
            if(strlen(line) == DATE_STR_LENGTH) {
                strcpy(date, line);
            } else if(strlen(line) <= MAX_ENTRY_LENGTH) {
                strcpy(entry, line);
                printf("%s\n%s\n\n", date, entry);
            } else {
                printf("\nError reading file. Entry skipped.\n\n");
            }
        }
        
        fclose(file);
    } else {
        printf("\nNo entries found. Create a new entry to begin.\n\n");
    }
}

// Function to delete a diary entry
void deleteEntry() {
    // Variable to hold user input index
    int index = 0;
    
    // Print all diary entries with index numbers
    printf("\nDelete an entry\n\n");
    readEntries();
    
    // Prompt user for index of entry to delete
    printf("Enter the index number of the entry you want to delete: ");
    scanf("%d", &index);
    fflush(stdin);  // Flush buffer to prevent unwanted input
    
    // Open diary file for read and write
    FILE *readFile = fopen("diary.txt", "r");
    FILE *writeFile = fopen("temp.txt", "w+");
    
    // Loop through each line in diary file
    char line[MAX_ENTRY_LENGTH + DATE_STR_LENGTH + 2];
    int currentIndex = 1;
    
    while(fgets(line, sizeof(line), readFile)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';
        
        if(strlen(line) == DATE_STR_LENGTH) {
            // If date line, compare index to user input
            if(currentIndex != index) {
                fprintf(writeFile, "%s\n", line);
            }
        } else if(strlen(line) <= MAX_ENTRY_LENGTH) {
            // If entry line, copy to temp file only if index does not match
            if(currentIndex != index) {
                fprintf(writeFile, "%s\n", line);
            }
            
            currentIndex++;
        } else {
            printf("\nError reading file. Entry skipped.\n\n");
        }
    }
    
    fclose(readFile);
    fclose(writeFile);
    
    // Delete old file and rename temp file as new file
    remove("diary.txt");
    rename("temp.txt", "diary.txt");
    
    printf("\nEntry deleted successfully.\n\n");
}