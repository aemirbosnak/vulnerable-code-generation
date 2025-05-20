//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data type for library management system
typedef struct Music {
    char title[50];
    char artist[50];
    int year;
} Music;

// Array of music records
Music library[100];

// Number of music records in the library
int num_records = 0;

// Main menu options
const char* menu_options[] = {"Add a new record", "Search for a record", "List all records", "Exit"};

// Function to add a new record to the library
void add_record() {
    // Get the details of the new record
    printf("Enter the title of the song: ");
    scanf(" %[^\n]%*c", library[num_records].title);
    printf("Enter the name of the artist: ");
    scanf(" %[^\n]%*c", library[num_records].artist);
    printf("Enter the year the song was released: ");
    scanf("%d", &library[num_records].year);

    // Increment the number of records in the library
    num_records++;
}

// Function to search for a record in the library
void search_record() {
    // Get the search term
    char search_term[50];
    printf("Enter the search term: ");
    scanf(" %[^\n]%*c", search_term);

    // Search for the record
    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (strstr(library[i].title, search_term) != NULL) {
            // Record found
            printf("Record found:\n");
            printf("\tTitle: %s\n", library[i].title);
            printf("\tArtist: %s\n", library[i].artist);
            printf("\tYear: %d\n", library[i].year);
            found = 1;
            break;
        }
    }

    // If no record found, display an error message
    if (!found) {
        printf("No records found for the search term '%s'.\n", search_term);
    }
}

// Function to list all records in the library
void list_records() {
    // Iterate over the records and display their details
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("\tTitle: %s\n", library[i].title);
        printf("\tArtist: %s\n", library[i].artist);
        printf("\tYear: %d\n", library[i].year);
        printf("\n");
    }
}

// Main function
int main() {
    // Display welcome message
    printf("Welcome to the Music Library Management System!\n");

    // Main menu loop
    int choice = 0;
    while (choice != 4) {
        // Display the menu options
        printf("\nMain Menu:\n");
        for (int i = 0; i < sizeof(menu_options) / sizeof(char*); i++) {
            printf("%d. %s\n", i + 1, menu_options[i]);
        }

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                list_records();
                break;
            case 4:
                // Exit the program
                printf("Thank you for using the Music Library Management System.\n");
                break;
            default:
                // Display an error message if the user enters an invalid choice
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}