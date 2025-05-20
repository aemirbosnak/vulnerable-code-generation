//FormAI DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining our music library with struct
struct music_library{
    char name[100];
    char artist[100];
    char album[100];
    int release_year;
    int rating;
};

//Global variable to keep track of number of songs in our library
int total_songs = 0;

//Function to add a new song to our library
void add_song(struct music_library library[]){
    printf("\nEnter song name: ");
    scanf("%s", library[total_songs].name);
    printf("Enter artist name: ");
    scanf("%s", library[total_songs].artist);
    printf("Enter album name: ");
    scanf("%s", library[total_songs].album);
    printf("Enter release year: ");
    scanf("%d", &library[total_songs].release_year);
    printf("Enter rating between 1-5: ");
    scanf("%d", &library[total_songs].rating);

    total_songs++;
}

//Function to display all songs in our library
void display_library(struct music_library library[]){
    if(total_songs == 0){
        printf("No songs in library\n");
        return;
    }

    printf("\n%-30s%-30s%-30s%-18s%-10s\n", "SONG NAME", "ARTIST", "ALBUM", "RELEASE YEAR", "RATING");
    for(int i = 0; i < total_songs; i++){
        printf("%-30s%-30s%-30s%-18d%-10d\n", 
            library[i].name, library[i].artist, library[i].album, library[i].release_year, library[i].rating);
    }
}

//Function to search for songs by artist
void search_artist(struct music_library library[]){
    char search_artist[100];
    printf("Enter artist name to search: ");
    scanf("%s", search_artist);

    int found = 0;
    printf("\n%-30s%-30s%-30s%-18s%-10s\n", "SONG NAME", "ARTIST", "ALBUM", "RELEASE YEAR", "RATING");
    for(int i = 0; i < total_songs; i++){
        if(strcmp(library[i].artist, search_artist) == 0){
            printf("%-30s%-30s%-30s%-18d%-10d\n", 
                library[i].name, library[i].artist, library[i].album, library[i].release_year, library[i].rating);
            found = 1;
        }
    }

    if(!found){
        printf("No songs found for artist '%s'\n", search_artist);
    }
}

int main(){
    struct music_library library[100];

    int option;
    do{
        printf("\nChoose an option:\n");
        printf("1. Add new song\n");
        printf("2. Display all songs in library\n");
        printf("3. Search for songs by artist\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                add_song(library);
                break;
            case 2:
                display_library(library);
                break;
            case 3:
                search_artist(library);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option, please try again\n");
                break;
        }

    } while(option != 4);

    return 0;
}