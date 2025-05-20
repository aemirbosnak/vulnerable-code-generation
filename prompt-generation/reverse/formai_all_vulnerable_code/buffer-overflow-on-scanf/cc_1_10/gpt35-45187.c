//FormAI DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 50
#define MAX_SONGS 100

typedef struct {
    char name[50];
    int year;
} Album;

typedef struct {
    char title[50];
    char artist[50];
    int duration;
} Song;

Album albums[MAX_ALBUMS];
Song songs[MAX_SONGS];

int num_albums = 0;
int num_songs = 0;

void print_menu() {
    printf("\nMUSIC LIBRARY MANAGEMENT SYSTEM\n");
    printf("1. Add Album\n");
    printf("2. Add Song\n");
    printf("3. Remove Album\n");
    printf("4. Remove Song\n");
    printf("5. List Albums\n");
    printf("6. List Songs\n");
    printf("7. Exit\n");
}

void add_album() {
    Album album;
    printf("\nEnter album name: ");
    scanf("%s", album.name);
    printf("Enter release year: ");
    scanf("%d", &album.year);
    albums[num_albums++] = album;
    printf("\nAlbum added successfully!\n");
}

void add_song() {
    char album_name[50];
    int album_index = -1;
    Song song;
    printf("\nEnter song title: ");
    scanf("%s", song.title);
    printf("Enter artist name: ");
    scanf("%s", song.artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &song.duration);
    printf("Enter album name: ");
    scanf("%s", album_name);
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(albums[i].name, album_name) == 0) {
            album_index = i;
            break;
        }
    }
    if (album_index == -1) {
        printf("\nError: Album not found!\n");
    } else {
        songs[num_songs++] = song;
        printf("\nSong added successfully!\n");
    }
}

void remove_album() {
    char album_name[50];
    int album_index = -1;
    printf("\nEnter album name: ");
    scanf("%s", album_name);
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(albums[i].name, album_name) == 0) {
            album_index = i;
            break;
        }
    }
    if (album_index == -1) {
        printf("\nError: Album not found!\n");
    } else {
        for (int i = album_index; i < num_albums - 1; i++) {
            albums[i] = albums[i + 1];
        }
        num_albums--;
        printf("\nAlbum removed successfully!\n");
    }
}

void remove_song() {
    char song_title[50];
    int song_index = -1;
    printf("\nEnter song title: ");
    scanf("%s", song_title);
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].title, song_title) == 0) {
            song_index = i;
            break;
        }
    }
    if (song_index == -1) {
        printf("\nError: Song not found!\n");
    } else {
        for (int i = song_index; i < num_songs - 1; i++) {
            songs[i] = songs[i + 1];
        }
        num_songs--;
        printf("\nSong removed successfully!\n");
    }
}

void list_albums() {
    printf("\nAlbums:\n");
    for (int i = 0; i < num_albums; i++) {
        printf("%s (%d)\n", albums[i].name, albums[i].year);
    }
}

void list_songs() {
    printf("\nSongs:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%s - %s (%d seconds)\n", songs[i].title, songs[i].artist, songs[i].duration);
    }
}

int main() {
    int choice;
    do {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_album();
                break;
            case 2:
                add_song();
                break;
            case 3:
                remove_album();
                break;
            case 4:
                remove_song();
                break;
            case 5:
                list_albums();
                break;
            case 6:
                list_songs();
                break;
            case 7:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nError: Invalid choice!\n");
                break;
        }
    } while (choice != 7);
    return 0;
}