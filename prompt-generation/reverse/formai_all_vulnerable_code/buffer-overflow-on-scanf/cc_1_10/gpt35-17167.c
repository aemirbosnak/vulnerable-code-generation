//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUM 100

// Album struct
typedef struct
{
    char title[100];
    char artist[100];
    int num_tracks;
    int year;
} Album;

// Function prototypes
void add_album(Album albums[], int* num_albums);
void display_albums(Album albums[], int num_albums);
void search_album(Album albums[], int num_albums);
void edit_album(Album albums[], int num_albums);
void delete_album(Album albums[], int* num_albums);

int main()
{
    Album albums[MAX_ALBUM];
    int num_albums = 0;
    int choice;

    // User menu loop
    while(1)
    {
        printf("Welcome to the Music Library Management System!\n");
        printf("1. Add new album\n");
        printf("2. Display all albums\n");
        printf("3. Search album\n");
        printf("4. Edit album\n");
        printf("5. Delete album\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice)
        {
            // Add new album
            case 1:
                add_album(albums, &num_albums);
                break;

            // Display all albums
            case 2:
                display_albums(albums, num_albums);
                break;

            // Search album
            case 3:
                search_album(albums, num_albums);
                break;

            // Edit album
            case 4:
                edit_album(albums, num_albums);
                break;

            // Delete album
            case 5:
                delete_album(albums, &num_albums);
                break;

            // Exit program
            case 6:
                exit(0);
                break;

            // Invalid choice
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
    }

    return 0;
}

// Add new album
void add_album(Album albums[], int* num_albums)
{
    Album new_album;

    printf("Enter album title: ");
    fgets(new_album.title, sizeof(new_album.title), stdin);
    new_album.title[strcspn(new_album.title, "\n")] = '\0';

    printf("Enter album artist: ");
    fgets(new_album.artist, sizeof(new_album.artist), stdin);
    new_album.artist[strcspn(new_album.artist, "\n")] = '\0';

    printf("Enter number of tracks: ");
    scanf("%d", &new_album.num_tracks);

    printf("Enter release year: ");
    scanf("%d", &new_album.year);
    fflush(stdin);

    albums[*num_albums] = new_album;
    (*num_albums)++;

    printf("Album added successfully!\n");
}

// Display all albums
void display_albums(Album albums[], int num_albums)
{
    if(num_albums == 0)
    {
        printf("No albums in library.\n");
        return;
    }

    printf("%-30s %-20s %-15s %s\n", "Title", "Artist", "Tracks", "Year");
    for(int i = 0; i < num_albums; i++)
    {
        printf("%-30s %-20s %-15d %d\n", albums[i].title, albums[i].artist, albums[i].num_tracks, albums[i].year);
    }
}

// Search album
void search_album(Album albums[], int num_albums)
{
    char search_term[100];
    int found = 0;

    printf("Enter search term: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    printf("%-30s %-20s %-15s %s\n", "Title", "Artist", "Tracks", "Year");
    for(int i = 0; i < num_albums; i++)
    {
        if(strstr(albums[i].title, search_term) != NULL || strstr(albums[i].artist, search_term) != NULL)
        {
            printf("%-30s %-20s %-15d %d\n", albums[i].title, albums[i].artist, albums[i].num_tracks, albums[i].year);
            found = 1;
        }
    }

    if(!found)
    {
        printf("No albums found.\n");
    }
}

// Edit album
void edit_album(Album albums[], int num_albums)
{
    int album_choice;
    char edit_field[100];
    char new_value[100];

    if(num_albums == 0)
    {
        printf("No albums in library.\n");
        return;
    }

    printf("%-5s %-30s %-20s %-15s %s\n", "Index", "Title", "Artist", "Tracks", "Year");
    for(int i = 0; i < num_albums; i++)
    {
        printf("%-5d %-30s %-20s %-15d %d\n", i, albums[i].title, albums[i].artist, albums[i].num_tracks, albums[i].year);
    }

    printf("Enter index of album to edit: ");
    scanf("%d", &album_choice);
    fflush(stdin);

    if(album_choice < 0 || album_choice >= num_albums)
    {
        printf("Invalid album index.\n");
        return;
    }

    printf("Enter field to edit (title, artist, tracks, year): ");
    fgets(edit_field, sizeof(edit_field), stdin);
    edit_field[strcspn(edit_field, "\n")] = '\0';

    printf("Enter new value: ");
    fgets(new_value, sizeof(new_value), stdin);
    new_value[strcspn(new_value, "\n")] = '\0';

    if(strcmp(edit_field, "title") == 0)
    {
        strcpy(albums[album_choice].title, new_value);
    }
    else if(strcmp(edit_field, "artist") == 0)
    {
        strcpy(albums[album_choice].artist, new_value);
    }
    else if(strcmp(edit_field, "tracks") == 0)
    {
        albums[album_choice].num_tracks = atoi(new_value);
    }
    else if(strcmp(edit_field, "year") == 0)
    {
        albums[album_choice].year = atoi(new_value);
    }
    else
    {
        printf("Invalid field.\n");
        return;
    }

    printf("Album edited successfully!\n");
}

// Delete album
void delete_album(Album albums[], int* num_albums)
{
    int album_choice;

    if(*num_albums == 0)
    {
        printf("No albums in library.\n");
        return;
    }

    printf("%-5s %-30s %-20s %-15s %s\n", "Index", "Title", "Artist", "Tracks", "Year");
    for(int i = 0; i < *num_albums; i++)
    {
        printf("%-5d %-30s %-20s %-15d %d\n", i, albums[i].title, albums[i].artist, albums[i].num_tracks, albums[i].year);
    }

    printf("Enter index of album to delete: ");
    scanf("%d", &album_choice);
    fflush(stdin);

    if(album_choice < 0 || album_choice >= *num_albums)
    {
        printf("Invalid album index.\n");
        return;
    }

    for(int i = album_choice; i < *num_albums - 1; i++)
    {
        albums[i] = albums[i+1];
    }

    (*num_albums)--;

    printf("Album deleted successfully!\n");
}