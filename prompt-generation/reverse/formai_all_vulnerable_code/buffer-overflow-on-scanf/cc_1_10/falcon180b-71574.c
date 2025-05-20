//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_ARTIST_NAME_LENGTH 50
#define MAX_ALBUM_NAME_LENGTH 50

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char artist_name[MAX_ARTIST_NAME_LENGTH];
    char album_name[MAX_ALBUM_NAME_LENGTH];
} MusicFile;

void addMusicFile(MusicFile* musicLibrary, int numFiles, MusicFile file) {
    if (numFiles >= MAX_MUSIC_FILES) {
        printf("Library is full. Cannot add anymore files.\n");
        return;
    }
    strcpy(musicLibrary[numFiles].file_name, file.file_name);
    strcpy(musicLibrary[numFiles].artist_name, file.artist_name);
    strcpy(musicLibrary[numFiles].album_name, file.album_name);
    numFiles++;
}

void displayMusicFiles(MusicFile* musicLibrary, int numFiles) {
    printf("Music Library:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%d. %s by %s (%s)\n", i+1, musicLibrary[i].file_name, musicLibrary[i].artist_name, musicLibrary[i].album_name);
    }
}

int main() {
    MusicFile musicLibrary[MAX_MUSIC_FILES];
    int numFiles = 0;
    char choice;
    do {
        printf("Music Library Management System\n");
        printf("1. Add music file\n");
        printf("2. Display music files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1': {
                printf("Enter file name: ");
                scanf("%s", musicLibrary[numFiles].file_name);
                printf("Enter artist name: ");
                scanf("%s", musicLibrary[numFiles].artist_name);
                printf("Enter album name: ");
                scanf("%s", musicLibrary[numFiles].album_name);
                addMusicFile(musicLibrary, numFiles, musicLibrary[numFiles]);
                break;
            }
            case '2': {
                displayMusicFiles(musicLibrary, numFiles);
                break;
            }
            case '3': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while (choice!= '3');
    return 0;
}