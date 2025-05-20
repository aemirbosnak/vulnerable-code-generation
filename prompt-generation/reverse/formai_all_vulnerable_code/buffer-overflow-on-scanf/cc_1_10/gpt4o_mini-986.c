//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int duration; // duration in seconds
} Music;

int musicCount = 0;
Music musicLibrary[MAX_MUSIC];

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Music Library is full.\n");
        return;
    }

    Music newMusic;
    printf("Enter Title: ");
    fgets(newMusic.title, MAX_TITLE, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0;  // Remove newline

    printf("Enter Artist: ");
    fgets(newMusic.artist, MAX_ARTIST, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;  // Remove newline

    printf("Enter Duration (in seconds): ");
    scanf("%d", &newMusic.duration);
    getchar(); // Clear newline from buffer

    musicLibrary[musicCount++] = newMusic;
    printf("Music added successfully!\n");
}

void viewMusic() {
    if (musicCount == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < musicCount; i++) {
        printf("%d. Title: %s | Artist: %s | Duration: %d seconds\n", 
                i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].duration);
    }
}

void deleteMusic() {
    int index;
    printf("Enter music number to delete: ");
    scanf("%d", &index);
    getchar(); // Clear newline from buffer

    if (index < 1 || index > musicCount) {
        printf("Invalid selection.\n");
        return;
    }

    for (int i = index - 1; i < musicCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }

    musicCount--;
    printf("Music deleted successfully!\n");
}

void searchMusic() {
    char searchTerm[MAX_TITLE];
    printf("Enter title or artist to search: ");
    fgets(searchTerm, MAX_TITLE, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strstr(musicLibrary[i].title, searchTerm) || strstr(musicLibrary[i].artist, searchTerm)) {
            printf("%d. Title: %s | Artist: %s | Duration: %d seconds\n", 
                    i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("No matches found.\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. View Music\n");
        printf("3. Delete Music\n");
        printf("4. Search Music\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

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
                printf("Exiting the program. See you again!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Music Library Management System!\n");
    menu();
    return 0;
}