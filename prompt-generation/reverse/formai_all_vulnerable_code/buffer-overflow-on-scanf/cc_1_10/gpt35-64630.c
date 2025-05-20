//FormAI DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_GENRE_LENGTH 20

typedef struct song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
} Song;

Song songs[MAX_SONGS];
int num_songs = 0;

void add_song() {
    if (num_songs == MAX_SONGS) {
        printf("Maximum number of songs reached!\n");
        return;
    }

    Song new_song;

    printf("Enter the song title: ");
    fgets(new_song.title, MAX_TITLE_LENGTH, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = 0; // Remove trailing newline

    printf("Enter the artist name: ");
    fgets(new_song.artist, MAX_ARTIST_LENGTH, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = 0;

    printf("Enter the album name: ");
    fgets(new_song.album, MAX_ALBUM_LENGTH, stdin);
    new_song.album[strcspn(new_song.album, "\n")] = 0;

    printf("Enter the genre: ");
    fgets(new_song.genre, MAX_GENRE_LENGTH, stdin);
    new_song.genre[strcspn(new_song.genre, "\n")] = 0;

    songs[num_songs++] = new_song;

    printf("Song added!\n");
}

void search_songs() {
    int found_songs = 0;
    char search_term[MAX_TITLE_LENGTH];
    printf("Enter the search term: ");
    fgets(search_term, MAX_TITLE_LENGTH, stdin);
    search_term[strcspn(search_term, "\n")] = 0;

    printf("Search results:\n");
    for (int i = 0; i < num_songs; i++) {
        if (strstr(songs[i].title, search_term) != NULL || strstr(songs[i].artist, search_term) != NULL ||
            strstr(songs[i].album, search_term) != NULL || strstr(songs[i].genre, search_term) != NULL) {
            printf("%s - %s (%s, %s)\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].genre);
            found_songs++;
        }
    }

    if (found_songs == 0) {
        printf("No results found.\n");
    } else {
        printf("%d result(s) found.\n", found_songs);
    }
}

void print_menu() {
    printf("\n");
    printf("1. Add song\n");
    printf("2. Search songs\n");
    printf("3. Quit\n");
    printf("\n");
    printf("Enter your choice: ");
}

int main() {
    int choice = 0;

    while (choice != 3) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // Remove trailing newline

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_songs();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}