//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
} Music;

typedef struct {
    Music collection[MAX_MUSICS];
    int count;
} MusicLibrary;

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSICS) {
        printf("Oh dear! The library is overflowing with love songs! Can't add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter the title of the music: ");
    fgets(newMusic.title, MAX_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline

    printf("Enter the artist's name: ");
    fgets(newMusic.artist, MAX_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // Remove newline

    printf("Enter the genre: ");
    fgets(newMusic.genre, MAX_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // Remove newline

    printf("Enter the year of release: ");
    scanf("%d", &newMusic.year);
    getchar(); // Consume the newline

    library->collection[library->count] = newMusic;
    library->count++;
    printf("Your love song '%s' has been added to the collection!\n", newMusic.title);
}

void viewMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("Oh love, the library is empty! Fill it with sweet melodies.\n");
        return;
    }

    printf("\nHere are the love songs in your library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Song %d: '%s' by %s - Genre: %s (%d)\n", 
               i + 1, library->collection[i].title, 
               library->collection[i].artist, 
               library->collection[i].genre, 
               library->collection[i].year);
    }
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("Alas! There are no songs to erase from this serenade!\n");
        return;
    }

    int index;
    printf("Enter the number of the song to remove (1 to %d): ", library->count);
    scanf("%d", &index);
    getchar(); // Consume the newline

    if (index < 1 || index > library->count) {
        printf("Oh my! That number is not in our collection of love!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;
    printf("The song has been gently released from the library, like a whisper in the night.\n");
}

void menu() {
    printf("\nWelcome to the Enchanted Music Library\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Delete Music\n");
    printf("4. Exit\n");
    printf("Choose your romantic adventure: ");
}

int main() {
    MusicLibrary library = {{0}, 0};
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        getchar(); // Consume the newline

        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                viewMusic(&library);
                break;
            case 3:
                deleteMusic(&library);
                break;
            case 4:
                printf("Farewell, dear music lover! Until we meet again in melodies.\n");
                break;
            default:
                printf("Invalid choice! Please choose a number from 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}