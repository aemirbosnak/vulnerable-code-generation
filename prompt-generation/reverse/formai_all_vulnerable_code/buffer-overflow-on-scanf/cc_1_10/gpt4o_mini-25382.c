//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 50
#define MAX_ARTIST 50
#define MAX_ALBUM 50

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char album[MAX_ALBUM];
    int year;
} Music;

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Music\n");
    printf("2. View All Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("========================================\n");
    printf("Select an option: ");
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    Music newMusic;
    printf("Enter title: ");
    getchar(); // consume the newline character
    fgets(newMusic.title, MAX_TITLE, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove new line
    printf("Enter artist: ");
    fgets(newMusic.artist, MAX_ARTIST, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;
    printf("Enter album: ");
    fgets(newMusic.album, MAX_ALBUM, stdin);
    newMusic.album[strcspn(newMusic.album, "\n")] = 0;
    printf("Enter year: ");
    scanf("%d", &newMusic.year);
    
    library[*count] = newMusic;
    (*count)++;
    printf("Music added successfully!\n");
}

void viewAllMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library.\n");
        return;
    }
    printf("\nList of Music:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Album: %s, Year: %d\n",
               library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

void searchMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library.\n");
        return;
    }
    char searchTitle[MAX_TITLE];
    printf("Enter title to search: ");
    getchar();
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, searchTitle) != NULL) {
            printf("Found: Title: %s, Artist: %s, Album: %s, Year: %d\n",
                   library[i].title, library[i].artist, library[i].album, library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found with the title '%s'.\n", searchTitle);
    }
}

void deleteMusic(Music *library, int *count) {
    if (*count == 0) {
        printf("No music in the library.\n");
        return;
    }
    char deleteTitle[MAX_TITLE];
    printf("Enter title to delete: ");
    getchar();
    fgets(deleteTitle, MAX_TITLE, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1]; // Shifting elements to the left
            }
            (*count)--;
            printf("Music deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("No music found with the title '%s' to delete.\n", deleteTitle);
    }
}

int main() {
    Music library[MAX_MUSIC];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMusic(library, &count);
                break;
            case 2:
                viewAllMusic(library, count);
                break;
            case 3:
                searchMusic(library, count);
                break;
            case 4:
                deleteMusic(library, &count);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
        }
    }
    return 0;
}