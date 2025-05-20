//FormAI DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct song{
    char title[50];
    char artist[50];
    char genre[50];
    int duration;
}Song;

void addSong(Song** songs, int* count);
void searchSong(Song** songs, int count);
void displaySongs(Song** songs, int count);
void saveLibrary(Song** songs, int count);

int main(){
    int option, count = 0;
    Song** songs = malloc(100 * sizeof(Song*));

    do {
        printf("\n\n*****C MUSIC LIBRARY MANAGEMENT SYSTEM*****\n");
        printf("1. Add Song\n");
        printf("2. Search Song\n");
        printf("3. Display Songs\n");
        printf("4. Save Library\n");
        printf("0. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                addSong(songs, &count);
                break;
            case 2:
                searchSong(songs, count);
                break;
            case 3:
                displaySongs(songs, count);
                break;
            case 4:
                saveLibrary(songs, count);
                break;
            case 0:
                printf("Thank you!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }

    }while(option != 0);

    free(songs);        
    return 0;
}

void addSong(Song** songs, int* count){
    printf("\n*****ADD SONG*****\n");

    songs[*count] = (Song*)malloc(sizeof(Song));

    printf("Enter Title: ");
    scanf("%s", songs[*count]->title);

    printf("Enter Artist: ");
    scanf("%s", songs[*count]->artist);

    printf("Enter Genre: ");
    scanf("%s", songs[*count]->genre);

    printf("Enter Duration (in seconds): ");
    scanf("%d", &songs[*count]->duration);

    (*count)++;
}

void searchSong(Song** songs, int count){
    printf("\n*****SEARCH SONG*****\n");

    char title[50];
    printf("Enter Title: ");
    scanf("%s", title);

    int flag = 0;
    for(int i=0; i<count; i++){
        if(strcmp(title, songs[i]->title) == 0){
            printf("Song found!\n");
            printf("Title: %s\n", songs[i]->title);
            printf("Artist: %s\n", songs[i]->artist);
            printf("Genre: %s\n", songs[i]->genre);
            printf("Duration: %d seconds\n", songs[i]->duration);
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("Song not found!\n");
    }
}

void displaySongs(Song** songs, int count){
    printf("\n*****DISPLAY SONGS*****\n");

    for(int i=0; i<count; i++){
        printf("Title: %s\n", songs[i]->title);
        printf("Artist: %s\n", songs[i]->artist);
        printf("Genre: %s\n", songs[i]->genre);
        printf("Duration: %d seconds\n", songs[i]->duration);
        printf("*************************\n");
    }
}

void saveLibrary(Song** songs, int count){
    printf("\n*****SAVE LIBRARY*****\n");

    FILE* fp = fopen("songs.txt", "w");

    for(int i=0; i<count; i++){
        fprintf(fp, "%s, %s, %s, %d\n", songs[i]->title, songs[i]->artist, songs[i]->genre, songs[i]->duration);
    }

    fclose(fp);

    printf("Library saved to songs.txt!\n");
}