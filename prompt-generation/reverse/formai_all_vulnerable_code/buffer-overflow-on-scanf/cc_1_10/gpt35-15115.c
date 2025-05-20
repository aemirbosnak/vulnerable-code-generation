//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define constants for the program
#define MAX_LIBRARIES 5
#define MAX_SONGS 100

// Define the structure for songs
typedef struct {
    char title[50];
    char artist[50];
    int year;
    float length;
} Song;

// Define the structure for libraries
typedef struct {
    char name[50];
    Song songs[MAX_SONGS];
    int numSongs;
} MusicLibrary;

// Function to add a new song to a library
void addSong(MusicLibrary *library) {
    if (library->numSongs >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, 50, stdin);
    printf("Enter artist name: ");
    fgets(newSong.artist, 50, stdin);
    printf("Enter year of release: ");
    scanf("%d", &newSong.year);
    printf("Enter length (in minutes): ");
    scanf("%f", &newSong.length);
    getchar();

    library->songs[library->numSongs] = newSong;
    library->numSongs++;
    printf("Song added successfully!\n");
}

// Function to display all songs in a library
void displaySongs(MusicLibrary *library) {
    if (library->numSongs == 0) {
        printf("No songs in library!\n");
        return;
    }

    printf("Title\tArtist\tYear\tLength\n");
    for (int i = 0; i < library->numSongs; i++) {
        printf("%s\t%s\t%d\t%.2f\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year, library->songs[i].length);
    }
}

int main() {
    int choice;
    MusicLibrary libraries[MAX_LIBRARIES];
    int numLibraries = 0;

    // Loop to display menu and handle user input
    while (1) {
        printf("\n");
        printf("1. Add library\n");
        printf("2. Add song to library\n");
        printf("3. Display songs in library\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (numLibraries >= MAX_LIBRARIES) {
                    printf("Cannot add more libraries!\n");
                    break;
                }

                printf("Enter library name: ");
                fgets(libraries[numLibraries].name, 50, stdin);
                libraries[numLibraries].numSongs = 0;
                numLibraries++;
                printf("Library added successfully!\n");
                break;
            case 2:
                if (numLibraries == 0) {
                    printf("No libraries available! Please add a library first.\n");
                    break;
                }

                printf("Enter library number (1-%d): ", numLibraries);
                int libNum;
                scanf("%d", &libNum);
                getchar();

                if (libNum < 1 || libNum > numLibraries) {
                    printf("Invalid library number!\n");
                    break;
                }

                addSong(&libraries[libNum-1]);
                break;
            case 3:
                if (numLibraries == 0) {
                    printf("No libraries available! Please add a library first.\n");
                    break;
                }

                printf("Enter library number (1-%d): ", numLibraries);
                scanf("%d", &libNum);
                getchar();

                if (libNum < 1 || libNum > numLibraries) {
                    printf("Invalid library number!\n");
                    break;
                }

                printf("\nSongs in library %d - %s:\n", libNum, libraries[libNum-1].name);
                displaySongs(&libraries[libNum-1]);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}