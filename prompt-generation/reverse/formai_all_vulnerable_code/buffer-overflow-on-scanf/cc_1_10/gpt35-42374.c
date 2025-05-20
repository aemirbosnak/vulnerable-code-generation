//FormAI DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIB_SIZE 100
#define MAX_TITLE_SIZE 50

typedef struct {
    char title[MAX_TITLE_SIZE];
    bool isOwned;
} Song;

Song library[MAX_LIB_SIZE];

int numSongs = 0;

// Function to add a song to the library
void addSong(char* title) {
    if (numSongs >= MAX_LIB_SIZE) {
        printf("The library is full!\n");
        return;
    }

    // Check if the title already exists in the library
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(title, library[i].title) == 0) {
            printf("The song already exists in the library.\n");
            return;
        }
    }

    // Add the song to the library
    strcpy(library[numSongs].title, title);
    library[numSongs].isOwned = false;
    numSongs++;

    printf("The song has been added to the library.\n");
}

// Function to remove a song from the library
void removeSong(char* title) {
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(title, library[i].title) == 0) {
            // Shift all the songs after the removed song to the left
            for (int j = i; j < numSongs - 1; j++) {
                strcpy(library[j].title, library[j+1].title);
                library[j].isOwned = library[j+1].isOwned;
            }

            // Clear the last song in the library
            strcpy(library[numSongs-1].title, "");
            library[numSongs-1].isOwned = false;
            numSongs--;

            printf("The song has been removed from the library.\n");
            return;
        }
    }

    printf("The song does not exist in the library.\n");
}

// Function to mark a song as owned in the library
void markOwned(char* title) {
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(title, library[i].title) == 0) {
            library[i].isOwned = true;
            printf("The song has been marked as owned.\n");
            return;
        }
    }

    printf("The song does not exist in the library.\n");
}

// Function to print all the songs in the library
void printLibrary() {
    printf("Library:\n");

    for (int i = 0; i < numSongs; i++) {
        printf("%s", library[i].title);
        if (library[i].isOwned) printf(" (owned)");
        printf("\n");
    }
}

// Main function to run the program
int main() {
    char input[MAX_TITLE_SIZE];
    bool running = true;

    while (running) {
        printf("Enter a command (add, remove, mark, print, quit):\n");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter the title of the song to add:\n");
            scanf("%s", input);
            addSong(input);
        }
        else if (strcmp(input, "remove") == 0) {
            printf("Enter the title of the song to remove:\n");
            scanf("%s", input);
            removeSong(input);
        }
        else if (strcmp(input, "mark") == 0) {
            printf("Enter the title of the song to mark as owned:\n");
            scanf("%s", input);
            markOwned(input);
        }
        else if (strcmp(input, "print") == 0) {
            printLibrary();
        }
        else if (strcmp(input, "quit") == 0) {
            running = false;
        }
        else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}