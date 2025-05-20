//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Music;

void addMusic(Music *musicLibrary, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }
    printf("Enter the title of the music: ");
    getchar(); // To consume possible newline
    fgets(musicLibrary[*count].title, sizeof(musicLibrary[*count].title), stdin);
    musicLibrary[*count].title[strcspn(musicLibrary[*count].title, "\n")] = 0; // Remove newline

    printf("Enter the artist: ");
    fgets(musicLibrary[*count].artist, sizeof(musicLibrary[*count].artist), stdin);
    musicLibrary[*count].artist[strcspn(musicLibrary[*count].artist, "\n")] = 0; // Remove newline

    printf("Enter the genre: ");
    fgets(musicLibrary[*count].genre, sizeof(musicLibrary[*count].genre), stdin);
    musicLibrary[*count].genre[strcspn(musicLibrary[*count].genre, "\n")] = 0; // Remove newline

    printf("Enter the year: ");
    scanf("%d", &musicLibrary[*count].year);

    (*count)++;
    printf("Music added successfully!\n");
}

void displayMusic(const Music *musicLibrary, int count) {
    if (count == 0) {
        printf("No music found in the library.\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", musicLibrary[i].title);
        printf("Artist: %s\n", musicLibrary[i].artist);
        printf("Genre: %s\n", musicLibrary[i].genre);
        printf("Year: %d\n", musicLibrary[i].year);
        printf("---------------------------\n");
    }
}

void searchMusic(const Music *musicLibrary, int count) {
    char title[100];
    printf("Enter the title of the music to search: ");
    getchar(); // To consume possible newline
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            printf("Found Music:\n");
            printf("Title: %s\n", musicLibrary[i].title);
            printf("Artist: %s\n", musicLibrary[i].artist);
            printf("Genre: %s\n", musicLibrary[i].genre);
            printf("Year: %d\n", musicLibrary[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void deleteMusic(Music *musicLibrary, int *count) {
    char title[100];
    printf("Enter the title of the music to delete: ");
    getchar(); // To consume possible newline
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                musicLibrary[j] = musicLibrary[j + 1];
            }
            (*count)--;
            printf("Music deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

int main() {
    Music musicLibrary[MAX_MUSIC];
    int musicCount = 0;
    int choice;

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(musicLibrary, &musicCount);
                break;
            case 2:
                displayMusic(musicLibrary, musicCount);
                break;
            case 3:
                searchMusic(musicLibrary, musicCount);
                break;
            case 4:
                deleteMusic(musicLibrary, &musicCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}