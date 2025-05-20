//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
    char genre[MAX_TITLE];
} Music;

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Music\n");
    printf("2. Display All Music\n");
    printf("3. Search by Title\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Please choose an option: ");
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    printf("Enter title: ");
    getchar(); // To consume newline character from previous input
    fgets(library[*count].title, MAX_TITLE, stdin);
    strtok(library[*count].title, "\n"); // Remove newline character

    printf("Enter artist: ");
    fgets(library[*count].artist, MAX_ARTIST, stdin);
    strtok(library[*count].artist, "\n"); // Remove newline character

    printf("Enter year: ");
    scanf("%d", &library[*count].year);
    getchar(); // To consume newline character

    printf("Enter genre: ");
    fgets(library[*count].genre, MAX_TITLE, stdin);
    strtok(library[*count].genre, "\n"); // Remove newline character

    (*count)++;
    printf("Music added successfully!\n");
}

void displayAllMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music found in the library.\n");
        return;
    }
    printf("\n=== Music Library ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s | Artist: %s | Year: %d | Genre: %s\n",
               i + 1, library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
}

void searchMusic(Music *library, int count) {
    char title[MAX_TITLE];
    printf("Enter title to search: ");
    getchar(); // To consume newline character
    fgets(title, MAX_TITLE, stdin);
    strtok(title, "\n"); // Remove newline character

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            printf("Found Music - Title: %s | Artist: %s | Year: %d | Genre: %s\n",
                   library[i].title, library[i].artist, library[i].year, library[i].genre);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found with the title: %s\n", title);
    }
}

void deleteMusic(Music *library, int *count) {
    int index;
    if (*count == 0) {
        printf("No music to delete.\n");
        return;
    }

    printf("Enter the index of music to delete (1 to %d): ", *count);
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        library[i] = library[i + 1];
    }
    (*count)--;
    printf("Music deleted successfully!\n");
}

int main() {
    Music library[MAX_MUSIC];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(library, &count);
                break;
            case 2:
                displayAllMusic(library, count);
                break;
            case 3:
                searchMusic(library, count);
                break;
            case 4:
                deleteMusic(library, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}