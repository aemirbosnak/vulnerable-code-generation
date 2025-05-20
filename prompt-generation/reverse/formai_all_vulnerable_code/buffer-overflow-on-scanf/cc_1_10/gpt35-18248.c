//FormAI DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining the maximum length of the diary entry
#define MAX_LENGTH 1000

// defining the maximum number of entries
#define MAX_ENTRIES 50

// structure for storing the diary entry
struct entry {
    int day, month, year;
    char text[MAX_LENGTH];
};

// function for displaying the menu
void display_menu() {
    printf("Welcome to your Digital Diary\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Exit\n");
}

// function for adding a new entry to the diary
void add_entry(struct entry *entries, int *num_entries) {
    // checking if the maximum number of entries has been reached
    if (*num_entries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached\n");
        return;
    }

    // getting the date of the new entry
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &entries[*num_entries].day, &entries[*num_entries].month, &entries[*num_entries].year);

    // getting the text of the new entry
    printf("Enter the text (max length %d characters): ", MAX_LENGTH);
    getchar(); // to clear the input buffer
    fgets(entries[*num_entries].text, MAX_LENGTH, stdin);
    entries[*num_entries].text[strcspn(entries[*num_entries].text, "\n")] = 0; // to remove the new line character at the end of the string

    // incrementing the number of entries
    (*num_entries)++;

    printf("Entry added successfully\n");
}

// function for viewing an existing entry from the diary
void view_entry(struct entry *entries, int num_entries) {
    // getting the date of the entry to be viewed
    int day, month, year;
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // searching for the entry and displaying it
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (entries[i].day == day && entries[i].month == month && entries[i].year == year) {
            printf("Date: %02d/%02d/%04d\n", entries[i].day, entries[i].month, entries[i].year);
            printf("Text: %s\n", entries[i].text);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found\n");
    }
}

int main() {
    // array for storing the diary entries
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // loop for displaying the menu and processing the user's choice
    int choice = 0;
    while (choice != 3) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                view_entry(entries, num_entries);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again\n");
                break;
        }
    }

    return 0;
}