//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100

typedef struct {
    int id;
    char title[100];
    char artist[50];
    char genre[30];
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Library is full! Can't add more music.\n");
        return;
    }
    
    Music newMusic;
    newMusic.id = musicCount + 1;

    printf("Enter Music Title: ");
    getchar(); // clear the newline character from the buffer
    fgets(newMusic.title, sizeof(newMusic.title), stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline character

    printf("Enter Artist Name: ");
    fgets(newMusic.artist, sizeof(newMusic.artist), stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;

    printf("Enter Genre: ");
    fgets(newMusic.genre, sizeof(newMusic.genre), stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0;

    musicLibrary[musicCount] = newMusic;
    musicCount++;
    printf("Music added successfully! ID: %d\n\n", newMusic.id);
}

void viewMusic() {
    if (musicCount == 0) {
        printf("No music in the library!\n\n");
        return;
    }
    
    printf("ID\tTitle\t\t\t\tArtist\t\t\tGenre\n");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < musicCount; i++) {
        printf("%d\t%-25s%-25s%-25s\n", musicLibrary[i].id, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].genre);
    }
    printf("\n");
}

void deleteMusic() {
    if (musicCount == 0) {
        printf("No music to delete!\n\n");
        return;
    }
    
    int id;
    printf("Enter Music ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > musicCount) {
        printf("Invalid ID! Please try again.\n\n");
        return;
    }
    
    for (int i = id - 1; i < musicCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    musicCount--;
    printf("Music ID %d deleted successfully!\n\n", id);
}

void searchMusic() {
    if (musicCount == 0) {
        printf("No music available for search!\n\n");
        return;
    }

    char searchTerm[50];
    printf("Enter Music Title or Artist to search: ");
    getchar();
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;

    printf("Search Results:\n");
    printf("ID\tTitle\t\t\t\tArtist\t\t\tGenre\n");
    printf("---------------------------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strstr(musicLibrary[i].title, searchTerm) != NULL || strstr(musicLibrary[i].artist, searchTerm) != NULL) {
            printf("%d\t%-25s%-25s%-25s\n", musicLibrary[i].id, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].genre);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No music found for: %s\n\n", searchTerm);
    } else {
        printf("\n");
    }
}

void menu() {
    int choice;
    do {
        printf("=== Music Library Management System ===\n");
        printf("1. Add Music\n");
        printf("2. View Music\n");
        printf("3. Delete Music\n");
        printf("4. Search Music\n");
        printf("5. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                viewMusic();
                break;
            case 3:
                deleteMusic();
                break;
            case 4:
                searchMusic();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}