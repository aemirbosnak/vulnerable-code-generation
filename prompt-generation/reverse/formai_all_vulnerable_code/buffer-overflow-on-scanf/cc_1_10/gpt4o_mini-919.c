//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music details
typedef struct {
    char title[50];
    char artist[50];
    char genre[30];
    int year;
} Music;

// Function prototypes
void addMusic(Music *library, int *count);
void displayMusic(Music *library, int count);
void searchMusic(Music *library, int count);
void deleteMusic(Music *library, int *count);
void menu();

int main() {
    Music library[100]; // Array to store music collection
    int count = 0; // Count of added music
    menu(library, &count);
    return 0;
}

void menu(Music *library, int *count) {
    int choice;
    do {
        printf("\n----- Music Library Management System -----\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(library, count);
                break;
            case 2:
                displayMusic(library, *count);
                break;
            case 3:
                searchMusic(library, *count);
                break;
            case 4:
                deleteMusic(library, count);
                break;
            case 5:
                printf("Goodbye! Keep listening to great music!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);
}

void addMusic(Music *library, int *count) {
    if (*count >= 100) {
        printf("Library is full! Can't add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter music title: ");
    getchar(); // Clear the newline character from input buffer
    fgets(newMusic.title, sizeof(newMusic.title), stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove the newline character

    printf("Enter artist name: ");
    fgets(newMusic.artist, sizeof(newMusic.artist), stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;

    printf("Enter genre: ");
    fgets(newMusic.genre, sizeof(newMusic.genre), stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);

    library[*count] = newMusic; // Add new music to library
    (*count)++; // Increment count
    printf("Music added successfully!\n");
}

void displayMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library!\n");
        return;
    }
    printf("\n----- Music Library -----\n");
    for (int i = 0; i < count; i++) {
        printf("Music #%d: \n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("Year: %d\n\n", library[i].year);
    }
}

void searchMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library to search!\n");
        return;
    }

    char searchTitle[50];
    printf("Enter the title of the music to search: ");
    getchar(); // Clear the input buffer
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Music found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music with title \"%s\" not found in the library.\n", searchTitle);
    }
}

void deleteMusic(Music *library, int *count) {
    if (*count == 0) {
        printf("No music to delete!\n");
        return;
    }

    char deleteTitle[50];
    printf("Enter the title of the music to delete: ");
    getchar(); // Clear the input buffer
    fgets(deleteTitle, sizeof(deleteTitle), stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, deleteTitle) == 0) {
            // Shift music down to remove the entry
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--; // Decrease count
            found = 1;
            printf("Music \"%s\" deleted successfully!\n", deleteTitle);
            break;
        }
    }
    if (!found) {
        printf("Music with title \"%s\" not found! Nothing deleted.\n", deleteTitle);
    }
}