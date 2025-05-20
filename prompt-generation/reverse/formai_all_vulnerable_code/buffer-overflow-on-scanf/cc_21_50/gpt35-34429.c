//FormAI DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_LENGTH 50

typedef struct Song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int duration; //in seconds
} Song;

typedef struct Playlist {
    char name[MAX_LENGTH];
    int num_songs;
    Song songs[MAX_SONGS];
} Playlist;

int main() {
    int num_playlists = 0;
    Playlist playlists[MAX_SONGS]; //maximum of 1000 playlists
    int choice = 0;

    while (choice != 5) {
        printf("\n\nMenu:\n");
        printf("1. Create a new playlist\n");
        printf("2. Add a song to a playlist\n");
        printf("3. Remove a song from a playlist\n");
        printf("4. View a playlist\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (num_playlists == MAX_SONGS) {
                    printf("Error: Maximum number of playlists reached.\n");
                    break;
                }

                printf("Enter playlist name: ");
                scanf("%s", playlists[num_playlists].name);
                playlists[num_playlists].num_songs = 0;
                num_playlists++;
                printf("Playlist created successfully.\n");
                break;
            case 2:
                if (num_playlists == 0) {
                    printf("Error: No playlists created yet.\n");
                    break;
                }

                char playlist_name[MAX_LENGTH];
                printf("Enter playlist name: ");
                scanf("%s", playlist_name);

                int i;
                for (i = 0; i < num_playlists; i++) {
                    if (strcmp(playlist_name, playlists[i].name) == 0) {
                        Song song;
                        printf("Enter song title: ");
                        scanf("%s", song.title);
                        printf("Enter artist name: ");
                        scanf("%s", song.artist);
                        printf("Enter song duration in seconds: ");
                        scanf("%d", &song.duration);

                        if (playlists[i].num_songs == MAX_SONGS) {
                            printf("Error: Maximum number of songs reached for this playlist.\n");
                            break;
                        }

                        playlists[i].songs[playlists[i].num_songs++] = song;
                        printf("Song added to playlist successfully.\n");
                        break;
                    }
                }

                if (i == num_playlists) {
                    printf("Error: Playlist not found.\n");
                }
                break;
            case 3:
                if (num_playlists == 0) {
                    printf("Error: No playlists created yet.\n");
                    break;
                }

                char playlist_name_remove[MAX_LENGTH];
                printf("Enter playlist name: ");
                scanf("%s", playlist_name_remove);

                for (i = 0; i < num_playlists; i++) {
                    if (strcmp(playlist_name_remove, playlists[i].name) == 0) {
                        if (playlists[i].num_songs == 0) {
                            printf("Error: Playlist is empty.\n");
                            break;
                        }

                        char song_title[MAX_LENGTH];
                        printf("Enter song title: ");
                        scanf("%s", song_title);

                        int j;
                        for (j = 0; j < playlists[i].num_songs; j++) {
                            if (strcmp(song_title, playlists[i].songs[j].title) == 0) {
                                int k;
                                for (k = j; k < playlists[i].num_songs - 1; k++) {
                                    playlists[i].songs[k] = playlists[i].songs[k+1];
                                }

                                playlists[i].num_songs--;
                                printf("Song removed from playlist successfully.\n");
                                break;
                            }
                        }

                        if (j == playlists[i].num_songs) {
                            printf("Error: Song not found in playlist.\n");
                        }

                        break;
                    }
                }

                if (i == num_playlists) {
                    printf("Error: Playlist not found.\n");
                }
                break;
            case 4:
                if (num_playlists == 0) {
                    printf("Error: No playlists created yet.\n");
                    break;
                }

                char playlist_name_view[MAX_LENGTH];
                printf("Enter playlist name: ");
                scanf("%s", playlist_name_view);

                for (i = 0; i < num_playlists; i++) {
                    if (strcmp(playlist_name_view, playlists[i].name) == 0) {
                        printf("Playlist Name: %s\n", playlists[i].name);
                        printf("Number of Songs: %d\n", playlists[i].num_songs);
                        printf("\nTitle\t\tArtist\t\tDuration\n");
                        int j;
                        for (j = 0; j < playlists[i].num_songs; j++) {
                            printf("%s\t\t%s\t\t%d seconds\n", playlists[i].songs[j].title,
                                   playlists[i].songs[j].artist, playlists[i].songs[j].duration);
                        }
                        break;
                    }
                }

                if (i == num_playlists) {
                    printf("Error: Playlist not found.\n");
                }
                break;
            case 5:
                printf("\nThank you for using the music library management system!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}