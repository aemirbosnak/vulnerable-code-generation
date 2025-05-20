//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for maximum number of albums and songs */
#define MAX_ALBUMS 50
#define MAX_SONGS 100

/* Define structs for album and song details */
typedef struct {
    char name[50];
    char artist[50];
    int num_songs;
    float rating;
} Album;

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    float duration;
} Song;

/* Define global variables for the library */
Album library[MAX_ALBUMS];
Song songs[MAX_SONGS];
int num_albums = 0;
int num_songs = 0;

/* Function to add an album to the library */
void add_album() {
    Album new_album; // Create a new album struct
    printf("Enter album name: ");
    scanf("%s", new_album.name);
    printf("Enter artist name: ");
    scanf("%s", new_album.artist);
    printf("Enter number of songs: ");
    scanf("%d", &new_album.num_songs);
    printf("Enter album rating: ");
    scanf("%f", &new_album.rating);
    library[num_albums] = new_album; // Add the new album to the library
    num_albums++; // Increment the number of albums in the library
    printf("Album added!\n");
}

/* Function to add a song to the library */
void add_song() {
    Song new_song; // Create a new song struct
    printf("Enter song title: ");
    scanf("%s", new_song.title);
    printf("Enter song artist: ");
    scanf("%s", new_song.artist);
    printf("Enter album name: ");
    scanf("%s", new_song.album);
    printf("Enter song duration: ");
    scanf("%f", &new_song.duration);
    songs[num_songs] = new_song; // Add the new song to the library
    num_songs++; // Increment the number of songs in the library
    printf("Song added!\n");
}

/* Function to display all albums in the library */
void display_albums() {
    if(num_albums == 0) {
        printf("No albums in library!\n");
        return;
    }
    printf("%-30s %-30s %-10s %-5s\n", "ALBUM", "ARTIST", "SONGS", "RATING");
    for(int i=0; i<num_albums; i++) {
        printf("%-30s %-30s %-10d %-5.1f\n", library[i].name, library[i].artist, library[i].num_songs, library[i].rating);
    }
}

/* Function to display all songs in the library */
void display_songs() {
    if(num_songs == 0) {
        printf("No songs in library!\n");
        return;
    }
    printf("%-30s %-30s %-30s %-5s\n", "TITLE", "ARTIST", "ALBUM", "DURATION");
    for(int i=0; i<num_songs; i++) {
        printf("%-30s %-30s %-30s %-5.1f\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].duration);
    }
}

/* Function to search for an album by name and display its details */
void search_album() {
    char album_name[50];
    printf("Enter album name: ");
    scanf("%s", album_name);
    for(int i=0; i<num_albums; i++) {
        if(strcmp(album_name, library[i].name) == 0) {
            printf("ALBUM: %s\n", library[i].name);
            printf("ARTIST: %s\n", library[i].artist);
            printf("SONGS: %d\n", library[i].num_songs);
            printf("RATING: %.1f\n", library[i].rating);
            return;
        }
    }
    printf("Album not found!\n");
}

/* Function to search for a song by title and display its details */
void search_song() {
    char song_title[50];
    printf("Enter song title: ");
    scanf("%s", song_title);
    for(int i=0; i<num_songs; i++) {
        if(strcmp(song_title, songs[i].title) == 0) {
            printf("TITLE: %s\n", songs[i].title);
            printf("ARTIST: %s\n", songs[i].artist);
            printf("ALBUM: %s\n", songs[i].album);
            printf("DURATION: %.1f\n", songs[i].duration);
            return;
        }
    }
    printf("Song not found!\n");
}

/* Function to delete an album from the library */
void delete_album() {
    char album_name[50];
    printf("Enter album name: ");
    scanf("%s", album_name);
    for(int i=0; i<num_albums; i++) {
        if(strcmp(album_name, library[i].name) == 0) {
            for(int j=i; j<num_albums-1; j++) {
                library[j] = library[j+1];
            }
            num_albums--;
            printf("Album deleted!\n");
            return;
        }
    }
    printf("Album not found!\n");
}

/* Function to delete a song from the library */
void delete_song() {
    char song_title[50];
    printf("Enter song title: ");
    scanf("%s", song_title);
    for(int i=0; i<num_songs; i++) {
        if(strcmp(song_title, songs[i].title) == 0) {
            for(int j=i; j<num_songs-1; j++) {
                songs[j] = songs[j+1];
            }
            num_songs--;
            printf("Song deleted!\n");
            return;
        }
    }
    printf("Song not found!\n");
}

int main() {
    char menu_selection;
    do {
        printf("C MUSIC LIBRARY MANAGEMENT SYSTEM\n");
        printf("1. Add Album\n");
        printf("2. Add Song\n");
        printf("3. Display Albums\n");
        printf("4. Display Songs\n");
        printf("5. Search Album\n");
        printf("6. Search Song\n");
        printf("7. Delete Album\n");
        printf("8. Delete Song\n");
        printf("9. Exit\n");
        printf("Enter selection: ");
        scanf("%s", &menu_selection);
        switch(menu_selection) {
            case '1':
                add_album();
                break;
            case '2':
                add_song();
                break;
            case '3':
                display_albums();
                break;
            case '4':
                display_songs();
                break;
            case '5':
                search_album();
                break;
            case '6':
                search_song();
                break;
            case '7':
                delete_album();
                break;
            case '8':
                delete_song();
                break;
            case '9':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection!\n");
                break;
        }
    } while(menu_selection != '9');
    return 0;
}