//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include<stdio.h> 

#define MAX_SONGS 100  // maximum number of songs in the library
#define MAX_TITLE_LENGTH 50  // maximum length of title of a song
#define MAX_ARTIST_LENGTH 30  // maximum length of artist name

struct Song
{
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
};

struct MusicLibrary
{
    struct Song songs[MAX_SONGS];
    int num_songs;
};

// function prototypes
int addSong(struct MusicLibrary* library, char* title, char* artist, int year);
int searchSong(struct MusicLibrary* library, char* title);
int listSongs(struct MusicLibrary* library);
int removeSong(struct MusicLibrary* library, char* title);

int main()
{
    // initialize music library
    struct MusicLibrary library = { {}, 0 };
    
    // allow user to interact with music library
    char option;
    do
    {
        printf("Music Library Management System\n");
        printf("1. Add song\n");
        printf("2. Search song\n");
        printf("3. List all songs\n");
        printf("4. Remove song\n");
        printf("5. Exit\n");
        printf("Enter an option: ");
        scanf(" %c", &option);
        
        switch(option)
        {
            case '1':
            {
                char title[MAX_TITLE_LENGTH];
                char artist[MAX_ARTIST_LENGTH];
                int year;
                
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter artist: ");
                scanf("%s", artist);
                printf("Enter year: ");
                scanf("%d", &year);
                
                if(addSong(&library, title, artist, year))
                {
                    printf("Song added successfully.\n");
                }
                else
                {
                    printf("Error: Song could not be added.\n");
                }
                
                break;
            }
            case '2':
            {
                char title[MAX_TITLE_LENGTH];
                
                printf("Enter title: ");
                scanf("%s", title);
                
                int index = searchSong(&library, title);
                
                if(index >= 0)
                {
                    printf("Song found at index %d.\n", index);
                }
                else
                {
                    printf("Song not found.\n");
                }
                
                break;
            }
            case '3':
            {
                if(!listSongs(&library))
                {
                    printf("No songs in the library.\n");
                }
                
                break;
            }
            case '4':
            {
                char title[MAX_TITLE_LENGTH];
                
                printf("Enter title: ");
                scanf("%s", title);
                
                if(removeSong(&library, title))
                {
                    printf("Song removed successfully.\n");
                }
                else
                {
                    printf("Error: Song could not be removed.\n");
                }
                
                break;
            }
            case '5':
            {
                printf("Exiting program.\n");
                break;
            }
            default:
            {
                printf("Error: Invalid option selected.\n");
                break;
            }
        }
    } while(option != '5');
    
    return 0;
}

// function to add a song to the library
int addSong(struct MusicLibrary* library, char* title, char* artist, int year)
{
    if(library->num_songs >= MAX_SONGS)
    {
        return 0;
    }
    
    struct Song new_song;
    strcpy(new_song.title, title);
    strcpy(new_song.artist, artist);
    new_song.year = year;
    
    library->songs[library->num_songs++] = new_song;
    
    return 1;
}

// function to search for a song in the library
int searchSong(struct MusicLibrary* library, char* title)
{
    for(int i = 0; i < library->num_songs; i++)
    {
        if(strcmp(library->songs[i].title, title) == 0)
        {
            return i;
        }
    }
    
    return -1;
}

// function to list all songs in the library
int listSongs(struct MusicLibrary* library)
{
    if(library->num_songs == 0)
    {
        return 0;
    }
    
    printf("Title\tArtist\tYear\n");
    for(int i = 0; i < library->num_songs; i++)
    {
        printf("%s\t%s\t%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
    
    return 1;
}

// function to remove a song from the library
int removeSong(struct MusicLibrary* library, char* title)
{
    int index = searchSong(library, title);
    if(index < 0)
    {
        return 0;
    }
    
    for(int i = index; i < library->num_songs - 1; i++)
    {
        library->songs[i] = library->songs[i+1];
    }
    library->num_songs--;
    
    return 1;
}