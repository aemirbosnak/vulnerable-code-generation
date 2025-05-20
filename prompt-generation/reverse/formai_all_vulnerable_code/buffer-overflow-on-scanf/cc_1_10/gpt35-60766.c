//FormAI DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS_PER_ALBUM 20

typedef struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int track_number;
} Song;

typedef struct Album {
    char title[100];
    char artist[100];
    int year;
    Song songs[MAX_SONGS_PER_ALBUM];
    int total_songs;
} Album;

typedef struct Library {
    Album albums[MAX_ALBUMS];
    int total_albums;
} Library;

int add_album(Library *library, Album album) {
    if (library->total_albums >= MAX_ALBUMS) {
        printf("Your music library is full! Cannot add more albums.\n");
        return -1;
    }
    library->albums[library->total_albums++] = album;
    return library->total_albums;
}

int add_song(Library *library, Song song, char album_title[]) {
    for (int i = 0; i < library->total_albums; i++) {
        if (strcmp(library->albums[i].title, album_title) == 0) {
            if (library->albums[i].total_songs >= MAX_SONGS_PER_ALBUM) {
                printf("This album is already full! Cannot add more songs.\n");
                return -1;
            }
            library->albums[i].songs[library->albums[i].total_songs++] = song;
            return library->albums[i].total_songs;
        }
    }
    printf("Album not found!\n");
    return -1;
}

void display_library(Library library) {
    printf("======= MUSIC LIBRARY =======\n");
    for (int i = 0; i < library.total_albums; i++) {
        printf("\nALBUM #%d\n", i + 1);
        printf("Title: %s\n", library.albums[i].title);
        printf("Artist: %s\n", library.albums[i].artist);
        printf("Year: %d\n", library.albums[i].year);
        printf("SONGS:\n");
        for (int j = 0; j < library.albums[i].total_songs; j++) {
            printf("%d. %s - %s\n", library.albums[i].songs[j].track_number, library.albums[i].songs[j].artist, library.albums[i].songs[j].title);
        }
    }
    printf("\n============================\n");
}

int main() {
    Library library;
    library.total_albums = 0;
    int choice = 0;
    while (choice != 4) {
        printf("\nWhat do you want do?\n");
        printf("1. Add Album\n");
        printf("2. Add Song to Album\n");
        printf("3. Display Library\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                Album album;
                printf("Enter album title: ");
                fgets(album.title, 100, stdin);
                printf("Enter artist name: ");
                fgets(album.artist, 100, stdin);
                printf("Enter year of release: ");
                scanf("%d", &album.year);
                album.total_songs = 0;
                add_album(&library, album);
                break;
            }
            case 2: {
                Song song;
                printf("Enter song title: ");
                fgets(song.title, 100, stdin);
                printf("Enter artist name: ");
                fgets(song.artist, 100, stdin);
                printf("Enter album title: ");
                char album_title[100];
                fgets(album_title, 100, stdin);
                printf("Enter year of release: ");
                scanf("%d", &song.year);
                printf("Enter track number: ");
                scanf("%d", &song.track_number);
                add_song(&library, song, album_title);
                break;
            }
            case 3: {
                display_library(library);
                break;
            }
            case 4: {
                printf("Goodbye!");
                break;
            }
            default: {
                printf("Invalid choice! Try again");
                break;
            }
        }
    }
    return 0;
}