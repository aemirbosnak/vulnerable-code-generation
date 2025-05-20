//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Structure to store information about a song */
struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    double duration;
    char genre[50];
};

/* Function to add a new song to the library */
void addSong(struct song *library, int *numSongs) {
    // Get information about the song
    printf("Enter the song title: ");
    fgets(library[*numSongs].title, 50, stdin);
    library[*numSongs].title[strcspn(library[*numSongs].title, "\n")] = '\0'; // Remove \n from end of string
    printf("Enter the artist name: ");
    fgets(library[*numSongs].artist, 50, stdin);
    library[*numSongs].artist[strcspn(library[*numSongs].artist, "\n")] = '\0';
    printf("Enter the album name: ");
    fgets(library[*numSongs].album, 50, stdin);
    library[*numSongs].album[strcspn(library[*numSongs].album, "\n")] = '\0';
    printf("Enter the year the song was released: ");
    scanf("%d", &library[*numSongs].year);
    printf("Enter the duration of the song (in seconds): ");
    scanf("%lf", &library[*numSongs].duration);
    printf("Enter the genre of the song: ");
    getchar(); // Clear input buffer
    fgets(library[*numSongs].genre, 50, stdin);
    library[*numSongs].genre[strcspn(library[*numSongs].genre, "\n")] = '\0';
    
    // Increment the number of songs in the library
    (*numSongs)++;
}

/* Function to display information about a song */
void displaySong(struct song library) {
    printf("Title: %s\n", library.title);
    printf("Artist: %s\n", library.artist);
    printf("Album: %s\n", library.album);
    printf("Year: %d\n", library.year);
    printf("Duration: %.2lf seconds\n", library.duration);
    printf("Genre: %s\n", library.genre);
}

/* Function to search for a song in the library */
void searchLibrary(struct song *library, int numSongs) {
    char search[50];
    printf("Enter a search term: ");
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = '\0'; // Remove \n from end of string
    
    int found = 0;
    for (int i = 0; i < numSongs; i++) {
        // Check if title, artist, or album match the search term
        if (strstr(library[i].title, search) != NULL ||
            strstr(library[i].artist, search) != NULL ||
            strstr(library[i].album, search) != NULL) {
            displaySong(library[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matches found.\n");
    }
}

/* Function to delete a song from the library */
void deleteSong(struct song *library, int *numSongs) {
    char search[50];
    printf("Enter the title of the song to delete: ");
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = '\0'; // Remove \n from end of string
    
    int found = 0;
    for (int i = 0; i < *numSongs; i++) {
        // Check if title matches search term
        if (strcmp(library[i].title, search) == 0) {
            // Shift all songs after deleted song back one position
            for (int j = i; j < *numSongs - 1; j++) {
                library[j] = library[j+1];
            }
            // Decrement the number of songs in the library
            (*numSongs)--;
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Song deleted.\n");
    } else {
        printf("Song not found.\n");
    }
}

/* Main function */
int main() {
    struct song library[100];
    int numSongs = 0;
    int choice;
    do {
        // Display menu
        printf("Music Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Search the library\n");
        printf("3. Delete a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer
        printf("\n");
        
        // Handle menu choice
        switch (choice) {
            case 1:
                addSong(library, &numSongs);
                printf("Song added to library.\n\n");
                break;
            case 2:
                searchLibrary(library, numSongs);
                printf("\n");
                break;
            case 3:
                deleteSong(library, &numSongs);
                printf("\n");
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 4);
    
    return 0;
}