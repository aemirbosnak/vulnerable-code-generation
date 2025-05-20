//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    char genre[20];
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
    int count;
} MusicLibrary;

// Function prototypes
void initLibrary(MusicLibrary *library);
void addMusic(MusicLibrary *library);
void displayMusic(const MusicLibrary *library);
void searchMusic(const MusicLibrary *library);
void deleteMusic(MusicLibrary *library);
void saveToFile(const MusicLibrary *library);
void loadFromFile(MusicLibrary *library);

int main() {
    MusicLibrary library;
    initLibrary(&library);

    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: addMusic(&library); break;
            case 2: displayMusic(&library); break;
            case 3: searchMusic(&library); break;
            case 4: deleteMusic(&library); break;
            case 5: saveToFile(&library); break;
            case 6: loadFromFile(&library); break;
            case 0: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void initLibrary(MusicLibrary *library) {
    library->count = 0;
    loadFromFile(library); // Load existing library from a file
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }
    
    Music newMusic;
    printf("Enter the title of the music: ");
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    strtok(newMusic.title, "\n"); // Remove newline
    
    printf("Enter the artist: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    strtok(newMusic.artist, "\n"); // Remove newline
    
    printf("Enter the year of release: ");
    scanf("%d", &newMusic.year);
    getchar(); // Consume newline
    
    printf("Enter the genre: ");
    fgets(newMusic.genre, 20, stdin);
    strtok(newMusic.genre, "\n"); // Remove newline
    
    library->collection[library->count++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music found in the library!\n");
        return;
    }

    printf("\n---- Music Library ----\n");
    for (int i = 0; i < library->count; i++) {
        Music m = library->collection[i];
        printf("%d. Title: %s, Artist: %s, Year: %d, Genre: %s\n", i + 1, m.title, m.artist, m.year, m.genre);
    }
}

void searchMusic(const MusicLibrary *library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the music to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    strtok(searchTitle, "\n"); // Remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, searchTitle) == 0) {
            Music m = library->collection[i];
            printf("Found: Title: %s, Artist: %s, Year: %d, Genre: %s\n", m.title, m.artist, m.year, m.genre);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music titled '%s' not found!\n", searchTitle);
    }
}

void deleteMusic(MusicLibrary *library) {
    int index;
    displayMusic(library);
    
    printf("Enter the index of the music to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > library->count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;
    printf("Music deleted successfully!\n");
}

void saveToFile(const MusicLibrary *library) {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    for (int i = 0; i < library->count; i++) {
        Music m = library->collection[i];
        fprintf(file, "%s\n%s\n%d\n%s\n", m.title, m.artist, m.year, m.genre);
    }
    fclose(file);
    printf("Music library saved to file!\n");
}

void loadFromFile(MusicLibrary *library) {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("No saved library found, starting fresh.\n");
        return;
    }

    while (fscanf(file, " %[^\n] %[^\n] %d %[^\n]", 
                  library->collection[library->count].title, 
                  library->collection[library->count].artist, 
                  &library->collection[library->count].year, 
                  library->collection[library->count].genre) == 4) {
        library->count++;
    }
    fclose(file);
    printf("Music library loaded from file!\n");
}