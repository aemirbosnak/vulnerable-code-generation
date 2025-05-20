//FormAI DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_SONGS 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Song;

int main() {
    Song library[MAX_SONGS];
    int num_songs = 0;

    while(1) {
        int choice;
        printf("\nMenu\n");
        printf("1. Add song\n");
        printf("2. Display library\n");
        printf("3. Search song\n");
        printf("4. Remove song\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add song
                if(num_songs < MAX_SONGS) {
                    Song new_song;
                    printf("\nEnter new song details\n");
                    printf("Title: ");
                    scanf(" %[^\n]s", new_song.title);
                    printf("Artist: ");
                    scanf(" %[^\n]s", new_song.artist);
                    printf("Year: ");
                    scanf("%d", &new_song.year);
                    library[num_songs++] = new_song;
                    printf("\nSong added to library!\n");
                }
                else {
                    printf("\nMaximum capacity reached. No more songs can be added.\n");
                }
                break;

            case 2: // Display library
                if(num_songs == 0) {
                    printf("\nLibrary is empty.\n");
                }
                else {
                    printf("\nLibrary contents:\n");
                    for(int i = 0; i < num_songs; i++) {
                        printf("%d. %s by %s (%d)\n", i+1, library[i].title, library[i].artist, library[i].year);
                    }
                }
                break;

            case 3: // Search song
                if(num_songs == 0) {
                    printf("\nLibrary is empty. Cannot search for song.\n");
                }
                else {
                    char search_title[MAX_TITLE_LENGTH];
                    printf("\nEnter song title to search: ");
                    scanf(" %[^\n]s", search_title);
                    int found = 0;
                    for(int i = 0; i < num_songs; i++) {
                        if(strcmp(search_title, library[i].title) == 0) {
                            printf("\nSong found at position %d!\n", i+1);
                            printf("%s by %s (%d)\n", library[i].title, library[i].artist, library[i].year);
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        printf("\nSong not found in library.\n");
                    }
                }
                break;

            case 4: // Remove song
                if(num_songs == 0) {
                    printf("\nLibrary is empty. Nothing to remove.\n");
                }
                else {
                    char remove_title[MAX_TITLE_LENGTH];
                    printf("\nEnter song title to remove: ");
                    scanf(" %[^\n]s", remove_title);
                    int remove_index = -1;
                    for(int i = 0; i < num_songs; i++) {
                        if(strcmp(remove_title, library[i].title) == 0) {
                            remove_index = i;
                            break;
                        }
                    }
                    if(remove_index != -1) {
                        for(int i = remove_index; i < num_songs - 1; i++) {
                            library[i] = library[i+1];
                        }
                        num_songs--;
                        printf("\nSong removed from library.\n");
                    }
                    else {
                        printf("\nSong not found in library.\n");
                    }
                }
                break;

            case 5: // Quit
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}