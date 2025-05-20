//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100
#define MAX_SONGS 100

typedef struct Song{
    char songName[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
}Song;

Song playlist[MAX_SONGS];
int numSongs = 0;

void addSong(){
    Song newSong;
    printf("Enter song name: ");
    scanf("%s", newSong.songName);
    printf("Enter artist name: ");
    scanf("%s", newSong.artist);
    printf("Enter album name: ");
    scanf("%s", newSong.album);

    playlist[numSongs++] = newSong;
}

void displayPlaylist(){
    if(numSongs == 0){
        printf("Playlist is currently empty.\n");
        return;
    }

    printf("\t----------------------\n");
    printf("\t| %-20s|\n", "SONG NAME");
    printf("\t----------------------\n");
    for(int i=0; i<numSongs; i++){
        printf("\t| %-20s|\n", playlist[i].songName);
    }
    printf("\t----------------------\n");
}

void searchSong(){
    char search[MAX_LENGTH];
    printf("Enter a song name to search: ");
    scanf("%s", search);

    int found = 0;
    for(int i=0; i<numSongs; i++){
        if(strcmp(search, playlist[i].songName) == 0){
            printf("\t----------------------\n");
            printf("\t| %-20s|\n", "SONG DETAILS");
            printf("\t----------------------\n");
            printf("\t| %-20s|\n", "Song name:");
            printf("\t| %-20s|\n", playlist[i].songName);
            printf("\t| %-20s|\n", "Artist:");
            printf("\t| %-20s|\n", playlist[i].artist);
            printf("\t| %-20s|\n", "Album:");
            printf("\t| %-20s|\n", playlist[i].album);
            printf("\t----------------------\n");
            found = 1;
            break;
        }
    }

    if(!found){
        printf("The song \"%s\" was not found in the playlist.\n", search);
    }
}

void printMenu(){
    printf("\n");
    printf("\t######################\n");
    printf("\t#  MUSIC LIBRARY     #\n");
    printf("\t######################\n");
    printf("\t| Options:           |\n");
    printf("\t|      1. Add Song   |\n");
    printf("\t|      2. Search Song|\n");
    printf("\t|      3. Show All   |\n");
    printf("\t|      4. Exit       |\n");
    printf("\t|                    |\n");
    printf("\t|      Enter choice: |\n");
    printf("\t######################\n");
    printf("\n");
}

int main(){
    int choice = 0;

    while(choice != 4){
        printMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addSong();
                break;
            case 2:
                searchSong();
                break;
            case 3:
                displayPlaylist();
                break;
            case 4:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}