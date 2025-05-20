//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_TRACK_NUMBER 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int track_number;
} Song;

int main() {
    Song library[100];
    int num_songs = 0;
    char choice;

    printf("Welcome to the Music Library Management System!\n");
    printf("Please choose an option:\n");
    printf("1. Add a song\n");
    printf("2. Display all songs\n");
    printf("3. Search for a song\n");
    printf("4. Exit\n");

    scanf("%c", &choice);

    switch(choice) {
        case '1':
            printf("Enter song title: ");
            scanf("%s", library[num_songs].title);
            printf("Enter artist: ");
            scanf("%s", library[num_songs].artist);
            printf("Enter album: ");
            scanf("%s", library[num_songs].album);
            printf("Enter genre: ");
            scanf("%s", library[num_songs].genre);
            printf("Enter track number: ");
            scanf("%d", &library[num_songs].track_number);
            num_songs++;
            printf("Song added successfully!\n");
            break;
        case '2':
            printf("Songs in the library:\n");
            for(int i=0; i<num_songs; i++) {
                printf("%d. %s - %s - %s - %s - %d\n", i+1, library[i].title, library[i].artist, library[i].album, library[i].genre, library[i].track_number);
            }
            break;
        case '3':
            printf("Enter song title to search: ");
            char search_title[MAX_TITLE_LENGTH];
            scanf("%s", search_title);
            for(int i=0; i<num_songs; i++) {
                if(strcmp(library[i].title, search_title) == 0) {
                    printf("Song found:\n");
                    printf("Title: %s\n", library[i].title);
                    printf("Artist: %s\n", library[i].artist);
                    printf("Album: %s\n", library[i].album);
                    printf("Genre: %s\n", library[i].genre);
                    printf("Track Number: %d\n", library[i].track_number);
                }
            }
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option!\n");
    }

    return 0;
}