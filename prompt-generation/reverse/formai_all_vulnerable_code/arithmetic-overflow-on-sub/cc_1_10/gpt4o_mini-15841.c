//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_SONGS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char artist[NAME_LENGTH];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
    pthread_mutex_t mutex;
} MusicLibrary;

MusicLibrary library;

void* displayLibrary(void* arg) {
    while (1) {
        pthread_mutex_lock(&library.mutex);
        printf("\nCurrent Music Library:\n");
        for (int i = 0; i < library.count; i++) {
            printf("%d. %s by %s\n", i + 1, library.songs[i].name, library.songs[i].artist);
        }
        pthread_mutex_unlock(&library.mutex);
        sleep(5); // Update display every 5 seconds
    }
    return NULL;
}

void addSong(char* name, char* artist) {
    pthread_mutex_lock(&library.mutex);
    if (library.count < MAX_SONGS) {
        strcpy(library.songs[library.count].name, name);
        strcpy(library.songs[library.count].artist, artist);
        library.count++;
        printf("Added: %s by %s\n", name, artist);
    } else {
        printf("Library is full! Cannot add more songs.\n");
    }
    pthread_mutex_unlock(&library.mutex);
}

void removeSong(int index) {
    pthread_mutex_lock(&library.mutex);
    if (index >= 0 && index < library.count) {
        printf("Removed: %s by %s\n", library.songs[index].name, library.songs[index].artist);
        for (int i = index; i < library.count - 1; i++) {
            library.songs[i] = library.songs[i + 1];
        }
        library.count--;
    } else {
        printf("Invalid index! Cannot remove song.\n");
    }
    pthread_mutex_unlock(&library.mutex);
}

int main() {
    pthread_t displayThread;
    library.count = 0;
    pthread_mutex_init(&library.mutex, NULL);

    pthread_create(&displayThread, NULL, displayLibrary, NULL);

    while (1) {
        int choice;
        printf("\nMusic Library Management System:\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Exit\n");
        printf("Select an option (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            char name[NAME_LENGTH], artist[NAME_LENGTH];
            printf("Enter song name: ");
            scanf(" %[^\n]", name);
            printf("Enter artist name: ");
            scanf(" %[^\n]", artist);
            addSong(name, artist);
        } else if (choice == 2) {
            int index;
            printf("Enter song index to remove (1 to %d): ", library.count);
            scanf("%d", &index);
            removeSong(index - 1); // Convert to 0-based index
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    pthread_cancel(displayThread);
    pthread_join(displayThread, NULL);
    pthread_mutex_destroy(&library.mutex);

    return 0;
}