//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_FILES 10

struct MusicFile {
    char name[50];
    char artist[50];
    char genre[50];
};

struct MusicFile musicFiles[MAX_NUM_OF_FILES];
int numOfFiles = 0;

void addMusicFile(char *name, char *artist, char *genre) {
    int i;
    for (i = 0; i < numOfFiles; i++) {
        if (strcmp(musicFiles[i].name, name) == 0) {
            printf("File '%s' already exists.\n", name);
            return;
        }
    }
    strcpy(musicFiles[numOfFiles].name, name);
    strcpy(musicFiles[numOfFiles].artist, artist);
    strcpy(musicFiles[numOfFiles].genre, genre);
    numOfFiles++;
}

void deleteMusicFile(char *name) {
    int i;
    for (i = 0; i < numOfFiles; i++) {
        if (strcmp(musicFiles[i].name, name) == 0) {
            int j;
            for (j = i; j < numOfFiles - 1; j++) {
                musicFiles[j] = musicFiles[j + 1];
            }
            numOfFiles--;
            break;
        }
    }
}

void updateMusicFile(char *name, char *artist, char *genre) {
    int i;
    for (i = 0; i < numOfFiles; i++) {
        if (strcmp(musicFiles[i].name, name) == 0) {
            strcpy(musicFiles[i].artist, artist);
            strcpy(musicFiles[i].genre, genre);
            break;
        }
    }
}

void displayLibrary() {
    int i;
    for (i = 0; i < numOfFiles; i++) {
        printf("File '%s' by %s (%s)\n", musicFiles[i].name, musicFiles[i].artist, musicFiles[i].genre);
    }
}

int main() {
    int choice;
    char *name, *artist, *genre;
    while (1) {
        printf("Music Library Management System\n");
        printf("1. Add a new file\n");
        printf("2. Delete a file\n");
        printf("3. Update a file\n");
        printf("4. Display library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter artist: ");
                scanf("%s", artist);
                printf("Enter genre: ");
                scanf("%s", genre);
                addMusicFile(name, artist, genre);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", name);
                deleteMusicFile(name);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter artist: ");
                scanf("%s", artist);
                printf("Enter genre: ");
                scanf("%s", genre);
                updateMusicFile(name, artist, genre);
                break;
            case 4:
                displayLibrary();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}