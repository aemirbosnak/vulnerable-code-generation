//FormAI DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#define MAX_NAME 30
#define MAX_SONGS 100

struct Song{
    char title[MAX_NAME];
    char artist[MAX_NAME];
    char album[MAX_NAME];
    int year;
};

typedef struct Song song;

void add_song(song [], int *);
void print_songs(song [], int *);
void search_song_by_title(song [], int *);
void search_song_by_artist(song [], int *);

int main(){
    song songs[MAX_SONGS];
    int num_of_songs = 0;
    int choice;
    do{
        printf("\nWelcome to Music Library Management System\n");
        printf("==========================================\n");
        printf("1. Add a Song\n");
        printf("2. Print All Songs\n");
        printf("3. Search a Song by Title\n");
        printf("4. Search a Song by Artist\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_song(songs, &num_of_songs); break;
            case 2: print_songs(songs, &num_of_songs); break;
            case 3: search_song_by_title(songs, &num_of_songs); break;
            case 4: search_song_by_artist(songs, &num_of_songs); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }while(choice != 5);

    return 0;
}

void add_song(song songs[], int *num_of_songs){
    if(*num_of_songs == MAX_SONGS){
        printf("The library is full!\n");
        return;
    }
    song s;
    printf("Enter song title: ");
    fflush(stdin);
    fgets(s.title, MAX_NAME, stdin);
    printf("Enter artist name: ");
    fflush(stdin);
    fgets(s.artist, MAX_NAME, stdin);
    printf("Enter album name: ");
    fflush(stdin);
    fgets(s.album, MAX_NAME, stdin);
    printf("Enter song release year: ");
    scanf("%d", &s.year);

    songs[*num_of_songs] = s;
    (*num_of_songs)++;
    printf("%s added successfully!\n", s.title);
}

void print_songs(song songs[], int *num_of_songs){
    if(*num_of_songs == 0){
        printf("The library is empty!\n");
        return;
    }
    printf("S.No\tTitle\t\t\tArtist\t\tAlbum\t\t\tYear\n");
    for(int i=0; i<*num_of_songs; i++){
        printf("%d.\t%s\t\t%s\t\t%s\t\t%d\n", i+1, songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
    }
}

void search_song_by_title(song songs[], int *num_of_songs){
    if(*num_of_songs == 0){
        printf("The library is empty!\n");
        return;
    }
    char title[MAX_NAME];
    printf("Enter song title to search: ");
    fflush(stdin);
    fgets(title, MAX_NAME, stdin);

    int found = 0;
    for(int i=0; i<*num_of_songs; i++){
        if(strcmp(songs[i].title, title) == 0){
            printf("Title\t\t\tArtist\t\tAlbum\t\t\tYear\n");
            printf("%s\t\t%s\t\t%s\t\t%d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("%s not found in library!\n", title);
    }
}

void search_song_by_artist(song songs[], int *num_of_songs){
    if(*num_of_songs == 0){
        printf("The library is empty!\n");
        return;
    }

    char artist[MAX_NAME];
    printf("Enter artist name to search: ");
    fflush(stdin);
    fgets(artist, MAX_NAME, stdin);

    int found = 0;
    printf("Title\t\t\tArtist\t\tAlbum\t\t\tYear\n");
    for(int i=0; i<*num_of_songs; i++){
        if(strcmp(songs[i].artist, artist) == 0){
            printf("%s\t\t%s\t\t%s\t\t%d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
            found = 1;
        }
    }
    if(!found){
        printf("%s not found in library!\n", artist);
    }
}