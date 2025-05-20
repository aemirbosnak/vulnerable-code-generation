//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Album;

typedef struct {
    Album albums[MAX_ALBUMS];
    int count;
} MusicLibrary;

void initLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addAlbum(MusicLibrary *library) {
    if (library->count >= MAX_ALBUMS) {
        printf("Library is full! Cannot add more albums.\n");
        return;
    }
    
    Album newAlbum;
    printf("Enter album title: ");
    scanf(" %[^\n]s", newAlbum.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]s", newAlbum.artist);
    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    
    library->albums[library->count++] = newAlbum;
    printf("Album added successfully!\n");
}

void displayAlbums(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No albums in the library.\n");
        return;
    }
    
    printf("\n=== Music Library ===\n");
    for (int i = 0; i < library->count; i++) {
        Album *album = &library->albums[i];
        printf("Album %d: %s by %s (%d)\n", i + 1, album->title, album->artist, album->year);
    }
}

void saveLibraryToFile(const MusicLibrary *library, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(library, sizeof(MusicLibrary), 1, file);
    fclose(file);
    printf("Library saved to %s\n", filename);
}

void loadLibraryFromFile(MusicLibrary *library, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading. Starting with an empty library.\n");
        return;
    }

    fread(library, sizeof(MusicLibrary), 1, file);
    fclose(file);
    printf("Library loaded from %s\n", filename);
}

void removeAlbum(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No albums to remove from the library.\n");
        return;
    }
    
    int index;
    displayAlbums(library);
    printf("Enter the album number to remove: ");
    scanf("%d", &index);
    
    if (index < 1 || index > library->count) {
        printf("Invalid album number.\n");
        return;
    }
    
    for (int i = index - 1; i < library->count - 1; i++) {
        library->albums[i] = library->albums[i + 1];
    }
    library->count--;
    printf("Album removed successfully!\n");
}

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Album\n");
    printf("2. Display Albums\n");
    printf("3. Remove Album\n");
    printf("4. Save Library to File\n");
    printf("5. Load Library from File\n");
    printf("6. Exit\n");
}

int main() {
    MusicLibrary library;
    initLibrary(&library);
    
    int choice;
    char filename[MAX_TITLE_LENGTH] = "music_library.dat";

    loadLibraryFromFile(&library, filename);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum(&library);
                break;
            case 2:
                displayAlbums(&library);
                break;
            case 3:
                removeAlbum(&library);
                break;
            case 4:
                saveLibraryToFile(&library, filename);
                break;
            case 5:
                loadLibraryFromFile(&library, filename);
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}