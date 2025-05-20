//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int duration; // duration in seconds
} Song;

void addSong(Song *library, int *count) {
    if (*count >= MAX_SONGS) {
        printf("Music library is full!\n");
        return;
    }

    printf("Enter song title: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", library[*count].artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &library[*count].duration);
    
    (*count)++;
    printf("Song added successfully!\n");
}

void displaySongs(Song *library, int count) {
    if (count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < count; i++) {
        printf("Song %d: %s by %s [%d seconds]\n", i + 1, 
            library[i].title, library[i].artist, library[i].duration);
    }
}

void searchSong(Song *library, int count) {
    char searchTitle[MAX_TITLE_LEN];
    printf("Enter the title of the song to search: ");
    scanf(" %[^\n]", searchTitle);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found: %s by %s [%d seconds]\n", 
                library[i].title, library[i].artist, library[i].duration);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Song not found in the library.\n");
    }
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Search Song\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Song library[MAX_SONGS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(library, &count);
                break;
            case 2:
                displaySongs(library, count);
                break;
            case 3:
                searchSong(library, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}