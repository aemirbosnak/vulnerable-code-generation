//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_FILES 1000
#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_YEAR_LENGTH 4

typedef struct {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char year[MAX_YEAR_LENGTH];
} MusicFile;

int main() {
    int numMusicFiles;
    MusicFile musicFiles[MAX_MUSIC_FILES];
    char input[1024];

    printf("Enter the number of music files: ");
    scanf("%d", &numMusicFiles);

    for (int i = 0; i < numMusicFiles; i++) {
        printf("Enter the name of the music file: ");
        scanf("%s", musicFiles[i].name);

        printf("Enter the artist of the music file: ");
        scanf("%s", musicFiles[i].artist);

        printf("Enter the album of the music file: ");
        scanf("%s", musicFiles[i].album);

        printf("Enter the genre of the music file: ");
        scanf("%s", musicFiles[i].genre);

        printf("Enter the year of the music file: ");
        scanf("%s", musicFiles[i].year);
    }

    printf("Enter a search query: ");
    scanf("%s", input);

    int numResults = 0;
    for (int i = 0; i < numMusicFiles; i++) {
        if (strstr(musicFiles[i].name, input)!= NULL ||
            strstr(musicFiles[i].artist, input)!= NULL ||
            strstr(musicFiles[i].album, input)!= NULL ||
            strstr(musicFiles[i].genre, input)!= NULL ||
            strstr(musicFiles[i].year, input)!= NULL) {

            printf("Music file %d:\n", i + 1);
            printf("Name: %s\n", musicFiles[i].name);
            printf("Artist: %s\n", musicFiles[i].artist);
            printf("Album: %s\n", musicFiles[i].album);
            printf("Genre: %s\n", musicFiles[i].genre);
            printf("Year: %s\n", musicFiles[i].year);

            numResults++;
        }
    }

    if (numResults == 0) {
        printf("No results found.\n");
    }

    return 0;
}