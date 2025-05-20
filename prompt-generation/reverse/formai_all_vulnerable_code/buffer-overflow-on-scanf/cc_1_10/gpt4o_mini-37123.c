//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
} Music;

typedef struct {
    Music collection[MAX_MUSICS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;  // Initialize music count to zero
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSICS) {
        printf("Library is full. Cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    
    printf("Enter music title: ");
    scanf(" %[^\n]%*c", newMusic.title); // Read string with spaces

    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", newMusic.artist); // Read string with spaces

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);

    library->collection[library->count] = newMusic; // Add to collection
    library->count++;
    
    printf("Music added successfully!\n");
}

void displayCollection(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\nMusic Collection:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", library->collection[i].title, library->collection[i].artist, library->collection[i].year);
    }
}

void searchMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }

    char searchTitle[MAX_TITLE];
    printf("Enter music title to search: ");
    scanf(" %[^\n]%*c", searchTitle);

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, searchTitle) == 0) {
            printf("Found: Title: %s, Artist: %s, Year: %d\n", library->collection[i].title, library->collection[i].artist, library->collection[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music titled '%s' not found in the library.\n", searchTitle);
    }
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music to delete.\n");
        return;
    }

    char deleteTitle[MAX_TITLE];
    printf("Enter music title to delete: ");
    scanf(" %[^\n]%*c", deleteTitle);

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, deleteTitle) == 0) {
            // Shift all following elements to the left
            for (int j = i; j < library->count - 1; j++) {
                library->collection[j] = library->collection[j + 1];
            }
            library->count--; // Reduce count
            printf("Music titled '%s' deleted successfully!\n", deleteTitle);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music titled '%s' not found in the library.\n", deleteTitle);
    }
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Collection\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayCollection(&library);
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
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}