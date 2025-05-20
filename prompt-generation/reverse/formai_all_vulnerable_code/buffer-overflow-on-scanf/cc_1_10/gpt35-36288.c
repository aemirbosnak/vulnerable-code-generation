//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Song;

void print_menu()
{
    printf("----------MENU----------\n");
    printf("1. Add a song\n");
    printf("2. Display all songs\n");
    printf("3. Search for a song\n");
    printf("4. Delete a song\n");
    printf("5. Exit\n");
}

void add_song(Song *songs, int *count)
{
    printf("Enter Song Title: ");
    scanf("%s", songs[*count].title);
    printf("Enter Artist Name: ");
    scanf("%s", songs[*count].artist);
    printf("Enter Genre: ");
    scanf("%s", songs[*count].genre);
    printf("Enter Year: ");
    scanf("%d", &songs[*count].year);

    (*count)++;
    printf("Song added!\n\n");
}

void display_songs(Song *songs, int count)
{
    printf("----------SONGS----------\n");

    if (count == 0)
    {
        printf("No songs found!\n\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Title: %s\nArtist: %s\nGenre: %s\nYear: %d\n\n", songs[i].title, songs[i].artist, songs[i].genre, songs[i].year);
    }
}

void search_song(Song *songs, int count)
{
    char title[100];
    int found = 0;

    printf("Enter title of song to search: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(songs[i].title, title) == 0)
        {
            printf("Song found!\n\n");
            printf("Title: %s\nArtist: %s\nGenre: %s\nYear: %d\n\n", songs[i].title, songs[i].artist, songs[i].genre, songs[i].year);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Song not found!\n\n");
    }
}

void delete_song(Song *songs, int *count)
{
    char title[100];
    int found = 0;

    printf("Enter title of song to delete: ");
    scanf("%s", title);

    for (int i = 0; i < *count; i++)
    {
        if (strcmp(songs[i].title, title) == 0)
        {
            found = 1;
            *count -= 1;

            // Move rest of the array elements one position back
            for (int j = i; j < *count; j++)
            {
                strcpy(songs[j].title, songs[j + 1].title);
                strcpy(songs[j].artist, songs[j + 1].artist);
                strcpy(songs[j].genre, songs[j + 1].genre);
                songs[j].year = songs[j + 1].year;
            }

            printf("Song deleted!\n\n");
        }
    }

    if (!found)
    {
        printf("Song not found!\n\n");
    }
}

int main()
{
    Song songs[100];
    int count = 0;
    int choice;

    while (1)
    {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_song(songs, &count);
                break;
            case 2:
                display_songs(songs, count);
                break;
            case 3:
                search_song(songs, count);
                break;
            case 4:
                delete_song(songs, &count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    }

    return 0;
}