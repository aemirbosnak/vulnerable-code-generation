//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    int year;
    int duration;
    char genre[MAX_SIZE];
} Song;

Song songs[MAX_SIZE];
int numSongs = 0;

void add_song() {
    Song new_song;
    printf("Enter song title: ");
    scanf("%s", new_song.title);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter year released: ");
    scanf("%d", &new_song.year);
    printf("Enter duration in seconds: ");
    scanf("%d", &new_song.duration);
    printf("Enter genre: ");
    scanf("%s", new_song.genre);

    songs[numSongs] = new_song;
    numSongs++;
}

void display_songs() {
    if(numSongs == 0) {
        printf("No songs to display.\n");
        return;
    }

    printf("Title\tArtist\tYear\tDuration\tGenre\n");
    for(int i = 0; i < numSongs; i++) {
        printf("%s\t%s\t%d\t%d\t%s\n", songs[i].title, songs[i].artist, songs[i].year, songs[i].duration, songs[i].genre);
    }
}

void search_by_title() {
    if(numSongs == 0) {
        printf("No songs to search for.\n");
        return;
    }

    char search_title[MAX_SIZE];
    printf("Enter song title: ");
    scanf("%s", search_title);

    for(int i = 0; i < numSongs; i++) {
        if(strcmp(songs[i].title, search_title) == 0) {
            printf("%s\t%s\t%d\t%d\t%s\n", songs[i].title, songs[i].artist, songs[i].year, songs[i].duration, songs[i].genre);
            return;
        }
    }

    printf("Song not found.\n");
}

void search_by_artist() {
    if(numSongs == 0) {
        printf("No songs to search for.\n");
        return;
    }

    char search_artist[MAX_SIZE];
    printf("Enter artist name: ");
    scanf("%s", search_artist);

    printf("Title\tArtist\tYear\tDuration\tGenre\n");
    for(int i = 0; i < numSongs; i++) {
        if(strcmp(songs[i].artist, search_artist) == 0) {
            printf("%s\t%s\t%d\t%d\t%s\n", songs[i].title, songs[i].artist, songs[i].year, songs[i].duration, songs[i].genre);
        }
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add song\n");
        printf("2. Display all songs\n");
        printf("3. Search for song by title\n");
        printf("4. Search for song by artist\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_songs();
                break;
            case 3:
                search_by_title();
                break;
            case 4:
                search_by_artist();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}