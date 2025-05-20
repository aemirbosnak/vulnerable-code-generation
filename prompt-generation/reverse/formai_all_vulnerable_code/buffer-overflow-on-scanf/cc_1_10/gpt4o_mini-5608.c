//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
    char genre[MAX_TITLE_LENGTH];
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
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    printf("Enter music title: ");
    getchar(); // clear the newline buffer
    fgets(newMusic.title, MAX_TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline character

    printf("Enter artist name: ");
    fgets(newMusic.artist, MAX_ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // remove newline character

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);

    printf("Enter genre: ");
    getchar(); // clear the newline buffer
    fgets(newMusic.genre, MAX_TITLE_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // remove newline character

    library->collection[library->count++] = newMusic;
    printf("Music '%s' by '%s' added to the library!\n", newMusic.title, newMusic.artist);
}

void listMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: '%s', Artist: '%s', Year: %d, Genre: '%s'\n",
               i + 1, library->collection[i].title, library->collection[i].artist,
               library->collection[i].year, library->collection[i].genre);
    }
}

void searchMusicByArtist(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty.\n");
        return;
    }
    
    char artist[MAX_ARTIST_LENGTH];
    printf("Enter the artist name to search: ");
    getchar(); // clear the newline buffer
    fgets(artist, MAX_ARTIST_LENGTH, stdin);
    artist[strcspn(artist, "\n")] = 0; // remove newline character

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->collection[i].artist, artist) == 0) {
            printf("Title: '%s', Year: %d, Genre: '%s'\n",
                   library->collection[i].title,
                   library->collection[i].year,
                   library->collection[i].genre);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found for the artist '%s'.\n", artist);
    }
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is empty.\n");
        return;
    }

    int index;
    printf("Enter music number to delete (1 to %d): ", library->count);
    scanf("%d", &index);
    
    if (index < 1 || index > library->count) {
        printf("Invalid music number!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }

    library->count--;
    printf("Music deleted successfully!\n");
}

void displayMenu() {
    printf("\n*** Music Library Management System ***\n");
    printf("1. Add Music\n");
    printf("2. List Music\n");
    printf("3. Search Music by Artist\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                listMusic(&library);
                break;
            case 3:
                searchMusicByArtist(&library);
                break;
            case 4:
                deleteMusic(&library);
                break;
            case 5:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}