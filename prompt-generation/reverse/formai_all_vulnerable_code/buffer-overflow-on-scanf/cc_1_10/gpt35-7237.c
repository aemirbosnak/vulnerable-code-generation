//FormAI DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for the diary entry
typedef struct {
    int year;
    int month;
    int day;
    char body[1001];
} DiaryEntry;

// Define global variables
DiaryEntry *entries;
int max_entries = 50;
int num_entries = 0;

// Function to add a new entry to the diary
void add_entry() {
    // Allocate memory for the new entry
    DiaryEntry new_entry;
    entries = (DiaryEntry*)realloc(entries, (num_entries + 1) * sizeof(DiaryEntry));
    
    // Prompt the user for the year, month, and day of the entry
    printf("Enter the date of the entry (YYYY MM DD): ");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    
    // Set the date in the new entry
    new_entry.year = year;
    new_entry.month = month;
    new_entry.day = day;
    
    // Prompt the user for the body of the entry
    printf("Enter the body of the entry: ");
    char body[1001];
    getchar(); // consume the newline character left by scanf
    fgets(body, 1001, stdin); // read up to 1000 characters from stdin
    strcpy(new_entry.body, body);
    
    // Add the new entry to the diary and increment the number of entries
    entries[num_entries] = new_entry;
    num_entries++;
}

// Function to print all diary entries for a given year and month
void print_entries(int year, int month) {
    // Iterate through all entries and print the ones with the specified year and month
    int i;
    for (i = 0; i < num_entries; i++) {
        if (entries[i].year == year && entries[i].month == month) {
            printf("%04d-%02d-%02d: %s", entries[i].year, entries[i].month, entries[i].day, entries[i].body);
        }
    }
}

int main() {
    // Allocate memory for the initial diary entries
    entries = (DiaryEntry*)malloc(max_entries * sizeof(DiaryEntry));
    
    // Display the menu options to the user
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a new diary entry\n");
        printf("2. Print all diary entries for a given year and month\n");
        printf("3. Exit\n");
        
        // Prompt the user for their choice and perform the corresponding action
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                printf("Enter the year and month (YYYY MM): ");
                int year, month;
                scanf("%d %d", &year, &month);
                print_entries(year, month);
                break;
            case 3:
                // Free the memory allocated to the diary entries and exit the program
                free(entries);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}