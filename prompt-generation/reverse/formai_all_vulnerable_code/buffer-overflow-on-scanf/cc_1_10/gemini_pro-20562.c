//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the music library data
typedef struct music_library {
    char title[50];
    char artist[50];
    char genre[20];
    int year_released;
} music_library;

// Function to add a new music item to the library
void add_music_item(music_library *library, int *num_items) {
    // Get the music item details from the user
    printf("Enter the title of the music item: ");
    scanf("%s", library[*num_items].title);
    printf("Enter the artist of the music item: ");
    scanf("%s", library[*num_items].artist);
    printf("Enter the genre of the music item: ");
    scanf("%s", library[*num_items].genre);
    printf("Enter the year the music item was released: ");
    scanf("%d", &library[*num_items].year_released);

    // Increment the number of music items in the library
    (*num_items)++;
}

// Function to display the music library
void display_music_library(music_library *library, int num_items) {
    // Print the header for the music library
    printf("Music Library\n");
    printf("-----------------------------------------------------\n");
    printf("%-20s %-20s %-15s %-4s\n", "Title", "Artist", "Genre", "Year");

    // Print the music items in the library
    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-20s %-15s %-4d\n", library[i].title, library[i].artist, library[i].genre, library[i].year_released);
    }

    // Print the footer for the music library
    printf("-----------------------------------------------------\n");
}

// Function to search for a music item in the library
void search_music_library(music_library *library, int num_items) {
    // Get the search term from the user
    char search_term[50];
    printf("Enter the search term: ");
    scanf("%s", search_term);

    // Search for the music item in the library
    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strstr(library[i].title, search_term) != NULL || strstr(library[i].artist, search_term) != NULL || strstr(library[i].genre, search_term) != NULL) {
            // Print the found music item
            printf("Found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Year released: %d\n", library[i].year_released);
            found = 1;
            break;
        }
    }

    // If the music item was not found, print an error message
    if (!found) {
        printf("No music item found with the search term '%s'.\n", search_term);
    }
}

// Function to delete a music item from the library
void delete_music_item(music_library *library, int *num_items) {
    // Get the title of the music item to delete from the user
    char title[50];
    printf("Enter the title of the music item to delete: ");
    scanf("%s", title);

    // Search for the music item in the library
    int found = 0;
    int index = -1;
    for (int i = 0; i < *num_items; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    // If the music item was found, delete it from the library
    if (found) {
        for (int i = index; i < *num_items - 1; i++) {
            library[i] = library[i + 1];
        }
        (*num_items)--;
        printf("Music item deleted.\n");
    } else {
        // If the music item was not found, print an error message
        printf("No music item found with the title '%s'.\n", title);
    }
}

// Main function
int main() {
    // Create a music library
    music_library library[100];

    // Initialize the number of music items in the library to 0
    int num_items = 0;

    // Display the menu
    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("---------------------------------\n");
        printf("1. Add a music item\n");
        printf("2. Display the music library\n");
        printf("3. Search for a music item\n");
        printf("4. Delete a music item\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_music_item(library, &num_items);
                break;
            case 2:
                display_music_library(library, num_items);
                break;
            case 3:
                search_music_library(library, num_items);
                break;
            case 4:
                delete_music_item(library, &num_items);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}