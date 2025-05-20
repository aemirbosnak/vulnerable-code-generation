//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SONGS 100 // Maximum number of songs in the library

// Custom data structure to represent a song
typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int year;
} Song;

// Function prototypes
void addSong(Song library[], int *num_songs);
void removeSong(Song library[], int *num_songs);
void printLibrary(Song library[], int num_songs);
void saveLibrary(Song library[], int num_songs);
void loadLibrary(Song library[], int *num_songs);

int main() {
    Song library[MAX_SONGS]; // Array to store the song library
    int num_songs = 0; // Number of songs currently in the library
    char choice; // User's menu choice

    // Print welcome message and load library from file
    printf("Welcome to the C Music Library Management System!\n");
    loadLibrary(library, &num_songs);
    printf("Loaded %d songs from file.\n", num_songs);

    // Main menu loop
    do {
        printf("\nMenu:\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. View library\n");
        printf("4. Save library to file\n");
        printf("5. Quit\n");
        printf("Please enter your choice (1-5): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character

        switch(choice) {
            case '1':
                addSong(library, &num_songs);
                break;
            case '2':
                removeSong(library, &num_songs);
                break;
            case '3':
                printLibrary(library, num_songs);
                break;
            case '4':
                saveLibrary(library, num_songs);
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-5.\n");
        }
    } while (choice != '5');

    return 0;
}

// Function to add a song to the library
void addSong(Song library[], int *num_songs) {
    Song newSong; // Temporary struct to hold the new song data

    // Get user input for the new song's properties
    printf("Enter the song title: ");
    fgets(newSong.title, 100, stdin);
    newSong.title[strlen(newSong.title)-1] = '\0'; // Remove newline character from input
    printf("Enter the artist name: ");
    fgets(newSong.artist, 100, stdin);
    newSong.artist[strlen(newSong.artist)-1] = '\0';
    printf("Enter the album name: ");
    fgets(newSong.album, 100, stdin);
    newSong.album[strlen(newSong.album)-1] = '\0';
    printf("Enter the year the song was released: ");
    scanf("%d", &newSong.year);

    // Add the new song to the end of the library array
    library[*num_songs] = newSong;
    (*num_songs)++; // Increment the number of songs in the library

    printf("Added new song \"%s\" by %s to the library.\n", newSong.title, newSong.artist);
}

// Function to remove a song from the library
void removeSong(Song library[], int *num_songs) {
    char title[100];
    bool found = false; // Flag to indicate if the song was found and removed

    // Get user input for the title of the song to remove
    printf("Enter the title of the song to remove: ");
    fgets(title, 100, stdin);
    title[strlen(title)-1] = '\0';

    // Loop through the library array and remove the song if found
    for (int i = 0; i < *num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = true;
            printf("Removed song \"%s\" by %s from the library.\n", library[i].title, library[i].artist);
            for (int j = i; j < *num_songs-1; j++) {
                library[j] = library[j+1]; // Shift all elements after the removed song to the left
            }
            (*num_songs)--; // Decrement the number of songs in the library
            break; // Exit the loop as soon as the song is found and removed
        }
    }

    if (!found) {
        printf("No song with title \"%s\" was found in the library.\n", title);
    }
}

// Function to print the contents of the library
void printLibrary(Song library[], int num_songs) {
    // Print table header
    printf("%-30s | %-20s | %-20s | %s\n", "Title", "Artist", "Album", "Year");
    printf("-------------------------------------------------------------\n");

    // Loop through the library array and print the song information
    for (int i = 0; i < num_songs; i++) {
        printf("%-30s | %-20s | %-20s | %d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

// Function to save the library to a file
void saveLibrary(Song library[], int num_songs) {
    FILE *fp;
    char filename[100];

    // Get user input for the filename to save the library to
    printf("Enter the filename to save the library to: ");
    scanf("%s", filename);

    // Open the file for writing
    fp = fopen(filename, "w");

    // Loop through the library array and write the song information to the file
    for (int i = 0; i < num_songs; i++) {
        fprintf(fp, "%s,%s,%s,%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    // Close the file
    fclose(fp);

    printf("Library saved to file \"%s\".\n", filename);
}

// Function to load the library from a file
void loadLibrary(Song library[], int *num_songs) {
    FILE *fp;
    char filename[100], line[400], *token;
    Song newSong;

    // Get user input for the filename to load the library from
    printf("Enter the filename to load the library from: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");

    // Loop through each line in the file and add the song to the library
    while (fgets(line, 400, fp) != NULL) {
        // Remove newline character from input
        line[strlen(line)-1] = '\0';

        // Split the line into comma-separated values
        token = strtok(line, ",");
        strcpy(newSong.title, token);
        token = strtok(NULL, ",");
        strcpy(newSong.artist, token);
        token = strtok(NULL, ",");
        strcpy(newSong.album, token);
        token = strtok(NULL, ",");
        newSong.year = atoi(token);

        // Add the new song to the library array
        library[*num_songs] = newSong;
        (*num_songs)++;
    }

    // Close the file
    fclose(fp);
}