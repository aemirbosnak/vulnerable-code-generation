//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100
#define MAX_ALBUMS 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
} Album;

typedef struct {
    Album *albums;
    int count;
    int capacity;
} MusicLibrary;

// Function prototypes
MusicLibrary* createLibrary();
void addAlbum(MusicLibrary *lib, const char *title, const char *artist, int year);
void displayAlbums(MusicLibrary *lib);
int searchAlbum(MusicLibrary *lib, const char *title);
void deleteAlbum(MusicLibrary *lib, const char *title);
void freeLibrary(MusicLibrary *lib);

int main() {
    MusicLibrary *library = createLibrary();
    int choice, year, index;
    char title[TITLE_LENGTH], artist[ARTIST_LENGTH];

    while (1) {
        printf("\n===== Futuristic Music Library =====\n");
        printf("1. Add Album\n2. Display Albums\n3. Search Album\n4. Delete Album\n5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clearing the input buffer

        switch (choice) {
            case 1:
                printf("Enter Album Title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                printf("Enter Artist Name: ");
                fgets(artist, ARTIST_LENGTH, stdin);
                artist[strcspn(artist, "\n")] = 0; // Remove newline character

                printf("Enter Release Year: ");
                scanf("%d", &year);

                addAlbum(library, title, artist, year);
                break;

            case 2:
                displayAlbums(library);
                break;

            case 3:
                printf("Enter Album Title to Search: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                index = searchAlbum(library, title);
                if (index != -1) {
                    printf("Album found: %s by %s (%d)\n", library->albums[index].title, library->albums[index].artist, library->albums[index].year);
                } else {
                    printf("Album not found.\n");
                }
                break;

            case 4:
                printf("Enter Album Title to Delete: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                deleteAlbum(library, title);
                break;

            case 5:
                freeLibrary(library);
                printf("Exiting the library. Thank you for visiting!\n");
                return 0;

            default:
                printf("Invalid option. Please try again!\n");
                break;
        }
    }
}

MusicLibrary* createLibrary() {
    MusicLibrary *lib = (MusicLibrary *)malloc(sizeof(MusicLibrary));
    lib->count = 0;
    lib->capacity = MAX_ALBUMS;
    lib->albums = (Album *)malloc(lib->capacity * sizeof(Album));
    return lib;
}

void addAlbum(MusicLibrary *lib, const char *title, const char *artist, int year) {
    if (lib->count >= lib->capacity) {
        lib->capacity *= 2;
        lib->albums = (Album *)realloc(lib->albums, lib->capacity * sizeof(Album));
    }
    strcpy(lib->albums[lib->count].title, title);
    strcpy(lib->albums[lib->count].artist, artist);
    lib->albums[lib->count].year = year;
    lib->count++;
    printf("Album added successfully!\n");
}

void displayAlbums(MusicLibrary *lib) {
    if (lib->count == 0) {
        printf("No albums in the library.\n");
        return;
    }
    printf("\n------ Music Library ------\n");
    for (int i = 0; i < lib->count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, lib->albums[i].title, lib->albums[i].artist, lib->albums[i].year);
    }
}

int searchAlbum(MusicLibrary *lib, const char *title) {
    for (int i = 0; i < lib->count; i++) {
        if (strcmp(lib->albums[i].title, title) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void deleteAlbum(MusicLibrary *lib, const char *title) {
    int index = searchAlbum(lib, title);
    if (index == -1) {
        printf("Album not found. Cannot delete.\n");
        return;
    }
    for (int i = index; i < lib->count - 1; i++) {
        lib->albums[i] = lib->albums[i + 1]; // Shift albums left
    }
    lib->count--;
    printf("Album deleted successfully!\n");
}

void freeLibrary(MusicLibrary *lib) {
    free(lib->albums);
    free(lib);
}