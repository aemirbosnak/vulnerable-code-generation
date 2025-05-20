//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LEN 100

typedef struct {
    char title[MAX_LEN];
    char artist[MAX_LEN];
    char album[MAX_LEN];
} Song;

Song songs[MAX_SONGS];
int count = 0;

void addSong() {
    printf("Enter the song title: ");
    scanf("%s", songs[count].title);

    printf("Enter the artist name: ");
    scanf("%s", songs[count].artist);

    printf("Enter the album name: ");
    scanf("%s", songs[count].album);

    count++;
}

void displaySongs() {
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s from %s\n", i+1, songs[i].title, songs[i].artist, songs[i].album);
    }
}

void searchSong() {
    char search[MAX_LEN];
    printf("Enter the song title to search for: ");
    scanf("%s", search);

    for (int i = 0; i < count; i++) {
        if (strcmp(songs[i].title, search) == 0) {
            printf("%s by %s from %s\n", songs[i].title, songs[i].artist, songs[i].album);
        }
    }
}

int main() {
    count = 0;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}