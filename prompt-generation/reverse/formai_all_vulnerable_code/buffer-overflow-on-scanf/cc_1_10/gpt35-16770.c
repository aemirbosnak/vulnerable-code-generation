//FormAI DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 50

typedef struct song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
} song;

void add_song(song music_library[], int *num_songs);
void remove_song(song music_library[], int *num_songs);
void search_song(song music_library[], int num_songs);
void display_library(song music_library[], int num_songs);

int main() {
    song music_library[MAX_SONGS];
    int num_songs = 0;
    int choice;

    while(1) {
        printf("\n*************************\n");
        printf("Music Library Management System\n");
        printf("*************************\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Search Song\n");
        printf("4. Display Library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(music_library, &num_songs);
                break;
            case 2:
                remove_song(music_library, &num_songs);
                break;
            case 3:
                search_song(music_library, num_songs);
                break;
            case 4:
                display_library(music_library, num_songs);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input. Try Again.\n");
        }
    }

    return 0;
}

void add_song(song music_library[], int *num_songs) {
    if (*num_songs == MAX_SONGS) {
        printf("Music Library is Full. Unable to Add Song.\n");
        return;
    }

    song new_song;
    printf("\nEnter Song Title: ");
    scanf("%s", new_song.title);
    printf("Enter Artist Name: ");
    scanf("%s", new_song.artist);
    printf("Enter Album Name: ");
    scanf("%s", new_song.album);
    printf("Enter Release Year: ");
    scanf("%d", &new_song.year);

    music_library[*num_songs] = new_song;
    (*num_songs)++;

    printf("Song Added Successfully!\n");
}

void remove_song(song music_library[], int *num_songs) {
    if (*num_songs == 0) {
        printf("Music Library is Empty. Unable to Remove Song.\n");
        return;
    }

    char title[MAX_LENGTH];
    printf("\nEnter Song Title to Remove: ");
    scanf("%s", title);

    for (int i = 0; i < *num_songs; i++) {
        if (strcmp(music_library[i].title, title) == 0) {
            for (int j = i; j < (*num_songs - 1); j++) {
                music_library[j] = music_library[j+1];
            }

            (*num_songs)--;
            printf("Song Removed Successfully!\n");
            return;
        }
    }

    printf("Song Not Found in Library.\n");
}

void search_song(song music_library[], int num_songs) {
    if (num_songs == 0) {
        printf("Music Library is Empty. Unable to Search for Song.\n");
        return;
    }

    char title[MAX_LENGTH];
    printf("\nEnter Song Title to Search: ");
    scanf("%s", title);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(music_library[i].title, title) == 0) {
            found = 1;
            printf("\nSong Found!\n");
            printf("Title: %s\n", music_library[i].title);
            printf("Artist: %s\n", music_library[i].artist);
            printf("Album: %s\n", music_library[i].album);
            printf("Release Year: %d\n", music_library[i].year);
            break;
        }
    }

    if (!found) {
        printf("Song Not Found in Library.\n");
    }
}

void display_library(song music_library[], int num_songs) {
    if (num_songs == 0) {
        printf("Music Library is Empty.\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < num_songs; i++) {
        printf("Song %d\n", i+1);
        printf("Title: %s\n", music_library[i].title);
        printf("Artist: %s\n", music_library[i].artist);
        printf("Album: %s\n", music_library[i].album);
        printf("Release Year: %d\n", music_library[i].year);
        printf("\n");
    }
}