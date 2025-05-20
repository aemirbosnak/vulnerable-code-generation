//FormAI DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    int year;
    char genre[20];
    char album[50];
} Song;

int addSong(Song library[], int size) {
    if (size == 50) {
        printf("Cannot add more songs to the library.\n");
        return size;
    }
    printf("Enter title: ");
    scanf("%s", library[size].title);
    printf("Enter artist: ");
    scanf("%s", library[size].artist);
    printf("Enter year: ");
    scanf("%d", &library[size].year);
    printf("Enter genre: ");
    scanf("%s", library[size].genre);
    printf("Enter album: ");
    scanf("%s", library[size].album);
    size++;
    return size;
}

void displayLibrary(Song library[], int size) {
    printf("Title\tArtist\tYear\tGenre\tAlbum\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%s\t%d\t%s\t%s\n", library[i].title, library[i].artist, library[i].year, library[i].genre, library[i].album);
    }
}

void searchSong(Song library[], int size) {
    char keyword[50];
    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);
    int found = 0;
    printf("Title\tArtist\tYear\tGenre\tAlbum\n");
    for (int i = 0; i < size; i++) {
        if (strstr(library[i].title, keyword) != NULL || strstr(library[i].artist, keyword) != NULL || strstr(library[i].genre, keyword) != NULL || strstr(library[i].album, keyword) != NULL) {
            printf("%s\t%s\t%d\t%s\t%s\n", library[i].title, library[i].artist, library[i].year, library[i].genre, library[i].album);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs with keyword \"%s\" found in the library.\n", keyword);
    }
}

int deleteSong(Song library[], int size) {
    char keyword[50];
    printf("Enter the title of the song to delete: ");
    scanf("%s", keyword);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(library[i].title, keyword) == 0) {
            for (int j = i; j < size; j++) {
                strcpy(library[j].title, library[j+1].title);
                strcpy(library[j].artist, library[j+1].artist);
                library[j].year = library[j+1].year;
                strcpy(library[j].genre, library[j+1].genre);
                strcpy(library[j].album, library[j+1].album);
            }
            found = 1;
            size--;
            break;
        }
    }
    if (found) {
        printf("Song \"%s\" has been deleted from the library.\n", keyword);
    } else {
        printf("Song \"%s\" not found in the library.\n", keyword);
    }
    return size;
}

int main() {
    Song library[50];
    int size = 0;
    int choice = 0;
    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Display the library\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                size = addSong(library, size);
                break;
            case 2:
                displayLibrary(library, size);
                break;
            case 3:
                searchSong(library, size);
                break;
            case 4:
                size = deleteSong(library, size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}