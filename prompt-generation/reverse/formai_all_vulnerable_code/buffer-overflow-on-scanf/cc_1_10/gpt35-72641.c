//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    int year;
} Song;

int menu(){
    int choice;
    printf("\n\n===== Welcome to C Music Library Management System =====\n");
    printf("1. Add new song\n");
    printf("2. Display all songs\n");
    printf("3. Search for a song\n");
    printf("4. Remove a song\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_song(Song songs[], int *num_songs){
    if (*num_songs == MAX_SIZE){
        printf("Sorry, maximum capacity reached.");
        return;
    }
    Song new_song;
    printf("Enter song title: ");
    scanf(" %[^\n]", new_song.title);
    printf("Enter song artist: ");
    scanf(" %[^\n]", new_song.artist);
    printf("Enter song year: ");
    scanf("%d", &new_song.year);
    songs[*num_songs] = new_song;
    *num_songs += 1;
    printf("Song added successfully!\n");
}

void display_all_songs(Song songs[], int num_songs){
    if (num_songs == 0){
        printf("No songs in the library.\n");
        return;
    }
    printf("\n=== DISPLAYING ALL SONGS ===\n");
    for (int i = 0; i < num_songs; i++){
        printf("%d. %s - %s (%d)\n", i+1, songs[i].title, songs[i].artist, songs[i].year);
    }
}

void search_song(Song songs[], int num_songs){
    if (num_songs == 0){
        printf("No songs in the library.\n");
        return;
    }
    char query[MAX_SIZE];
    printf("Enter title or artist of song to search for: ");
    scanf(" %[^\n]", query);
    int results = 0;
    printf("\n=== SEARCH RESULTS ===\n");
    for (int i = 0; i < num_songs; i++){
        if (strstr(songs[i].title, query) != NULL || strstr(songs[i].artist, query) != NULL){
            printf("%d. %s - %s (%d)\n", i+1, songs[i].title, songs[i].artist, songs[i].year);
            results++;
        }
    }
    if (results == 0){
        printf("No results found.\n");
    }
}

void remove_song(Song songs[], int *num_songs){
    if (*num_songs == 0){
        printf("No songs in the library.\n");
        return;
    }
    int song_index;
    printf("Enter index of song to remove: ");
    scanf("%d", &song_index);
    if (song_index < 1 || song_index > *num_songs){
        printf("Invalid index.\n");
        return;
    }
    printf("Removed song: %s - %s (%d)\n", songs[song_index-1].title, songs[song_index-1].artist, songs[song_index-1].year);
    for (int i = song_index-1; i < *num_songs-1; i++){
        songs[i] = songs[i+1];
    }
    *num_songs -= 1;
}

int main(){
    Song songs[MAX_SIZE];
    int num_songs = 0;
    int choice;
    do {
        choice = menu();
        switch(choice){
            case 1:
                add_song(songs, &num_songs);
                break;
            case 2:
                display_all_songs(songs, num_songs);
                break;
            case 3:
                search_song(songs, num_songs);
                break;
            case 4:
                remove_song(songs, &num_songs);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 5);
    return 0;
}