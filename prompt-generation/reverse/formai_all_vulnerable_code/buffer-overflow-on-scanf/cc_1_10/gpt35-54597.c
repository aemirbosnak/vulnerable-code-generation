//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song{
    char title[100];
    char artist[100];
    char album[100];
    int year;
}song;

void add_song(song songs[],int *size){
    printf("Enter song title: ");
    scanf(" %[^\n]s",songs[*size].title);
    printf("Enter song artist: ");
    scanf(" %[^\n]s",songs[*size].artist);
    printf("Enter song album: ");
    scanf(" %[^\n]s",songs[*size].album);
    printf("Enter song year: ");
    scanf("%d",&songs[*size].year);
    *size += 1;
}

void display_songs(song songs[],int size){
    for(int i=0;i<size;i++){
        printf("Title: %s\n",songs[i].title);
        printf("Artist: %s\n",songs[i].artist);
        printf("Album: %s\n",songs[i].album);
        printf("Year: %d\n\n",songs[i].year);
    }
}

void search_song(song songs[],int size,char search_criteria[]){
    int found = 0;
    for(int i=0;i<size;i++){
        if(strstr(songs[i].title,search_criteria)!=NULL || 
           strstr(songs[i].artist,search_criteria)!=NULL || 
           strstr(songs[i].album,search_criteria)!=NULL){
            printf("Title: %s\n",songs[i].title);
            printf("Artist: %s\n",songs[i].artist);
            printf("Album: %s\n",songs[i].album);
            printf("Year: %d\n\n",songs[i].year);
            found = 1;
        }
    }
    if(!found){
        printf("No songs found.\n");
    }
}

int main(){
    song songs[100];
    int size = 0;

    printf("Welcome to the Music Library Management System!\n");

    while(1){
        printf("\n");
        printf("Enter 1 to add a song\n");
        printf("Enter 2 to display all songs\n");
        printf("Enter 3 to search for a song\n");
        printf("Enter 4 to exit\n");

        int option;
        scanf("%d",&option);

        switch(option){
            case 1:
                add_song(songs,&size);
                printf("Song added successfully!\n");
                break;
            case 2:
                display_songs(songs,size);
                break;
            case 3:
                printf("Enter search criteria: ");
                char search_criteria[100];
                scanf(" %[^\n]s",search_criteria);
                search_song(songs,size,search_criteria);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}