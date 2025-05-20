//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SONGS 1000  // maximum number of songs that can be stored in the library
#define MAX_ARTIST_NAME 50  // maximum length of artist name
#define MAX_SONG_NAME 50  // maximum length of song name

// Song structure
struct Song {
    char artist_name[MAX_ARTIST_NAME];
    char song_name[MAX_SONG_NAME];
    int rating;
};

struct Song music_library[MAX_SONGS];  // an array of songs to store songs in the library
int num_of_songs = 0;  // number of songs currently in the library

// Function declarations
void add_song();
void remove_song();
void search();
void display_all_songs();
void display_top_rated_songs();

int main(){
    int option;

    do {
        printf("\n-----------C Music Library Management System-----------\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Search\n");
        printf("4. Display All Songs\n");
        printf("5. Display Top Rated Songs\n");
        printf("6. Exit\n");
        printf("-------------------------------------------------------\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_song();
                break;
            case 2:
                remove_song();
                break;
            case 3:
                search();
                break;
            case 4:
                display_all_songs();
                break;
            case 5:
                display_top_rated_songs();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(option != 6);

    return 0;
}

// Function to add a song to the library
void add_song() {
    if(num_of_songs == MAX_SONGS) {
        printf("Sorry, the music library is full.\n");
        return;
    }

    struct Song new_song;

    printf("Enter Artist Name: ");
    scanf("%s", new_song.artist_name);

    printf("Enter Song Name: ");
    scanf("%s", new_song.song_name);

    printf("Enter Rating (1-5): ");
    scanf("%d", &new_song.rating);

    music_library[num_of_songs] = new_song;
    num_of_songs++;

    printf("Song added successfully.\n");
}

// Function to remove a song from the library
void remove_song() {
    if(num_of_songs == 0) {
        printf("Sorry, the music library is already empty.\n");
        return;
    }

    char artist_name[MAX_ARTIST_NAME];
    char song_name[MAX_SONG_NAME];

    printf("Enter the name of the artist: ");
    scanf("%s", artist_name);

    printf("Enter the name of the song: ");
    scanf("%s", song_name);

    int song_found = 0;

    for(int i=0; i<num_of_songs; i++) {
        if(strcmp(music_library[i].artist_name, artist_name) == 0 && 
        strcmp(music_library[i].song_name, song_name) == 0) {
            song_found = 1;
            for(int j=i; j<num_of_songs-1; j++) {
                music_library[j] = music_library[j+1];
            }
            num_of_songs--;
            printf("Song removed successfully.\n");
            break;
        }
    }

    if(song_found == 0) {
        printf("Sorry, the song was not found in the library.\n");
    }
}

// Function to search for a song in the library
void search() {
    if(num_of_songs == 0) {
        printf("Sorry, the music library is empty.\n");
        return;
    }

    char artist_name[MAX_ARTIST_NAME];
    char song_name[MAX_SONG_NAME];

    printf("Enter the name of the artist: ");
    scanf("%s", artist_name);

    printf("Enter the name of the song: ");
    scanf("%s", song_name);

    int song_found = 0;

    for(int i=0; i<num_of_songs; i++) {
        if(strcmp(music_library[i].artist_name, artist_name) == 0 && 
        strcmp(music_library[i].song_name, song_name) == 0) {
            song_found = 1;
            printf("\n-----------Song Found-----------\n");
            printf("Artist Name: %s\n", music_library[i].artist_name);
            printf("Song Name: %s\n", music_library[i].song_name);
            printf("Rating: %d\n", music_library[i].rating);
            break;
        }
    }

    if(song_found == 0) {
        printf("Sorry, the song was not found in the library.\n");
    }
}

// Function to display all songs in the library
void display_all_songs() {
    if(num_of_songs == 0) {
        printf("Sorry, the music library is empty.\n");
        return;
    }

    printf("\n-----------List of All Songs in the Library-----------\n");
    printf("Artist Name\tSong Name\tRating\n");

    for(int i=0; i<num_of_songs; i++) {
        printf("%s\t\t%s\t\t%d\n", music_library[i].artist_name, 
        music_library[i].song_name, music_library[i].rating);
    }
}

// Function to display top rated songs in the library
void display_top_rated_songs() {
    if(num_of_songs == 0) {
        printf("Sorry, the music library is empty.\n");
        return;
    }

    int max_rating = 0;

    for(int i=0; i<num_of_songs; i++) {
        if(music_library[i].rating > max_rating) {
            max_rating = music_library[i].rating;
        }
    }

    printf("\n-----------List of Top Rated Songs in the Library-----------\n");
    printf("Artist Name\tSong Name\tRating\n");

    for(int i=0; i<num_of_songs; i++) {
        if(music_library[i].rating == max_rating) {
            printf("%s\t\t%s\t\t%d\n", music_library[i].artist_name, 
            music_library[i].song_name, music_library[i].rating);
        }
    }
}