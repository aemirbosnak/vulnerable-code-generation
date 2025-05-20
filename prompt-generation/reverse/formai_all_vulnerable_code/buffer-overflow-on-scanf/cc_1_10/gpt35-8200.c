//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 1000
#define MAX_SONGS 10000

typedef struct {
    char title[50];
    char artist[50];
    int year;
} album;

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} song;

album albums[MAX_ALBUMS];
song songs[MAX_SONGS];
int album_count = 0;
int song_count = 0;

void add_album() {
    printf("Enter album title: ");
    fgets(albums[album_count].title, 50, stdin);
    albums[album_count].title[strcspn(albums[album_count].title, "\n")] = 0;

    printf("Enter artist name: ");
    fgets(albums[album_count].artist, 50, stdin);
    albums[album_count].artist[strcspn(albums[album_count].artist, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &albums[album_count].year);
    getchar(); // flush newline character from input buffer

    album_count++;
}

void add_song() {
    printf("Enter song title: ");
    fgets(songs[song_count].title, 50, stdin);
    songs[song_count].title[strcspn(songs[song_count].title, "\n")] = 0;

    printf("Enter artist name: ");
    fgets(songs[song_count].artist, 50, stdin);
    songs[song_count].artist[strcspn(songs[song_count].artist, "\n")] = 0;

    printf("Enter album title: ");
    fgets(songs[song_count].album, 50, stdin);
    songs[song_count].album[strcspn(songs[song_count].album, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &songs[song_count].year);
    getchar(); // flush newline character from input buffer

    song_count++;
}

int find_album(char* title, char* artist, int year) {
    for (int i = 0; i < album_count; i++) {
        if (strcmp(title, albums[i].title) == 0 && strcmp(artist, albums[i].artist) == 0 && year == albums[i].year) {
            return i;
        }
    }
    return -1;
}

void print_albums() {
    printf("Albums:\n");
    for (int i = 0; i < album_count; i++) {
        printf("%s by %s (%d)\n", albums[i].title, albums[i].artist, albums[i].year);
    }
    printf("\n");
}

void print_songs() {
    printf("Songs:\n");
    for (int i = 0; i < song_count; i++) {
        printf("%s by %s from %s (%d)\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
    }
    printf("\n");
}

int main() {
    int choice;

    printf("Welcome to the C Music Library Management System\n");

    while (1) {
        printf("MENU:\n");
        printf("1. Add album\n");
        printf("2. Add song\n");
        printf("3. List albums\n");
        printf("4. List songs\n");
        printf("5. Quit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        getchar(); // flush newline character from input buffer

        switch (choice) {
            case 1:
                add_album();
                break;
            case 2:
                add_song();
                break;
            case 3:
                print_albums();
                break;
            case 4:
                print_songs();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}