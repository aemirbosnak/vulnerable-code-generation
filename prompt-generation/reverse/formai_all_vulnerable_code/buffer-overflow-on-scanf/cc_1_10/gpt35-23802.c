//FormAI DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

/* Song structure */
typedef struct{
    int song_id;
    char title[50];
    char artist[50];
    int duration;
} song_t;

/* Library structure */
typedef struct{
    song_t songs[MAX_SONGS];
    int song_count;
} library_t;

/* Function declarations */
void add_song_to_library(library_t *library, song_t song);
void remove_song_from_library(library_t *library, int song_id);
void display_library(library_t library);

/* Main function */
int main(){
    library_t my_library;
    my_library.song_count = 0;
    int input;

    do{
        /* Display menu options */
        printf("\nC MUSIC LIBRARY MANAGEMENT SYSTEM\n");
        printf("1. Add Song to Library\n");
        printf("2. Remove Song from Library\n");
        printf("3. Display Library\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch(input){
            case 1:
            {
                /* Add song to library */
                song_t new_song;
                printf("\nEnter Song Title: ");
                scanf("%s", new_song.title);
                printf("Enter Song Artist: ");
                scanf("%s", new_song.artist);
                printf("Enter Song Duration (in seconds): ");
                scanf("%d", &new_song.duration);
                new_song.song_id = my_library.song_count + 1;
                add_song_to_library(&my_library, new_song);
                printf("\nSong added to library successfully!\n");
                break;
            }
            case 2:
            {
                /* Remove song from library */
                int song_id;
                printf("\nEnter Song ID to remove: ");
                scanf("%d", &song_id);
                remove_song_from_library(&my_library, song_id);
                printf("\nSong removed from library successfully!\n");
                break;
            }
            case 3:
            {
                /* Display library */
                display_library(my_library);
                break;
            }
            case 4:
            {
                /* Exit program */
                printf("\nGoodbye!\n\n");
                return 0;
            }
            default:
            {
                printf("\nInvalid input, please try again.\n");
                break;
            }
        }
    }while(input != 4);

    return 0;
}

/* Function to add a song to the library */
void add_song_to_library(library_t *library, song_t song){
    if(library->song_count < MAX_SONGS){
        library->songs[library->song_count] = song;
        library->song_count++;
    }
}

/* Function to remove a song from the library */
void remove_song_from_library(library_t *library, int song_id){
    int i, j;

    for(i = 0; i < library->song_count; i++){
        if(library->songs[i].song_id == song_id){
            for(j = i; j < library->song_count - 1; j++){
                library->songs[j] = library->songs[j+1];
            }
            library->song_count--;
            break;
        }
    }
}

/* Function to display the entire library */
void display_library(library_t library){
    int i;
    
    if(library.song_count == 0){
        printf("\nLibrary is empty.\n");
        return;
    }

    printf("\nSONG ID | TITLE | ARTIST | DURATION\n");
    printf("--------|-------|--------|---------\n");

    for(i = 0; i < library.song_count; i++){
        printf("%-8d| %-6s| %-7s| %-9d\n", library.songs[i].song_id, library.songs[i].title, library.songs[i].artist, library.songs[i].duration);
    }
    printf("\n");
}