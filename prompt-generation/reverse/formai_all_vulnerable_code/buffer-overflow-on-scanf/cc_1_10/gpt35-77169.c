//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MusicLibrary {
    char title[30];
    char artist[30];
    int year;
    float rating;
    char genre[20];
};

void addSong(struct MusicLibrary *library, int *numSongs);
void searchSong(struct MusicLibrary *library, int numSongs);
void deleteSong(struct MusicLibrary *library, int *numSongs);

int main() {
    struct MusicLibrary library[100];
    int numSongs = 0;
    int option;
    
    while(1) {
        printf("=== Music Library Management System ===\n");
        printf("Please select an option:\n");
        printf("1. Add Song\n2. Search Song\n3. Delete Song\n4. Exit\n\n");
        scanf("%d", &option);
        getchar();  // clear buffer
        
        switch(option) {
            case 1:
                addSong(library, &numSongs);
                break;
            case 2:
                searchSong(library, numSongs);
                break;
            case 3:
                deleteSong(library, &numSongs);
                break;
            case 4:
                printf("Thank you for using the Music Library Manager.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}

void addSong(struct MusicLibrary *library, int *numSongs) {
    printf("Enter the song's title: ");
    fgets(library[*numSongs].title, 30, stdin);
    printf("Enter the song's artist: ");
    fgets(library[*numSongs].artist, 30, stdin);
    printf("Enter the song's release year: ");
    scanf("%d", &library[*numSongs].year);
    printf("Enter the song's rating (out of 10): ");
    scanf("%f", &library[*numSongs].rating);
    getchar();  // clear buffer
    printf("Enter the song's genre: ");
    fgets(library[*numSongs].genre, 20, stdin);
    (*numSongs)++;
    printf("Song added to the library.\n");
}

void searchSong(struct MusicLibrary *library, int numSongs) {
    char search[30];
    printf("Enter the title of the song you want to search for: ");
    fgets(search, 30, stdin);
    for(int i = 0; i < numSongs; i++) {
        if(strcmp(search, library[i].title) == 0) {
            printf("Title: %s", library[i].title);
            printf("Artist: %s", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Rating: %.1f/10\n", library[i].rating);
            printf("Genre: %s", library[i].genre);
            return;
        }
    }
    printf("Song not found in the library.\n");
}

void deleteSong(struct MusicLibrary *library, int *numSongs) {
    char search[30];
    printf("Enter the title of the song you want to delete: ");
    fgets(search, 30, stdin);
    for(int i = 0; i < *numSongs; i++) {
        if(strcmp(search, library[i].title) == 0) {
            for(int j = i; j < (*numSongs)-1; j++) {
                strcpy(library[j].title, library[j+1].title);
                strcpy(library[j].artist, library[j+1].artist);
                library[j].year = library[j+1].year;
                library[j].rating = library[j+1].rating;
                strcpy(library[j].genre, library[j+1].genre);
            }
            (*numSongs)--;
            printf("Song deleted from the library.\n");
            return;
        }
    }
    printf("Song not found in the library.\n");
}