//FormAI DATASET v1.0 Category: Music Library Management System ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct artist {
    int artist_id;
    char artist_name[50];
};

struct album {
    int album_id;
    char album_name[50];
    int artist_id;
};

struct song {
    int song_id;
    char song_name[50];
    int artist_id;
    int album_id;
    int year;
};

struct artist *artists;
struct album *albums;
struct song *songs;

int artist_count = 0;
int album_count = 0;
int song_count = 0;

void display_menu() {
    printf("\n\nWelcome to the Music Library Management System!\n\n");
    printf("1. Add Artist\n");
    printf("2. Add Album\n");
    printf("3. Add Song\n");
    printf("4. List Artists\n");
    printf("5. List Albums\n");
    printf("6. List Songs\n");
    printf("7. Exit\n\n");
}

void add_artist() {
    printf("\nAdd an Artist:\n");
    printf("Enter the artist name: ");
    char artist_name[50];
    scanf("%s", artist_name);

    artist_count++;
    artists = (struct artist*) realloc(artists, artist_count * sizeof(struct artist));
    artists[artist_count-1].artist_id = artist_count;
    strcpy(artists[artist_count-1].artist_name, artist_name);

    printf("\n%s added successfully!\n\n", artist_name);
}

void add_album() {
    printf("\nAdd an Album:\n");
    printf("Enter the album name: ");
    char album_name[50];
    scanf("%s", album_name);

    printf("Enter the artist ID: ");
    int artist_id;
    scanf("%d", &artist_id);

    album_count++;
    albums = (struct album*) realloc(albums, album_count * sizeof(struct album));
    albums[album_count-1].album_id = album_count;
    strcpy(albums[album_count-1].album_name, album_name);
    albums[album_count-1].artist_id = artist_id;

    printf("\n%s added successfully!\n\n", album_name);
}

void add_song() {
    printf("\nAdd a Song:\n");
    printf("Enter the song name: ");
    char song_name[50];
    scanf("%s", song_name);

    printf("Enter the artist ID: ");
    int artist_id;
    scanf("%d", &artist_id);

    printf("Enter the album ID: ");
    int album_id;
    scanf("%d", &album_id);

    printf("Enter the year of release: ");
    int year;
    scanf("%d", &year);

    song_count++;
    songs = (struct song*) realloc(songs, song_count * sizeof(struct song));
    songs[song_count-1].song_id = song_count;
    strcpy(songs[song_count-1].song_name, song_name);
    songs[song_count-1].artist_id = artist_id;
    songs[song_count-1].album_id = album_id;
    songs[song_count-1].year = year;

    printf("\n%s added successfully!\n\n", song_name);
}

void list_artists() {
    printf("\nArtists:\n");
    for(int i = 0; i < artist_count; i++) {
        printf("%d. %s\n", artists[i].artist_id, artists[i].artist_name);
    }
}

void list_albums() {
    printf("\nAlbums:\n");
    for(int i = 0; i < album_count; i++) {
        printf("%d. %s (Artist ID: %d)\n", albums[i].album_id, albums[i].album_name, albums[i].artist_id);
    }
}

void list_songs() {
    printf("\nSongs:\n");
    for(int i = 0; i < song_count; i++) {
        printf("%d. %s (Artist ID: %d, Album ID: %d, Year: %d)\n", songs[i].song_id, songs[i].song_name, songs[i].artist_id, songs[i].album_id, songs[i].year);
    }
}

int main() {
    int choice = 0;
    while(choice != 7) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_artist();
                break;
            case 2:
                add_album();
                break;
            case 3:
                add_song();
                break;
            case 4:
                list_artists();
                break;
            case 5:
                list_albums();
                break;
            case 6:
                list_songs();
                break;
            case 7:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n\n");
                break;
        }
    }

    free(artists);
    free(albums);
    free(songs);

    return 0;
}