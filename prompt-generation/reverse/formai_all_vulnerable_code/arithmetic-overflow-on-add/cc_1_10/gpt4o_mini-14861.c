//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration;  // in seconds
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
    int count;
} MusicLibrary;

// Function prototypes
void initializeLibrary(MusicLibrary *library);
void addMusic(MusicLibrary *library);
void displayLibrary(const MusicLibrary *library);
void searchMusic(const MusicLibrary *library);
void deleteMusic(MusicLibrary *library);
void saveLibrary(const MusicLibrary *library);
void loadLibrary(MusicLibrary *library);

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    loadLibrary(&library);

    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add Music\n");
        printf("2. Display Music Library\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Save Library\n");
        printf("6. Load Library\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayLibrary(&library);
                break;
            case 3:
                searchMusic(&library);
                break;
            case 4:
                deleteMusic(&library);
                break;
            case 5:
                saveLibrary(&library);
                break;
            case 6:
                loadLibrary(&library);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Music library is full! Cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    printf("Enter the title of the music: ");
    getchar(); // clear buffer
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline
    
    printf("Enter the artist of the music: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // remove newline

    printf("Enter the duration of the music (in seconds): ");
    scanf("%d", &newMusic.duration);
    
    library->collection[library->count++] = newMusic;
    printf("Music added successfully!\n");
}

void displayLibrary(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty!\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s | Artist: %s | Duration: %d seconds\n", 
                i + 1, library->collection[i].title, 
                library->collection[i].artist, 
                library->collection[i].duration);
    }
}

void searchMusic(const MusicLibrary *library) {
    char searchTerm[TITLE_LENGTH];
    printf("Enter title or artist to search: ");
    getchar(); // clear buffer
    fgets(searchTerm, TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->collection[i].title, searchTerm) != NULL ||
            strstr(library->collection[i].artist, searchTerm) != NULL) {
            printf("Found - Title: %s | Artist: %s | Duration: %d seconds\n", 
                   library->collection[i].title, 
                   library->collection[i].artist, 
                   library->collection[i].duration);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No music found matching your search criteria.\n");
    }
}

void deleteMusic(MusicLibrary *library) {
    int index;
    if (library->count == 0) {
        printf("No music library entries to delete.\n");
        return;
    }
    
    displayLibrary(library);
    printf("Enter the number of the music you want to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > library->count) {
        printf("Invalid choice. Music not deleted.\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;
    printf("Music deleted successfully!\n");
}

void saveLibrary(const MusicLibrary *library) {
    FILE *file = fopen("music_library.txt", "w");
    if (file == NULL) {
        printf("Could not open file for saving.\n");
        return;
    }
    
    for (int i = 0; i < library->count; i++) {
        fprintf(file, "%s\n%s\n%d\n", 
                library->collection[i].title, 
                library->collection[i].artist, 
                library->collection[i].duration);
    }
    
    fclose(file);
    printf("Library saved successfully!\n");
}

void loadLibrary(MusicLibrary *library) {
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("Could not open file for loading.\n");
        return;
    }
    
    initializeLibrary(library);
    while (fscanf(file, "%[^\n]\n%[^\n]\n%d\n", 
                  library->collection[library->count].title, 
                  library->collection[library->count].artist, 
                  &library->collection[library->count].duration) != EOF) {
        library->count++;
    }
    
    fclose(file);
    printf("Library loaded successfully! Total music: %d\n", library->count);
}