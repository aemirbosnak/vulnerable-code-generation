//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
} Song;

Song songs[MAX_SONGS];
int num_songs;

void add_song() {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];

    printf("Enter song name: ");
    scanf("%s", name);

    printf("Enter song artist: ");
    scanf("%s", artist);

    printf("Enter song album: ");
    scanf("%s", album);

    strcpy(songs[num_songs].name, name);
    strcpy(songs[num_songs].artist, artist);
    strcpy(songs[num_songs].album, album);

    num_songs++;
}

void display_songs() {
    int i;

    printf("Song List:\n");

    for (i = 0; i < num_songs; i++) {
        printf("%d. %s - %s - %s\n", i+1, songs[i].name, songs[i].artist, songs[i].album);
    }
}

int main() {
    int choice;

    do {
        printf("Music Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_songs();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}