//FormAI DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTISTS 100
#define MAX_ALBUMS 1000
#define MAX_SONGS 10000

typedef struct artist {
    int id;
    char name[50];
    int num_albums;
    int album_ids[MAX_ALBUMS];
} Artist;

typedef struct album {
    int id;
    char title[50];
    char genre[20];
    int release_year;
    int num_songs;
    int song_ids[MAX_SONGS];
} Album;

typedef struct song {
    int id;
    char title[50];
    char artist_name[50];
    char album_title[50];
    int length;
} Song;

Artist artists[MAX_ARTISTS];
Album albums[MAX_ALBUMS];
Song songs[MAX_SONGS];
int num_artists = 0;
int num_albums = 0;
int num_songs = 0;

void add_artist(char* name) {
    Artist new_artist;
    new_artist.id = num_artists;
    strcpy(new_artist.name, name);
    new_artist.num_albums = 0;
    num_artists++;
    artists[num_artists-1] = new_artist;
    printf("Artist added successfully!\n");
}

void add_album(char* title, char* artist_name, char* genre, int release_year) {
    Album new_album;
    new_album.id = num_albums;
    strcpy(new_album.title, title);
    strcpy(new_album.genre, genre);
    new_album.release_year = release_year;
    new_album.num_songs = 0;
    for (int i = 0; i < num_artists; i++) {
        if (strcmp(artist_name, artists[i].name) == 0) {
            new_album.song_ids[artists[i].num_albums] = artists[i].id;
            artists[i].album_ids[artists[i].num_albums] = num_albums;
            artists[i].num_albums++;
        }
    }
    num_albums++;
    albums[num_albums-1] = new_album;
    printf("Album added successfully!\n");
}

void add_song(char* title, char* artist_name, char* album_title, int length) {
    Song new_song;
    new_song.id = num_songs;
    strcpy(new_song.title, title);
    strcpy(new_song.artist_name, artist_name);
    strcpy(new_song.album_title, album_title);
    new_song.length = length;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(album_title, albums[i].title) == 0) {
            albums[i].song_ids[albums[i].num_songs] = num_songs;
            albums[i].num_songs++;
        }
    }
    num_songs++;
    songs[num_songs-1] = new_song;
    printf("Song added successfully!\n");
}

void print_artists() {
    for (int i = 0; i < num_artists; i++) {
        printf("%d. %s\n", artists[i].id, artists[i].name);
    }
}

void print_artist_details(int artist_id) {
    printf("Name: %s\n", artists[artist_id].name);
    printf("Number of Albums: %d\n", artists[artist_id].num_albums);
    for (int i = 0; i < artists[artist_id].num_albums; i++) {
        printf("%d. %s\n", i+1, albums[artists[artist_id].album_ids[i]].title);
    }
}

void print_album_details(int album_id) {
    printf("Title: %s\n", albums[album_id].title);
    printf("Genre: %s\n", albums[album_id].genre);
    printf("Release Year: %d\n", albums[album_id].release_year);
    printf("Number of Songs: %d\n", albums[album_id].num_songs);
    for (int i = 0; i < albums[album_id].num_songs; i++) {
        printf("%d. %s\n", i+1, songs[albums[album_id].song_ids[i]].title);
    }
}

int main() {
    int choice;
    char name[50];
    char title[50];
    char artist_name[50];
    char genre[20];
    char album_title[50];
    int release_year;
    int length;
    int artist_id;
    int album_id;
    while(1) {
        printf("Enter an option:\n");
        printf("1. Add Artist\n");
        printf("2. Add Album\n");
        printf("3. Add Song\n");
        printf("4. Print List of Artists\n");
        printf("5. Print Artist Details\n");
        printf("6. Print Album Details\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the name of the artist: ");
                scanf("%s", name);
                add_artist(name);
                break;
            case 2:
                printf("Enter the title of the album: ");
                scanf("%s", title);
                printf("Enter the name of the artist: ");
                scanf("%s", artist_name);
                printf("Enter the genre of the album: ");
                scanf("%s", genre);
                printf("Enter the release year of the album: ");
                scanf("%d", &release_year);
                add_album(title, artist_name, genre, release_year);
                break;
            case 3:
                printf("Enter the title of the song: ");
                scanf("%s", title);
                printf("Enter the name of the artist: ");
                scanf("%s", artist_name);
                printf("Enter the title of the album: ");
                scanf("%s", album_title);
                printf("Enter the length of the song (in seconds): ");
                scanf("%d", &length);
                add_song(title, artist_name, album_title, length);
                break;
            case 4:
                print_artists();
                break;
            case 5:
                printf("Enter the ID of the artist: ");
                scanf("%d", &artist_id);
                if (artist_id < num_artists && artist_id >= 0) {
                    print_artist_details(artist_id);
                } else {
                    printf("Invalid artist ID!\n");
                }
                break;
            case 6:
                printf("Enter the ID of the album: ");
                scanf("%d", &album_id);
                if (album_id < num_albums && album_id >= 0) {
                    print_album_details(album_id);
                } else {
                    printf("Invalid album ID!\n");
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}