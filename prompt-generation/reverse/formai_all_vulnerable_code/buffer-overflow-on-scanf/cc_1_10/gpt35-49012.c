//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct{
    int song_id;
    char title[50];
    char artist[50];
    char genre[20];
    float duration;
} Song;

Song song_db[MAX_SONGS];
int num_of_songs = 0;

void add_song();
void remove_song();
void search_song();
void print_all_songs();

int main(){

    int choice;

    do{
        printf("\n ---- C Music Library Management System ---- \n\n");
        printf("Enter 1 to add a song\n");
        printf("Enter 2 to remove a song\n");
        printf("Enter 3 to search for a song\n");
        printf("Enter 4 to print all songs\n");
        printf("Enter 0 to exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                remove_song();
                break;
            case 3:
                search_song();
                break;
            case 4:
                print_all_songs();
                break;
            case 0:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Try again.");
        }

    }while(choice != 0);
    
    return 0;
}

void add_song(){

    Song new_song;

    printf("Enter song id: ");
    scanf("%d", &new_song.song_id);

    printf("Enter song title: ");
    getchar();
    fgets(new_song.title, 50, stdin);

    printf("Enter song artist: ");
    fgets(new_song.artist, 50, stdin);

    printf("Enter song genre: ");
    fgets(new_song.genre, 20, stdin);

    printf("Enter song duration in seconds: ");
    scanf("%f", &new_song.duration);

    song_db[num_of_songs] = new_song;
    num_of_songs++;

    printf("\n--- Song added successfully. ---\n");

}

void remove_song(){

    int song_id, i, j, found = 0;

    printf("Enter song id: ");
    scanf("%d", &song_id);

    for(i = 0; i < num_of_songs; i++){
        if(song_db[i].song_id == song_id){
            found = 1;
            printf("\n--- Song found: ---\n");
            printf("Song id: %d\n", song_db[i].song_id);
            printf("Title: %s", song_db[i].title);
            printf("Artist: %s", song_db[i].artist);
            printf("Genre: %s", song_db[i].genre);
            printf("Duration: %.2f seconds\n", song_db[i].duration);
            printf("\nAre you sure you want to remove this song? (y/n): ");

            char answer[5];
            scanf("%s", answer);

            if(strcmp(answer, "y") == 0){
                for(j = i; j < num_of_songs; j++){
                    song_db[j] = song_db[j+1];
                }
                num_of_songs--;
                printf("\n--- Song removed successfully. ---\n");
            }else{
                printf("\n--- Removal cancelled. ---\n");
            }
            break;
        }
    }

    if(!found){
        printf("\n--- Song not found. ---\n");
    }

}

void search_song(){

    char keyword[50];
    int i, found = 0;

    printf("Enter search keyword (title/artist/genre): ");
    getchar();
    fgets(keyword, 50, stdin);

    printf("\n--- Search results: ---\n");

    for(i = 0; i < num_of_songs; i++){
        if(strstr(song_db[i].title, keyword) != NULL ||
           strstr(song_db[i].artist, keyword) != NULL ||
           strstr(song_db[i].genre, keyword) != NULL){

            printf("Song id: %d\n", song_db[i].song_id);
            printf("Title: %s", song_db[i].title);
            printf("Artist: %s", song_db[i].artist);
            printf("Genre: %s", song_db[i].genre);
            printf("Duration: %.2f seconds\n", song_db[i].duration);
            printf("--------------------\n");
            found = 1;
        }
    }

    if(!found){
        printf("No results found.");
    }

}

void print_all_songs(){

    int i;

    printf("\n--- List of all songs ---\n");
    for(i = 0; i < num_of_songs; i++){
        printf("Song id: %d\n", song_db[i].song_id);
        printf("Title: %s", song_db[i].title);
        printf("Artist: %s", song_db[i].artist);
        printf("Genre: %s", song_db[i].genre);
        printf("Duration: %.2f seconds\n", song_db[i].duration);
        printf("--------------------\n");
    }

    printf("Total number of songs: %d\n", num_of_songs);

}