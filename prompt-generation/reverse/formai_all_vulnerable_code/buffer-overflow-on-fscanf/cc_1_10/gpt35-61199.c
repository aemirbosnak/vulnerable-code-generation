//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for music
struct Music {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Define function prototypes
void addSong(struct Music *library, int *count);
void viewLibrary(struct Music *library, int count);
void searchLibrary(struct Music *library, int count, char *searchTerm);
void saveToFile(struct Music *library, int count);

int main() {
    // Define variables
    struct Music library[1000];
    int count = 0, choice;
    char searchTerm[50];

    // Load existing library from file
    FILE *file = fopen("library.txt", "r");
    if (file != NULL) {
        while(!feof(file)) {
            fscanf(file, "%[^,],%[^,],%[^,],%d\n", library[count].title, library[count].artist, library[count].album, &library[count].year);
            count++;
        }
        fclose(file);
    }

    // Show main menu and take user input until they choose to quit
    do {
        printf("\nWelcome to the Music Library Management System\n");
        printf("1. Add a Song\n");
        printf("2. View Library\n");
        printf("3. Search Library\n");
        printf("4. Save to File\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong(library, &count);
                break;
            case 2:
                viewLibrary(library, count);
                break;
            case 3:
                printf("Enter search term: ");
                scanf("%s", searchTerm);
                searchLibrary(library, count, searchTerm);
                break;
            case 4:
                saveToFile(library, count);
                printf("Library successfully saved to file!\n");
                break;
            case 5:
                printf("Thank you for using the Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to add a new song to the library
void addSong(struct Music *library, int *count) {
    // Make sure library has room for new song
    if (*count < 1000) {
        // Take user input for new song information
        printf("Enter the song title: ");
        scanf("%s", library[*count].title);
        printf("Enter the song artist: ");
        scanf("%s", library[*count].artist);
        printf("Enter the song album: ");
        scanf("%s", library[*count].album);
        printf("Enter the song year: ");
        scanf("%d", &library[*count].year);

        // Increment song count
        (*count)++;

        printf("Song successfully added to library!\n");
    } else {
        printf("Music library is full! Please delete a song before adding a new one.\n");
    }
}

// Function to view all songs in the library
void viewLibrary(struct Music *library, int count) {
    // Make sure library has songs
    if (count > 0) {
        printf("%-30s %-20s %-20s %-10s\n", "Title", "Artist", "Album", "Year");
        printf("----------------------------------------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%-30s %-20s %-20s %-10d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
        }
    } else {
        printf("Music library is empty! Please add a song before viewing.\n");
    }
}

// Function to search for songs in the library
void searchLibrary(struct Music *library, int count, char *searchTerm) {
    int found = 0;

    // Loop through each song in the library
    for (int i = 0; i < count; i++) {
        // Check if the search term is found in any of the song fields
        if (strstr(library[i].title, searchTerm) != NULL || strstr(library[i].artist, searchTerm) != NULL || strstr(library[i].album, searchTerm) != NULL || (char)library[i].year == *searchTerm) {
            if (!found) {
                printf("%-30s %-20s %-20s %-10s\n", "Title", "Artist", "Album", "Year");
                printf("----------------------------------------------------------------------------------\n");
                found = 1;
            }
            printf("%-30s %-20s %-20s %-10d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
        }
    }

    // If no songs are found, notify the user
    if (!found) {
        printf("No matching songs found.\n");
    }
}

// Function to save the library to a file
void saveToFile(struct Music *library, int count) {
    FILE *file = fopen("library.txt", "w");

    // Loop through each song in the library and write to the file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    fclose(file);
}