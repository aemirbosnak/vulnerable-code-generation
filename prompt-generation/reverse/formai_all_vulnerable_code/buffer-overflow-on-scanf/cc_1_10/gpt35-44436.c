//FormAI DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 10
#define SONG_TITLE_LENGHT 50
#define ARTIST_LENGHT 50

struct Song {
    char title[SONG_TITLE_LENGHT];
    char artist[ARTIST_LENGHT];
    char genre[20];
    int playing_time;
};

void addSong(struct Song library[], int *total_songs) {
    if (*total_songs == MAX_SONGS) {
        printf("The library is already full.\n");
        return;
    }

    // Get song information from user
    struct Song newSong;
    printf("Enter Song Title: ");
    gets(newSong.title);
    printf("Enter Artist: ");
    gets(newSong.artist);
    printf("Enter Genre: ");
    gets(newSong.genre);
    printf("Enter Playing Time (in seconds): ");
    scanf("%d", &newSong.playing_time);
    fflush(stdin);

    // Add song to library
    library[*total_songs] = newSong;
    *total_songs += 1;

    printf("The song has been added to the library.\n");
}

void displayLibrary(struct Song library[], int total_songs) {
    if (total_songs == 0) {
        printf("The library is currently empty.\n");
        return;
    }

    printf("\nLibrary:\n");
    printf("Title\t\t| Artist\t\t| Genre\t| Playing Time (s)\n");
    for (int i = 0; i < total_songs; i++) {
        printf("%s\t| %s\t| %s\t| %d\n", library[i].title, library[i].artist, library[i].genre, library[i].playing_time);
    }
}

void searchSong(struct Song library[], int total_songs) {
    if (total_songs == 0) {
        printf("The library is currently empty.\n");
        return;
    }

    char search_title[SONG_TITLE_LENGHT];
    printf("Enter Song Title to Search: ");
    gets(search_title);

    int found = 0;
    printf("Search Results:\n");
    printf("Title\t\t| Artist\t\t| Genre\t| Playing Time (s)\n");
    for (int i = 0; i < total_songs; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            printf("%s\t| %s\t| %s\t| %d\n", library[i].title, library[i].artist, library[i].genre, library[i].playing_time);
            found = 1;
        }
    }

    if (!found) {
        printf("The song \"%s\" is not in the library.\n", search_title);
    }
}

int main() {
    // Initialize variables
    struct Song library[MAX_SONGS];
    int total_songs = 0;
    int choice;

    // Main menu loop
    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Library\n");
        printf("3. Search Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                addSong(library, &total_songs);
                break;
            case 2:
                displayLibrary(library, total_songs);
                break;
            case 3:
                searchSong(library, total_songs);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a number between 1 and 4.\n");
        }
    }

    return 0;
}