//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Album;

void addAlbum(Album *collection, int *count) {
    if (*count >= MAX_ALBUMS) {
        printf("Collection is full. Cannot add more albums.\n");
        return;
    }

    Album new_album;
    printf("Enter album title: ");
    scanf(" %[^\n]", new_album.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", new_album.artist);
    printf("Enter release year: ");
    scanf("%d", &new_album.year);

    collection[*count] = new_album;
    (*count)++;
    printf("Album added successfully!\n");
}

void viewAlbums(Album *collection, int count) {
    if (count == 0) {
        printf("No albums in the collection.\n");
        return;
    }

    printf("\nAlbums in the collection:\n");
    for (int i = 0; i < count; i++) {
        printf("Album %d: %s by %s (%d)\n", i + 1, collection[i].title, collection[i].artist, collection[i].year);
    }
}

void deleteAlbum(Album *collection, int *count) {
    if (*count == 0) {
        printf("No albums to delete.\n");
        return;
    }

    int index;
    printf("Enter the album number to delete (1 to %d): ", *count);
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid album number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        collection[i] = collection[i + 1];
    }
    
    (*count)--;
    printf("Album deleted successfully!\n");
}

void displayMenu() {
    printf("\n---- Music Library Management System ----\n");
    printf("1. Add Album\n");
    printf("2. View Albums\n");
    printf("3. Delete Album\n");
    printf("4. Exit\n");
    printf("-----------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    Album collection[MAX_ALBUMS];
    int albumCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum(collection, &albumCount);
                break;
            case 2:
                viewAlbums(collection, albumCount);
                break;
            case 3:
                deleteAlbum(collection, &albumCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}