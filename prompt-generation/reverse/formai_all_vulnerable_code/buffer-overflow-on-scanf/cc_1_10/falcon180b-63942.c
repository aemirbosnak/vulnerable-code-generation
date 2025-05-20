//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_ARTIST_NAME_LENGTH 50
#define MAX_ALBUM_NAME_LENGTH 100

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char artistName[MAX_ARTIST_NAME_LENGTH];
    char albumName[MAX_ALBUM_NAME_LENGTH];
} MusicFile;

void printMenu() {
    printf("Music Library Management System\n");
    printf("1. Add music file\n");
    printf("2. Remove music file\n");
    printf("3. Search music file\n");
    printf("4. Display all music files\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    int numOfMusicFiles = 0;
    MusicFile musicFiles[MAX_MUSIC_FILES];
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(numOfMusicFiles >= MAX_MUSIC_FILES) {
                    printf("Library is full!\n");
                } else {
                    printf("Enter file name: ");
                    scanf("%s", musicFiles[numOfMusicFiles].fileName);
                    printf("Enter artist name: ");
                    scanf("%s", musicFiles[numOfMusicFiles].artistName);
                    printf("Enter album name: ");
                    scanf("%s", musicFiles[numOfMusicFiles].albumName);
                    numOfMusicFiles++;
                }
                break;
            case 2:
                printf("Enter file name to remove: ");
                scanf("%s", musicFiles[numOfMusicFiles - 1].fileName);
                numOfMusicFiles--;
                break;
            case 3:
                printf("Enter file name to search: ");
                scanf("%s", musicFiles[numOfMusicFiles - 1].fileName);
                break;
            case 4:
                for(int i = 0; i < numOfMusicFiles; i++) {
                    printf("%d. File name: %s, Artist name: %s, Album name: %s\n", i+1, musicFiles[i].fileName, musicFiles[i].artistName, musicFiles[i].albumName);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);
    
    return 0;
}