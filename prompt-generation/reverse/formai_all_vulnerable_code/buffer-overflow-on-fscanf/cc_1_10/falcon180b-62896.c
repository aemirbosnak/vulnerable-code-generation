//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_YEAR_LENGTH 4
#define MAX_TRACK_NUMBER_LENGTH 3
#define MAX_FILE_PATH_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH + 1];
    char artist[MAX_ARTIST_LENGTH + 1];
    char album[MAX_ALBUM_LENGTH + 1];
    char genre[MAX_GENRE_LENGTH + 1];
    char year[MAX_YEAR_LENGTH + 1];
    char track_number[MAX_TRACK_NUMBER_LENGTH + 1];
    char file_path[MAX_FILE_PATH_LENGTH + 1];
} Music;

void read_music_file(Music* music) {
    FILE* file = fopen("music.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open music file.\n");
        exit(1);
    }

    fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", music->title, music->artist, music->album, music->genre, music->year, music->track_number, music->file_path);

    fclose(file);
}

void write_music_file(const Music* music) {
    FILE* file = fopen("music.txt", "w");

    if (file == NULL) {
        printf("Error: Could not open music file for writing.\n");
        exit(1);
    }

    fprintf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", music->title, music->artist, music->album, music->genre, music->year, music->track_number, music->file_path);

    fclose(file);
}

int main() {
    Music music;

    read_music_file(&music);

    printf("Title: %s\n", music.title);
    printf("Artist: %s\n", music.artist);
    printf("Album: %s\n", music.album);
    printf("Genre: %s\n", music.genre);
    printf("Year: %s\n", music.year);
    printf("Track Number: %s\n", music.track_number);
    printf("File Path: %s\n", music.file_path);

    return 0;
}