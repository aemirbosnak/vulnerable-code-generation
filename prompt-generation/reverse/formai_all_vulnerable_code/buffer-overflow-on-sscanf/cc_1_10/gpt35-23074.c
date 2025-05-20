//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the diary entry
struct DiaryEntry {
    int day;
    int month;
    int year;
    char *title;
    char *entry;
};

// Function to add an entry to the diary
void addEntry(struct DiaryEntry *diary, int *numEntries) {
    int day, month, year;
    char buffer[256];

    // Get the date of the entry
    printf("Enter the date of the entry (mm/dd/yyyy): ");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d/%d/%d", &month, &day, &year);

    // Allocate memory for the new entry
    struct DiaryEntry *newEntry = malloc(sizeof(struct DiaryEntry));
    newEntry->title = malloc(sizeof(char) * 256);
    newEntry->entry = malloc(sizeof(char) * 1024);

    // Set the values of the new entry
    newEntry->day = day;
    newEntry->month = month;
    newEntry->year = year;

    // Get the title of the entry
    printf("Enter the title of the entry: ");
    fgets(newEntry->title, 256, stdin);

    // Get the entry text
    printf("Enter the text of the entry: ");
    fgets(newEntry->entry, 1024, stdin);

    // Add the new entry to the diary
    diary[*numEntries] = *newEntry;
    *numEntries += 1;

    // Free the memory allocated for the new entry
    free(newEntry->title);
    free(newEntry->entry);
    free(newEntry);
}

// Function to display all entries in the diary
void displayEntries(struct DiaryEntry *diary, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%02d/%02d/%04d - %s\n%s\n", diary[i].month, diary[i].day, diary[i].year,
               diary[i].title, diary[i].entry);
        printf("------------------------------------------------------\n");
    }
}

// Main program loop
int main() {
    int choice, numEntries = 0;
    struct DiaryEntry diary[100];

    // Program loop
    while (1) {
        // Display the menu
        printf("Digital Diary\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Get the user's choice
        char buffer[256];
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                addEntry(diary, &numEntries);
                break;
            case 2:
                displayEntries(diary, numEntries);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                break;
        }

        // Pause the program to allow the user to read the output
        printf("Press Enter to continue...");
        getchar();
        printf("\n");
    }
}