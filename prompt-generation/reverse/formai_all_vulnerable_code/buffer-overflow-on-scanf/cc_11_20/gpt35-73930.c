//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int song_id;
    char song_name[50];
    char artist_name[50];
    char album_name[50];
    int year;
    float duration;
} Song;

int main() {
    int choice, i, j, k, song_count = 0, id;
    char search[50];
    Song *songs = NULL;

    while (1) {
        printf("\n---------------------------\n");
        printf("C MUSIC LIBRARY MANAGEMENT SYSTEM\n");
        printf("---------------------------\n\n");
        printf("1. Add song\n");
        printf("2. Delete song\n");
        printf("3. Search song\n");
        printf("4. Display all songs\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add song
                song_count++;
                songs = realloc(songs, song_count * sizeof(Song));

                printf("\nEnter song name: ");
                fflush(stdin);
                fgets(songs[song_count-1].song_name, 50, stdin);
                strtok(songs[song_count-1].song_name, "\n");

                printf("Enter artist name: ");
                fflush(stdin);
                fgets(songs[song_count-1].artist_name, 50, stdin);
                strtok(songs[song_count-1].artist_name, "\n");

                printf("Enter album name: ");
                fflush(stdin);
                fgets(songs[song_count-1].album_name, 50, stdin);
                strtok(songs[song_count-1].album_name, "\n");

                printf("Enter year: ");
                scanf("%d", &songs[song_count-1].year);

                printf("Enter duration (in minutes): ");
                scanf("%f", &songs[song_count-1].duration);

                printf("Song added successfully!\n");
                break;
            case 2: // Delete song
                printf("\nEnter song ID: ");
                scanf("%d", &id);

                for (i = 0; i < song_count; i++) {
                    if (songs[i].song_id == id) {
                        for (j = i; j < song_count - 1; j++) {
                            songs[j] = songs[j+1];
                        }
                        song_count--;
                        songs = realloc(songs, song_count * sizeof(Song));
                        printf("Song deleted successfully!\n");
                        break;
                    }
                }
                if (i == song_count) {
                    printf("Song ID not found!\n");
                }
                break;
            case 3: // Search song
                printf("\nEnter text to search: ");
                fflush(stdin);
                fgets(search, 50, stdin);
                strtok(search, "\n");

                printf("\nSearch results:\n");
                for (i = 0; i < song_count; i++) {
                    if (strstr(songs[i].song_name, search) != NULL || strstr(songs[i].artist_name, search) != NULL
                            || strstr(songs[i].album_name, search) != NULL) {
                        printf("\nSong ID: %d\nSong name: %s\nArtist name: %s\nAlbum name: %s\nYear: %d\nDuration: %.2f minutes\n", 
                        songs[i].song_id, songs[i].song_name, songs[i].artist_name, songs[i].album_name, songs[i].year, songs[i].duration);
                    }
                }
                break;
            case 4: // Display all songs
                printf("\nDisplaying all songs:\n");
                for (i = 0; i < song_count; i++) {
                    printf("\nSong ID: %d\nSong name: %s\nArtist name: %s\nAlbum name: %s\nYear: %d\nDuration: %.2f minutes\n", 
                    songs[i].song_id, songs[i].song_name, songs[i].artist_name, songs[i].album_name, songs[i].year, songs[i].duration);
                }
                break;
            case 5: // Exit
                printf("\nGoodbye!");
                free(songs);
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}