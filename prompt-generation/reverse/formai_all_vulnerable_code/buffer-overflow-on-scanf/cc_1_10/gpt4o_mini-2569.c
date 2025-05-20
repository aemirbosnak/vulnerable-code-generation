//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // Duration in seconds
} Music;

void addMusic(Music musicLibrary[], int *count);
void displayMusic(const Music musicLibrary[], int count);
void deleteMusic(Music musicLibrary[], int *count);
void searchMusic(const Music musicLibrary[], int count);
void menu();

int main() {
    Music musicLibrary[MAX_MUSIC];
    int count = 0;
    int option;

    while (1) {
        menu();
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // to consume the newline character after scanf

        switch (option) {
            case 1:
                addMusic(musicLibrary, &count);
                break;
            case 2:
                displayMusic(musicLibrary, count);
                break;
            case 3:
                deleteMusic(musicLibrary, &count);
                break;
            case 4:
                searchMusic(musicLibrary, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void menu() {
    printf("\n------ Music Library Management System ------\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Delete Music\n");
    printf("4. Search Music\n");
    printf("5. Exit\n");
}

void addMusic(Music musicLibrary[], int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }
    Music newMusic;
    printf("Enter the title of the music: ");
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline character

    printf("Enter the artist of the music: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // Remove newline character

    printf("Enter the duration of the music in seconds: ");
    scanf("%d", &newMusic.duration);
    getchar(); // to consume the newline character after scanf

    musicLibrary[*count] = newMusic;
    (*count)++;
    printf("Music added successfully!\n");
}

void displayMusic(const Music musicLibrary[], int count) {
    if (count == 0) {
        printf("No music available in the library.\n");
        return;
    }
    printf("\n------ Music Library ------\n");
    for (int i = 0; i < count; i++) {
        printf("Music #%d:\n", i + 1);
        printf("Title: %s\n", musicLibrary[i].title);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Duration: %d seconds\n", musicLibrary[i].duration);
        printf("-------------------------\n");
    }
}

void deleteMusic(Music musicLibrary[], int *count) {
    if (*count == 0) {
        printf("No music available to delete.\n");
        return;
    }
    int i;
    printf("Enter the index of the music to delete (1-%d): ", *count);
    scanf("%d", &i);
    getchar(); // to consume the newline character after scanf
    
    if (i < 1 || i > *count) {
        printf("Invalid index!\n");
        return;
    }
    
    for (int j = i - 1; j < *count - 1; j++) {
        musicLibrary[j] = musicLibrary[j + 1];
    }
    (*count)--;
    printf("Music deleted successfully!\n");
}

void searchMusic(const Music musicLibrary[], int count) {
    if (count == 0) {
        printf("No music available for search.\n");
        return;
    }
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the music to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("Music found!\n");
            printf("Title: %s\n", musicLibrary[i].title);
            printf("Artist: %s\n", musicLibrary[i].artist);
            printf("Duration: %d seconds\n", musicLibrary[i].duration);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}