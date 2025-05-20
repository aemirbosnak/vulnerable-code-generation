//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_YEAR_LENGTH 5
#define MAX_SONGS 1000

struct song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char year[MAX_YEAR_LENGTH];
};

struct song s[MAX_SONGS];
int num_songs = 0;

void addSong() {
    if(num_songs >= MAX_SONGS) {
        printf("Sorry, maximum number of songs reached.\n");
        return;
        }

        printf("Enter song title: ");
        fgets(s[num_songs].title, MAX_TITLE_LENGTH, stdin);
        s[num_songs].title[strlen(s[num_songs].title) - 1] = '\0';

        printf("Enter artist name: ");
        fgets(s[num_songs].artist, MAX_ARTIST_LENGTH, stdin);
        s[num_songs].artist[strlen(s[num_songs].artist) - 1] = '\0';

        printf("Enter album name: ");
        fgets(s[num_songs].album, MAX_ALBUM_LENGTH, stdin);
        s[num_songs].album[strlen(s[num_songs].album) - 1] = '\0';

        printf("Enter year released: ");
        fgets(s[num_songs].year, MAX_YEAR_LENGTH, stdin);
        s[num_songs].year[strlen(s[num_songs].year) - 1] = '\0';

        printf("Song added successfully!\n");
        num_songs++;
}

void displaySongs() {
    if(num_songs == 0) {
        printf("No songs in library.\n");
        return;
    }

    printf("#\tTitle\t\t\t\tArtist\t\t\t\tAlbum\t\t\tYear\n");
    printf("------------------------------------------------------------------------\n");

    for(int i=0; i<num_songs; i++) {
        printf("%d\t%-30s%-30s%-30s%s\n", i+1, s[i].title, s[i].artist, s[i].album, s[i].year);
    }
}

void searchByTitle() {
    if(num_songs == 0) {
        printf("No songs in library.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter song title to search: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strlen(title) - 1] = '\0';

    int found = 0;

    for(int i=0; i<num_songs; i++) {
        if(strcasecmp(title, s[i].title) == 0) {
            if(!found) {
                printf("#\tTitle\t\t\t\tArtist\t\t\t\tAlbum\t\t\tYear\n");
                printf("------------------------------------------------------------------------\n");
            }
            found = 1;
            printf("%d\t%-30s%-30s%-30s%s\n", i+1, s[i].title, s[i].artist, s[i].album, s[i].year);
        }
    }

    if(!found) {
        printf("No songs found.\n");
    }
}

int main() {
    printf("Welcome to the Music Library Management System (MLMS)!\n");

    while(1) {
        printf("\nMain Menu:\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search by song title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchByTitle();
                break;
            case 4:
                printf("Thanks for using MLMS. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}