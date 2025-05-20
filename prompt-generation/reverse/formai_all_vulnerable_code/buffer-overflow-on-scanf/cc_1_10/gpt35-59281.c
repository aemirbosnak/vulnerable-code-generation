//FormAI DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char title[100];
    char artist[50];
} song;

//Function prototypes
void addSong(song *library, int *count);
void displayLibrary(song *library, int count);
void searchSongByTitle(song *library, int count, char *search);
void searchSongByArtist(song *library, int count, char *search);
void deleteSong(song *library, int *count, int id);
void sortLibrary(song *library, int count);

int main() {
    song library[100]; // Create song library for 100 songs
    int count = 0, choice, id;
    char search[50];

    do {
        printf("======= C Music Library Management System =======\n");
        printf("1. Add Song\n");
        printf("2. Display Library\n");
        printf("3. Search Song by Title\n");
        printf("4. Search Song by Artist\n");
        printf("5. Delete Song\n");
        printf("6. Sort Library\n");
        printf("7. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(library, &count);
                break;
            case 2:
                displayLibrary(library, count);
                break;
            case 3:
                printf("Please enter song title to search: ");
                scanf("%s", search);
                searchSongByTitle(library, count, search);
                break;
            case 4:
                printf("Please enter artist name to search: ");
                scanf("%s", search);
                searchSongByArtist(library, count, search);
                break;
            case 5:
                printf("Please enter ID of the song to delete: ");
                scanf("%d", &id);
                deleteSong(library, &count, id);
                break;
            case 6:
                sortLibrary(library, count);
                printf("Library sorted successfully!\n");
                break;
            case 7:
                printf("Thank you for using C Music Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

    } while (1);

    return 0;
}

//Function to add a song to the library
void addSong(song *library, int *count) {
    song newSong;

    printf("Please enter the Song ID (Numeric): ");
    scanf("%d", &newSong.id);
    printf("Please enter the Song Title: ");
    scanf(" %[^\n]s", newSong.title);
    printf("Please enter the Song Artist: ");
    scanf(" %[^\n]s", newSong.artist);

    library[*count] = newSong;
    (*count)++;

    printf("Song added successfully!\n");
}

//Function to display the library
void displayLibrary(song *library, int count) {
    printf("\n============= Music Library =============\n");
    printf("ID \t Title \t\t Artist\n");
    printf("========================================\n");

    for (int i = 0; i < count; i++) {
        printf("%d \t %s \t %s\n", library[i].id, library[i].title, library[i].artist);
    }
}

//Function to search a song by title
void searchSongByTitle(song *library, int count, char *search) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, search) != NULL) {
            printf("%d \t %s \t %s\n", library[i].id, library[i].title, library[i].artist);
            found = 1;
        }
    }

    if (!found) {
        printf("Sorry, no songs found matching the search criteria.\n");
    }
}

//Function to search a song by artist
void searchSongByArtist(song *library, int count, char *search) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(library[i].artist, search) != NULL) {
            printf("%d \t %s \t %s\n", library[i].id, library[i].title, library[i].artist);
            found = 1;
        }
    }

    if (!found) {
        printf("Sorry, no songs found matching the search criteria.\n");
    }
}

//Function to delete a song from the library
void deleteSong(song *library, int *count, int id) {
    int i, j, found = 0;

    for (i = 0; i < *count; i++) {
        if (library[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (j = i; j < *count - 1; j++) {
            library[j] = library[j + 1];
        }
        (*count)--;
        printf("Song deleted successfully!\n");
    } else {
        printf("Sorry, no songs found matching the given ID.\n");
    }
}

//Function to sort songs in the library
void sortLibrary(song *library, int count) {
    int i, j;
    song temp;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(library[i].title, library[j].title) > 0) {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }
}