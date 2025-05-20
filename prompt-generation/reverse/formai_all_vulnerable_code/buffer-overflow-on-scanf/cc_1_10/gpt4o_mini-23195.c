//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 50
#define MAX_ARTIST 50

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
    char genre[MAX_TITLE];
} Music;

Music library[MAX_MUSIC];
int music_count = 0;

void addMusic() {
    if (music_count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }

    Music new_music;
    printf("Enter music title: ");
    fgets(new_music.title, MAX_TITLE, stdin);
    new_music.title[strcspn(new_music.title, "\n")] = '\0'; // remove newline

    printf("Enter artist name: ");
    fgets(new_music.artist, MAX_ARTIST, stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = '\0'; // remove newline

    printf("Enter year of release: ");
    scanf("%d", &new_music.year);
    getchar(); // consume newline

    printf("Enter genre: ");
    fgets(new_music.genre, MAX_TITLE, stdin);
    new_music.genre[strcspn(new_music.genre, "\n")] = '\0'; // remove newline

    library[music_count++] = new_music;
    printf("Music added successfully!\n");
}

void viewMusic() {
    if (music_count == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < music_count; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n", 
                library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
}

void searchMusic() {
    char query[MAX_TITLE];
    printf("Enter title or artist to search: ");
    fgets(query, MAX_TITLE, stdin);
    query[strcspn(query, "\n")] = '\0'; // remove newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strstr(library[i].title, query) != NULL || 
            strstr(library[i].artist, query) != NULL) {
            printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n", 
                    library[i].title, library[i].artist, library[i].year, library[i].genre);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found.\n");
    }
}

void deleteMusic() {
    if (music_count == 0) {
        printf("No music to delete.\n");
        return;
    }

    char title[MAX_TITLE];
    printf("Enter the title of the music to delete: ");
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = '\0'; // remove newline

    for (int i = 0; i < music_count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < music_count - 1; j++) {
                library[j] = library[j + 1];
            }
            music_count--;
            printf("Music deleted successfully!\n");
            return;
        }
    }
    printf("Music not found.\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                viewMusic();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}