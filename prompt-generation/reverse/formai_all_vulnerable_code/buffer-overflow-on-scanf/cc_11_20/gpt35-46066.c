//FormAI DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum number of songs in the library
#define MAX_SONGS 1000

// song struct containing song information
typedef struct {
    int id;
    char title[50];
    char artist[50];
    int year;
} Song;

// main function
int main() {
    // initialize song library as an array of Song structs
    Song library[MAX_SONGS];
    // initialize count of songs in library to 0
    int song_count = 0;
    
    // loop until user chooses to exit program
    while (1) {
        // print options menu
        printf("\nOPTIONS: \n1. Add a song \n2. Print all songs \n3. Search for a song \n4. Exit\n");
        // read user input as integer choice
        int choice;
        scanf("%d", &choice);
        
        // clear input buffer
        while (getchar() != '\n');
        
        // switch based on user choice
        switch (choice) {
            case 1:
                // add a song to the library
                printf("\nEnter the song info: \n");
                // create new Song struct to store song info
                Song new_song;
                new_song.id = song_count + 1;
                // read in song title, artist, year from user input
                printf("Title: ");
                fgets(new_song.title, 50, stdin);
                new_song.title[strcspn(new_song.title, "\n")] = 0;
                printf("Artist: ");
                fgets(new_song.artist, 50, stdin);
                new_song.artist[strcspn(new_song.artist, "\n")] = 0;
                printf("Year: ");
                scanf("%d", &new_song.year);
                // add the new song to the library
                library[song_count] = new_song;
                song_count++;
                printf("\nAdded successfully!\n");
                break;
            case 2:
                // print all songs in the library
                printf("\nSONG LIBRARY:\n");
                for (int i = 0; i < song_count; i++) {
                    printf("%d. %s - %s (%d)\n", library[i].id, library[i].artist, library[i].title, library[i].year);
                }
                break;
            case 3:
                // search for a song in the library
                printf("\nEnter a search term: ");
                char search_term[50];
                fgets(search_term, 50, stdin);
                search_term[strcspn(search_term, "\n")] = 0;
                printf("\nSEARCH RESULTS:\n");
                for (int i = 0; i < song_count; i++) {
                    if (strstr(library[i].title, search_term) || strstr(library[i].artist, search_term)) {
                        printf("%d. %s - %s (%d)\n", library[i].id, library[i].artist, library[i].title, library[i].year);
                    }
                }
                break;
            case 4:
                // exit program
                printf("\nGoodbye!\n");
                return 0;
            default:
                // invalid choice, prompt user to try again
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}