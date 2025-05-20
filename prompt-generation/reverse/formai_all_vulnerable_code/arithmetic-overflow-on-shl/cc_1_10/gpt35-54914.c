//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* artist;
    char* title;
    char* album;
    int year;
} Song;

// Function to extract metadata from MP3 file
Song extract_metadata(char* filename) {
    Song song;
    song.artist = NULL;
    song.title = NULL;
    song.album = NULL;
    song.year = 0;

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file \"%s\".\n", filename);
        return song;
    }

    // Check if file is an MP3
    fseek(fp, 0, SEEK_SET);
    char header[4];
    fread(header, 1, 4, fp);
    if (strncmp(header, "ID3", 3) != 0) {
        printf("Error: File \"%s\" is not an MP3 file.\n", filename);
        fclose(fp);
        return song;
    }

    // Read tags from MP3
    fseek(fp, 10, SEEK_SET);
    char buffer[4];
    fread(buffer, 1, 4, fp);
    int tag_size = ((unsigned char)buffer[0] << 21) | ((unsigned char)buffer[1] << 14) | ((unsigned char)buffer[2] << 7) | (unsigned char)buffer[3];

    fseek(fp, 10 + tag_size, SEEK_SET);
    while (!feof(fp)) {
        fread(header, 1, 4, fp);
        if (strncmp(header, "TIT2", 4) == 0) {
            fread(buffer, 1, 4, fp);
            int size = ((unsigned char)buffer[0] << 24) | ((unsigned char)buffer[1] << 16) | ((unsigned char)buffer[2] << 8) | (unsigned char)buffer[3];
            song.title = malloc(size+1);
            fread(song.title, 1, size, fp);
            song.title[size] = '\0';
        }
        else if (strncmp(header, "TPE1", 4) == 0) {
            fread(buffer, 1, 4, fp);
            int size = ((unsigned char)buffer[0] << 24) | ((unsigned char)buffer[1] << 16) | ((unsigned char)buffer[2] << 8) | (unsigned char)buffer[3];
            song.artist = malloc(size+1);
            fread(song.artist, 1, size, fp);
            song.artist[size] = '\0';
        }
        else if (strncmp(header, "TALB", 4) == 0) {
            fread(buffer, 1, 4, fp);
            int size = ((unsigned char)buffer[0] << 24) | ((unsigned char)buffer[1] << 16) | ((unsigned char)buffer[2] << 8) | (unsigned char)buffer[3];
            song.album = malloc(size+1);
            fread(song.album, 1, size, fp);
            song.album[size] = '\0';
        }
        else if (strncmp(header, "TYER", 4) == 0) {
            fread(buffer, 1, 4, fp);
            int size = ((unsigned char)buffer[0] << 24) | ((unsigned char)buffer[1] << 16) | ((unsigned char)buffer[2] << 8) | (unsigned char)buffer[3];
            char year_str[5];
            fread(year_str, 1, size, fp);
            year_str[size] = '\0';
            song.year = atoi(year_str);
        }
        else {
            fread(buffer, 1, 4, fp);
            int size = ((unsigned char)buffer[0] << 24) | ((unsigned char)buffer[1] << 16) | ((unsigned char)buffer[2] << 8) | (unsigned char)buffer[3];
            fseek(fp, size, SEEK_CUR);
        }
    }

    fclose(fp);
    return song;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: Please specify an MP3 file to extract metadata from.\n");
        return 1;
    }

    Song song = extract_metadata(argv[1]);

    if (song.title) {
        printf("Title: %s\n", song.title);
    }
    if (song.artist) {
        printf("Artist: %s\n", song.artist);
    }
    if (song.album) {
        printf("Album: %s\n", song.album);
    }
    if (song.year) {
        printf("Year: %d\n", song.year);
    }

    free(song.title);
    free(song.artist);
    free(song.album);

    return 0;
}