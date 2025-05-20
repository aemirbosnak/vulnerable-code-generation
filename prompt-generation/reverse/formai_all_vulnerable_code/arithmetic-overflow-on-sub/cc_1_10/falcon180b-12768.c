//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int duration;
} Song;

Song songs[MAX_SONGS];
int numSongs;

void addSong() {
    printf("Enter the title of the song: ");
    scanf("%s", songs[numSongs].title);

    printf("Enter the artist of the song: ");
    scanf("%s", songs[numSongs].artist);

    printf("Enter the duration of the song (in seconds): ");
    scanf("%d", &songs[numSongs].duration);

    numSongs++;
}

void playSong(int songIndex) {
    printf("Playing %s by %s...\n", songs[songIndex].title, songs[songIndex].artist);
    printf("Duration: %d seconds\n", songs[songIndex].duration);
}

void playlist() {
    printf("Your playlist:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s by %s - %d seconds\n", i+1, songs[i].title, songs[i].artist, songs[i].duration);
    }
}

int main() {
    numSongs = 0;

    while (numSongs < MAX_SONGS) {
        printf("What would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Play a song\n");
        printf("3. View your playlist\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                printf("Enter the index of the song you want to play (1-%d): ", numSongs-1);
                int songIndex;
                scanf("%d", &songIndex);
                playSong(songIndex-1);
                break;
            case 3:
                playlist();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}