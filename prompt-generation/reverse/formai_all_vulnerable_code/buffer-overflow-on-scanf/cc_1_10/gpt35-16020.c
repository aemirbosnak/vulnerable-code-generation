//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_SONGS 100

typedef struct song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int trackNumber;
    int year;
    float duration;
} Song;

void printSong(Song s);
void addSong(Song playlist[], int* numSongs);
void removeSong(Song playlist[], int* numSongs);
void searchSongs(Song playlist[], int numSongs);

int main() {
    Song playlist[MAX_SONGS];
    int numSongs = 0;

    int choice = 0;
    do {
        printf("\n\nMusic Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong(playlist, &numSongs);
                break;
            case 2:
                removeSong(playlist, &numSongs);
                break;
            case 3:
                searchSongs(playlist, numSongs);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void printSong(Song s) {
    printf("%s\n", s.title);
    printf("Artist: %s\n", s.artist);
    printf("Album: %s\n", s.album);
    printf("Track Number: %d\n", s.trackNumber);
    printf("Year: %d\n", s.year);
    printf("Duration: %.2f\n", s.duration);
}

void addSong(Song playlist[], int* numSongs) {
    Song s;

    printf("Enter song title: ");
    scanf("%s", s.title);
    printf("Enter artist: ");
    scanf("%s", s.artist);
    printf("Enter album: ");
    scanf("%s", s.album);
    printf("Enter track number: ");
    scanf("%d", &s.trackNumber);
    printf("Enter year: ");
    scanf("%d", &s.year);
    printf("Enter duration (in minutes): ");
    scanf("%f", &s.duration);

    playlist[*numSongs] = s;
    (*numSongs)++;
}

void removeSong(Song playlist[], int* numSongs) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the song you want to remove: ");
    scanf("%s", title);

    for(int i = 0; i < *numSongs; i++) {
        if(strcmp(playlist[i].title, title) == 0) {
            for(int j = i; j < *numSongs - 1; j++) {
                playlist[j] = playlist[j+1];
            }
            (*numSongs)--;
            break;
        }
    }
}

void searchSongs(Song playlist[], int numSongs) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the song you want to search for: ");
    scanf("%s", title);

    for(int i = 0; i < numSongs; i++) {
        if(strcmp(playlist[i].title, title) == 0) {
            printSong(playlist[i]);
            return;
        }
    }

    printf("Song not found!\n");
}