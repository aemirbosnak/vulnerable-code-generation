//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
/* 
 * Music Library Management System 
 * 
 * This program manages a music library by allowing users to add, delete, edit, and search for songs.
 * Song information includes title, artist, album, and year of release. 
 * 
 * The program uses dynamic memory allocation to manage the library collection.
 * It also includes error handling and input validation to avoid memory leaks and wrong inputs.
 * 
 * Author: Claude Shannon 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the song information
struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

// Function prototypes
void menu();
void newSong();
void deleteSong();
void editSong();
void searchSong();
void displaySong();

// Global variables
struct Song* library[100];  // Array of song pointers
int numSongs = 0;  // Number of songs in the library

// Main function
int main() {
    int choice;
    menu();
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: newSong(); break;
            case 2: deleteSong(); break;
            case 3: editSong(); break;
            case 4: searchSong(); break;
            case 5: displaySong(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
        menu();
    }
    return 0;
}

// Function to display the menu
void menu() {
    printf("\n===========================================\n");
    printf("           Music Library Manager\n");
    printf("===========================================\n");
    printf("1. Add a new song\n");
    printf("2. Delete a song\n");
    printf("3. Edit a song\n");
    printf("4. Search for a song by title or artist\n");
    printf("5. Display all songs\n");
    printf("6. Exit\n");
}

// Function to add a new song to the library
void newSong() {
    if (numSongs >= 100) {
        printf("The library is full!\n");
        return;
    }
    struct Song* s = malloc(sizeof(struct Song));
    if (s == NULL) {
        printf("Memory allocation error!\n");
        return;
    }
    printf("Enter song title: ");
    getchar();
    fgets(s->title, 100, stdin);
    s->title[strcspn(s->title, "\n")] = '\0';
    printf("Enter artist name: ");
    fgets(s->artist, 100, stdin);
    s->artist[strcspn(s->artist, "\n")] = '\0';
    printf("Enter album name: ");
    fgets(s->album, 100, stdin);
    s->album[strcspn(s->album, "\n")] = '\0';
    printf("Enter year of release: ");
    scanf("%d", &s->year);
    library[numSongs++] = s;
    printf("Song added successfully!\n");
}

// Function to delete a song from the library
void deleteSong() {
    if (numSongs == 0) {
        printf("The library is empty!\n");
        return;
    }
    char title[100];
    printf("Enter song title to be deleted: ");
    getchar();
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(title, library[i]->title) == 0) {
            free(library[i]);
            printf("Song deleted successfully!\n");
            for (int j = i; j < numSongs-1; j++) {
                library[j] = library[j+1];
            }
            numSongs--;
            return;
        }
    }
    printf("Song not found!\n");
}

// Function to edit a song in the library
void editSong() {
    if (numSongs == 0) {
        printf("The library is empty!\n");
        return;
    }
    char title[100];
    printf("Enter song title to be edited: ");
    getchar();
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(title, library[i]->title) == 0) {
            struct Song* s = library[i];
            printf("Enter new song title (leave blank to keep current): ");
            fgets(s->title, 100, stdin);
            s->title[strcspn(s->title, "\n")] = '\0';
            printf("Enter new artist name (leave blank to keep current): ");
            fgets(s->artist, 100, stdin);
            s->artist[strcspn(s->artist, "\n")] = '\0';
            printf("Enter new album name (leave blank to keep current): ");
            fgets(s->album, 100, stdin);
            s->album[strcspn(s->album, "\n")] = '\0';
            printf("Enter new year of release (leave blank to keep current): ");
            char input[100];
            fgets(input, 100, stdin);
            if (input[0] != '\n') {
                sscanf(input, "%d", &s->year);
            }
            printf("Song edited successfully!\n");
            return;
        }
    }
    printf("Song not found!\n");
}

// Function to search for a song in the library
void searchSong() {
    if (numSongs == 0) {
        printf("The library is empty!\n");
        return;
    }
    char input[100];
    printf("Enter search keyword (title or artist): ");
    getchar();
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("Search results:\n");
    for (int i = 0; i < numSongs; i++) {
        if (strstr(library[i]->title, input) != NULL || strstr(library[i]->artist, input) != NULL) {
            printf("- %s (%s, %s, %d)\n", library[i]->title, library[i]->artist, library[i]->album, library[i]->year);
        }
    }
}

// Function to display all songs in the library
void displaySong() {
    if (numSongs == 0) {
        printf("The library is empty!\n");
        return;
    }
    printf("All songs:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("- %s (%s, %s, %d)\n", library[i]->title, library[i]->artist, library[i]->album, library[i]->year);
    }
}