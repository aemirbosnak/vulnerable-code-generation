//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 50
#define MAX_GENRE_LEN 20

struct Song {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    int year;
};

struct Library {
    struct Song songs[MAX_SONGS];
    int total_songs;
};

void add_song_to_library(struct Library *library, struct Song *song) {
    if (library->total_songs < MAX_SONGS) {
        memcpy(&(library->songs[library->total_songs]), song, sizeof(struct Song));
        library->total_songs++;
        printf("Song added to library!\n");
    } else {
        printf("Library is full, cannot add song.\n");
    }
}

void print_song_details(struct Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Genre: %s\n", song->genre);
    printf("Year: %d\n", song->year);
}

void print_all_songs(struct Library *library) {
    if (library->total_songs == 0) {
        printf("Library is empty.\n");
        return;
    }
    
    printf("------- All Songs -------\n");
    for (int i = 0; i < library->total_songs; i++) {
        printf("Song %d:\n", i+1);
        print_song_details(&(library->songs[i]));
        printf("\n");
    }
    printf("-------------------------\n");
}

int main() {
    struct Library library;
    library.total_songs = 0;
    
    while (1) {
        printf("Enter 'a' to add a song to the library, 'p' to print all songs in the library, or 'q' to quit.\n");
        char option;
        scanf(" %c", &option);
        
        if (option == 'a') {
            struct Song song;
            printf("Song Title: ");
            scanf(" %[^\n]s", song.title);
            printf("Artist: ");
            scanf(" %[^\n]s", song.artist);
            printf("Album: ");
            scanf(" %[^\n]s", song.album);
            printf("Genre: ");
            scanf(" %[^\n]s", song.genre);
            printf("Year: ");
            scanf("%d", &song.year);
            
            add_song_to_library(&library, &song);
        } else if (option == 'p') {
            print_all_songs(&library);
        } else if (option == 'q') {
            printf("Exiting... \n");
            break;
        } else {
            printf("Invalid option, try again.\n");
        }
    }
    
    return 0;
}