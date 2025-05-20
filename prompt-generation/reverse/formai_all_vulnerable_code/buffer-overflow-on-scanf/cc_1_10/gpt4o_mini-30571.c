//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: curious
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

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Remove Music\n");
    printf("3. View All Music\n");
    printf("4. Search Music\n");
    printf("5. Exit\n");
    printf("-----------------------------------------\n");
    printf("Choose an option: ");
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }

    printf("Enter title of the music: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", library[*count].artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", library[*count].genre);
    printf("Enter release year: ");
    scanf("%d", &library[*count].year);

    (*count)++;
    printf("Music added successfully!\n");
}

void removeMusic(Music *library, int *count) {
    char title[100];
    printf("Enter the title of the music to remove: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Music removed successfully!\n");
            return;
        }
    }
    printf("Music not found in the library.\n");
}

void viewMusic(const Music *library, int count) {
    if (count == 0) {
        printf("The library is empty!\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Year: %d\n", 
                library[i].title, library[i].artist, library[i].genre, library[i].year);
    }
}

void searchMusic(const Music *library, int count) {
    char title[100];
    printf("Enter the title of the music to search: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Found Music - Title: %s, Artist: %s, Genre: %s, Year: %d\n", 
                    library[i].title, library[i].artist, library[i].genre, library[i].year);
            return;
        }
    }
    printf("Music not found in the library.\n");
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
                removeMusic(library, &count);
                break;
            case 3:
                viewMusic(library, count);
                break;
            case 4:
                searchMusic(library, count);
                break;
            case 5:
                printf("Thank you for using the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again!\n");
        }
    }

    return 0;
}