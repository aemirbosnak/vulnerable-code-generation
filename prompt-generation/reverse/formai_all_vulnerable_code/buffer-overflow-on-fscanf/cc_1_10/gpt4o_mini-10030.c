//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
} Song;

void addSong(Song *library, int *count);
void displaySongs(Song *library, int count);
void searchSong(Song *library, int count);
void saveToFile(Song *library, int count);
void loadFromFile(Song *library, int *count);

// Function to add a song to the library
void addSong(Song *library, int *count) {
    if (*count >= MAX_SONGS) {
        printf("Music library is full! Cannot add more songs.\n");
        return;
    }
    
    printf("Enter the title of the song: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter the artist's name: ");
    scanf(" %[^\n]", library[*count].artist);
    printf("Enter the album name: ");
    scanf(" %[^\n]", library[*count].album);
    printf("Enter the release year: ");
    scanf("%d", &library[*count].year);
    
    (*count)++;
    printf("Song added successfully!\n");
}

// Function to display all songs in the library
void displaySongs(Song *library, int count) {
    if (count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < count; i++) {
        printf("Song %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
    }
}

// Function to search for a song by title
void searchSong(Song *library, int count) {
    char searchTitle[MAX_LENGTH];
    printf("Enter the title of the song you want to search for: ");
    scanf(" %[^\n]", searchTitle);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            found = 1;
            printf("Song found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            break;
        }
    }
    
    if (!found) {
        printf("Song not found in the library.\n");
    }
}

// Function to save songs to a file
void saveToFile(Song *library, int count) {
    FILE *file = fopen("music_library.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s|%s|%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
    
    fclose(file);
    printf("Library saved successfully!\n");
}

// Function to load songs from a file
void loadFromFile(Song *library, int *count) {
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    while (fscanf(file, " %[^|]|%[^|]|%[^|]|%d\n", library[*count].title, library[*count].artist, library[*count].album, &library[*count].year) != EOF) {
        (*count)++;
    }
    
    fclose(file);
    printf("Library loaded successfully!\n");
}

int main() {
    Song library[MAX_SONGS];
    int count = 0;

    loadFromFile(library, &count);
    
    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search Song\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSong(library, &count);
                break;
            case 2:
                displaySongs(library, count);
                break;
            case 3:
                searchSong(library, count);
                break;
            case 4:
                saveToFile(library, count);
                break;
            case 5:
                loadFromFile(library, &count);
                break;
            case 6:
                printf("Thank you for using the Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}