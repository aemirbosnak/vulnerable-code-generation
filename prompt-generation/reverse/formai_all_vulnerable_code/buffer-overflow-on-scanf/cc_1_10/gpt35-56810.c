//FormAI DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Global variables
// Store diary entries in an array of strings
char diary[MAX_ENTRIES][1000];
int num_entries = 0;

// Function prototypes
void menu();
void add_entry();
void view_entries();

int main()
{
    printf("Welcome to your digital diary!\n\n");
    menu();
    return 0;
}

// Displays the main menu and prompts the user to select an option
void menu()
{
    int choice;

    do {
        printf("\nSelect an option:\n");
        printf("1. Add an entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);
}

// Allows the user to add a new diary entry
void add_entry()
{
    char entry[1000];

    if (num_entries >= MAX_ENTRIES) {
        printf("\nSorry, you have reached the maximum number of entries.\n");
        return;
    }

    printf("\nEnter your diary entry:\n");
    getchar(); // Clear input buffer
    fgets(entry, sizeof(entry), stdin);
    entry[strcspn(entry, "\n")] = 0; // Remove newline character

    strcpy(diary[num_entries], entry);
    num_entries++;

    printf("\nEntry added successfully!\n");
}

// Displays all previous diary entries in the order they were added
void view_entries()
{
    if (num_entries == 0) {
        printf("\nSorry, there are no entries to display.\n");
        return;
    }

    printf("\nPrevious entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s\n", i+1, diary[i]);
    }
}