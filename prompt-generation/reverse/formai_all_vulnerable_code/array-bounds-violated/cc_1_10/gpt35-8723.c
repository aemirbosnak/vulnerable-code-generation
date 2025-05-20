//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the structure of the song
struct Music {
    char title[100];
    char artist[50];
    char album[50];
    int year;
};

int main() {
    // declaration of variables
    int i, n, delete_song;
    char search_song[100];
    struct Music song[100];

    printf("Welcome to the Happy Music Library Management System\n");

    // taking input of number of songs from user
    printf("Enter the number of songs in your library: ");
    scanf("%d", &n);

    // taking input of song details from user
    for(i=0; i<n; i++) {
        printf("\nEnter details of song %d:\n", i+1);
        printf("Title: ");
        scanf(" %[^\n]s", song[i].title);
        printf("Artist: ");
        scanf(" %[^\n]s", song[i].artist);
        printf("Album: ");
        scanf(" %[^\n]s", song[i].album);
        printf("Year: ");
        scanf("%d", &song[i].year);
    }

    // displaying the song list
    printf("\n---------------YOUR SONG LIST-------------\n");
    printf("S.No.   Title                          Artist                      Album                       Year\n");

    for(i=0; i<n; i++) {
        printf("%-7d %-30s %-25s %-25s %d\n", i+1, song[i].title, song[i].artist, song[i].album, song[i].year);
    }

    // getting the title of the song to be searched from user
    printf("\nEnter the title of the song you want to search: ");
    scanf(" %[^\n]s", search_song);

    // search for the song in the list
    for(i=0; i<n; i++) {
        if(strcmp(search_song, song[i].title) == 0) {
            printf("\nSong Found!\n");
            printf("Title: %s\n", song[i].title);
            printf("Artist: %s\n", song[i].artist);
            printf("Album: %s\n", song[i].album);
            printf("Year: %d\n", song[i].year);
            break;
        }
    }

    // deleting the song from the list
    printf("\nEnter the serial number of the song you want to delete: ");
    scanf("%d", &delete_song);
    for(i=delete_song-1; i<n-1; i++) {
        strcpy(song[i].title, song[i+1].title);
        strcpy(song[i].artist, song[i+1].artist);
        strcpy(song[i].album, song[i+1].album);
        song[i].year = song[i+1].year;
    }
    n--;

    // displaying the updated song list
    printf("\n---------------YOUR UPDATED SONG LIST-------------\n");
    printf("S.No.   Title                          Artist                      Album                       Year\n");

    for(i=0; i<n; i++) {
        printf("%-7d %-30s %-25s %-25s %d\n", i+1, song[i].title, song[i].artist, song[i].album, song[i].year);
    }

    printf("\nThank you for using Happy Music Library Management System! Have a great day!\n");

    return 0;
}