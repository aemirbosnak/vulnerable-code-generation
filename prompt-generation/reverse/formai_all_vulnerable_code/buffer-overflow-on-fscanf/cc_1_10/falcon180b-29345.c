//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 50
#define MAX_YEAR 4

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    int year;
} Song;

int read_songs(Song songs[]) {
    FILE *fp;
    int count = 0;

    fp = fopen("songs.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open songs file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %s %d\n", songs[count].title, songs[count].artist, songs[count].album, songs[count].genre, &songs[count].year)!= EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

void display_songs(Song songs[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%s - %s\n", songs[i].title, songs[i].artist);
    }
}

void search_songs(Song songs[], int count, char *query) {
    int i, j;

    printf("Searching for songs...\n");
    for (i = 0; i < count; i++) {
        for (j = 0; j < strlen(query); j++) {
            if (tolower(songs[i].title[j])!= tolower(query[j]) && tolower(songs[i].artist[j])!= tolower(query[j])) {
                break;
            }
        }
        if (j == strlen(query)) {
            printf("%s - %s\n", songs[i].title, songs[i].artist);
        }
    }
}

int main() {
    Song songs[MAX_SONGS];
    int count;

    count = read_songs(songs);
    if (count == 0) {
        printf("No songs found in the songs file.\n");
        exit(1);
    }

    while (1) {
        printf("\n1. Display all songs\n2. Search for a song\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &count);

        switch (count) {
        case 1:
            display_songs(songs, count);
            break;
        case 2:
            printf("Enter the song title or artist: ");
            scanf("%s", songs[0].title);
            search_songs(songs, count, songs[0].title);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}