//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct Song {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // in seconds
} Song;

typedef struct MusicLibrary {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

// Function prototypes
void initLibrary(MusicLibrary *library);
void addSong(MusicLibrary *library);
void displaySongs(MusicLibrary *library);
int searchSong(MusicLibrary *library, const char *title);

int main() {
    MusicLibrary myLibrary;
    initLibrary(&myLibrary);
    
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Search Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addSong(&myLibrary);
                break;
            case 2:
                displaySongs(&myLibrary);
                break;
            case 3: {
                char searchTitle[TITLE_LENGTH];
                printf("Enter song title to search: ");
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character
                int index = searchSong(&myLibrary, searchTitle);
                if (index != -1) {
                    printf("Song found: %s by %s, Duration: %d seconds\n",
                           myLibrary.songs[index].title, 
                           myLibrary.songs[index].artist, 
                           myLibrary.songs[index].duration);
                } else {
                    printf("Song not found.\n");
                }
                break;
            }
            case 4:
                printf("Exiting the Music Library.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addSong(MusicLibrary *library) {
    if (library->count < MAX_SONGS) {
        Song newSong;
        printf("Enter song title: ");
        fgets(newSong.title, sizeof(newSong.title), stdin);
        newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline character
        
        printf("Enter artist: ");
        fgets(newSong.artist, sizeof(newSong.artist), stdin);
        newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline character
        
        printf("Enter duration (in seconds): ");
        scanf("%d", &newSong.duration);
        getchar(); // Consume the newline character after integer input

        library->songs[library->count] = newSong;
        library->count++;
        printf("Song added successfully.\n");
    } else {
        printf("Library is full! Cannot add more songs.\n");
    }
}

void displaySongs(MusicLibrary *library) {
    printf("\n--- List of Songs in Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s, Duration: %d seconds\n", 
               i + 1, 
               library->songs[i].title, 
               library->songs[i].artist, 
               library->songs[i].duration);
    }
}

int searchSong(MusicLibrary *library, const char *title) {
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->songs[i].title, title) == 0) {
            return i; // Return the index of the found song
        }
    }
    return -1; // Song not found
}