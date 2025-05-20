//FormAI DATASET v1.0 Category: Music Library Management System ; Style: excited
#include<stdio.h>
#include<string.h>

struct MusicLibrary
{
    char songName[100];
    char artistName[100];
    char albumName[100];
    int releaseYear;
};

// Function declarations
int displayMenu();
void addSong(struct MusicLibrary[], int);
void displayMusicLibrary(struct MusicLibrary[], int);
void sortMusicLibrary(struct MusicLibrary[], int);
void searchMusicLibrary(struct MusicLibrary[], int);

int main()
{
    int choice = 0, numSongs = 0;
    struct MusicLibrary music[100];

    printf("\n\t Welcome to Music Library Management System!");
    printf("\n\t ==========================================\n");

    do
    {
        choice = displayMenu();
        switch (choice)
        {
            case 1:
                addSong(music, numSongs);
                numSongs++;
                break;
            case 2:
                displayMusicLibrary(music, numSongs);
                break;
            case 3:
                sortMusicLibrary(music, numSongs);
                break;
            case 4:
                searchMusicLibrary(music, numSongs);
                break;
            case 5:
                printf("\n\t Goodbye!");
                break;
            default:
                printf("\n\t Please enter a valid option!");
        }
    } while (choice != 5);

    printf("\n\n");
    return 0;
}

// Function definitions
int displayMenu()
{
    int choice;
    
    printf("\n\t Menu:");
    printf("\n\t =====\n");
    printf("\t 1. Add Song\n");
    printf("\t 2. Display Music Library\n");
    printf("\t 3. Sort Music Library\n");
    printf("\t 4. Search Music Library\n");
    printf("\t 5. Exit\n");
    printf("\n\t Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void addSong(struct MusicLibrary music[], int numSongs)
{
    printf("\n\t Add Song:");
    printf("\n\t ========");
    printf("\n\t Song Name: ");
    scanf("%s", &music[numSongs].songName);
    printf("\t Artist Name: ");
    scanf("%s", &music[numSongs].artistName);
    printf("\t Album Name: ");
    scanf("%s", &music[numSongs].albumName);
    printf("\t Release Year: ");
    scanf("%d", &music[numSongs].releaseYear);
}

void displayMusicLibrary(struct MusicLibrary music[], int numSongs)
{
    int i;
    
    printf("\n\t Music Library:");
    printf("\n\t ==============\n");
    for (i = 0; i < numSongs; i++)
    {
        printf("\t Song Name: %s\n", music[i].songName);
        printf("\t Artist Name: %s\n", music[i].artistName);
        printf("\t Album Name: %s\n", music[i].albumName);
        printf("\t Release Year: %d\n", music[i].releaseYear);
        printf("\n");
    }
}

void sortMusicLibrary(struct MusicLibrary music[], int numSongs)
{
    int i, j;
    struct MusicLibrary temp;
    
    for (i = 0; i < numSongs-1; i++)
    {
        for (j = 0; j < numSongs-1-i; j++)
        {
            if (strcmp(music[j].songName, music[j+1].songName) > 0)
            {
                temp = music[j];
                music[j] = music[j+1];
                music[j+1] = temp;
            }
        }
    }
    
    printf("\n\t Music Library sorted by Song Name!");
}

void searchMusicLibrary(struct MusicLibrary music[], int numSongs)
{
    int i, flag = 0;
    char searchName[100];
    
    printf("\n\t Search Music Library:");
    printf("\n\t ======================\n");
    printf("\t Enter Song Name to search: ");
    scanf("%s", &searchName);
    
    for (i = 0; i < numSongs; i++)
    {
        if (strcmp(searchName, music[i].songName) == 0)
        {
            printf("\n\t Song Name: %s\n", music[i].songName);
            printf("\t Artist Name: %s\n", music[i].artistName);
            printf("\t Album Name: %s\n", music[i].albumName);
            printf("\t Release Year: %d\n", music[i].releaseYear);
            printf("\n");
            flag = 1;
        }
    }
    
    if (flag == 0)
    {
        printf("\n\t Song Name not found in Music Library!");
    }
}