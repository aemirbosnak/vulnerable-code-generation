//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_ARTISTS 500
#define MAX_PLAYLISTS 100

typedef struct {
    char title[50];
    char artist[30];
    int year;
    char album[50];
    char genre[20];
    float duration;
} Song;

typedef struct {
    char name[30];
    int num_songs;
    Song playlist_songs[MAX_SONGS];
} Playlist;

int num_songs = 0;
int num_artists = 0;
Song music_library[MAX_SONGS];
char artist_list[MAX_ARTISTS][30];
int num_playlists = 0;
Playlist playlists[MAX_PLAYLISTS];

void add_song() {
    Song new_song;
    printf("Enter the title of the song: ");
    scanf(" %50[^\n]", new_song.title);
    printf("Enter the artist of the song: ");
    scanf(" %30[^\n]", new_song.artist);
    printf("Enter the year of the song: ");
    scanf("%d", &new_song.year);
    printf("Enter the album of the song: ");
    scanf(" %50[^\n]", new_song.album);
    printf("Enter the genre of the song: ");
    scanf(" %20[^\n]", new_song.genre);
    printf("Enter the duration of the song: ");
    scanf("%f", &new_song.duration);

    music_library[num_songs] = new_song;

    // check if artist already exists in artist_list array or add if new
    int artist_found = 0;
    for (int i = 0; i < num_artists; i++) {
        if (strcmp(artist_list[i], new_song.artist) == 0) {
            artist_found = 1;
            break;
        }
    }
    if (!artist_found) {
        strcpy(artist_list[num_artists], new_song.artist);
        num_artists++;
    }

    printf("Song added to the music library!\n\n");
    num_songs++;
}

void display_music_library() {
    if (num_songs == 0) {
        printf("The music library is empty.\n\n");
        return;
    }
    printf("DISPLAYING MUSIC LIBRARY:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d)\nTitle: %s\nArtist: %s\nYear: %d\nAlbum: %s\nGenre: %s\nDuration: %.02f mins\n", 
        i+1, music_library[i].title, music_library[i].artist, music_library[i].year, music_library[i].album, 
        music_library[i].genre, music_library[i].duration);
        printf("----------------------\n");
    }
    printf("\n");
}

void display_artists() {
    if (num_artists == 0) {
        printf("There are no artists in the music library.\n\n");
        return;
    }
    printf("DISPLAYING ARTISTS:\n");
    for (int i = 0; i < num_artists; i++) {
        printf("%d) %s\n", i+1, artist_list[i]);
        printf("---------------------\n");
    }
    printf("\n");
}

void create_playlist() {
    if (num_songs == 0) {
        printf("Cannot create a playlist as the music library is empty.\n\n");
        return;
    }
    Playlist new_playlist;
    printf("Enter the name of the playlist: ");
    scanf(" %30[^\n]", new_playlist.name);
    printf("How many songs would you like in the playlist? ");
    scanf("%d", &new_playlist.num_songs);
    for (int i = 0; i < new_playlist.num_songs; i++) {
        int song_num;
        printf("Enter the song number to add to the playlist: ");
        scanf("%d", &song_num);
        // check if song number is valid
        if (song_num < 1 || song_num > num_songs) {
            printf("Invalid song number.\n");
            i--;
            continue;
        }
        new_playlist.playlist_songs[i] = music_library[song_num-1];
    }
    playlists[num_playlists] = new_playlist;
    printf("Playlist created!\n\n");
    num_playlists++;
}

void display_playlists() {
    if (num_playlists == 0) {
        printf("There are no playlists created.\n\n");
        return;
    }
    printf("DISPLAYING PLAYLISTS:\n");
    for (int i = 0; i < num_playlists; i++) {
        printf("Name: %s\nNumber of songs: %d\n", playlists[i].name, playlists[i].num_songs);
        for (int j = 0; j < playlists[i].num_songs; j++) {
            printf("%d)\nTitle: %s\nArtist: %s\nYear: %d\nAlbum: %s\nGenre: %s\nDuration: %.02f mins\n", 
            j+1, playlists[i].playlist_songs[j].title, playlists[i].playlist_songs[j].artist,
            playlists[i].playlist_songs[j].year, playlists[i].playlist_songs[j].album,
            playlists[i].playlist_songs[j].genre, playlists[i].playlist_songs[j].duration);
            printf("----------------------\n");
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("MUSIC LIBRARY MANAGEMENT SYSTEM:\n");
        printf("1) Add a song\n");
        printf("2) Display music library\n");
        printf("3) Display artists\n");
        printf("4) Create a playlist\n");
        printf("5) Display playlists\n");
        printf("6) Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_music_library();
                break;
            case 3:
                display_artists();
                break;
            case 4:
                create_playlist();
                break;
            case 5:
                display_playlists();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}