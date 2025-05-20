//FormAI DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure for the music library
typedef struct{
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    int duration;
} Song;

Song createSong(char title[], char artist[], int duration){
    Song newSong;
    strcpy(newSong.title, title);
    strcpy(newSong.artist, artist);
    newSong.duration = duration;
    return newSong;
}

void printSong(Song s){
    printf("%s by %s (%d seconds)\n", s.title, s.artist, s.duration);
}

int main(){
    int option, i, numSongs = 0;
    Song musicLibrary[MAX_SIZE], newSong;

    printf("Welcome to the Music Library Management System!\n");

    do{
        printf("\nOptions:\n");
        printf("1. Add a Song to the Library\n");
        printf("2. View all Songs in the Library\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                // Add a Song to the Library
                if(numSongs >= MAX_SIZE){
                    printf("The library is full!\n");
                    break;
                }
                printf("\nEnter the title of the song: ");
                scanf("%s", newSong.title);
                printf("Enter the artist of the song: ");
                scanf("%s", newSong.artist);
                printf("Enter the duration of the song (in seconds): ");
                scanf("%d", &newSong.duration);
                musicLibrary[numSongs] = newSong;
                numSongs++;
                printf("Song added to the library!\n");
                break;
            case 2:
                // View all Songs in the Library
                printf("\n");
                if(numSongs == 0){
                    printf("The library is empty!\n");
                }
                else{
                    for(i = 0; i < numSongs; i++){
                        printf("%d. ", i+1);
                        printSong(musicLibrary[i]);
                    }
                }
                break;
            case 3:
                // Exit
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid Option! Please Try Again.\n");
        }
    } while(option != 3);

    return 0;
}