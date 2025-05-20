//FormAI DATASET v1.0 Category: Music Library Management System ; Style: statistical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100

//Defining a structure to hold information of each music
typedef struct{
    char title[50];
    char artist[50];
    char genre[30];
    int duration;
}Music;

//Defining a structure to hold information of the current playlist
typedef struct{
    Music list[MAX_SIZE];
    int size;
}Playlist;

//Function to add a new music to the playlist
void add_music(Playlist *pl, Music m){
    if(pl->size == MAX_SIZE){
        printf("Playlist is full. Cannot add more music.\n");
        return;
    }
    pl->list[pl->size] = m;
    pl->size++;
    printf("Music \"%s\" by %s added to the playlist.\n", m.title, m.artist);
}

//Function to remove a music from the playlist
void remove_music(Playlist *pl, Music m){
    int found = 0;
    for(int i=0; i<pl->size; i++){
        if(strcmp(pl->list[i].title, m.title) == 0 && strcmp(pl->list[i].artist, m.artist) == 0){
            found = 1;
            for(int j=i; j<pl->size - 1; j++){
                pl->list[j] = pl->list[j+1];
            }
            pl->size--;
            printf("Music \"%s\" by %s removed from the playlist.\n", m.title, m.artist);
            break;
        }
    }
    if(!found){
        printf("Music \"%s\" by %s not found in the playlist.\n", m.title, m.artist);
    }
}

//Function to search for music(s) in the playlist by title
void search_music_by_title(Playlist pl, char *title){
    int found = 0;
    for(int i=0; i<pl.size; i++){
        if(strcmp(pl.list[i].title, title) == 0){
            found = 1;
            printf("Title: %s, Artist: %s, Genre: %s, Duration: %d seconds\n", pl.list[i].title, pl.list[i].artist, pl.list[i].genre, pl.list[i].duration);
        }
    }
    if(!found){
        printf("Music with title \"%s\" not found in the playlist.\n", title);
    }
}

//Function to search for music(s) in the playlist by artist
void search_music_by_artist(Playlist pl, char *artist){
    int found = 0;
    for(int i=0; i<pl.size; i++){
        if(strcmp(pl.list[i].artist, artist) == 0){
            found = 1;
            printf("Title: %s, Artist: %s, Genre: %s, Duration: %d seconds\n", pl.list[i].title, pl.list[i].artist, pl.list[i].genre, pl.list[i].duration);
        }
    }
    if(!found){
        printf("Music with artist \"%s\" not found in the playlist.\n", artist);
    }
}

//Function to display all the music(s) in the playlist
void display_all_music(Playlist pl){
    if(pl.size == 0){
        printf("Playlist is empty.\n");
        return;
    }
    printf("All music(s) in the playlist:\n");
    for(int i=0; i<pl.size; i++){
        printf("Title: %s, Artist: %s, Genre: %s, Duration: %d seconds\n", pl.list[i].title, pl.list[i].artist, pl.list[i].genre, pl.list[i].duration);
    }
}

//Driver function to test all the above functions
int main(){
    Playlist pl = {0}; //Initializing a new playlist
    int choice;
    do{
        printf("\n---------Menu---------\n");
        printf("1. Add music to the playlist\n");
        printf("2. Remove music from the playlist\n");
        printf("3. Search music by title\n");
        printf("4. Search music by artist\n");
        printf("5. Display all music(s) in the playlist\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                Music m;
                printf("Enter title: ");
                scanf(" %[^\n]%*c", m.title);
                printf("Enter artist: ");
                scanf(" %[^\n]%*c", m.artist);
                printf("Enter genre: ");
                scanf(" %[^\n]%*c", m.genre);
                printf("Enter duration (in seconds): ");
                scanf("%d", &m.duration);
                add_music(&pl, m);
                break;
            }
            case 2:{
                Music m;
                printf("Enter title: ");
                scanf(" %[^\n]%*c", m.title);
                printf("Enter artist: ");
                scanf(" %[^\n]%*c", m.artist);
                remove_music(&pl, m);
                break;
            }
            case 3:{
                char title[50];
                printf("Enter title to search: ");
                scanf(" %[^\n]%*c", title);
                search_music_by_title(pl, title);
                break;
            }
            case 4:{
                char artist[50];
                printf("Enter artist to search: ");
                scanf(" %[^\n]%*c", artist);
                search_music_by_artist(pl, artist);
                break;
            }
            case 5:{
                display_all_music(pl);
                break;
            }
            case 6:{
                printf("Exiting...");
                break;
            }
            default:{
                printf("Invalid choice. Please try again.\n");
            }
        }
    }while(choice != 6);
    return 0;
}