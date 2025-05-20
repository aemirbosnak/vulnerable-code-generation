//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_ARTIST 50
#define MAX_TITLE 100

typedef struct {
    char artist[MAX_ARTIST];
    char title[MAX_TITLE];
    char genre[MAX_ARTIST];
    int releaseYear;
} Music;

typedef struct {
    Music musicLibrary[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Oh dear! The library is full of melodies, unable to add more.\n");
        return;
    }
    Music newMusic;
    printf("Enter the artist's name: ");
    getchar(); // Consume newline left by previous input
    fgets(newMusic.artist, MAX_ARTIST, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // Remove the newline character

    printf("Enter the title of the music: ");
    fgets(newMusic.title, MAX_TITLE, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove the newline character

    printf("Enter the genre: ");
    fgets(newMusic.genre, MAX_ARTIST, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // Remove the newline character

    printf("Enter the release year: ");
    scanf("%d", &newMusic.releaseYear);

    library->musicLibrary[library->count] = newMusic;
    library->count++;

    printf("Ah, a new song added to our love story! 🎶\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("Our library is empty, a quiet heart yearning for melodies...\n");
        return;
    }

    printf("💖 Here are the songs in our heart:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Song %d:\n", i + 1);
        printf("  Artist: %s\n", library->musicLibrary[i].artist);
        printf("  Title: %s\n", library->musicLibrary[i].title);
        printf("  Genre: %s\n", library->musicLibrary[i].genre);
        printf("  Release Year: %d\n", library->musicLibrary[i].releaseYear);
    }
}

void searchMusic(const MusicLibrary *library) {
    char searchArtist[MAX_ARTIST];
    printf("Whose melody do you seek? Enter the artist's name: ");
    getchar(); // Consume newline
    fgets(searchArtist, MAX_ARTIST, stdin);
    searchArtist[strcspn(searchArtist, "\n")] = 0; // Remove the newline character

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->musicLibrary[i].artist, searchArtist) == 0) {
            printf("🎵 Found a song of love by %s:\n", searchArtist);
            printf("  Title: %s\n", library->musicLibrary[i].title);
            printf("  Genre: %s\n", library->musicLibrary[i].genre);
            printf("  Release Year: %d\n", library->musicLibrary[i].releaseYear);
            found = 1;
        }
    }

    if (!found) {
        printf("Alas! No song by %s has touched our hearts...\n", searchArtist);
    }
}

void removeMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("Our library is a silent realm, no song to remove...\n");
        return;
    }

    int index;
    printf("Which song would you like to remove? Enter song number (1 to %d): ", library->count);
    scanf("%d", &index);
    if (index < 1 || index > library->count) {
        printf("Forgive me! That is not a valid song number.\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->musicLibrary[i] = library->musicLibrary[i + 1];
    }
    
    library->count--;
    printf("❌ A song has been released back into the ether of time...\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int choice;
    do {
        printf("\nWelcome to the Music Library of Love! 💕\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Remove Music\n");
        printf("5. Exit\n");
        printf("Choose your heart's desire (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayMusic(&library);
                break;
            case 3:
                searchMusic(&library);
                break;
            case 4:
                removeMusic(&library);
                break;
            case 5:
                printf("Thank you for visiting our enchanted library! Until we meet again...\n");
                break;
            default:
                printf("Ah! A choice as elusive as the wind. Kindly choose a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}