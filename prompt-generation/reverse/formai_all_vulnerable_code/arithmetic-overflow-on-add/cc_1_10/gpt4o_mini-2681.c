//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    float duration; // in minutes
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

// Function prototypes
void displayMenu();
void addSong(MusicLibrary* library);
void viewSongs(const MusicLibrary* library);
void deleteSong(MusicLibrary* library);
void searchSong(const MusicLibrary* library);
void saveLibrary(const MusicLibrary* library, const char* filename);
void loadLibrary(MusicLibrary* library, const char* filename);

int main() {
    MusicLibrary library;
    library.count = 0;
    
    loadLibrary(&library, "music_library.txt");

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSong(&library);
                break;
            case 2:
                viewSongs(&library);
                break;
            case 3:
                deleteSong(&library);
                break;
            case 4:
                searchSong(&library);
                break;
            case 5:
                saveLibrary(&library, "music_library.txt");
                printf("Library saved successfully!\n");
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

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Delete Song\n");
    printf("4. Search Song\n");
    printf("5. Save Library\n");
    printf("6. Exit\n");
}

void addSong(MusicLibrary* library) {
    if (library->count >= MAX_SONGS) {
        printf("Music library is full! Can't add more songs.\n");
        return;
    }
    
    Song newSong;
    printf("Enter song title: ");
    getchar(); // clear the newline character from previous input
    fgets(newSong.title, MAX_TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // remove newline

    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // remove newline
    
    printf("Enter song duration (in minutes): ");
    scanf("%f", &newSong.duration);
    
    library->songs[library->count++] = newSong;
    printf("Song added successfully!\n");
}

void viewSongs(const MusicLibrary* library) {
    if (library->count == 0) {
        printf("No songs in the library!\n");
        return;
    }
    
    printf("\n--- List of Songs ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s, Artist: %s, Duration: %.2f mins\n", 
               i + 1, library->songs[i].title, 
               library->songs[i].artist, library->songs[i].duration);
    }
}

void deleteSong(MusicLibrary* library) {
    if (library->count == 0) {
        printf("No songs to delete!\n");
        return;
    }

    viewSongs(library);
    
    int index;
    printf("Enter the number of the song to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > library->count) {
        printf("Invalid song number!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->count--;
    printf("Song deleted successfully!\n");
}

void searchSong(const MusicLibrary* library) {
    if (library->count == 0) {
        printf("No songs to search!\n");
        return;
    }
    
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter song title to search: ");
    getchar(); // clear the newline character
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->songs[i].title, searchTitle) != NULL) {
            printf("%d. Title: %s, Artist: %s, Duration: %.2f mins\n",
                   i + 1, library->songs[i].title,
                   library->songs[i].artist, library->songs[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs found with that title!\n");
    }
}

void saveLibrary(const MusicLibrary* library, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for writing!\n");
        return;
    }
    for (int i = 0; i < library->count; i++) {
        fprintf(file, "%s|%s|%.2f\n", library->songs[i].title, 
                library->songs[i].artist, library->songs[i].duration);
    }
    fclose(file);
}

void loadLibrary(MusicLibrary* library, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No existing library found, starting fresh!\n");
        return;
    }
    while (fscanf(file, "%[^|]|%[^|]|%f\n", library->songs[library->count].title, 
           library->songs[library->count].artist, &library->songs[library->count].duration) != EOF) {
        library->count++;
    }
    fclose(file);
}