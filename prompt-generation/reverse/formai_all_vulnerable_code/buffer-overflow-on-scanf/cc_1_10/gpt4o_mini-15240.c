//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char genre[MAX_TITLE];
    int year;
} Music;

Music library[MAX_MUSIC];
int musicCount = 0;

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Delete Music\n");
    printf("3. Search Music\n");
    printf("4. Display All Music\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Music library is full! Cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    printf("Enter Music Title: ");
    scanf(" %[^\n]%*c", newMusic.title);
    printf("Enter Artist: ");
    scanf(" %[^\n]%*c", newMusic.artist);
    printf("Enter Genre: ");
    scanf(" %[^\n]%*c", newMusic.genre);
    printf("Enter Year of Release: ");
    scanf("%d", &newMusic.year);
    
    library[musicCount] = newMusic;
    musicCount++;
    printf("Music added successfully!\n");
}

void deleteMusic() {
    char title[MAX_TITLE];
    printf("Enter the title of the music to delete: ");
    scanf(" %[^\n]%*c", title);
    
    for (int i = 0; i < musicCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < musicCount - 1; j++) {
                library[j] = library[j + 1];
            }
            musicCount--;
            printf("Music deleted successfully!\n");
            return;
        }
    }
    printf("Music not found!\n");
}

void searchMusic() {
    char title[MAX_TITLE];
    printf("Enter the title of the music to search: ");
    scanf(" %[^\n]%*c", title);
    
    for (int i = 0; i < musicCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Music Found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Year: %d\n", library[i].year);
            return;
        }
    }
    printf("Music not found!\n");
}

void displayAllMusic() {
    if (musicCount == 0) {
        printf("No music found in the library!\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < musicCount; i++) {
        printf("%d: %s by %s (%s, %d)\n", i + 1, library[i].title, library[i].artist, library[i].genre, library[i].year);
    }
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
                deleteMusic();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                displayAllMusic();
                break;
            case 5:
                printf("Exiting Music Library Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please choose between 1 and 5.\n");
        }
    }

    return 0;
}