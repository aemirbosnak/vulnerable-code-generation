//FormAI DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 1000

struct Song{
    char name[50];
    char artist[50];
    char album[50];
    int year;
    char genre[50];
} library[MAX_SONGS];

struct User{
    char name[50];
    int age;
    char gender[10];
} user;

int num_songs = 0;

void add_song(){
    if(num_songs == MAX_SONGS){
        printf("Library is full! Can't add more songs.\n");
        return;
    }
    printf("Enter the song name: ");
    scanf("%s", library[num_songs].name);
    printf("Enter the artist name: ");
    scanf("%s", library[num_songs].artist);
    printf("Enter the album name: ");
    scanf("%s", library[num_songs].album);
    printf("Enter the release year of the song: ");
    scanf("%d", &library[num_songs].year);
    printf("Enter the genre of the song: ");
    scanf("%s", library[num_songs].genre);
    num_songs++;
    printf("Song added to the library successfully.\n");
}

void display_song(int index){
    printf("\n\nSong %d: \n", index+1);
    printf("Name: %s\n", library[index].name);
    printf("Artist: %s\n", library[index].artist);
    printf("Album: %s\n", library[index].album);
    printf("Year: %d\n", library[index].year);
    printf("Genre: %s\n", library[index].genre);
}

void display_library(){
    if(num_songs == 0){
        printf("Library is empty!\n");
        return;
    }
    for(int i=0; i<num_songs; i++){
        display_song(i);
    }
}

void search_song_by_artist(){
    char artist_name[50];
    int found = 0;
    printf("Enter the artist name: ");
    scanf("%s", artist_name);
    for(int i=0; i<num_songs; i++){
        if(strcmp(library[i].artist, artist_name) == 0){
            display_song(i);
            found = 1;
        }
    }
    if(found == 0){
        printf("\nNo songs found for the artist '%s'.\n", artist_name);
    }
}

void search_song_by_name(){
    char song_name[50];
    int found = 0;
    printf("Enter the song name: ");
    scanf("%s", song_name);
    for(int i=0; i<num_songs; i++){
        if(strcmp(library[i].name, song_name) == 0){
            display_song(i);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nNo songs found with the name '%s'.\n", song_name);
    }
}

int main(){
    int choice = 0;
    printf("Welcome to Music Library Management System!\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your gender (Male/Female): ");
    scanf("%s", user.gender);
    while(choice != 5){
        printf("\n\n%s's Music Library Menu:\n", user.name);
        printf("1. Add a song to the library\n");
        printf("2. Display all songs in the library\n");
        printf("3. Search a song by artist\n");
        printf("4. Search a song by name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                display_library();
                break;
            case 3:
                search_song_by_artist();
                break;
            case 4:
                search_song_by_name();
                break;
            case 5:
                printf("\nThanks for using Music Library Management System! Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}