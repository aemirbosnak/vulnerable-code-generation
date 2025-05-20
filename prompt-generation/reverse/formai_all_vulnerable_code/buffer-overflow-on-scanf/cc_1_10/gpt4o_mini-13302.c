//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_SIZE 100
#define MAX_ARTIST_SIZE 100

typedef struct {
    char title[MAX_TITLE_SIZE];
    char artist[MAX_ARTIST_SIZE];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void addSong(MusicLibrary *library);
void listSongs(MusicLibrary *library);
void deleteSong(MusicLibrary *library);
void displayMenu();

int main() {
    MusicLibrary library;
    library.count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                listSongs(&library);
                break;
            case 3:
                deleteSong(&library);
                break;
            case 4:
                printf("Thanks for grooving with us! Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Hmm, that's not a valid choice. Try again!\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n*** Welcome to the Curious Music Library! ***\n");
    printf("1. Add a Song\n");
    printf("2. List All Songs\n");
    printf("3. Delete a Song\n");
    printf("4. Exit\n");
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("The library is full! Cannot add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter the title of the song: ");
    getchar(); // Consume the newline character left by scanf
    fgets(newSong.title, MAX_TITLE_SIZE, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the artist of the song: ");
    fgets(newSong.artist, MAX_ARTIST_SIZE, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = '\0'; // Remove trailing newline

    library->songs[library->count] = newSong;
    library->count++;
    printf("Song '%s' by '%s' added to the library!\n", newSong.title, newSong.artist);
}

void listSongs(MusicLibrary *library) {
    if (library->count == 0) {
        printf("Oh no! The library is empty! Add some songs first.\n");
        return;
    }

    printf("\n*** Your Music Library ***\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. [%s] by [%s]\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
}

void deleteSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("Hmm, there's nothing to delete! The library is empty.\n");
        return;
    }

    int index;
    printf("Which song number do you want to delete? (1 to %d): ", library->count);
    scanf("%d", &index);

    if (index < 1 || index > library->count) {
        printf("That's not a valid song number! Try again.\n");
        return;
    }

    // Shift songs to the left to delete the song
    for (int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    printf("Song number %d has been removed from your library. Groove on!\n", index);
}