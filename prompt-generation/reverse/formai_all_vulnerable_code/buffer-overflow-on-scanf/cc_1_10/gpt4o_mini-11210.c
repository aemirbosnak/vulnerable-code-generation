//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    int duration; // in seconds
} Song;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Song songs[MAX_SONGS];
    int song_count;
} Album;

Album musicLibrary[MAX_ALBUMS];
int album_count = 0;

void displayMenu() {
    printf("*************************************\n");
    printf("Welcome to the Silly Music Library!\n");
    printf("Choose one of the following options:\n");
    printf("1. Add Album\n");
    printf("2. View Albums\n");
    printf("3. Add Song to Album\n");
    printf("4. View Songs in Album\n");
    printf("5. Exit (Or run away screaming)\n");
    printf("*************************************\n");
}

void addAlbum() {
    if (album_count >= MAX_ALBUMS) {
        printf("Oops! You have too many albums! Can't add more, try deleting some!\n");
        return;
    }
    printf("Enter album name: ");
    scanf(" %[^\n]", musicLibrary[album_count].name);
    musicLibrary[album_count].song_count = 0;
    album_count++;
    printf("Album '%s' added to the library!\n", musicLibrary[album_count - 1].name);
}

void viewAlbums() {
    if (album_count == 0) {
        printf("No albums found! It's like a desert out here!\n");
        return;
    }
    printf("Here are your albums:\n");
    for (int i = 0; i < album_count; i++) {
        printf("%d. %s\n", i + 1, musicLibrary[i].name);
    }
}

void addSongToAlbum() {
    int albumIndex;
    viewAlbums();
    printf("Select album by number to add a song: ");
    scanf("%d", &albumIndex);
    
    if (albumIndex < 1 || albumIndex > album_count) {
        printf("Invalid album number! That's what you get for mixing up your numbers!\n");
        return;
    }

    albumIndex--; // adjust for zero-indexing
    if (musicLibrary[albumIndex].song_count >= MAX_SONGS) {
        printf("Whoa! This album is already maxed out! No more songs!\n");
        return;
    }

    printf("Enter song title: ");
    scanf(" %[^\n]", musicLibrary[albumIndex].songs[musicLibrary[albumIndex].song_count].title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", musicLibrary[albumIndex].songs[musicLibrary[albumIndex].song_count].artist);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &musicLibrary[albumIndex].songs[musicLibrary[albumIndex].song_count].duration);

    musicLibrary[albumIndex].song_count++;
    printf("Song '%s' added to album '%s'! Rock on!\n", musicLibrary[albumIndex].songs[musicLibrary[albumIndex].song_count - 1].title, musicLibrary[albumIndex].name);
}

void viewSongsInAlbum() {
    int albumIndex;
    viewAlbums();
    printf("Select album by number to view songs: ");
    scanf("%d", &albumIndex);

    if (albumIndex < 1 || albumIndex > album_count) {
        printf("Your fingers are not cooperating! Please provide a valid number.\n");
        return;
    }

    albumIndex--; // adjust for zero-indexing
    if (musicLibrary[albumIndex].song_count == 0) {
        printf("This album is as empty as my bank account!\n");
        return;
    }

    printf("Songs in album '%s':\n", musicLibrary[albumIndex].name);
    for (int i = 0; i < musicLibrary[albumIndex].song_count; i++) {
        printf(" - %s by %s (%d seconds)\n", musicLibrary[albumIndex].songs[i].title, musicLibrary[albumIndex].songs[i].artist, musicLibrary[albumIndex].songs[i].duration);
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("What's your pick? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAlbum(); break;
            case 2: viewAlbums(); break;
            case 3: addSongToAlbum(); break;
            case 4: viewSongsInAlbum(); break;
            case 5: printf("Goodbye! Don't forget to dance like nobody's watching!\n"); exit(0);
            default: printf("What? I don't understand that! Let's just dance instead!\n");
        }
    }
    return 0;
}