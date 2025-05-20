//FormAI DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

struct songLibrary {
    struct song songs[100];
    int count;
};

struct songLibrary library;

void addSong() {
    char title[50], artist[50], album[50], yearStr[10];
    int year;

    printf("Please enter the song title: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Please enter the artist name: ");
    fgets(artist, 50, stdin);
    artist[strcspn(artist, "\n")] = '\0';

    printf("Please enter the album name: ");
    fgets(album, 50, stdin);
    album[strcspn(album, "\n")] = '\0';

    printf("Please enter the year of release: ");
    fgets(yearStr, 10, stdin);
    yearStr[strcspn(yearStr, "\n")] = '\0';
    year = atoi(yearStr);

    struct song newSong;
    strcpy(newSong.title, title);
    strcpy(newSong.artist, artist);
    strcpy(newSong.album, album);
    newSong.year = year;

    library.songs[library.count] = newSong;
    library.count++;

    printf("Song added successfully!\n");
}

void displaySongs() {
    if (library.count == 0) {
        printf("No songs in the library.\n");
    } else {
        printf("%-30s %-30s %-30s %s\n", "Title", "Artist", "Album", "Year");
        for (int i = 0; i < library.count; i++) {
            printf("%-30s %-30s %-30s %d\n", library.songs[i].title, library.songs[i].artist, library.songs[i].album, library.songs[i].year);
        }
    }
}

void saveToFile() {
    FILE *fptr;
    fptr = fopen("songLibrary.txt", "w");

    if (fptr == NULL) {
        printf("Error in saving to file.\n");
    } else {
        fprintf(fptr, "%-30s %-30s %-30s %s\n", "Title", "Artist", "Album", "Year");
        for (int i = 0; i < library.count; i++) {
            fprintf(fptr, "%-30s %-30s %-30s %d\n", library.songs[i].title, library.songs[i].artist, library.songs[i].album, library.songs[i].year);
        }
        printf("Songs saved to file successfully!\n");
    }

    fclose(fptr);
}

void loadFromFile() {
    FILE *fptr;
    fptr = fopen("songLibrary.txt", "r");

    if (fptr == NULL) {
        printf("Error in loading from file.\n");
    } else {
        char line[200], *token;
        fgets(line, 200, fptr);  // skip header line
        
        while (fgets(line, 200, fptr) != NULL) {
            struct song newSong;

            token = strtok(line, " ");
            strcpy(newSong.title, token);

            token = strtok(NULL, " ");
            strcpy(newSong.artist, token);

            token = strtok(NULL, " ");
            strcpy(newSong.album, token);

            token = strtok(NULL, " ");
            newSong.year = atoi(token);

            library.songs[library.count] = newSong;
            library.count++;
        }

        printf("Songs loaded from file successfully!\n");
    }

    fclose(fptr);
}

int main() {
    library.count = 0;

    printf("=== C Music Library Management System ===\n");
    printf("1. Add Song\n");
    printf("2. Display All Songs\n");
    printf("3. Save Songs to File\n");
    printf("4. Load Songs from File\n");
    printf("5. Exit\n");

    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                loadFromFile();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}