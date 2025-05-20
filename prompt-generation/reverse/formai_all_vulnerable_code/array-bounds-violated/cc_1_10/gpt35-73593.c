//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIBRARY_SIZE 100 // Maximum number of songs in library
#define TITLE_SIZE 50 // Maximum length of song title
#define ARTIST_SIZE 50 // Maximum length of artist name

typedef struct song
{
    char title[TITLE_SIZE];
    char artist[ARTIST_SIZE];
    int year;
    float duration;
} Song;

Song library[LIBRARY_SIZE]; // Creating the library

int num_songs = 0; // Number of songs currently in the library

// Function to add a song to the library
void add_song()
{
    if(num_songs == LIBRARY_SIZE)
    {
        printf("Sorry, the library is full.\n");
        return;
    }
    
    Song new_song;
    printf("Enter song title: ");
    fgets(new_song.title, TITLE_SIZE, stdin);
    new_song.title[strlen(new_song.title) - 1] = '\0'; // Remove newline character
    
    printf("Enter artist name: ");
    fgets(new_song.artist, ARTIST_SIZE, stdin);
    new_song.artist[strlen(new_song.artist) - 1] = '\0'; // Remove newline character
    
    printf("Enter year of release: ");
    scanf("%d", &new_song.year);
    
    printf("Enter duration of song (in minutes): ");
    scanf("%f", &new_song.duration);
    
    library[num_songs++] = new_song; // Add new song to library
    printf("Song successfully added to the library.\n");
}

// Function to display all songs in the library
void display_library()
{
    if(num_songs == 0)
    {
        printf("Library is empty.\n");
        return;
    }
    
    printf("Displaying all songs in the library:\n");
    printf("| %-50s | %-50s | %4s | %7s |\n", "Title", "Artist", "Year", "Duration");
    
    for(int i = 0; i < num_songs; i++)
    {
        printf("| %-50s | %-50s | %4d | %5.2f min |\n", library[i].title,
                                                      library[i].artist,
                                                      library[i].year,
                                                      library[i].duration);
    }
}

// Function to search for a song in the library by title
void search_song()
{
    if(num_songs == 0)
    {
        printf("Library is empty.\n");
        return;
    }
    
    char search_title[TITLE_SIZE];
    printf("Enter song title to search for: ");
    fgets(search_title, TITLE_SIZE, stdin);
    search_title[strlen(search_title) - 1] = '\0'; // Remove newline character
    
    printf("Displaying search results:\n");
    printf("| %-50s | %-50s | %4s | %7s |\n", "Title", "Artist", "Year", "Duration");
    
    int search_count = 0; // Number of results found
    
    for(int i = 0; i < num_songs; i++)
    {
        if(strcmp(library[i].title, search_title) == 0)
        {
            printf("| %-50s | %-50s | %4d | %5.2f min |\n", library[i].title,
                                                          library[i].artist,
                                                          library[i].year,
                                                          library[i].duration);
            search_count++;
        }
    }
    
    if(search_count == 0)
    {
        printf("No results found for search query.\n");
    }
}

int main()
{
    printf("Welcome to the C Music Library Management System!\n");
    
    int choice;
    
    do
    {
        printf("\nMenu:\n");
        printf("1. Add a song to the library\n");
        printf("2. Display all songs in the library\n");
        printf("3. Search for a song by title\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove newline character from input buffer
        
        switch(choice)
        {
            case 1:
                add_song();
                break;
            case 2:
                display_library();
                break;
            case 3:
                search_song();
                break;
            case 4:
                printf("Exiting program. Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}