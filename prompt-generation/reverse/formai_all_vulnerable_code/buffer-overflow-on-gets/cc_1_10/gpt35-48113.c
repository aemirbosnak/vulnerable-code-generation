//FormAI DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct song
{
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float duration;
    char genre[50];
    char location[100];
    struct song *next;
}song_t;

song_t *head = NULL;
song_t *tail = NULL;

// Function to add a song to the library
void add_song()
{
    song_t *new_song = malloc(sizeof(song_t));
    printf("\nEnter Song Title: ");
    gets(new_song->title);
    printf("\nEnter Artist Name: ");
    gets(new_song->artist);
    printf("\nEnter Album Name: ");
    gets(new_song->album);
    printf("\nEnter Release Year: ");
    scanf("%d", &new_song->year);
    printf("\nEnter Duration (in minutes): ");
    scanf("%f", &new_song->duration);
    printf("\nEnter Genre: ");
    getchar();
    gets(new_song->genre);
    printf("\nEnter Song File Location: ");
    gets(new_song->location);

    // Check if the library is empty
    if(head == NULL)
    {
        head = new_song;
        tail = new_song;
        new_song->next = NULL;
    }
    else
    {
        tail->next = new_song;
        tail = new_song;
        new_song->next = NULL;
    }
    printf("\n%s by %s added to the library!", new_song->title, new_song->artist);
}

// Function to display all songs in the library
void display_songs()
{
    if(head == NULL)
    {
        printf("\nLibrary is Empty!\n");
        return;
    }
    song_t *current_song = head;
    printf("\n%-50s %-20s %-20s %-10s %-15s %-20s", "Title", "Artist", "Album", "Year", "Duration", "Genre");
    while(current_song != NULL)
    {
        printf("\n%-50s %-20s %-20s %-10d %-15.2f %-20s", current_song->title, current_song->artist, current_song->album,
                                                        current_song->year, current_song->duration, current_song->genre);
        current_song = current_song->next;
    }
}

// Function to search for a specific song in the library
void search_song()
{
    if(head == NULL)
    {
        printf("\nLibrary is Empty!\n");
        return;
    }
    char search_title[50];
    printf("\nEnter the title of the song you want to search for: ");
    getchar();
    gets(search_title);
    song_t *current_song = head;
    while(current_song != NULL)
    {
        if(strcmp(current_song->title, search_title) == 0)
        {
            printf("\n%-50s %-20s %-20s %-10s %-15s %-20s\n", "Title", "Artist", "Album", "Year", "Duration", "Genre");
            printf("%-50s %-20s %-20s %-10d %-15.2f %-20s", current_song->title, current_song->artist, current_song->album,
                                                            current_song->year, current_song->duration, current_song->genre);
            return;
        }
        current_song = current_song->next;
    }
    printf("\n%s not found in the library.", search_title);
}

// Function to remove a song from the library
void remove_song()
{
    if(head == NULL)
    {
        printf("\nLibrary is Empty!\n");
        return;
    }
    char remove_title[50];
    printf("\nEnter the title of the song you want to remove: ");
    getchar();
    gets(remove_title);
    song_t *current_song = head;
    song_t *previous_song = NULL;

    while(current_song != NULL)
    {
        if(strcmp(current_song->title, remove_title) == 0)
        {
            if(current_song == head)
            {
                head = head->next;
            }
            else if(current_song == tail)
            {
                tail = previous_song;
                tail->next = NULL;
            }
            else
            {
                previous_song->next = current_song->next;
            }
            printf("\n%s by %s removed from the library.", current_song->title, current_song->artist);
            free(current_song);
            return;
        }
        previous_song = current_song;
        current_song = current_song->next;
    }
    printf("\n%s not found in the library.", remove_title);
}

// Function to update a song in the library
void update_song()
{
    if(head == NULL)
    {
        printf("\nLibrary is Empty!\n");
        return;
    }
    char update_title[50];
    printf("\nEnter the title of the song you want to update: ");
    getchar();
    gets(update_title);
    song_t *current_song = head;

    while(current_song != NULL)
    {
        if(strcmp(current_song->title, update_title) == 0)
        {
            printf("\nEnter New Title of the Song: ");
            gets(current_song->title);
            printf("\nEnter New Artist Name: ");
            gets(current_song->artist);
            printf("\nEnter New Album Name: ");
            gets(current_song->album);
            printf("\nEnter New Release Year: ");
            scanf("%d", &current_song->year);
            printf("\nEnter New Duration (in minutes): ");
            scanf("%f", &current_song->duration);
            printf("\nEnter New Genre: ");
            getchar();
            gets(current_song->genre);
            printf("\nSong Details Updated Successfully!\n");
            return;
        }
        current_song = current_song->next;
    }
    printf("\n%s not found in the library.", update_title);
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n--------------------\n");
        printf("Music Library Manager\n");
        printf("--------------------\n");
        printf("1. Add a Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search for a Song\n");
        printf("4. Remove a Song\n");
        printf("5. Update a Song\n");
        printf("6. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : add_song();
                     break;
            case 2 : display_songs();
                     break;
            case 3 : search_song();
                     break;
            case 4 : remove_song();
                     break;
            case 5 : update_song();
                     break;
            case 6 : exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}