//FormAI DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the maximum number of songs
#define MAX_SONGS 100

// Declare the Song structure
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float duration;
} Song;

// Declare the function prototypes
void displayMenu();
void addSong(Song [], int *);
void removeSong(Song [], int *);
void searchSong(Song [], int *);
void printAllSongs(Song [], int);

int main() {
    // Declare the variables
    Song songs[MAX_SONGS];
    int numOfSongs = 0, choice = 0;
    
    // Run the program until the user decides to exit
    do {
        // Display the menu options
        displayMenu();
        
        // Read the user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1: // Add a new song to the library
                addSong(songs, &numOfSongs);
                break;
            case 2: // Remove an existing song from the library
                removeSong(songs, &numOfSongs);
                break;
            case 3: // Search for a song in the library
                searchSong(songs, &numOfSongs);
                break;
            case 4: // Print all songs in the library
                printAllSongs(songs, numOfSongs);
                break;
            case 5: // Exit the program
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\n---------- C Music Library Manager ----------\n");
    printf("1. Add a new song to the library\n");
    printf("2. Remove an existing song from the library\n");
    printf("3. Search for a song in the library\n");
    printf("4. Print all songs in the library\n");
    printf("5. Exit\n");
}

void addSong(Song songs[], int *numOfSongs) {
    // Check if the maximum number of songs has been reached
    if(*numOfSongs == MAX_SONGS) {
        printf("The library is full, cannot add more songs.\n");
        return;
    }
    
    // Read the song details from the user
    printf("\nEnter the song details:\n");
    printf("Title: ");
    fgets(songs[*numOfSongs].title, 50, stdin);
    songs[*numOfSongs].title[strcspn(songs[*numOfSongs].title, "\n")] = 0;
    printf("Artist: ");
    fgets(songs[*numOfSongs].artist, 50, stdin);
    songs[*numOfSongs].artist[strcspn(songs[*numOfSongs].artist, "\n")] = 0;
    printf("Album: ");
    fgets(songs[*numOfSongs].album, 50, stdin);
    songs[*numOfSongs].album[strcspn(songs[*numOfSongs].album, "\n")] = 0;
    printf("Year: ");
    scanf("%d", &songs[*numOfSongs].year);
    getchar();
    printf("Duration (in minutes): ");
    scanf("%f", &songs[*numOfSongs].duration);
    getchar();
    
    // Increment the number of songs in the library
    (*numOfSongs)++;
    
    printf("Song added successfully!\n");
}

void removeSong(Song songs[], int *numOfSongs) {
    // Read the song title from the user
    printf("\nEnter the title of the song to be removed: ");
    char searchTitle[50];
    fgets(searchTitle, 50, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;
    
    // Search for the song in the library
    int i, index = -1;
    for(i = 0; i < *numOfSongs; i++) {
        if(strcmp(songs[i].title, searchTitle) == 0) {
            index = i;
            break;
        }
    }
    
    // Remove the song if found
    if(index != -1) {
        for(i = index; i < *numOfSongs - 1; i++) {
            songs[i] = songs[i + 1];
        }
        (*numOfSongs)--;
        printf("Song removed successfully!\n");
    }
    else {
        printf("Song not found in the library.\n");
    }
}

void searchSong(Song songs[], int *numOfSongs) {
    // Read the search keyword from the user
    printf("\nEnter the search keyword: ");
    char searchKeyword[50];
    fgets(searchKeyword, 50, stdin);
    searchKeyword[strcspn(searchKeyword, "\n")] = 0;
    
    // Search for songs that match the search keyword
    int i, count = 0;
    printf("\nSearch results:\n");
    for(i = 0; i < *numOfSongs; i++) {
        if(strstr(songs[i].title, searchKeyword) != NULL || 
           strstr(songs[i].artist, searchKeyword) != NULL || 
           strstr(songs[i].album, searchKeyword) != NULL) {
            printf("Title: %s\n", songs[i].title);
            printf("Artist: %s\n", songs[i].artist);
            printf("Album: %s\n", songs[i].album);
            printf("Year: %d\n", songs[i].year);
            printf("Duration: %.2f minutes\n", songs[i].duration);
            printf("\n");
            count++;
        }
    }
    
    // Print no results if no matching songs are found
    if(count == 0) {
        printf("No matching songs found in the library.\n");
    }
}

void printAllSongs(Song songs[], int numOfSongs) {
    // Print the details of all songs in the library
    printf("\nAll songs in the library:\n");
    int i;
    for(i = 0; i < numOfSongs; i++) {
        printf("Title: %s\n", songs[i].title);
        printf("Artist: %s\n", songs[i].artist);
        printf("Album: %s\n", songs[i].album);
        printf("Year: %d\n", songs[i].year);
        printf("Duration: %.2f minutes\n", songs[i].duration);
        printf("\n");
    }
}