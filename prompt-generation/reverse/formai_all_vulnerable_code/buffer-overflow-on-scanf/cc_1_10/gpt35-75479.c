//FormAI DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

/* Music library structure */
typedef struct{
    char artist[50];
    char album[50];
    char song[50];
    int year;
    float duration;
    char genre[50];
}music_t;

/* function to add new song to library */
void add_song(int *num_songs, music_t *library){
    printf("***ADD NEW SONG***\n");
    printf("Enter the artist name: ");
    scanf(" %[^\n]s", library[*num_songs].artist);
    printf("Enter the album name: ");
    scanf(" %[^\n]s", library[*num_songs].album);
    printf("Enter the song name: ");
    scanf(" %[^\n]s", library[*num_songs].song);
    printf("Enter the release year: ");
    scanf("%d", &library[*num_songs].year);
    printf("Enter the song duration (in minutes): ");
    scanf("%f", &library[*num_songs].duration);
    printf("Enter the genre: ");
    scanf(" %[^\n]s", library[*num_songs].genre);
    (*num_songs)++;
    printf("Song added successfully\n");
}

/* function to search for a song in library */
void search_song(int num_songs, music_t *library){
    char song_name[50];
    printf("***SEARCH SONG***\n");
    printf("Enter the name of the song: ");
    scanf(" %[^\n]s", song_name);

    int i;
    int found = 0;
    for(i=0;i<num_songs;i++){
        if(strcmp(song_name, library[i].song)==0){
            printf("Song found\n");
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Release year: %d\n", library[i].year);
            printf("Duration: %.2f minutes\n", library[i].duration);
            printf("Genre: %s\n", library[i].genre);
            found = 1;
            break;
        }
    }
    if(found==0){
        printf("Song not found\n");
    }
}

/* function to display all the songs in library */
void display_songs(int num_songs, music_t *library){
    printf("***DISPLAY ALL SONGS***\n");
    int i;
    for(i=0;i<num_songs;i++){
        printf("Song %d\n", i+1);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Song name: %s\n", library[i].song);
        printf("Release year: %d\n", library[i].year);
        printf("Duration: %.2f minutes\n", library[i].duration);
        printf("Genre: %s\n", library[i].genre);
        printf("\n");
    }
}

int main(){
    printf("***WELCOME TO PARANOID MUSIC LIBRARY MANAGEMENT SYSTEM***\n");

    int num_songs = 0;
    music_t library[1000];

    while(1){
        printf("\n");
        printf("Press 1 to add new song\n");
        printf("Press 2 to search for a song\n");
        printf("Press 3 to display all songs\n");
        printf("Press 4 to exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song(&num_songs, library);
                break;
            case 2:
                search_song(num_songs, library);
                break;
            case 3:
                display_songs(num_songs, library);
                break;
            case 4:
                printf("Thank you for using Paranoid Music Library Management System\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}