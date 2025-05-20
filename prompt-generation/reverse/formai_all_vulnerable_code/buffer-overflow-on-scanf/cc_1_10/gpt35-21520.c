//FormAI DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 10    // Maximum number of entries that the diary can hold

typedef struct {
    char date[11];        // Date of the diary entry
    char content[1000];   // Content of the diary entry
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];  // Diary array to store the entries
int num_entries = 0;            // Number of entries currently in the diary

// Function to add a new entry to the diary
void addEntry() {

    // Check if there's still space in the diary
    if(num_entries >= MAX_ENTRIES) {
        printf("Diary is full!");
        return;
    }

    // Get user input for the diary entry
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", diary[num_entries].date);
    printf("Enter content: ");
    scanf(" %[^\n]s", diary[num_entries].content);

    // Increment the number of entries and display a message
    num_entries++;
    printf("\nEntry added to the diary!\n\n");

}

// Function to display all the entries in the diary
void viewEntries() {

    // Check if there are no entries in the diary yet
    if(num_entries == 0) {
        printf("\nNo entries yet!\n\n");
        return;
    }

    // Display all the entries in the diary
    printf("\nDiary entries:\n\n");
    for(int i=0; i<num_entries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Content: %s\n\n", diary[i].content);
    }

}

// Main function
int main() {

    int choice;

    while(1) {

        // Display menu and get user input
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform an action depending on the user's choice
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("\nExiting digital diary...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n\n");
        }

    }

    return 0;

}