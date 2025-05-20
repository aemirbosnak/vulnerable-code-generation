//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    int duration; // duration in seconds
} Album;

Album musicLibrary[MAX_ALBUMS];
int albumCount = 0;

void addAlbum(char *title, char *artist, int year, int duration) {
    if (albumCount < MAX_ALBUMS) {
        strncpy(musicLibrary[albumCount].title, title, TITLE_LENGTH);
        strncpy(musicLibrary[albumCount].artist, artist, ARTIST_LENGTH);
        musicLibrary[albumCount].year = year;
        musicLibrary[albumCount].duration = duration;
        albumCount++;
        printf("\n[INFO] A new album has been uploaded to the Metaverse: %s by %s\n", title, artist);
    } else {
        printf("\n[ERROR] The virtual storage grid is full. Unable to add further albums.\n");
    }
}

void displayAlbums() {
    if (albumCount == 0) {
        printf("\n[EMPTY] The digital soundscape is barren. No albums found.\n");
        return;
    }
    printf("\n--- Humanoid Music Library ---\n");
    for (int i = 0; i < albumCount; i++) {
        printf("[%d] '%s' by %s, released in %d [%d seconds]\n",
               i + 1, musicLibrary[i].title, musicLibrary[i].artist,
               musicLibrary[i].year, musicLibrary[i].duration);
    }
}

void searchAlbum(char *query) {
    int found = 0;
    printf("\n--- Searching for '%s' in the neon-lit archives... ---\n", query);
    for (int i = 0; i < albumCount; i++) {
        if (strstr(musicLibrary[i].title, query) != NULL || 
            strstr(musicLibrary[i].artist, query) != NULL) {
            printf("Found: '%s' by %s, released in %d [%d seconds]\n",
                   musicLibrary[i].title, musicLibrary[i].artist,
                   musicLibrary[i].year, musicLibrary[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("No matches found... The digital ghosts remain silent.\n");
    }
}

void deleteAlbum(int index) {
    if (index < 0 || index >= albumCount) {
        printf("\n[ERROR] Invalid album index. The system glitched.\n");
        return;
    }
    printf("\n[INFO] Deleting Album: '%s'...\n", musicLibrary[index].title);
    for (int i = index; i < albumCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    albumCount--;
    printf("Album deleted. [%d remaining]\n", albumCount);
}

void clearMusicLibrary() {
    albumCount = 0;
    printf("\n[INFO] The music library has been wiped clean! Start anew?\n");
}

void printMenu() {
    printf("\n--- Neon Lights Music Library System ---\n");
    printf("1. Add Album\n");
    printf("2. Display Albums\n");
    printf("3. Search Album\n");
    printf("4. Delete Album\n");
    printf("5. Clear Library\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

int main() {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year, duration, choice, index;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Album Title: ");
                scanf(" %[^\n]%*c", title);
                printf("Enter Artist: ");
                scanf(" %[^\n]%*c", artist);
                printf("Enter Release Year: ");
                scanf("%d", &year);
                printf("Enter Duration (seconds): ");
                scanf("%d", &duration);
                addAlbum(title, artist, year, duration);
                break;
            case 2:
                displayAlbums();
                break;
            case 3:
                printf("Enter search query: ");
                scanf(" %[^\n]%*c", title);
                searchAlbum(title);
                break;
            case 4:
                printf("Enter album index to delete: ");
                scanf("%d", &index);
                deleteAlbum(index - 1);
                break;
            case 5:
                clearMusicLibrary();
                break;
            case 6:
                printf("Exiting the dimly lit system. Until next time...\n");
                exit(0);
            default:
                printf("[INVALID OPTION] Stay in the loop.\n");
        }
    }

    return 0;
}