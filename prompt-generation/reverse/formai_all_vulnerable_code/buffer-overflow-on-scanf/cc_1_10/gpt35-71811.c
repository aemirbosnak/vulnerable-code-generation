//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[50];
    char artist[50];
    char genre[20];
    int year;
} C_Music;

void display_menu()
{
    printf("\nWelcome to the C Music Library Management System!");
    printf("\n-------------------------------------------------\n");
    printf("1. Add a new song\n");
    printf("2. Display all songs\n");
    printf("3. Search for a song\n");
    printf("4. Delete a song\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

void add_song(C_Music *arr, int *size)
{
    printf("\nEnter the song's details:");
    printf("\nTitle: "); scanf("%s", arr[*size].title);
    printf("Artist: "); scanf("%s", arr[*size].artist);
    printf("Genre: "); scanf("%s", arr[*size].genre);
    printf("Year: "); scanf("%d", &arr[*size].year);
    (*size)++;
    printf("\nSong added successfully!\n");
}

void display_songs(C_Music *arr, int size)
{
    if(size == 0)
    {
        printf("\nNo songs found!\n");
        return;
    }
    printf("\n%-20s %-20s %-10s %-4s\n", "Title", "Artist", "Genre", "Year");
    printf("--------------------------------------------------------\n");
    for(int i=0; i<size; i++)
    {
        printf("%-20s %-20s %-10s %-4d\n", arr[i].title, arr[i].artist, arr[i].genre, arr[i].year);
    }
}

void search_song(C_Music *arr, int size)
{
    char title[50];
    printf("\nEnter the title of the song to search: ");
    scanf("%s", title);
    for(int i=0; i<size; i++)
    {
        if(strcmp(title, arr[i].title) == 0)
        {
            printf("\n%-20s %-20s %-10s %-4s\n", "Title", "Artist", "Genre", "Year");
            printf("--------------------------------------------------------\n");
            printf("%-20s %-20s %-10s %-4d\n", arr[i].title, arr[i].artist, arr[i].genre, arr[i].year);
            return;
        }
    }
    printf("\nSong not found!\n");
}

void delete_song(C_Music *arr, int *size)
{
    char title[50];
    printf("\nEnter the title of the song to delete: ");
    scanf("%s", title);
    for(int i=0; i<*size; i++)
    {
        if(strcmp(title, arr[i].title) == 0)
        {
            for(int j=i; j<*size-1; j++)
            {
                strcpy(arr[j].title, arr[j+1].title);
                strcpy(arr[j].artist, arr[j+1].artist);
                strcpy(arr[j].genre, arr[j+1].genre);
                arr[j].year = arr[j+1].year;
            }
            (*size)--;
            printf("\nSong deleted successfully!\n");
            return;
        }
    }
    printf("\nSong not found!\n");
}

int main()
{
    int choice, size = 0, capacity = 100;
    C_Music *arr = (C_Music*) malloc(capacity * sizeof(C_Music));
    if(arr == NULL)
    {
        printf("\nMemory allocation error!\n");
        return 0;
    }
    while(1)
    {
        display_menu();
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: add_song(arr, &size);
                    break;
            case 2: display_songs(arr, size);
                    break;
            case 3: search_song(arr, size);
                    break;
            case 4: delete_song(arr, &size);
                    break;
            case 5: printf("\nGoodbye!\n");
                    free(arr);
                    return 0;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}