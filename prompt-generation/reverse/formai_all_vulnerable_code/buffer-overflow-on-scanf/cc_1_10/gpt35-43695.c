//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Music Structure */
struct Music {
    char name[50];
    char artist[50];
    char genre[20];
    int year;
};

/* Declare Functions */
void printMenu();
void addSong();
void displaySongs();
void searchSong();
void deleteSong();

/* Declare Global Variables */
struct Music library[100];
int songCount = 0;

int main() {
    int choice;

    /* Loop until user quits */
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

/* Prints the program menu */
void printMenu() {
    printf("------------------------------\n");
    printf("       Music Library Menu     \n");
    printf("------------------------------\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Search Song\n");
    printf("4. Delete Song\n");
    printf("5. Quit\n");
}

/* Adds a song to the music library */
void addSong() {
    struct Music newSong;

    printf("Enter song name: ");
    scanf(" %[^\n]", newSong.name);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newSong.artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", newSong.genre);
    printf("Enter year: ");
    scanf("%d", &newSong.year);

    library[songCount] = newSong;
    songCount++;

    printf("Song added successfully!\n");
}

/* Displays all the songs in the music library */
void displaySongs() {
    if(songCount == 0) {
        printf("No songs found in library.\n");
    } else {
        printf("%-30s %-25s %-15s %-7s\n", "Song Name", "Artist", "Genre", "Year");
        printf("--------------------------------------------------------------\n");
        for(int i = 0; i < songCount; i++) {
            printf("%-30s %-25s %-15s %-7d\n", library[i].name, library[i].artist, library[i].genre, library[i].year);
        }
    }
}

/* Searches the music library for a song */
void searchSong() {
    char searchName[50];
    int found = 0;

    printf("Enter song name: ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < songCount; i++) {
        if(strcmp(searchName, library[i].name) == 0) {
            printf("%-30s %-25s %-15s %-7s\n", "Song Name", "Artist", "Genre", "Year");
            printf("--------------------------------------------------------------\n");
            printf("%-30s %-25s %-15s %-7d\n", library[i].name, library[i].artist, library[i].genre, library[i].year);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Song not found in library.\n");
    }
}

/* Deletes a song from the music library */
void deleteSong() {
    char deleteName[50];
    int found = 0;

    printf("Enter song name: ");
    scanf(" %[^\n]", deleteName);

    for(int i = 0; i < songCount; i++) {
        if(strcmp(deleteName, library[i].name) == 0) {
            for(int j = i + 1; j < songCount; j++) {
                library[j - 1] = library[j];
            }
            songCount--;
            found = 1;
            printf("Song deleted successfully!\n");
            break;
        }
    }

    if(found == 0) {
        printf("Song not found in library.\n");
    }
}