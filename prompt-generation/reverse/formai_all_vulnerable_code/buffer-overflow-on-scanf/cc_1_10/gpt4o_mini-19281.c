//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Music;

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add New Music\n");
    printf("2. View All Music\n");
    printf("3. Search Music by Title\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSICS) {
        printf("Library is full.\n");
        return;
    }
    printf("Enter music title: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", library[*count].artist);
    printf("Enter release year: ");
    scanf("%d", &library[*count].year);
    (*count)++;
    printf("Music added successfully!\n");
}

void viewMusic(Music *library, int count) {
    printf("\nCurrent Music Library:\n");
    if (count == 0) {
        printf("No music in the library.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", 
                library[i].title, library[i].artist, library[i].year);
    }
}

void searchMusic(Music *library, int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter music title to search: ");
    scanf(" %[^\n]", title);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Found music - Title: %s, Artist: %s, Year: %d\n", 
                    library[i].title, library[i].artist, library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found.\n");
    }
}

void deleteMusic(Music *library, int *count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter music title to delete: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Music deleted successfully!\n");
            return;
        }
    }
    printf("Music not found for deletion.\n");
}

int main() {
    Music library[MAX_MUSICS];
    int musicCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic(library, &musicCount);
                break;
            case 2:
                viewMusic(library, musicCount);
                break;
            case 3:
                searchMusic(library, musicCount);
                break;
            case 4:
                deleteMusic(library, &musicCount);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}