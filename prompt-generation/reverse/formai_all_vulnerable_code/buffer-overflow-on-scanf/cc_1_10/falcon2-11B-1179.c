//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    int year;
    char genre[20];
} Song;

void addSong(Song *song, int numOfSongs){
    if(numOfSongs == 0){
        printf("Music library is empty!\n");
        return;
    }
    printf("Enter song details:\n");
    printf("Name: ");
    scanf("%s", song->name);
    printf("Year: ");
    scanf("%d", &song->year);
    printf("Genre: ");
    scanf("%s", song->genre);
    printf("Song added successfully!\n");
}

void removeSong(Song *song, int numOfSongs){
    if(numOfSongs == 0){
        printf("Music library is empty!\n");
        return;
    }
    printf("Enter song name to remove:\n");
    scanf("%s", song->name);
    printf("Song removed successfully!\n");
}

void displaySongs(Song *songs, int numOfSongs){
    if(numOfSongs == 0){
        printf("Music library is empty!\n");
        return;
    }
    printf("Displaying songs in the library:\n");
    for(int i = 0; i < numOfSongs; i++){
        printf("Name: %s\n", songs[i].name);
        printf("Year: %d\n", songs[i].year);
        printf("Genre: %s\n", songs[i].genre);
        printf("\n");
    }
}

int main(){
    Song songs[10];
    int numOfSongs = 0;

    printf("Welcome to the Music Library Management System!\n");
    printf("1. Add Song\n");
    printf("2. Remove Song\n");
    printf("3. Display Songs\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &numOfSongs);

    while(numOfSongs!= 4){
        switch(numOfSongs){
            case 1:
                addSong(&songs[numOfSongs], numOfSongs);
                break;
            case 2:
                removeSong(&songs[numOfSongs], numOfSongs);
                break;
            case 3:
                displaySongs(&songs[numOfSongs], numOfSongs);
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Enter your choice: ");
        scanf("%d", &numOfSongs);
    }
    printf("Thank you for using the Music Library Management System!\n");
    return 0;
}