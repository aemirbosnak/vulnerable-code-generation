//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_SONGS 1000

typedef struct song_t {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
} Song;

Song library[MAX_SONGS];
int numSongs = 0;

void addSong(char title[], char artist[], char album[], int year) {
    if(numSongs < MAX_SONGS) {
        Song newSong;
        strcpy(newSong.title, title);
        strcpy(newSong.artist, artist);
        strcpy(newSong.album, album);
        newSong.year = year;
        library[numSongs] = newSong;
        numSongs++;
        printf("Song added successfully!\n");
    } else {
        printf("The library is full, cannot add song!\n");
    }
}

void searchSongs(char term[]) {
    printf("Search results for \"%s\":\n", term);
    int numResults = 0;
    for(int i = 0; i < numSongs; i++) {
        if(strstr(library[i].title, term) || strstr(library[i].artist, term) || strstr(library[i].album, term)) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("--------------------\n");
            numResults++;
        }
    }
    if(numResults == 0) {
        printf("No results found for \"%s\".\n", term);
    } else {
        printf("%d result(s) found.\n", numResults);
    }
}

void printLibrary() {
    printf("Library contents:\n");
    for(int i = 0; i < numSongs; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("--------------------\n");
    }
}

int main() {
    int choice;
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
    char term[MAX_LENGTH];
    do {
        printf("What would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Search for songs\n");
        printf("3. Print library contents\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter song title: ");
                scanf("%s", title);
                printf("Enter artist name: ");
                scanf("%s", artist);
                printf("Enter album name: ");
                scanf("%s", album);
                printf("Enter year: ");
                scanf("%d", &year);
                addSong(title, artist, album, year);
                break;
            case 2:
                printf("Enter search term: ");
                scanf("%s", term);
                searchSongs(term);
                break;
            case 3:
                printLibrary();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}