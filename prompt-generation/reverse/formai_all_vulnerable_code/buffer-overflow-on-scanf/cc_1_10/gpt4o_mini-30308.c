//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONG_LENGTH 100

typedef struct Song {
    char title[MAX_SONG_LENGTH];
    struct Song* next;
} Song;

typedef struct Playlist {
    Song* head;
    int size;
} Playlist;

void initializePlaylist(Playlist* playlist) {
    playlist->head = NULL;
    playlist->size = 0;
}

void addSong(Playlist* playlist, const char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strncpy(newSong->title, title, MAX_SONG_LENGTH);
    newSong->next = playlist->head;
    playlist->head = newSong;
    playlist->size++;
    printf("Added \"%s\" to the playlist. Thank you for sharing music!\n", title);
}

void displayPlaylist(const Playlist* playlist) {
    if (playlist->size == 0) {
        printf("Your playlist is currently empty. Let's add some songs!\n");
        return;
    }
    
    printf("\nYour Playlist:\n");
    Song* current = playlist->head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s\n", index++, current->title);
        current = current->next;
    }
}

void removeSong(Playlist* playlist, const char* title) {
    Song* current = playlist->head;
    Song* previous = NULL;

    while (current != NULL && strncmp(current->title, title, MAX_SONG_LENGTH) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Song \"%s\" not found in the playlist. Try another one!\n", title);
        return;
    }

    if (previous == NULL) {
        playlist->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    playlist->size--;
    printf("Successfully removed \"%s\" from your playlist. Thank you for your musical taste!\n", title);
}

void freePlaylist(Playlist* playlist) {
    Song* current = playlist->head;
    while (current != NULL) {
        Song* next = current->next;
        free(current);
        current = next;
    }
    playlist->head = NULL;
    playlist->size = 0;
}

int main() {
    Playlist myPlaylist;
    initializePlaylist(&myPlaylist);
    int choice;
    char title[MAX_SONG_LENGTH];

    while (1) {
        printf("\n--- Music Playlist ---\n");
        printf("1. Add song\n");
        printf("2. Display playlist\n");
        printf("3. Remove song\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, MAX_SONG_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline char
                addSong(&myPlaylist, title);
                break;

            case 2:
                displayPlaylist(&myPlaylist);
                break;

            case 3:
                printf("Enter song title to remove: ");
                fgets(title, MAX_SONG_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline char
                removeSong(&myPlaylist, title);
                break;

            case 4:
                freePlaylist(&myPlaylist);
                printf("Thank you for using the Playlist program! Enjoy your music!\n");
                return 0;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}