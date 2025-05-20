//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure definition to hold music details
struct music{
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Function to display menu and get user input
int menu()
{
    int choice;
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add new music\n");
    printf("2. Display all music\n");
    printf("3. Search music by title\n");
    printf("4. Search music by artist\n");
    printf("5. Search music by album\n");
    printf("6. Search music by year\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add new music to library
void add_music(struct music* library, int* num_music)
{
    printf("\nEnter details of new music:\n");
    printf("Title: ");
    scanf(" %[^\n]s", library[*num_music].title);
    printf("Artist: ");
    scanf(" %[^\n]s", library[*num_music].artist);
    printf("Album: ");
    scanf(" %[^\n]s", library[*num_music].album);
    printf("Year: ");
    scanf("%d", &library[*num_music].year);   
    (*num_music)++;
    printf("\nNew music added successfully!\n");
}

// Function to display all music in library
void display_music(struct music* library, int num_music)
{
    if(num_music == 0)
    {
        printf("\nMusic library is empty!\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for(int i=0;i<num_music;i++)
    {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("\n");
    }
}

// Function to search music by title in library
void search_by_title(struct music* library, int num_music)
{
    char title[50];
    int found = 0;
    printf("\nEnter title to search: ");
    scanf(" %[^\n]s", title);
    printf("\nSearch results:\n");
    for(int i=0;i<num_music;i++)
    {
        if(strcmp(library[i].title, title) == 0)
        {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("\n");
            found = 1;
        }
    }
    if(found == 0)
        printf("No music found with title '%s'\n", title);
}

// Function to search music by artist in library
void search_by_artist(struct music* library, int num_music)
{
    char artist[50];
    int found = 0;
    printf("\nEnter artist name to search: ");
    scanf(" %[^\n]s", artist);
    printf("\nSearch results:\n");
    for(int i=0;i<num_music;i++)
    {
        if(strcmp(library[i].artist, artist) == 0)
        {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("\n");
            found = 1;
        }
    }
    if(found == 0)
        printf("No music found by artist '%s'\n", artist);
}

// Function to search music by album in library
void search_by_album(struct music* library, int num_music)
{
    char album[50];
    int found = 0;
    printf("\nEnter album name to search: ");
    scanf(" %[^\n]s", album);
    printf("\nSearch results:\n");
    for(int i=0;i<num_music;i++)
    {
        if(strcmp(library[i].album, album) == 0)
        {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("\n");
            found = 1;
        }
    }
    if(found == 0)
        printf("No music found by album '%s'\n", album);
}

// Function to search music by year in library
void search_by_year(struct music* library, int num_music)
{
    int year;
    int found = 0;
    printf("\nEnter year to search: ");
    scanf("%d", &year);
    printf("\nSearch results:\n");
    for(int i=0;i<num_music;i++)
    {
        if(library[i].year == year)
        {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("\n");
            found = 1;
        }
    }
    if(found == 0)
        printf("No music found in year '%d'\n", year);
}

// Driver function
int main()
{
    struct music library[100];
    int num_music = 0;
    int choice;
    
    do
    {
        choice = menu();
        switch(choice)
        {
            case 1:
                add_music(library, &num_music);
                break;
            case 2:
                display_music(library, num_music);
                break;
            case 3:
                search_by_title(library, num_music);
                break;
            case 4:
                search_by_artist(library, num_music);
                break;
            case 5:
                search_by_album(library, num_music);
                break;
            case 6:
                search_by_year(library, num_music);
                break;
            case 7:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }while(choice != 7);
    
    return 0;
}