//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define ALBUM_NAME_LEN 100
#define ARTIST_NAME_LEN 100
#define GENRE_LEN 50

typedef struct {
    char albumName[ALBUM_NAME_LEN];
    char artistName[ARTIST_NAME_LEN];
    char genre[GENRE_LEN];
    int releaseYear;
} Album;

void addAlbum();
void viewAlbums();
void searchAlbum();
void deleteAlbum();
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from buffer

        switch(choice) {
            case 1: addAlbum(); break;
            case 2: viewAlbums(); break;
            case 3: searchAlbum(); break;
            case 4: deleteAlbum(); break;
            case 5: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n*** Music Library Management System ***\n");
    printf("1. Add Album\n");
    printf("2. View Albums\n");
    printf("3. Search Album\n");
    printf("4. Delete Album\n");
    printf("5. Exit\n");
}

void addAlbum() {
    FILE *file = fopen("music_library.txt", "a");
    Album newAlbum;

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter album name: ");
    fgets(newAlbum.albumName, ALBUM_NAME_LEN, stdin);
    newAlbum.albumName[strcspn(newAlbum.albumName, "\n")] = 0;  // Remove newline

    printf("Enter artist name: ");
    fgets(newAlbum.artistName, ARTIST_NAME_LEN, stdin);
    newAlbum.artistName[strcspn(newAlbum.artistName, "\n")] = 0;  // Remove newline

    printf("Enter genre: ");
    fgets(newAlbum.genre, GENRE_LEN, stdin);
    newAlbum.genre[strcspn(newAlbum.genre, "\n")] = 0;  // Remove newline

    printf("Enter release year: ");
    scanf("%d", &newAlbum.releaseYear);
    getchar();  // Clear newline character from buffer

    fwrite(&newAlbum, sizeof(Album), 1, file);
    fclose(file);

    printf("Album added successfully!\n");
}

void viewAlbums() {
    FILE *file = fopen("music_library.txt", "r");
    Album tempAlbum;

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n*** Music Library ***\n");
    while (fread(&tempAlbum, sizeof(Album), 1, file)) {
        printf("Album Name: %s\n", tempAlbum.albumName);
        printf("Artist Name: %s\n", tempAlbum.artistName);
        printf("Genre: %s\n", tempAlbum.genre);
        printf("Release Year: %d\n", tempAlbum.releaseYear);
        printf("--------------------------\n");
    }

    fclose(file);
}

void searchAlbum() {
    FILE *file = fopen("music_library.txt", "r");
    Album tempAlbum;
    char searchTitle[ALBUM_NAME_LEN];
    int found = 0;

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter album name to search: ");
    fgets(searchTitle, ALBUM_NAME_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;  // Remove newline

    while (fread(&tempAlbum, sizeof(Album), 1, file)) {
        if (strcmp(tempAlbum.albumName, searchTitle) == 0) {
            found = 1;
            printf("Album Found:\n");
            printf("Album Name: %s\n", tempAlbum.albumName);
            printf("Artist Name: %s\n", tempAlbum.artistName);
            printf("Genre: %s\n", tempAlbum.genre);
            printf("Release Year: %d\n", tempAlbum.releaseYear);
            break;
        }
    }

    if (!found) {
        printf("Album not found!\n");
    }

    fclose(file);
}

void deleteAlbum() {
    FILE *file = fopen("music_library.txt", "r");
    FILE *tempFile = fopen("temp_library.txt", "w");
    Album tempAlbum;
    char deleteTitle[ALBUM_NAME_LEN];
    int found = 0;

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter album name to delete: ");
    fgets(deleteTitle, ALBUM_NAME_LEN, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0;  // Remove newline

    while (fread(&tempAlbum, sizeof(Album), 1, file)) {
        if (strcmp(tempAlbum.albumName, deleteTitle) != 0) {
            fwrite(&tempAlbum, sizeof(Album), 1, tempFile);
        } else {
            found = 1;  // Found the album to delete
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("music_library.txt");
    rename("temp_library.txt", "music_library.txt");

    if (found) {
        printf("Album '%s' deleted successfully!\n", deleteTitle);
    } else {
        printf("Album not found for deletion!\n");
    }
}