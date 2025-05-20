//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
// Music Library Management System 
// By Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for song and album
typedef struct {
    char title[50];
    char artist[50];
    int duration;
    int year;
} Song;

typedef struct {
    char title[50];
    char artist[50];
    int num_songs;
    Song songs[10];
} Album;

// Define function prototypes
void add_song();
void add_album();
void search_song();
void search_album();
void display_all();
void display_album();

// Define global variables
Album albums[50];
int num_albums = 0;

int main() {
    int choice;

    while (1) {
        // Main menu
        printf("\nMusic Library Management System\n");
        printf("----------------------------------------\n");
        printf("1. Add Song\n");
        printf("2. Add Album\n");
        printf("3. Search Song\n");
        printf("4. Search Album\n");
        printf("5. Display All Songs\n");
        printf("6. Display Album\n");
        printf("7. Quit\n");

        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        // Call appropriate function based on user's choice
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                add_album();
                break;
            case 3:
                search_song();
                break;
            case 4:
                search_album();
                break;
            case 5:
                display_all();
                break;
            case 6:
                display_album();
                break;
            case 7:
                printf("Thank you for using Music Library Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a song to an existing album
void add_song_to_album(Album *album) {
    // Check if album already has 10 songs
    if (album->num_songs == 10) {
        printf("Maximum number of songs reached for this album.\n");
        return;
    }

    // Prompt user to enter song details
    printf("\nEnter song title: ");
    scanf("%s", album->songs[album->num_songs].title);
    printf("Enter artist name: ");
    scanf("%s", album->songs[album->num_songs].artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &album->songs[album->num_songs].duration);
    printf("Enter year: ");
    scanf("%d", &album->songs[album->num_songs].year);

    // Increment number of songs in the album
    album->num_songs++;

    printf("Song added to the album.\n");
}

// Function to add a new song to the library
void add_song() {
    Song song;

    // Prompt user to enter song details
    printf("\nEnter song title: ");
    scanf("%s", song.title);
    printf("Enter artist name: ");
    scanf("%s", song.artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &song.duration);
    printf("Enter year: ");
    scanf("%d", &song.year);

    // Add song to the first available album
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(albums[i].artist, song.artist) == 0) {
            add_song_to_album(&albums[i]);
            return;
        }
    }

    // If no album exists for the artist, create a new album
    Album album;
    strcpy(album.title, "Untitled");
    strcpy(album.artist, song.artist);
    album.num_songs = 0;
    albums[num_albums] = album;
    num_albums++;
    add_song_to_album(&album);

    printf("New album created for the artist: %s\n", album.artist);
}

// Function to add a new album to the library
void add_album() {
    Album album;

    // Prompt user to enter album details
    printf("\nEnter album title: ");
    scanf("%s", album.title);
    printf("Enter artist name: ");
    scanf("%s", album.artist);
    printf("Enter number of songs: ");
    scanf("%d", &album.num_songs);

    // Prompt user to enter song details for each song in the album
    for (int i = 0; i < album.num_songs; i++) {
        printf("\nSong %d\n", i+1);
        printf("Enter song title: ");
        scanf("%s", album.songs[i].title);
        printf("Enter artist name: ");
        scanf("%s", album.songs[i].artist);
        printf("Enter duration (in seconds): ");
        scanf("%d", &album.songs[i].duration);
        printf("Enter year: ");
        scanf("%d", &album.songs[i].year);
    }

    // Add album to the library
    albums[num_albums] = album;
    num_albums++;

    printf("Album added to the library.\n");
}

// Function to search for a song in the library
void search_song() {
    char title[50];
    char artist[50];

    // Prompt user to enter search criteria
    printf("\nEnter song title (or press enter to skip): ");
    scanf("%s", title);
    printf("Enter artist name (or press enter to skip): ");
    scanf("%s", artist);

    // Display all songs that match the search criteria
    printf("\nResults:\n");
    for (int i = 0; i < num_albums; i++) {
        for (int j = 0; j < albums[i].num_songs; j++) {
            if ((title[0] == '\0' || strcmp(albums[i].songs[j].title, title) == 0)
                && (artist[0] == '\0' || strcmp(albums[i].songs[j].artist, artist) == 0)) {
                printf("- %s by %s (%d seconds, %d)\n", 
                    albums[i].songs[j].title, 
                    albums[i].songs[j].artist, 
                    albums[i].songs[j].duration, 
                    albums[i].songs[j].year);
            }
        }
    }
}

// Function to search for an album in the library
void search_album() {
    char title[50];
    char artist[50];

    // Prompt user to enter search criteria
    printf("\nEnter album title (or press enter to skip): ");
    scanf("%s", title);
    printf("Enter artist name (or press enter to skip): ");
    scanf("%s", artist);

    // Display all albums that match the search criteria
    printf("\nResults:\n");
    for (int i = 0; i < num_albums; i++) {
        if ((title[0] == '\0' || strcmp(albums[i].title, title) == 0)
            && (artist[0] == '\0' || strcmp(albums[i].artist, artist) == 0)) {
            printf("- %s by %s (%d songs)\n", 
                albums[i].title, 
                albums[i].artist, 
                albums[i].num_songs);
        }
    }
}

// Function to display all songs in the library
void display_all() {
    printf("\nAll Songs:\n");
    for (int i = 0; i < num_albums; i++) {
        for (int j = 0; j < albums[i].num_songs; j++) {
            printf("- %s by %s (%d seconds, %d)\n", 
                albums[i].songs[j].title, 
                albums[i].songs[j].artist, 
                albums[i].songs[j].duration, 
                albums[i].songs[j].year);
        }
    }
}

// Function to display all songs in a specific album
void display_album() {
    char title[50];
    char artist[50];

    // Prompt user to enter album details
    printf("\nEnter album title: ");
    scanf("%s", title);
    printf("Enter artist name: ");
    scanf("%s", artist);

    // Find album in the library
    int album_index = -1;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(albums[i].title, title) == 0 && strcmp(albums[i].artist, artist) == 0) {
            album_index = i;
            break;
        }
    }

    // Display all songs in the album
    if (album_index == -1) {
        printf("Album not found.\n");
    } else {
        printf("\n%s by %s:\n", albums[album_index].title, albums[album_index].artist);
        for (int i = 0; i < albums[album_index].num_songs; i++) {
            printf("- %s (%d seconds, %d)\n", 
                albums[album_index].songs[i].title,
                albums[album_index].songs[i].duration,
                albums[album_index].songs[i].year);
        }
    }
}