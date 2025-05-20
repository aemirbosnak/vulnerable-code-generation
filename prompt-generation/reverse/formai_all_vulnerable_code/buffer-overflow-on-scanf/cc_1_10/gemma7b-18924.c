//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music entry into the library
void insertMusic(MusicLibrary* head) {
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    printf("Enter title: ");
    scanf("%s", newMusic->title);
    printf("Enter artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter year: ");
    scanf("%d", &newMusic->year);

    newMusic->next = NULL;

    if (head == NULL) {
        head = newMusic;
    } else {
        MusicLibrary* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMusic;
    }
}

// Function to search for music by title
MusicLibrary* searchMusicByTitle(MusicLibrary* head, char* title) {
    MusicLibrary* currentMusic = head;
    while (currentMusic) {
        if (strcmp(currentMusic->title, title) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to search for music by artist
MusicLibrary* searchMusicByArtist(MusicLibrary* head, char* artist) {
    MusicLibrary* currentMusic = head;
    while (currentMusic) {
        if (strcmp(currentMusic->artist, artist) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to delete music from the library
void deleteMusic(MusicLibrary* head, char* title) {
    MusicLibrary* currentMusic = head;
    MusicLibrary* previousMusic = NULL;

    while (currentMusic) {
        if (strcmp(currentMusic->title, title) == 0) {
            if (previousMusic != NULL) {
                previousMusic->next = currentMusic->next;
            } else {
                head = currentMusic->next;
            }
            free(currentMusic);
            return;
        }
        previousMusic = currentMusic;
        currentMusic = currentMusic->next;
    }

    printf("Music not found.\n");
}

// Main function
int main() {
    MusicLibrary* head = NULL;

    // Insert some music into the library
    insertMusic(head);
    insertMusic(head);
    insertMusic(head);

    // Search for music by title
    MusicLibrary* music = searchMusicByTitle(head, "Song 1");
    if (music) {
        printf("Title: %s\n", music->title);
        printf("Artist: %s\n", music->artist);
        printf("Genre: %s\n", music->genre);
        printf("Year: %d\n", music->year);
    }

    // Search for music by artist
    music = searchMusicByArtist(head, "Artist 1");
    if (music) {
        printf("Title: %s\n", music->title);
        printf("Artist: %s\n", music->artist);
        printf("Genre: %s\n", music->genre);
        printf("Year: %d\n", music->year);
    }

    // Delete music from the library
    deleteMusic(head, "Song 1");

    // Search for music by title after deletion
    music = searchMusicByTitle(head, "Song 1");
    if (music) {
        printf("Music not found.\n");
    }

    return 0;
}