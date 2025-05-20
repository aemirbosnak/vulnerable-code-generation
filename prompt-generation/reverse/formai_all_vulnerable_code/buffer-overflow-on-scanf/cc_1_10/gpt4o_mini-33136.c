//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LEN 50
#define ARTIST_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Music Library is full.\n");
        return;
    }
    Music newMusic;
    printf("Enter music title: ");
    getchar();  // clear newline from previous input
    fgets(newMusic.title, TITLE_LEN, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = '\0';  // remove newline

    printf("Enter artist name: ");
    fgets(newMusic.artist, ARTIST_LEN, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = '\0';  // remove newline

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);

    musicLibrary[musicCount++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusic() {
    if (musicCount == 0) {
        printf("No music found in the library.\n");
        return;
    }
    printf("\nMusic Library:\n");
    printf("------------------------------------------------------\n");
    printf("| %-20s | %-20s | Year |\n", "Title", "Artist");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < musicCount; i++) {
        printf("| %-20s | %-20s | %d  |\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
    printf("------------------------------------------------------\n");
}

void searchMusic() {
    char searchTerm[TITLE_LEN];
    printf("Enter music title or artist to search: ");
    getchar();  // clear newline from previous input
    fgets(searchTerm, TITLE_LEN, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';  // remove newline

    int found = 0;
    printf("\nSearch Results:\n");
    printf("------------------------------------------------------\n");
    printf("| %-20s | %-20s | Year |\n", "Title", "Artist");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < musicCount; i++) {
        if (strstr(musicLibrary[i].title, searchTerm) != NULL || 
            strstr(musicLibrary[i].artist, searchTerm) != NULL) {
            printf("| %-20s | %-20s | %d  |\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found matching the search term: %s\n", searchTerm);
    }
    printf("------------------------------------------------------\n");
}

void clearLibrary() {
    musicCount = 0;
    printf("Music library cleared.\n");
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Search Music\n");
    printf("4. Clear Library\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                displayMusic();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                clearLibrary();
                break;
            case 5:
                printf("Exiting the Music Library Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}