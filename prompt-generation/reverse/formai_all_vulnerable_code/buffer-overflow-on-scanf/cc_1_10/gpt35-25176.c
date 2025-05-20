//FormAI DATASET v1.0 Category: Music Library Management System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SONGS 1000
#define MAX_ARTISTS 1000

// structures for song and artist
typedef struct song {
    char title[50];
    int rating;
    char genre[20];
    char artist[50];
} Song;

typedef struct artist {
    char name[50];
    char origin[30];
    char genre[20];
} Artist;

Song songs[MAX_SONGS];
Artist artists[MAX_ARTISTS];
int numSongs = 0, numArtists = 0;

// function to add a song
void addSong() {
    Song newSong;
    printf("\nAdd New Song:\n");
    printf("Title: ");
    scanf("%s", newSong.title);
    printf("Artist: ");
    scanf("%s", newSong.artist);
    printf("Rating: ");
    scanf("%d", &newSong.rating);
    printf("Genre: ");
    scanf("%s", newSong.genre);
    songs[numSongs++] = newSong;
    printf("%s by %s added successfully!\n", newSong.title, newSong.artist);
}

// function to display all songs
void displaySongs() {
    if(numSongs == 0)
        printf("\nNo songs found!\n");
    else {
        printf("\nAll Songs:\n");
        for(int i=0; i<numSongs; i++) {
            printf("%d.\nTitle: %s\nArtist: %s\nRating: %d\nGenre: %s\n", i+1, songs[i].title, songs[i].artist, songs[i].rating, songs[i].genre);
            printf("-----------------\n");
        }
    }
}

// function to search for a song by title
void searchSong() {
    char searchTitle[50];
    printf("\nEnter Song Title to Search: ");
    scanf("%s", searchTitle);
    int searchFound = 0;
    for(int i=0; i<numSongs; i++) {
        if(strcmp(songs[i].title, searchTitle) == 0) {
            printf("\nSong Found!\n");
            printf("Title: %s\nArtist: %s\nRating: %d\nGenre: %s\n", songs[i].title, songs[i].artist, songs[i].rating, songs[i].genre);
            searchFound = 1;
            break;
        }
    }
    if(searchFound == 0)
        printf("\nSong not found!\n");
}

// function to add a new artist
void addArtist() {
    Artist newArtist;
    printf("\nAdd New Artist:\n");
    printf("Name: ");
    scanf("%s", newArtist.name);
    printf("Origin: ");
    scanf("%s", newArtist.origin);
    printf("Genre: ");
    scanf("%s", newArtist.genre);
    artists[numArtists++] = newArtist;
    printf("%s added successfully!\n", newArtist.name);
}

// function to display all artists
void displayArtists() {
    if(numArtists == 0)
        printf("\nNo artists found!\n");
    else {
        printf("\nAll Artists:\n");
        for(int i=0; i<numArtists; i++) {
            printf("%d.\nName: %s\nOrigin: %s\nGenre: %s\n", i+1, artists[i].name, artists[i].origin, artists[i].genre);
            printf("-----------------\n");
        }
    }
}

// function to search for an artist by name
void searchArtist() {
    char searchName[50];
    printf("\nEnter Artist Name to Search: ");
    scanf("%s", searchName);
    int searchFound = 0;
    for(int i=0; i<numArtists; i++) {
        if(strcmp(artists[i].name, searchName) == 0) {
            printf("\nArtist Found!\n");
            printf("Name: %s\nOrigin: %s\nGenre: %s\n", artists[i].name, artists[i].origin, artists[i].genre);
            searchFound = 1;
            break;
        }
    }
    if(searchFound == 0)
        printf("\nArtist not found!\n");
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search Song\n");
        printf("4. Add Artist\n");
        printf("5. Display All Artists\n");
        printf("6. Search Artist\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                addArtist();
                break;
            case 5:
                displayArtists();
                break;
            case 6:
                searchArtist();
                break;
            case 7:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
    } while(choice != 7);
    return 0;
}