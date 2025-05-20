//FormAI DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char genre[20];
    int length;
    char album[50];
};

void add_song(struct song songs[], int *count) {
    printf("Enter song title: ");
    scanf("%s", songs[*count].title);
    printf("Enter song artist: ");
    scanf("%s", songs[*count].artist);
    printf("Enter song genre: ");
    scanf("%s", songs[*count].genre);
    printf("Enter song length in seconds: ");
    scanf("%d", &songs[*count].length);
    printf("Enter song album (if applicable): ");
    scanf("%s", songs[*count].album);
    (*count)++;
}

void print_song(struct song song) {
    printf("%s - %s (%s) [%d seconds] - %s\n", song.artist, song.title, song.genre, song.length, song.album);
}

void print_all_songs(struct song songs[], int count) {
    printf("Current Music Library:\n");
    for(int i = 0; i < count; i++) {
        print_song(songs[i]);
    }
}

void search_song(struct song songs[], int count, char search_term[]) {
    printf("Search Results:\n");
    for(int i = 0; i < count; i++) {
        if(strstr(songs[i].title, search_term) || strstr(songs[i].artist, search_term) || strstr(songs[i].genre, search_term) || strstr(songs[i].album, search_term)) {
            print_song(songs[i]);
        }
    }
}

int main() {
    int option, count = 0;
    struct song songs[100];
    char search_term[50];
    
    printf("Welcome to the Music Library Management System!\n");
    
    do {
        printf("\n---------\n");
        printf("Menu:\n");
        printf("1. Add a song\n");
        printf("2. View all songs\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");
        printf("\nWhat would you like to do? ");
        scanf("%d", &option);
        printf("---------\n");
        
        switch(option) {
            case 1:
                add_song(songs, &count);
                break;
            case 2:
                print_all_songs(songs, count);
                break;
            case 3:
                printf("Enter search term: ");
                scanf("%s", search_term);
                search_song(songs, count, search_term);
                break;
            case 4:
                printf("Thank you for using the Music Library Management System!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while(option != 4);
    
    return 0;
}