//FormAI DATASET v1.0 Category: Digital Diary ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of entries in the diary
#define MAX_ENTRIES 100

// Define the maximum length of each entry
#define MAX_ENTRY_LENGTH 1000

// Define the filename for the diary file
#define DIARY_FILE "diary.txt"

// Struct to store each diary entry
struct DiaryEntry {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
};

// Function to print a menu of options to the user
void printMenu() {
    printf("\n\nDigital Diary\n\n");
    printf("1. Create a new diary entry\n");
    printf("2. View an existing diary entry\n");
    printf("3. Edit an existing diary entry\n");
    printf("4. Delete an existing diary entry\n");
    printf("5. Exit\n");
}

// Function to create a new diary entry
void createEntry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        printf("Error: Could not open diary file for writing.\n");
        return;
    }

    struct DiaryEntry entry;

    // Get the current date/time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(entry.date, sizeof(entry.date), "%c", tm);
    
    // Ask the user for the entry text
    printf("Enter your diary entry below:\n");
    fgets(entry.entry, MAX_ENTRY_LENGTH, stdin);
    
    // Write the entry to the file
    fprintf(file, "%s\n%s\n", entry.date, entry.entry);
    fclose(file);
    
    printf("New entry created successfully!\n");
}

// Function to view an existing diary entry
void viewEntry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open diary file for reading.\n");
        return;
    }

    char date[20];
    printf("Enter the date of the entry you would like to view (in the format of \"Mon Jan 01 00:00:00 2022\"):\n");
    fgets(date, sizeof(date), stdin);
    date[strlen(date)-1] = '\0'; // Remove trailing newline character
    
    char entry[MAX_ENTRY_LENGTH];
    int found = 0;
    
    // Loop through the file, looking for the matching date
    while (fgets(date, sizeof(date), file) != NULL && fgets(entry, MAX_ENTRY_LENGTH, file) != NULL) {
        if (strcmp(date, entry) == 0) {
            printf("\n%s\n%s", date, entry);
            found = 1;
            break;
        }
    }

    fclose(file);
    
    if (!found) {
        printf("Entry not found.\n");
    }
}

// Function to edit an existing diary entry
void editEntry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open diary file for reading.\n");
        return;
    }

    char date[20];
    printf("Enter the date of the entry you would like to edit (in the format of \"Mon Jan 01 00:00:00 2022\"):\n");
    fgets(date, sizeof(date), stdin);
    date[strlen(date)-1] = '\0'; // Remove trailing newline character
    
    struct DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    
    // Loop through the file, building an array of DiaryEntry structs
    while (fgets(entries[numEntries].date, sizeof(entries[numEntries].date), file) != NULL &&
           fgets(entries[numEntries].entry, sizeof(entries[numEntries].entry), file) != NULL) {
        entries[numEntries].date[strlen(entries[numEntries].date)-1] = '\0'; // Remove trailing newline character
        numEntries++;
    }

    fclose(file);
    
    // Loop through the entries and find the one with the matching date
    int index = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Entry not found.\n");
        return;
    }
    
    // Prompt the user for the new entry text
    printf("Enter your new diary entry below:\n");
    fgets(entries[index].entry, MAX_ENTRY_LENGTH, stdin);
    
    // Write the updated entries to the file
    file = fopen(DIARY_FILE, "w");
    if (file == NULL) {
        printf("Error: Could not open diary file for writing.\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s\n%s\n", entries[i].date, entries[i].entry);
    }

    fclose(file);
    
    printf("Entry updated successfully!\n");
}

// Function to delete an existing diary entry
void deleteEntry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open diary file for reading.\n");
        return;
    }

    char date[20];
    printf("Enter the date of the entry you would like to delete (in the format of \"Mon Jan 01 00:00:00 2022\"):\n");
    fgets(date, sizeof(date), stdin);
    date[strlen(date)-1] = '\0'; // Remove trailing newline character
    
    struct DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    
    // Loop through the file, building an array of DiaryEntry structs
    while (fgets(entries[numEntries].date, sizeof(entries[numEntries].date), file) != NULL &&
           fgets(entries[numEntries].entry, sizeof(entries[numEntries].entry), file) != NULL) {
        entries[numEntries].date[strlen(entries[numEntries].date)-1] = '\0'; // Remove trailing newline character
        numEntries++;
    }

    fclose(file);
    
    // Loop through the entries and find the one with the matching date
    int index = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Entry not found.\n");
        return;
    }
    
    // Remove the entry from the array by shifting all following entries up by one
    for (int i = index; i < numEntries - 1; i++) {
        entries[i] = entries[i+1];
    }
    
    // Write the updated entries to the file
    file = fopen(DIARY_FILE, "w");
    if (file == NULL) {
        printf("Error: Could not open diary file for writing.\n");
        return;
    }

    for (int i = 0; i < numEntries - 1; i++) {
        fprintf(file, "%s\n%s\n", entries[i].date, entries[i].entry);
    }

    fclose(file);
    
    printf("Entry deleted successfully!\n");
}

int main() {
    int choice = 0;
    
    while (choice != 5) {
        printMenu();
        printf("Enter your choice (1-5):\n");
        scanf("%d", &choice);
        getchar(); // Consume trailing newline character
        
        switch (choice) {
            case 1:
                createEntry();
                break;
            case 2:
                viewEntry();
                break;
            case 3:
                editEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}