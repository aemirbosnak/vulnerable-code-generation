//FormAI DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALBUMS 10
#define MAX_SONGS 100

struct song {
    char title[20];
    char artist[20];
    int duration;
};

struct album {
    char title[20];
    char artist[20];
    int year;
    int num_songs;
    struct song songs[MAX_SONGS];
};

struct music_library {
    int num_albums;
    int total_duration;
    struct album albums[MAX_ALBUMS];
};

void add_album(struct music_library *library);
void add_song(struct album *album);
void print_library(struct music_library library);

int main() {
    struct music_library library;
    library.num_albums = 0;
    library.total_duration = 0;

    int user_choice = 0;
    while (user_choice != 4) {
        printf("Music Library Management System\n");
        printf("1. Add album\n");
        printf("2. Add song\n");
        printf("3. Print music library\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                add_album(&library);
                break;
            case 2:
                // add song to album
                break;
            case 3:
                print_library(library);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

void add_album(struct music_library *library) {
    if (library->num_albums == MAX_ALBUMS) {
        printf("Music library is full, cannot add album.\n");
        return;
    }

    struct album *new_album = &(library->albums[library->num_albums++]);
    printf("Enter album title: ");
    scanf("%s", new_album->title);
    printf("Enter artist name: ");
    scanf("%s", new_album->artist);
    printf("Enter year of release: ");
    scanf("%d", &new_album->year);
    printf("Enter number of songs in album: ");
    scanf("%d", &new_album->num_songs);

    for (int i = 0; i < new_album->num_songs; i++) {
        add_song(new_album);
    }
}

void add_song(struct album *album) {
    if (album->num_songs == MAX_SONGS) {
        printf("Album is full, cannot add song.\n");
        return;
    }

    struct song *new_song = &(album->songs[album->num_songs++]);
    printf("Enter song title: ");
    scanf("%s", new_song->title);
    printf("Enter artist name: ");
    scanf("%s", new_song->artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &new_song->duration);
}

void print_library(struct music_library library) {
    printf("Music library contents:\n");
    printf("Num albums: %d\n", library.num_albums);
    printf("Total duration: %d seconds\n", library.total_duration);

    for (int i = 0; i < library.num_albums; i++) {
        struct album album = library.albums[i];
        printf("Album %d:\n", i+1);
        printf("Title: %s\n", album.title);
        printf("Artist: %s\n", album.artist);
        printf("Year of release: %d\n", album.year);
        printf("Num songs: %d\n", album.num_songs);

        for (int j = 0; j < album.num_songs; j++) {
            struct song song = album.songs[j];
            printf("Song %d:\n", j+1);
            printf("Title: %s\n", song.title);
            printf("Artist: %s\n", song.artist);
            printf("Duration: %d seconds\n", song.duration);
        }
    }
}