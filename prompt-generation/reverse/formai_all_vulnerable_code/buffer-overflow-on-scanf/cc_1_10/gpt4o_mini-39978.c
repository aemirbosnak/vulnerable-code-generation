//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a song
typedef struct Song {
    char title[100];
    char artist[100];
    char album[100];
    struct Song* next;
} Song;

Song* head = NULL;

// Function to create a new song
Song* createSong(char* title, char* artist, char* album) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    strcpy(newSong->album, album);
    newSong->next = NULL;
    return newSong;
}

// Function to add a song to the library
void addSong() {
    char title[100], artist[100], album[100];
    printf("Enter song title: ");
    scanf(" %[^\n]", title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", artist);
    printf("Enter album name: ");
    scanf(" %[^\n]", album);

    Song* newSong = createSong(title, artist, album);
    
    if (head == NULL) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }

    printf("Song added successfully!\n");
}

// Function to remove a song from the library
void removeSong() {
    char title[100];
    printf("Enter the title of the song to remove: ");
    scanf(" %[^\n]", title);

    Song* temp = head;
    Song* prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next; // First element
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Song removed successfully!\n");
}

// Function to display all songs in the library
void displaySongs() {
    if (head == NULL) {
        printf("No songs available in the library.\n");
        return;
    }

    Song* temp = head;
    printf("\n--- Music Library ---\n");
    while (temp != NULL) {
        printf("Title: %s, Artist: %s, Album: %s\n", temp->title, temp->artist, temp->album);
        temp = temp->next;
    }
}

// Function to clear the memory used by the song list
void freeSongs() {
    Song* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Display Songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                removeSong();
                break;
            case 3:
                displaySongs();
                break;
            case 4:
                freeSongs();
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}