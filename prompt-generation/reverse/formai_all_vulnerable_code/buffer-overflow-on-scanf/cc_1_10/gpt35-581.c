//FormAI DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for music library data
struct MusicLibrary{
    char song[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
}music[100];

//function to add new song to the library
void add_song(int i){
    printf("\nEnter Song: ");
    scanf("%s", &music[i].song);
    printf("\nEnter Artist: ");
    scanf("%s", &music[i].artist);
    printf("\nEnter Album: ");
    scanf("%s", &music[i].album);
    printf("\nEnter Year: ");
    scanf("%d", &music[i].year);
    printf("\nEnter Genre: ");
    scanf("%s", &music[i].genre);
    printf("\nNew song added successfully!!\n");
}

//function to search song by artist name
void search_song_by_artist(char artist[50], int count){
    int flag=0;
    printf("\nSearch Results:\n");
    for(int i=0; i<count; i++){
        if(strcmp(music[i].artist,artist)==0){
            flag = 1;
            printf("\nSong: %s\n", music[i].song);
            printf("Artist: %s\n", music[i].artist);
            printf("Album: %s\n", music[i].album);
            printf("Year: %d\n", music[i].year);
            printf("Genre: %s\n", music[i].genre);
        }
    }
    if(flag==0){
        printf("\nNo matching records found!!\n");
    }
}

//function to display all songs in the library
void display_songs(int count){
    if(count==0){
        printf("\nNo songs in the library!!\n");
    }
    else{
        printf("\nSong\tArtist\tAlbum\tYear\tGenre\n");
        for(int i=0; i<count; i++){
            printf("%s\t%s\t%s\t%d\t%s\n", music[i].song, music[i].artist, music[i].album, music[i].year, music[i].genre);
        }
    }
}

int main(){
    int choice, count=0;
    char artist_name[50];
    while(1){
        printf("\n----Music Library Management System----\n\n");
        printf("1. Add Song\n");
        printf("2. Search Song by Artist\n");
        printf("3. Display All Songs\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_song(count);
                    count++;
                    break;
            case 2: printf("\nEnter Artist Name: ");
                    scanf("%s", &artist_name);
                    search_song_by_artist(artist_name, count);
                    break;
            case 3: display_songs(count);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice!!\n");
        }
    }
    return 0;
}