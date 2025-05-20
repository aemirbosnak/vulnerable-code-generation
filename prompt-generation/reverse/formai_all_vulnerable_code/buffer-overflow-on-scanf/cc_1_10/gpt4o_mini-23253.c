//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
} Song;

Song musicLibrary[MAX_SONGS];
int songCount = 0;

void addSong() {
    if (songCount >= MAX_SONGS) {
        printf("Music library is full!\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    getchar(); // to consume the newline left by previous input
    fgets(newSong.title, MAX_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // remove newline

    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // remove newline

    printf("Enter genre: ");
    fgets(newSong.genre, MAX_LENGTH, stdin);
    newSong.genre[strcspn(newSong.genre, "\n")] = 0; // remove newline

    printf("Enter year of release: ");
    scanf("%d", &newSong.year);

    musicLibrary[songCount++] = newSong;
    printf("Song added successfully!\n");
}

void viewSongs() {
    if (songCount == 0) {
        printf("No songs in the library.\n");
        return;
    }
    printf("\nMusic Library:\n");
    for (int i = 0; i < songCount; i++) {
        printf("%d. Title: %s | Artist: %s | Genre: %s | Year: %d\n",
               i + 1, musicLibrary[i].title, musicLibrary[i].artist, 
               musicLibrary[i].genre, musicLibrary[i].year);
    }
}

void searchSong() {
    char searchTerm[MAX_LENGTH];
    printf("Enter song title or artist name to search: ");
    getchar(); // to consume the newline left by previous input
    fgets(searchTerm, MAX_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < songCount; i++) {
        if (strstr(musicLibrary[i].title, searchTerm) != NULL || 
            strstr(musicLibrary[i].artist, searchTerm) != NULL) {
            printf("Found: Title: %s | Artist: %s | Genre: %s | Year: %d\n",
                   musicLibrary[i].title, musicLibrary[i].artist, 
                   musicLibrary[i].genre, musicLibrary[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching songs found.\n");
    }
}

void deleteSong() {
    int index;
    printf("Enter the number of the song to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > songCount) {
        printf("Invalid song number!\n");
        return;
    }

    for (int i = index - 1; i < songCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    songCount--;
    printf("Song deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. View Songs\n");
        printf("3. Search Song\n");
        printf("4. Delete Song\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                viewSongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}