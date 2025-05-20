//FormAI DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    int choice, num_songs = 0;
    char title[100], artist[50], album[50];
    
    // Create array of structures to hold song information
    struct Song {
        char title[100];
        char artist[50];
        char album[50];
    } songs[100];

    // Display menu and ask for user input
    do {
        printf("\nPlease choose an option:\n");
        printf("1- Add a song\n");
        printf("2- Delete a song\n");
        printf("3- Display all songs\n");
        printf("4- Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a song
                printf("\nEnter the song title: ");
                scanf("%s", title);
                printf("Enter the artist name: ");
                scanf("%s", artist);
                printf("Enter the album name: ");
                scanf("%s", album);
                
                // Save song information in array of structures
                strcpy(songs[num_songs].title, title);
                strcpy(songs[num_songs].artist, artist);
                strcpy(songs[num_songs].album, album);
                
                num_songs++; // Increment number of songs
                printf("\nSong added successfully.\n");
                
                break;
                
            case 2:
                // Delete a song
                printf("\nEnter the title of the song to be deleted: ");
                scanf("%s", title);
                
                // Search for song in array of structures
                int i;
                for (i = 0; i < num_songs; i++) {
                    if (strcmp(songs[i].title, title) == 0) {
                        // Shift all songs after this one back by one position
                        int j;
                        for (j = i; j < num_songs - 1; j++) {
                            strcpy(songs[j].title, songs[j+1].title);
                            strcpy(songs[j].artist, songs[j+1].artist);
                            strcpy(songs[j].album, songs[j+1].album);
                        }
                        num_songs--; // Decrement number of songs
                        printf("\nSong deleted successfully.\n");
                        break;
                    }
                }
                if (i == num_songs) {
                    printf("\nSong not found.\n");
                }
                
                break;
                
            case 3:
                // Display all songs
                printf("\n");
                if (num_songs == 0) {
                    printf("No songs in the library.\n");
                } else {
                    int k;
                    for (k = 0; k < num_songs; k++) {
                        printf("%d. %s - %s (%s)\n", k+1, songs[k].title, songs[k].artist, songs[k].album);
                    }
                }
                
                break;
                
            case 4:
                // Exit program
                printf("\nGoodbye!\n");
                break;
                
            default:
                // Invalid input
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}