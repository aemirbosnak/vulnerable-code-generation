//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
    char genre[MAX_TITLE];
} Song;

void addSong(Song *library, int *count) {
    printf("Enter title of the song: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter artist of the song: ");
    scanf(" %[^\n]", library[*count].artist);
    printf("Enter year of release: ");
    scanf("%d", &library[*count].year);
    printf("Enter genre of the song: ");
    scanf(" %[^\n]", library[*count].genre);
    (*count)++;
    printf("Ah, another melodic piece has been added to our collection!\n");
}

void findSongByArtist(Song *library, int count) {
    char searchArtist[MAX_ARTIST];
    printf("Enter artist's name to search for their songs: ");
    scanf(" %[^\n]", searchArtist);
    printf("Searching for songs by %s...\n", searchArtist);
    
    int found = 0;
    for(int i = 0; i < count; i++) {
        if (strcmp(library[i].artist, searchArtist) == 0) {
            printf("Found: %s by %s, Year: %d, Genre: %s\n", 
                   library[i].title, library[i].artist, 
                   library[i].year, library[i].genre);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs found by %s. Quite puzzling indeed!\n", searchArtist);
    }
}

void listAllSongs(Song *library, int count) {
    printf("Listing all songs in the library...\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s, Year: %d, Genre: %s\n", 
               i + 1, library[i].title, library[i].artist, 
               library[i].year, library[i].genre);
    }
}

int main() {
    Song library[MAX_SONGS];
    int count = 0;
    int choice;
    
    while (1) {
        printf("\nSherlock's Musical Library Management System\n");
        printf("1. Add a new song\n");
        printf("2. Search songs by artist\n");
        printf("3. List all songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (count < MAX_SONGS) {
                    addSong(library, &count);
                } else {
                    printf("Library is full, no more songs can be added!\n");
                }
                break;
            case 2:
                findSongByArtist(library, count);
                break;
            case 3:
                listAllSongs(library, count);
                break;
            case 4:
                printf("Thank you for using the musical library management system.\n");
                exit(0);
            default:
                printf("Elementary my dear Watson, please choose a valid option!\n");
        }
    }

    return 0;
}