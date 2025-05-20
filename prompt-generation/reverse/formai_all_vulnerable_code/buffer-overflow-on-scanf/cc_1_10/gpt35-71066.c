//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 1000

typedef struct{
    char title[50];
    char artist[50];
    char genre[20];
    int year;
    float duration;
}Song;

typedef struct{
    char name[50];
    int num_songs;
    Song songs[MAX_SONGS];
}Album;

typedef struct{
    Album *albums[MAX_ALBUMS];
    int num_albums;
}Library;

void add_song(Album *album){
    Song new_song;

    printf("\nEnter the song title: ");
    scanf("%s", new_song.title);

    printf("Enter the artist name: ");
    scanf("%s", new_song.artist);

    printf("Enter the genre: ");
    scanf("%s", new_song.genre);

    printf("Enter the year: ");
    scanf("%d", &(new_song.year));

    printf("Enter the duration: ");
    scanf("%f", &(new_song.duration));

    album->songs[album->num_songs] = new_song;
    album->num_songs++;
}

void add_album(Library *lib){
    Album *new_album = malloc(sizeof(Album));

    printf("\nEnter the album name: ");
    scanf("%s", new_album->name);

    new_album->num_songs = 0;

    char add_song_choice;
    printf("Would you like to add a song to this album? (y/n): ");
    scanf(" %c", &add_song_choice);

    while(add_song_choice == 'y'){
        add_song(new_album);
        printf("Would you like to add another song? (y/n): ");
        scanf(" %c", &add_song_choice);
    }

    lib->albums[lib->num_albums] = new_album;
    lib->num_albums++;
}

void print_song(Song *song){
    printf("%s - %s (%d) [%s] - %.2f minutes\n", song->artist, song->title, song->year, song->genre, song->duration);
}

void print_album(Album *album){
    printf("\n%s (%d songs):\n", album->name, album->num_songs);
    for(int i=0; i<album->num_songs; i++){
        print_song(&(album->songs[i]));
    }
}

void print_library(Library *lib){
    printf("\nMY MUSIC LIBRARY (%d albums):\n", lib->num_albums);
    for(int i=0; i<lib->num_albums; i++){
        print_album(lib->albums[i]);
    }
}

int main(){
    Library my_library;
    my_library.num_albums = 0;

    printf("Welcome to My Music Library!\n\n");

    char user_choice;
    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Add an album\n");
        printf("2. View my library\n");
        printf("3. Quit\n");
        printf("Your choice: ");
        scanf(" %c", &user_choice);

        switch(user_choice){
            case '1':
                add_album(&my_library);
                break;
            case '2':
                print_library(&my_library);
                break;
            case '3':
                printf("\nThank you for using My Music Library! Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}