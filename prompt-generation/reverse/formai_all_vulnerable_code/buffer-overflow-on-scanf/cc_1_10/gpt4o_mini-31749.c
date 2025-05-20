//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 50
#define MAX_ARTIST 50

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
    char genre[MAX_TITLE];
} Music;

typedef struct {
    Music library[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *lib) {
    lib->count = 0;
}

void addMusic(MusicLibrary *lib) {
    if (lib->count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    Music newMusic;
    printf("Enter music title: ");
    scanf(" %[^\n]%*c", newMusic.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", newMusic.artist);
    printf("Enter release year: ");
    scanf("%d", &newMusic.year);
    printf("Enter genre: ");
    scanf(" %[^\n]%*c", newMusic.genre);
    
    lib->library[lib->count] = newMusic;
    lib->count++;
    printf("Music added successfully!\n");
}

void viewMusic(const MusicLibrary *lib) {
    if (lib->count == 0) {
        printf("No music found in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < lib->count; i++) {
        printf("%d. Title: %s | Artist: %s | Year: %d | Genre: %s\n", 
               i + 1, lib->library[i].title, lib->library[i].artist, 
               lib->library[i].year, lib->library[i].genre);
    }
}

void searchMusic(const MusicLibrary *lib) {
    char searchTitle[MAX_TITLE];
    printf("Enter music title to search: ");
    scanf(" %[^\n]%*c", searchTitle);
    
    int found = 0;
    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->library[i].title, searchTitle) == 0) {
            printf("Found: Title: %s | Artist: %s | Year: %d | Genre: %s\n", 
                   lib->library[i].title, lib->library[i].artist, 
                   lib->library[i].year, lib->library[i].genre);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No music found with the title: %s\n", searchTitle);
    }
}

void deleteMusic(MusicLibrary *lib) {
    int index;
    printf("Enter the index of the music to delete (1 to %d): ", lib->count);
    scanf("%d", &index);
    
    if (index < 1 || index > lib->count) {
        printf("Invalid index! Please try again.\n");
        return;
    }

    for (int i = index - 1; i < lib->count - 1; i++) {
        lib->library[i] = lib->library[i + 1];
    }
    lib->count--;
    printf("Music deleted successfully!\n");
}

int main() {
    MusicLibrary myMusicLibrary;
    int choice;

    initializeLibrary(&myMusicLibrary);
    
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. View Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                addMusic(&myMusicLibrary); 
                break;
            case 2: 
                viewMusic(&myMusicLibrary); 
                break;
            case 3: 
                searchMusic(&myMusicLibrary); 
                break;
            case 4: 
                deleteMusic(&myMusicLibrary); 
                break;
            case 5: 
                printf("Exiting the program. Goodbye!\n"); 
                break;
            default: 
                printf("Invalid choice. Please try again.\n"); 
        }
    } while (choice != 5);

    return 0;
}