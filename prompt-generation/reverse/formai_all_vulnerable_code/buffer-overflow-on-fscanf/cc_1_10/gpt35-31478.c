//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

// Define our Song struct
typedef struct
{
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;

} Song;

// Define our MusicLibrary struct
typedef struct
{
    Song songs[MAX_SONGS];
    int num_songs;

} MusicLibrary;

// Declare our function prototypes
int menu();
void add_song(MusicLibrary *library);
void search_song(MusicLibrary library);
void remove_song(MusicLibrary *library);
void display_library(MusicLibrary library);
void save_library(MusicLibrary library);
MusicLibrary load_library();

// Our main function
int main()
{
    MusicLibrary library = load_library();

    // Loop until the user exits the program
    while (1)
    {
        int choice = menu();

        switch (choice)
        {
        case 1:
            add_song(&library);
            save_library(library);
            break;
        case 2:
            search_song(library);
            break;
        case 3:
            remove_song(&library);
            save_library(library);
            break;
        case 4:
            display_library(library);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Display our menu and get the user's choice
int menu()
{
    int choice;

    printf("\n");
    printf("Welcome to our Music Library Management System!\n");
    printf("1. Add song\n");
    printf("2. Search song\n");
    printf("3. Remove song\n");
    printf("4. Display library\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    return choice;
}

// Add a song to our library
void add_song(MusicLibrary *library)
{
    if (library->num_songs >= MAX_SONGS)
    {
        printf("The library is full. Cannot add song.\n");
        return;
    }

    Song new_song;

    printf("Enter the title of the song: ");
    scanf("%s", new_song.title);

    printf("Enter the artist of the song: ");
    scanf("%s", new_song.artist);

    printf("Enter the album of the song: ");
    scanf("%s", new_song.album);

    printf("Enter the year the song was released: ");
    scanf("%d", &new_song.year);

    printf("Enter the duration of the song (in seconds): ");
    scanf("%d", &new_song.duration);

    // Add the song to our library
    library->songs[library->num_songs] = new_song;
    library->num_songs++;

    printf("Song added successfully!\n");
}

// Search for a song in our library
void search_song(MusicLibrary library)
{
    char search_query[50];
    int i, found = 0;

    printf("Enter the title, artist, or album of the song you are searching for: ");
    scanf("%s", search_query);

    for (i = 0; i < library.num_songs; i++)
    {
        if (strstr(library.songs[i].title, search_query) != NULL ||
            strstr(library.songs[i].artist, search_query) != NULL ||
            strstr(library.songs[i].album, search_query) != NULL)
        {
            printf("%s by %s from %s (%d)\n", library.songs[i].title,
                                              library.songs[i].artist,
                                              library.songs[i].album,
                                              library.songs[i].year);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No results found.\n");
    }
}

// Remove a song from our library
void remove_song(MusicLibrary *library)
{
    char search_query[50];
    int i, j, found = 0;

    printf("Enter the title of the song you want to remove: ");
    scanf("%s", search_query);

    for (i = 0; i < library->num_songs; i++)
    {
        if (strcmp(library->songs[i].title, search_query) == 0)
        {
            found = 1;

            // Shift all the songs after the one we're removing over to fill the gap
            for (j = i; j < library->num_songs - 1; j++)
            {
                library->songs[j] = library->songs[j+1];
            }

            // Update the number of songs in the library
            library->num_songs--;

            printf("Song removed successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Song not found.\n");
    }
}

// Display all the songs in our library
void display_library(MusicLibrary library)
{
    int i;

    printf("Songs in library: %d\n", library.num_songs);

    for (i = 0; i < library.num_songs; i++)
    {
        printf("%s by %s from %s (%d)\n", library.songs[i].title,
                                          library.songs[i].artist,
                                          library.songs[i].album,
                                          library.songs[i].year);
    }
}

// Save our library to a file
void save_library(MusicLibrary library)
{
    FILE *file = fopen("music_library.txt", "w");

    fprintf(file, "%d\n", library.num_songs);

    int i;

    for (i = 0; i < library.num_songs; i++)
    {
        fprintf(file, "%s|%s|%s|%d|%d\n", library.songs[i].title,
                                           library.songs[i].artist,
                                           library.songs[i].album,
                                           library.songs[i].year,
                                           library.songs[i].duration);
    }

    fclose(file);
}

// Load our library from a file
MusicLibrary load_library()
{
    MusicLibrary library = {0};
    FILE *file = fopen("music_library.txt", "r");

    if (file == NULL)
    {
        return library;
    }

    fscanf(file, "%d", &library.num_songs);

    int i;

    for (i = 0; i < library.num_songs; i++)
    {
        Song new_song;

        fscanf(file, "%[^|]|%[^|]|%[^|]|%d|%d\n", new_song.title,
                                                   new_song.artist,
                                                   new_song.album,
                                                   &new_song.year,
                                                   &new_song.duration);

        library.songs[i] = new_song;
    }

    fclose(file);

    return library;
}