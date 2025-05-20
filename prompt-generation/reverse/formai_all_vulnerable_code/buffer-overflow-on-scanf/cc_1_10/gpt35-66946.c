//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {                  //Define the Music struct
    char title[30];
    char artist[30];
    int duration;
    char genre[20];
    char album[30];
};

void add_music(struct Music *music, int n);    //Function prototype to add music
void display_music(struct Music *music, int n);   //Function prototype to display music
void search_music(struct Music *music, int n, char *title); //Function prototype to search for music
void delete_music(struct Music *music, int *n, char *title);  //Function prototype to delete music

int main()
{
    int choice, n = 0, i;
    char title[30];
    struct Music music[100];   //Define the music array

    while(1)    //Menu driven program
    {
        printf("*****Music Library Management System*****\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);      //Clears the input buffer

        switch(choice)
        {
            case 1:
                add_music(music, n);
                n++;
                break;
            case 2:
                display_music(music, n);
                break;
            case 3:
                printf("Enter the title of the music: ");
                scanf("%s", title);
                search_music(music, n, title);
                break;
            case 4:
                printf("Enter the title of the music to be deleted: ");
                scanf("%s", title);
                delete_music(music, &n, title);
                break;
            case 5:
                printf("Exiting..");
                exit(0);    //Exits the program
            default:
                printf("Invalid Choice, Try again..\n");
                break;
        }
    }
    return 0;
}

void add_music(struct Music *music, int n)   //Function to add music to the music library
{
    printf("Enter the details of music number %d:\n", n+1);
    printf("Title: ");
    scanf("%s", (music+n)->title);
    printf("Artist: ");
    scanf("%s", (music+n)->artist);
    printf("Album: ");
    scanf("%s", (music+n)->album);
    printf("Duration: ");
    scanf("%d", &(music+n)->duration);
    printf("Genre: ");
    scanf("%s", (music+n)->genre);
    printf("Music Added Successfully!\n");
}

void display_music(struct Music *music, int n)  //Function to display all music in the music library
{
    int i;
    printf("\nTitle\t\tArtist\t\tAlbum\t\tDuration\tGenre\n");
    for(i=0; i<n; i++)
    {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\n", (music+i)->title, (music+i)->artist, (music+i)->album, (music+i)->duration, (music+i)->genre);
    }
}

void search_music(struct Music *music, int n, char *title)  //Function to search for music in the music library
{
    int i, flag = 0;
    for(i=0; i<n; i++)
    {
        if(strcmp((music+i)->title, title) == 0)
        {
            printf("Music Found!!\n");
            printf("Title: %s\n", (music+i)->title);
            printf("Artist: %s\n", (music+i)->artist);
            printf("Album: %s\n", (music+i)->album);
            printf("Duration: %d\n", (music+i)->duration);
            printf("Genre: %s\n", (music+i)->genre);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Music not found!\n");
    }
}

void delete_music(struct Music *music, int *n, char *title)   //Function to delete music from the music library
{
    int i, j, flag = 0;
    for(i=0; i<*n; i++)
    {
        if(strcmp((music+i)->title, title) == 0)
        {
            flag = 1;
            printf("Music Deleted Successfully!\n");
            for(j=i; j<*n-1; j++)
            {
                *(music+j) = *(music+(j+1));
            }
            (*n)--;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Music not found!\n");
    }
}