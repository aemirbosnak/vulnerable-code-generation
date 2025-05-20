//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 30
#define GENRE_LENGTH 20

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char genre[GENRE_LENGTH];
    int year;
} Music;

void addMusic(Music *collection, int *count) {
    if (*count >= MAX_MUSICS) {
        printf("Music collection is full!\n");
        return;
    }

    printf("Enter music title: ");
    getchar(); // To consume the newline character
    fgets(collection[*count].title, TITLE_LENGTH, stdin);
    collection[*count].title[strcspn(collection[*count].title, "\n")] = 0; // Remove newline

    printf("Enter music artist: ");
    fgets(collection[*count].artist, ARTIST_LENGTH, stdin);
    collection[*count].artist[strcspn(collection[*count].artist, "\n")] = 0; // Remove newline

    printf("Enter music genre: ");
    fgets(collection[*count].genre, GENRE_LENGTH, stdin);
    collection[*count].genre[strcspn(collection[*count].genre, "\n")] = 0; // Remove newline

    printf("Enter year of release: ");
    scanf("%d", &collection[*count].year);

    (*count)++;
    printf("Music added successfully!\n");
}

void displayMusics(Music *collection, int count) {
    if (count == 0) {
        printf("No music in the collection.\n");
        return;
    }

    printf("\nMusic Collection:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Year: %d\n",
               collection[i].title, collection[i].artist, collection[i].genre, collection[i].year);
    }
}

void searchMusic(Music *collection, int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter music title to search: ");
    getchar(); // To consume the newline character
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(collection[i].title, searchTitle) == 0) {
            printf("Music found: Title: %s, Artist: %s, Genre: %s, Year: %d\n",
                   collection[i].title, collection[i].artist, collection[i].genre, collection[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found in the collection.\n");
    }
}

void deleteMusic(Music *collection, int *count) {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter music title to delete: ");
    getchar(); // To consume the newline character
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(collection[i].title, deleteTitle) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < *count - 1; i++) {
            collection[i] = collection[i + 1];
        }
        (*count)--;
        printf("Music deleted successfully!\n");
    } else {
        printf("Music not found to delete.\n");
    }
}

int main() {
    Music collection[MAX_MUSICS];
    int count = 0;
    int choice;

    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add Music\n");
        printf("2. Display Musics\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(collection, &count);
                break;
            case 2:
                displayMusics(collection, count);
                break;
            case 3:
                searchMusic(collection, count);
                break;
            case 4:
                deleteMusic(collection, &count);
                break;
            case 5:
                printf("Exiting... Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}