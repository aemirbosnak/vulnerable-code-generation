//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
} Song;

Song library[MAX_SONGS];
int song_count = 0;

void addSong() {
    if (song_count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }
    Song new_song;
    printf("Enter song title: ");
    getchar(); // To clear buffer
    fgets(new_song.title, MAX_LENGTH, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(new_song.artist, MAX_LENGTH, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &new_song.year);

    library[song_count++] = new_song;
    printf("Song added successfully!\n");
}

void viewSongs() {
    if (song_count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    printf("Songs in the library:\n");
    for (int i = 0; i < song_count; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n",
                library[i].title, library[i].artist, library[i].year);
    }
}

void searchSong() {
    char search_title[MAX_LENGTH];
    printf("Enter the title of the song to search: ");
    getchar(); // To clear buffer
    fgets(search_title, MAX_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < song_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) {
            printf("Found: Title: %s, Artist: %s, Year: %d\n",
                    library[i].title, library[i].artist, library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found in the library.\n");
    }
}

void saveLibrary() {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Could not open file to save the library.\n");
        return;
    }
    for (int i = 0; i < song_count; i++) {
        fprintf(file, "%s\n%s\n%d\n", library[i].title, library[i].artist, library[i].year);
    }
    fclose(file);
    printf("Library saved successfully to music_library.txt!\n");
}

void loadLibrary() {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("Could not open file to load the library.\n");
        return;
    }
    while (!feof(file) && song_count < MAX_SONGS) {
        fgets(library[song_count].title, MAX_LENGTH, file);
        library[song_count].title[strcspn(library[song_count].title, "\n")] = 0; // Remove newline

        fgets(library[song_count].artist, MAX_LENGTH, file);
        library[song_count].artist[strcspn(library[song_count].artist, "\n")] = 0; // Remove newline

        fscanf(file, "%d\n", &library[song_count].year);
        song_count++;
    }
    fclose(file);
    printf("Library loaded successfully! %d songs loaded.\n", song_count);
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Search Song\n");
    printf("4. Save Library\n");
    printf("5. Load Library\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    loadLibrary();
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                viewSongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                saveLibrary();
                break;
            case 5:
                loadLibrary();
                break;
            case 6:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}