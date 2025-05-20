//FormAI DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

/*
    Digital Diary example program in C
*/

// Define structure to hold each diary entry
typedef struct entry {
    int day;
    int month;
    int year;
    char content[200];
} Entry;

// Define array to hold all diary entries
Entry diary[MAX_ENTRIES];
// Define counter for number of entries in diary
int num_entries = 0;

// Function to add a new diary entry
void add_entry() {
    // Check if diary is full
    if (num_entries == MAX_ENTRIES) {
        printf("Sorry, diary is full.\n");
    } else {
        // Prompt user for date and content
        printf("Enter date (DD MM YYYY): ");
        scanf("%d %d %d", &diary[num_entries].day, &diary[num_entries].month, &diary[num_entries].year);
        printf("Enter content (<200 chars): ");
        getchar(); // Clear buffer
        fgets(diary[num_entries].content, 200, stdin);
        // Increment counter
        num_entries++;
        printf("Entry added!\n");
    }
}

// Function to display all diary entries
void display_entries() {
    // Check if diary is empty
    if (num_entries == 0) {
        printf("No entries yet.\n");
    } else {
        // Display each entry
        for (int i = 0; i < num_entries; i++) {
            printf("Date: %02d/%02d/%04d\n", diary[i].day, diary[i].month, diary[i].year);
            printf("Content: %s\n", diary[i].content);
        }
    }
}

// Function to search for diary entries by date
void search_entry() {
    // Prompt user for date to search
    int search_day, search_month, search_year;
    printf("Enter date to search (DD MM YYYY): ");
    scanf("%d %d %d", &search_day, &search_month, &search_year);
    // Search for matching entries
    int num_matches = 0;
    for (int i = 0; i < num_entries; i++) {
        if (diary[i].day == search_day && diary[i].month == search_month && diary[i].year == search_year) {
            printf("Date: %02d/%02d/%04d\n", diary[i].day, diary[i].month, diary[i].year);
            printf("Content: %s\n", diary[i].content);
            num_matches++;
        }
    }
    // Display message if no matches found
    if (num_matches == 0) {
        printf("No matching entries found.\n");
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        // Display menu
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for entry\n");
        printf("4. Exit\n");
        // Prompt user for choice
        printf("Enter choice: ");
        scanf("%d", &choice);
        // Take action based on choice
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                // Exit program
                printf("Exiting program.\n");
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}