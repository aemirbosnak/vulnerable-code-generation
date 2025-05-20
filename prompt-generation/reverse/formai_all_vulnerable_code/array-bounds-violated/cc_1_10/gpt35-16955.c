//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure declarations */
struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

/* Function declarations */
void add_song();
void edit_song();
void delete_song();
void display_song();
void search_song();

/* Global variables */
int count = 0;
struct Song songs[100];

/* Main function */
int main()
{
    int option;
    do {
        printf("\nWelcome to the C Music Library Management System!\n");
        printf("1. Add Song\n");
        printf("2. Edit Song\n");
        printf("3. Delete Song\n");
        printf("4. Display All Songs\n");
        printf("5. Search Song\n");
        printf("6. Exit\n");
        printf("What would you like to do? ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_song();
                break;
            case 2:
                edit_song();
                break;
            case 3:
                delete_song();
                break;
            case 4:
                display_song();
                break;
            case 5:
                search_song();
                break;
            case 6:
                printf("\nThank you for using the Music Library Management System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while(option != 6);

    return 0;
}

/* Function to add a song */
void add_song()
{
    printf("\nEnter the details of the song:\n");
    printf("Title: ");
    scanf("%s", songs[count].title);
    printf("Artist: ");
    scanf("%s", songs[count].artist);
    printf("Album: ");
    scanf("%s", songs[count].album);
    printf("Year: ");
    scanf("%d", &songs[count].year);

    printf("\nSuccess! Song added to the library.\n");
    count++;
}

/* Function to edit a song */
void edit_song()
{
    int i, index;
    char title[100];

    printf("\nEnter the title of the song you want to edit: ");
    scanf("%s", title);

    for(i = 0; i < count; i++) {
        if(strcmp(title, songs[i].title) == 0) {
            index = i;
            break;
        }
    }

    printf("\nEnter the updated details of the song:\n");
    printf("Title: ");
    scanf("%s", songs[index].title);
    printf("Artist: ");
    scanf("%s", songs[index].artist);
    printf("Album: ");
    scanf("%s", songs[index].album);
    printf("Year: ");
    scanf("%d", &songs[index].year);

    printf("\nSuccess! Song updated.\n");
}

/* Function to delete a song */
void delete_song()
{
    int i, index;
    char title[100];

    printf("\nEnter the title of the song you want to delete: ");
    scanf("%s", title);

    for(i = 0; i < count; i++) {
        if(strcmp(title, songs[i].title) == 0) {
            index = i;
            break;
        }
    }

    for(i = index; i < count - 1; i++) {
        songs[i] = songs[i+1];
    }

    count--;
    printf("\nSuccess! Song deleted from the library.\n");
}

/* Function to display all songs */
void display_song()
{
    int i;

    printf("\n%d songs found in the library:\n", count);
    for(i = 0; i < count; i++) {
        printf("%d. Title: %s, Artist: %s, Album: %s, Year: %d\n",
            i+1, songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
    }
}

/* Function to search for a song */
void search_song()
{
    int i, found = 0;
    char title[100];

    printf("\nEnter the title of the song you want to search: ");
    scanf("%s", title);

    for(i = 0; i < count; i++) {
        if(strcmp(title, songs[i].title) == 0) {
            printf("\nSong found!\n");
            printf("Title: %s, Artist: %s, Album: %s, Year: %d\n",
                songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nSong not found in the library.\n");
    }
}