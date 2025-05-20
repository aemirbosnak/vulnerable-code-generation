//FormAI DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE 50
#define MAX_ARTIST 50

typedef struct{
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
    int rating;
    int played_count;
} Song;

Song song_list[MAX_SONGS];
int song_count = 0;

void add_song(){
    Song new_song;
    printf("Enter song title: ");
    scanf("%s", new_song.title);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter year of release: ");
    scanf("%d", &new_song.year);
    printf("Enter rating (1-5): ");
    scanf("%d", &new_song.rating);
    printf("Enter number of times played: ");
    scanf("%d", &new_song.played_count);

    song_list[song_count++] = new_song;
    printf("Song added successfully!\n");
}

void search_song(){
    char search_term[MAX_TITLE];
    printf("Enter the name of the song to search for: ");
    scanf("%s", search_term);

    int found = 0;
    for(int i=0; i<song_count; i++){
        if(strcmp(song_list[i].title, search_term) == 0){
            printf("Title: %s\n", song_list[i].title);
            printf("Artist: %s\n", song_list[i].artist);
            printf("Year: %d\n", song_list[i].year);
            printf("Rating: %d\n", song_list[i].rating);
            printf("Play count: %d\n", song_list[i].played_count);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Song not found.\n");
    }
}

void display_songs(){
    if(song_count == 0){
        printf("No songs in library.\n");
        return;
    }

    printf("| %-20s | %-20s | %-4s | %-3s | %-7s |\n", "Title", "Artist", "Year", "Rating", "Play Count");
    printf("|----------------------|----------------------|------|------|----------|\n");
    for(int i=0; i<song_count; i++){
        printf("| %-20s | %-20s | %-4d | %-3d | %-7d |\n", song_list[i].title, song_list[i].artist, song_list[i].year, song_list[i].rating, song_list[i].played_count);
    }
}

int main(){
    int choice;
    printf("Welcome to the C Music Library Management System!\n");

    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Add new song\n");
        printf("2. Search for a song\n");
        printf("3. Display all songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                display_songs();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 4);

    return 0;
}