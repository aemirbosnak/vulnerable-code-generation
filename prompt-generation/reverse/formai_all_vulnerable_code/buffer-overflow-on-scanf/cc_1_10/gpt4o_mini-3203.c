//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // in seconds
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic() {
    if (musicCount < MAX_MUSIC) {
        printf("\n🎶 Add a New Music to the Library 🎶\n");
        printf("Enter the title of the music: ");
        getchar();  // Clear the input buffer
        fgets(musicLibrary[musicCount].title, TITLE_LENGTH, stdin);
        musicLibrary[musicCount].title[strcspn(musicLibrary[musicCount].title, "\n")] = 0; // Remove newline

        printf("Enter the artist's name: ");
        fgets(musicLibrary[musicCount].artist, ARTIST_LENGTH, stdin);
        musicLibrary[musicCount].artist[strcspn(musicLibrary[musicCount].artist, "\n")] = 0; // Remove newline

        printf("Enter the duration (in seconds): ");
        scanf("%d", &musicLibrary[musicCount].duration);

        musicCount++;
        printf("🎉 Music added successfully! 🎉\n");
    } else {
        printf("😢 The library is full! Cannot add more music.\n");
    }
}

void displayMusic() {
    printf("\n🎵 Your Music Library 🎵\n");
    if (musicCount == 0) {
        printf("😢 Your music library is empty!\n");
        return;
    }
    for (int i = 0; i < musicCount; i++) {
        printf("%d. %s by %s - Duration: %d seconds\n", 
            i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].duration);
    }
}

void searchMusic() {
    char query[TITLE_LENGTH];
    printf("\n🔍 Search Music by Title 🔍\n");
    printf("Enter the title to search: ");
    getchar();  // Clear the input buffer
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline

    printf("🎵 Search Results 🎵\n");
    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strstr(musicLibrary[i].title, query) != NULL) {
            printf("%d. %s by %s - Duration: %d seconds\n", 
                i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("😢 No music found with that title!\n");
    }
}

void deleteMusic() {
    int index;
    if (musicCount == 0) {
        printf("😢 Your music library is empty! Nothing to delete.\n");
        return;
    }
    
    printf("\n🗑️ Delete a Music 🎶\n");
    displayMusic();
    printf("Enter the number of the music to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > musicCount) {
        printf("😢 Invalid choice! Please try again.\n");
        return;
    }
    
    for (int i = index - 1; i < musicCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    musicCount--;
    printf("✅ Music successfully deleted!\n");
}

void displayMenu() {
    printf("\n🌟 Welcome to the Music Library Management System 🌟\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
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
                deleteMusic();
                break;
            case 5:
                printf("🎉 Thank you for using the Music Library! Goodbye! 🎉\n");
                return 0;
            default:
                printf("😢 Invalid option, please try again!\n");
        }
    }
    return 0;
}