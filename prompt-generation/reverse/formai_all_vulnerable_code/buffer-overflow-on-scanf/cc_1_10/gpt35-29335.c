//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for artists and albums
struct Artist {
    char name[100];
    int numAlbums;
};

struct Album {
    char name[100];
    char artist[100];
    int year;
    int numTracks;
};

// Define an array to hold the artists and albums
struct Artist artists[100];
struct Album albums[1000];
int numArtists = 0;
int numAlbums = 0;

// Function declarations
void addArtist();
void addAlbum();
void removeAlbum();
void printLibrary();
void printArtist();
void printAlbum();
void clearLibrary();

int main() {
    printf("Welcome to the C Music Library Management System!\n");
    printf("Type 'help' for a list of available commands.\n");

    char command[100];
    while (1) {
        printf("\nEnter a command: ");
        scanf("%s", command);
        if (strcmp(command, "add_artist") == 0) {
            addArtist();
        } else if (strcmp(command, "add_album") == 0) {
            addAlbum();
        } else if (strcmp(command, "remove_album") == 0) {
            removeAlbum();
        } else if (strcmp(command, "print_library") == 0) {
            printLibrary();
        } else if (strcmp(command, "print_artist") == 0) {
            printArtist();
        } else if (strcmp(command, "print_album") == 0) {
            printAlbum();
        } else if (strcmp(command, "clear_library") == 0) {
            clearLibrary();
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("  add_artist\n");
            printf("  add_album\n");
            printf("  remove_album\n");
            printf("  print_library\n");
            printf("  print_artist\n");
            printf("  print_album\n");
            printf("  clear_library\n");
            printf("  help\n");
        } else {
            printf("Unknown command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}

// Function to add a new artist to the library
void addArtist() {
    char name[100];
    printf("Enter the name of the artist: ");
    scanf("%s", name);

    // Check if the artist is already in the library
    for (int i = 0; i < numArtists; i++) {
        if (strcmp(name, artists[i].name) == 0) {
            printf("Artist already in library.\n");
            return;
        }
    }

    struct Artist artist;
    strcpy(artist.name, name);
    artist.numAlbums = 0;
    artists[numArtists] = artist;
    numArtists++;
    printf("Artist added.\n");
}

// Function to add a new album to the library
void addAlbum() {
    char name[100];
    char artist[100];
    int year;
    int numTracks;
    printf("Enter the name of the album: ");
    scanf("%s", name);
    printf("Enter the name of the artist: ");
    scanf("%s", artist);
    printf("Enter the year of release: ");
    scanf("%d", &year);
    printf("Enter the number of tracks: ");
    scanf("%d", &numTracks);

    // Check if the artist is already in the library
    int artistIndex = -1;
    for (int i = 0; i < numArtists; i++) {
        if (strcmp(artist, artists[i].name) == 0) {
            artistIndex = i;
            break;
        }
    }
    if (artistIndex == -1) {
        printf("Artist not found in library.\n");
        return;
    }

    // Check if the album is already in the library
    for (int i = 0; i < numAlbums; i++) {
        if (strcmp(name, albums[i].name) == 0 && strcmp(artist, albums[i].artist) == 0) {
            printf("Album already in library.\n");
            return;
        }
    }

    struct Album album;
    strcpy(album.name, name);
    strcpy(album.artist, artist);
    album.year = year;
    album.numTracks = numTracks;
    albums[numAlbums] = album;
    artists[artistIndex].numAlbums++;
    numAlbums++;
    printf("Album added.\n");
}

// Function to remove an album from the library
void removeAlbum() {
    char name[100];
    char artist[100];
    printf("Enter the name of the album: ");
    scanf("%s", name);
    printf("Enter the name of the artist: ");
    scanf("%s", artist);

    // Find the album in the library
    int albumIndex = -1;
    for (int i = 0; i < numAlbums; i++) {
        if (strcmp(name, albums[i].name) == 0 && strcmp(artist, albums[i].artist) == 0) {
            albumIndex = i;
            break;
        }
    }
    if (albumIndex == -1) {
        printf("Album not found in library.\n");
        return;
    }

    // Remove the album from the library
    for (int i = albumIndex; i < numAlbums - 1; i++) {
        albums[i] = albums[i + 1];
    }
    numAlbums--;

    // Decrement the number of albums by the artist
    int artistIndex = -1;
    for (int i = 0; i < numArtists; i++) {
        if (strcmp(artist, artists[i].name) == 0) {
            artistIndex = i;
            break;
        }
    }
    if (artistIndex == -1) {
        printf("Error: artist not found in library.\n");
        return;
    }
    artists[artistIndex].numAlbums--;
    printf("Album removed.\n");
}

// Function to print the entire library
void printLibrary() {
    printf("Music Library:\n\n");
    for (int i = 0; i < numArtists; i++) {
        printf("%s\n", artists[i].name);
        for (int j = 0; j < numAlbums; j++) {
            if (strcmp(albums[j].artist, artists[i].name) == 0) {
                printf("  - %s (%d tracks, %d)\n", albums[j].name, albums[j].numTracks, albums[j].year);
            }
        }
        printf("\n");
    }
}

// Function to print all albums by a specific artist
void printArtist() {
    char artist[100];
    printf("Enter the name of the artist: ");
    scanf("%s", artist);

    // Find the artist in the library
    int artistIndex = -1;
    for (int i = 0; i < numArtists; i++) {
        if (strcmp(artist, artists[i].name) == 0) {
            artistIndex = i;
            break;
        }
    }
    if (artistIndex == -1) {
        printf("Artist not found in library.\n");
        return;
    }

    // Print all albums by the artist
    printf("Albums by %s:\n\n", artist);
    for (int i = 0; i < numAlbums; i++) {
        if (strcmp(albums[i].artist, artist) == 0) {
            printf("- %s (%d tracks, %d)\n", albums[i].name, albums[i].numTracks, albums[i].year);
        }
    }
}

// Function to print the details of a specific album
void printAlbum() {
    char name[100];
    char artist[100];
    printf("Enter the name of the album: ");
    scanf("%s", name);
    printf("Enter the name of the artist: ");
    scanf("%s", artist);

    // Find the album in the library
    int albumIndex = -1;
    for (int i = 0; i < numAlbums; i++) {
        if (strcmp(name, albums[i].name) == 0 && strcmp(artist, albums[i].artist) == 0) {
            albumIndex = i;
            break;
        }
    }
    if (albumIndex == -1) {
        printf("Album not found in library.\n");
        return;
    }

    // Print the details of the album
    printf("%s by %s (%d tracks, %d)\n", albums[albumIndex].name, albums[albumIndex].artist, albums[albumIndex].numTracks, albums[albumIndex].year);
}

// Function to clear the entire library
void clearLibrary() {
    char confirmation[100];
    printf("Are you sure you want to clear the entire library? This action cannot be undone. (y/n) ");
    scanf("%s", confirmation);
    if (strcmp(confirmation, "y") == 0) {
        numArtists = 0;
        numAlbums = 0;
        printf("Library cleared.\n");
    } else {
        printf("Operation canceled.\n");
    }
}