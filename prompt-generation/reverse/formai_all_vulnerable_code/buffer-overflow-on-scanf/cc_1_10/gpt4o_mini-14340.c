//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    char genre[MAX_NAME_LENGTH];
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }
    
    Music newMusic;
    newMusic.id = library->count + 1; // unique id based on count
    printf("Enter music title: ");
    scanf(" %[^\n]", newMusic.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newMusic.artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", newMusic.genre);
    
    library->collection[library->count] = newMusic;
    library->count++;
    
    printf("Music added successfully!\n");
}

void viewMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("\nMusic Collection:\n");
    for (int i = 0; i < library->count; i++) {
        printf("ID: %d, Title: %s, Artist: %s, Genre: %s\n",
               library->collection[i].id,
               library->collection[i].title,
               library->collection[i].artist,
               library->collection[i].genre);
    }
}

void searchMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library to search for.\n");
        return;
    }
    
    char searchTitle[MAX_NAME_LENGTH];
    printf("Enter the music title to search: ");
    scanf(" %[^\n]", searchTitle);
    
    printf("Search Results:\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->collection[i].title, searchTitle) == 0) {
            printf("ID: %d, Title: %s, Artist: %s, Genre: %s\n",
                   library->collection[i].id,
                   library->collection[i].title,
                   library->collection[i].artist,
                   library->collection[i].genre);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No music found with the title: %s\n", searchTitle);
    }
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library to delete.\n");
        return;
    }
    
    int id;
    printf("Enter the ID of the music to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > library->count) {
        printf("Invalid ID!\n");
        return;
    }
    
    for (int i = id - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    
    library->count--;
    printf("Music deleted successfully!\n");
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;
    
    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                viewMusic(&library);
                break;
            case 3:
                searchMusic(&library);
                break;
            case 4:
                deleteMusic(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}