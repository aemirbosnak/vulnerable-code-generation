//FormAI DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of each entry
#define MAX_ENTRY_LENGTH 1000

// Define the maximum number of entries
#define MAX_ENTRIES 1000

// Define the structure of an entry
struct entry {
    char date[20];
    char content[MAX_ENTRY_LENGTH];
};

// Create an array of entries
struct entry entries[MAX_ENTRIES];

// Define a function to add an entry to the diary
void addEntry() {
    // Get the current date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[MAX_ENTRIES-1].date, 20, "%Y-%m-%d %H:%M:%S", t);

    // Get user input for the entry content
    printf("Enter diary entry:\n");
    fgets(entries[MAX_ENTRIES-1].content, MAX_ENTRY_LENGTH, stdin);
    entries[MAX_ENTRIES-1].content[strcspn(entries[MAX_ENTRIES-1].content, "\n")] = 0;

    printf("\nEntry added successfully!\n");
}

// Define a function to view all entries in the diary
void viewEntries() {
    // Check if there are any entries
    int count = 0;
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (strlen(entries[i].content) > 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("\nNo entries yet!\n");
    } else {
        // Print the entries
        printf("\n");
        for (int i = 0; i < MAX_ENTRIES; i++) {
            if (strlen(entries[i].content) > 0) {
                printf("%s\n%s\n\n", entries[i].date, entries[i].content);
            }
        }
    }
}

// Define a function to search for entries with given keyword
void searchEntries() {
    // Get user input for the search keyword
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword to search for:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    // Search for entries and print them
    printf("\nSearch results:\n");
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (strstr(entries[i].content, keyword) != NULL) {
            printf("%s\n%s\n\n", entries[i].date, entries[i].content);
        }
    }
}

int main() {
    // Display welcome message
    printf("Welcome to your digital diary!\n\n");

    // Display menu and get user input
    int choice = 0;
    while (choice != 4) {
        printf("Menu:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        getchar(); // Consume the '\n' character left behind by scanf

        // Execute the appropriate function based on user input
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                printf("\nThank you for using your digital diary!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}