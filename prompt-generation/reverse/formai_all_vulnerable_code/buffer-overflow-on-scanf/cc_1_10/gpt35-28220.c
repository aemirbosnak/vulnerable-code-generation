//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum size of the diary entry
#define MAX_SIZE_ENTRY 100

// Define the maximum number of diary entries
#define MAX_NUMBER_ENTRY 50

// Define the data structure for a single diary entry
typedef struct DiaryEntry {
    char date[11];
    char entry[MAX_SIZE_ENTRY];
} DiaryEntry;

// Declare the global variable to hold the diary entries
DiaryEntry diary[MAX_NUMBER_ENTRY];

// Declare the global variable to hold the number of diary entries
int num_of_entries = 0;

// Function to display the menu
void display_menu() {
    printf("\n\n * Digital Diary *\n");
    printf("1 - Add a diary entry\n");
    printf("2 - View all diary entries\n");
    printf("3 - Search for a diary entry\n");
    printf("4 - Exit\n");
}

// Function to add a diary entry
void add_entry() {
    // Check if the diary already has the maximum number of entries
    if (num_of_entries == MAX_NUMBER_ENTRY) {
        printf("Sorry, your diary already has the maximum number of entries.\n");
        return;
    }
    
    // Ask the user for the date of the entry
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[11];
    strftime(date, sizeof(date), "%Y-%m-%d", t);
    printf("Date of entry (yyyy-mm-dd) [%s]: ", date);
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    if (strcmp(date, "") == 0) {
        strcpy(date, diary[num_of_entries - 1].date);
    }
    
    // Ask the user for the content of the entry
    char entry[MAX_SIZE_ENTRY];
    printf("Content of entry (max %d characters): ", MAX_SIZE_ENTRY);
    fgets(entry, sizeof(entry), stdin);
    entry[strcspn(entry, "\n")] = '\0';
    if (strcmp(entry, "") == 0) {
        printf("Error: You must enter some content for this diary entry.\n");
        return;
    }
    
    // Add the diary entry to the diary array
    strcpy(diary[num_of_entries].date, date);
    strcpy(diary[num_of_entries].entry, entry);
    num_of_entries++;
    
    printf("Diary entry successfully added!\n");
}

// Function to display all diary entries
void view_entries() {
    // Check if the diary has any entries
    if (num_of_entries == 0) {
        printf("Sorry, your diary has no entries yet.\n");
        return;
    }
    
    // Display all diary entries
    printf("All diary entries:\n");
    for (int i = 0; i < num_of_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

// Function to search for a diary entry
void search_entry() {
    // Check if the diary has any entries
    if (num_of_entries == 0) {
        printf("Sorry, your diary has no entries yet.\n");
        return;
    }
    
    // Ask the user for the date of the entry to search for
    char date[11];
    printf("Date of entry to search for (yyyy-mm-dd): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    
    // Search for the diary entry with the given date
    int found = 0;
    for (int i = 0; i < num_of_entries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("%s: %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    
    // If no diary entry was found, display an error message
    if (!found) {
        printf("Sorry, no diary entry with the given date was found.\n");
    }
}

// Main function
int main() {
    // Display the menu and ask for the user's choice
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        // Perform the chosen action
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}