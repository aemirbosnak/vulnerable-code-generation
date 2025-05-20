//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char genre[MAX_TITLE_LENGTH];
    int year;
    int duration; // Duration in seconds
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic();
void displayMusic();
void searchMusic();
void removeMusic();
void displayMenu();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    loadFromFile();

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMusic(); break;
            case 2: displayMusic(); break;
            case 3: searchMusic(); break;
            case 4: removeMusic(); break;
            case 5: saveToFile(); break;
            case 6: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display All Music\n");
    printf("3. Search Music\n");
    printf("4. Remove Music\n");
    printf("5. Save Music Library\n");
    printf("6. Exit\n");
}

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Music library is full! Cannot add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter the title of the music: ");
    getchar(); // Clear newline from buffer
    fgets(newMusic.title, MAX_TITLE_LENGTH, stdin);
    strtok(newMusic.title, "\n"); // Remove newline character
    printf("Enter the artist of the music: ");
    fgets(newMusic.artist, MAX_ARTIST_LENGTH, stdin);
    strtok(newMusic.artist, "\n"); // Remove newline character
    printf("Enter the genre: ");
    fgets(newMusic.genre, MAX_TITLE_LENGTH, stdin);
    strtok(newMusic.genre, "\n"); // Remove newline character
    printf("Enter the year of release: ");
    scanf("%d", &newMusic.year);
    printf("Enter the duration (in seconds): ");
    scanf("%d", &newMusic.duration);
    
    musicLibrary[musicCount++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusic() {
    if (musicCount == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < musicCount; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Year: %d, Duration: %d seconds\n",
               musicLibrary[i].title,
               musicLibrary[i].artist,
               musicLibrary[i].genre,
               musicLibrary[i].year,
               musicLibrary[i].duration);
    }
}

void searchMusic() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the music to search: ");
    getchar();
    fgets(title, MAX_TITLE_LENGTH, stdin);
    strtok(title, "\n"); // Remove newline character

    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            printf("Music found: Title: %s, Artist: %s, Genre: %s, Year: %d, Duration: %d seconds\n",
                   musicLibrary[i].title,
                   musicLibrary[i].artist,
                   musicLibrary[i].genre,
                   musicLibrary[i].year,
                   musicLibrary[i].duration);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void removeMusic() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the music to remove: ");
    getchar();
    fgets(title, MAX_TITLE_LENGTH, stdin);
    strtok(title, "\n"); // Remove newline character

    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            for (int j = i; j < musicCount - 1; j++) {
                musicLibrary[j] = musicLibrary[j + 1];
            }
            musicCount--;
            found = 1;
            printf("Music removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void saveToFile() {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Failed to open file for saving music library.\n");
        return;
    }

    for (int i = 0; i < musicCount; i++) {
        fprintf(file, "%s,%s,%s,%d,%d\n",
                musicLibrary[i].title,
                musicLibrary[i].artist,
                musicLibrary[i].genre,
                musicLibrary[i].year,
                musicLibrary[i].duration);
    }
    
    fclose(file);
    printf("Music library saved to file.\n");
}

void loadFromFile() {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("No saved library found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, " %99[^,],%99[^,],%99[^,],%d,%d\n",
                  musicLibrary[musicCount].title,
                  musicLibrary[musicCount].artist,
                  musicLibrary[musicCount].genre,
                  &musicLibrary[musicCount].year,
                  &musicLibrary[musicCount].duration) == 5) {
        musicCount++;
    }
    
    fclose(file);
    printf("Music library loaded successfully. %d songs found.\n", musicCount);
}