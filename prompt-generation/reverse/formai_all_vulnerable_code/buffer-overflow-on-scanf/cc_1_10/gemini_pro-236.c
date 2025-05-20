//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the struct for a diary entry
typedef struct diary_entry {
    // The date and time of the entry
    time_t timestamp;
    
    // The actual diary entry
    char *entry_content;
} diary_entry_t;

// Create an array of diary entries
diary_entry_t diary_entries[MAX_ENTRIES];

// The number of diary entries
int num_entries = 0;

// Get the current date and time
time_t get_current_time() {
    return time(NULL);
}

// Create a new diary entry
void create_new_entry(char *entry_content) {
    // Check if there are already too many entries
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Cannot create a new entry. The diary is full.\n");
        return;
    }

    // Allocate memory for the new entry
    diary_entry_t *new_entry = malloc(sizeof(diary_entry_t));
    
    // Initialize the new entry's timestamp
    new_entry->timestamp = get_current_time();
    
    // Copy the entry content into the new entry
    new_entry->entry_content = strdup(entry_content);
    
    // Add the new entry to the array of entries
    diary_entries[num_entries++] = *new_entry;
}

// View a specific diary entry
void view_entry(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid index.\n");
        return;
    }

    // Print the entry's timestamp
    printf("Timestamp: %s\n", ctime(&diary_entries[index].timestamp));
    
    // Print the entry's content
    printf("Entry: %s\n", diary_entries[index].entry_content);
}

// Edit a specific diary entry
void edit_entry(int index, char *new_entry_content) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid index.\n");
        return;
    }
    
    // Free the old entry content
    free(diary_entries[index].entry_content);
    
    // Copy the new entry content into the entry
    diary_entries[index].entry_content = strdup(new_entry_content);
}

// Delete a specific diary entry
void delete_entry(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid index.\n");
        return;
    }

    // Free the entry's content
    free(diary_entries[index].entry_content);
    
    // Move the remaining entries down one index
    for (int i = index; i < num_entries - 1; i++) {
        diary_entries[i] = diary_entries[i + 1];
    }
    
    // Decrement the number of entries
    num_entries--;
}

// Print the menu
void print_menu() {
    printf("--------------------------------------------------------------------------------\n");
    printf("Welcome to your digital diary!\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("1. Create a new entry.\n");
    printf("2. View a specific entry.\n");
    printf("3. Edit a specific entry.\n");
    printf("4. Delete a specific entry.\n");
    printf("5. Quit.\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Enter your choice: ");
}

// Get the user's choice
int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    // Print the menu
    print_menu();
    
    // Get the user's choice
    int choice = get_choice();
    
    // Loop until the user quits
    while (choice != 5) {
        switch (choice) {
            case 1:
                // Create a new entry
                printf("Enter your entry: ");
                char entry_content[MAX_ENTRY_LENGTH];
                scanf(" %[^\n]%*c", entry_content);
                create_new_entry(entry_content);
                break;
            case 2:
                // View a specific entry
                printf("Enter the index of the entry you want to view: ");
                int index;
                scanf("%d", &index);
                view_entry(index);
                break;
            case 3:
                // Edit a specific entry
                printf("Enter the index of the entry you want to edit: ");
                scanf("%d", &index);
                printf("Enter the new entry content: ");
                char new_entry_content[MAX_ENTRY_LENGTH];
                scanf(" %[^\n]%*c", new_entry_content);
                edit_entry(index, new_entry_content);
                break;
            case 4:
                // Delete a specific entry
                printf("Enter the index of the entry you want to delete: ");
                scanf("%d", &index);
                delete_entry(index);
                break;
            default:
                // Invalid choice
                printf("Error: Invalid choice.\n");
        }
        
        // Print the menu again
        print_menu();
        
        // Get the user's choice
        choice = get_choice();
    }
    
    // Quit the program
    printf("Goodbye!\n");
    return 0;
}