//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_LEN 100

typedef struct{
    char song[MAX_LEN];
    char artist[MAX_LEN];
    int year;
} Song;

Song songs[MAX_SONGS];
int num_songs = 0;

int add_song(char* song, char* artist, int year){
    if(num_songs == MAX_SONGS){
        printf("Music library is full!\n");
        return 1;
    }
    strcpy(songs[num_songs].song, song);
    strcpy(songs[num_songs].artist, artist);
    songs[num_songs].year = year;
    num_songs++;
    return 0;
}

int remove_song(int index){
    if(index < 0 || index >= num_songs){
        printf("Invalid song index!\n");
        return -1;
    }
    for(int i=index; i<num_songs-1; i++){
        strcpy(songs[i].song, songs[i+1].song);
        strcpy(songs[i].artist, songs[i+1].artist);
        songs[i].year = songs[i+1].year;
    }
    num_songs--;
    return 0;
}

void print_songs(){
    if(num_songs == 0){
        printf("Music library is empty!\n");
        return;
    }
    printf("Music library:\n");
    for(int i=0; i<num_songs; i++){
        printf("%d. %s - %s (%d)\n", i+1, songs[i].artist, songs[i].song, songs[i].year);
    }
}

void search_song(char* keyword){
    int results = 0;
    for(int i=0; i<num_songs; i++){
        if(strstr(songs[i].song, keyword) || strstr(songs[i].artist, keyword)){
            printf("%s - %s (%d)\n", songs[i].artist, songs[i].song, songs[i].year);
            results++;
        }
    }
    if(results == 0){
        printf("No results for '%s'!\n", keyword);
    }
}

int main(){
    char command[10];
    char song[MAX_LEN];
    char artist[MAX_LEN];
    int year, index;
    while(1){
        printf("\nEnter command (add/remove/print/search/quit): ");
        scanf("%s", command);
        if(strcmp(command, "add") == 0){
            printf("Enter song title: ");
            scanf("%s", song);
            printf("Enter artist name: ");
            scanf("%s", artist);
            printf("Enter year: ");
            scanf("%d", &year);
            add_song(song, artist, year);
        }
        else if(strcmp(command, "remove") == 0){
            printf("Enter song index: ");
            scanf("%d", &index);
            remove_song(index-1);
        }
        else if(strcmp(command, "print") == 0){
            print_songs();
        }
        else if(strcmp(command, "search") == 0){
            printf("Enter keyword: ");
            scanf("%s", song);
            search_song(song);
        }
        else if(strcmp(command, "quit") == 0){
            break;
        }
        else{
            printf("Invalid command!\n");
        }
    }
    return 0;
}