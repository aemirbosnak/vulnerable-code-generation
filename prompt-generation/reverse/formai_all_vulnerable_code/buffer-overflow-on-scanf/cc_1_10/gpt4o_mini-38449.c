//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIB_SIZE 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
} Song;

typedef struct {
    Song songs[MAX_LIB_SIZE];
    int count;
} MusicLibrary;

void displayMenu() {
    printf("\n===== Welcome to the Funky Music Library! =====\n");
    printf("1. Add a song to the library\n");
    printf("2. View all songs\n");
    printf("3. Search a song by title\n");
    printf("4. Remove a song\n");
    printf("5. Exit the funky library\n");
    printf("===============================================\n");
    printf("Please choose a number (1-5): ");
}

void addSong(MusicLibrary *library) {
    if(library->count >= MAX_LIB_SIZE) {
        printf("Oops! The library is full, just like my dancing skills.\n");
        return;
    }

    Song newSong;
    printf("Enter the song title (or be creative): ");
    getchar(); // To absorb any newline character
    fgets(newSong.title, MAX_TITLE_LEN, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline
    
    printf("Who's the artist? (Make them famous): ");
    fgets(newSong.artist, MAX_ARTIST_LEN, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline

    printf("And what year was this glorious song released? ");
    scanf("%d", &newSong.year);

    library->songs[library->count] = newSong;
    library->count++;

    printf("Yay! '%s' by %s added to the library!\n", newSong.title, newSong.artist);
}

void viewSongs(MusicLibrary *library) {
    printf("\n=== Playlist of Awesomeness ===\n");
    if(library->count == 0) {
        printf("There's nothing in the library! Let's change that!\n");
        return;
    }

    for(int i = 0; i < library->count; i++) {
        printf("%d. '%s' by %s (%d)\n", i+1, library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
    printf("=================================\n");
}

void searchSong(MusicLibrary *library) {
    char searchTitle[MAX_TITLE_LEN];
    printf("Which song title are you hunting for? ");
    getchar(); // To absorb the newline character
    fgets(searchTitle, MAX_TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    for(int i = 0; i < library->count; i++) {
        if (strcasecmp(library->songs[i].title, searchTitle) == 0) {
            printf("Found it! '%s' by %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
            return;
        }
    }
    printf("Nope! No song titled '%s' found here, sorry buddy!\n", searchTitle);
}

void removeSong(MusicLibrary *library) {
    int index;
    printf("Enter the number of the song you want to remove (1 to %d): ", library->count);
    scanf("%d", &index);
    
    if(index < 1 || index > library->count) {
        printf("That's not a valid song number! C'mon, we can do better.\n");
        return;
    }

    for(int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    
    printf("Poof! The song has been magically removed! 🎩✨\n");
}

int main() {
    MusicLibrary library;
    library.count = 0;

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                viewSongs(&library);
                break;
            case 3:
                searchSong(&library);
                break;
            case 4:
                removeSong(&library);
                break;
            case 5:
                printf("Thanks for grooving with us! Catch you later! 🎶🤘\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Try again, music maestro!\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}