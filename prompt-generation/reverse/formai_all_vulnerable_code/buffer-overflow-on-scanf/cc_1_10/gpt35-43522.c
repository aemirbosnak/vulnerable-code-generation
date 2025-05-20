//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 500

typedef struct {
    int id;
    char name[50];
    char artist[50];
    int num_songs;
    char genre[50];
} Album;

typedef struct {
    int id;
    char name[50];
    int duration;
    int album_id;
} Song;

Album albums[MAX_ALBUMS];
Song songs[MAX_SONGS];
int num_albums = 0;
int num_songs = 0;

void add_album(char name[], char artist[], int num_songs, char genre[]) {
    if(num_albums >= MAX_ALBUMS) {
        printf("Maximum number of albums reached. Cannot add new album.\n");
    } else {
        Album album;
        album.id = num_albums+1;
        strcpy(album.name, name);
        strcpy(album.artist, artist);
        album.num_songs = num_songs;
        strcpy(album.genre, genre);
        albums[num_albums] = album;
        num_albums++;
        printf("Album added successfully.\n");
    }
}

void add_song(char name[], int duration, int album_id) {
    if(num_songs >= MAX_SONGS) {
        printf("Maximum number of songs reached. Cannot add new song.\n");
    } else if(album_id < 1 || album_id > num_albums) {
        printf("Invalid album ID. Cannot add song.\n");
    } else {
        Song song;
        song.id = num_songs+1;
        strcpy(song.name, name);
        song.duration = duration;
        song.album_id = album_id;
        songs[num_songs] = song;
        num_songs++;
        printf("Song added successfully.\n");
    }
}

void display_albums() {
    printf("ID\tName\t\tArtist\t\tNumber of songs\tGenre\n");
    printf("--------------------------------------------------\n");
    for(int i=0; i<num_albums; i++) {
        printf("%d\t%-15s\t%-15s\t%d\t\t%s\n", albums[i].id, albums[i].name, albums[i].artist, albums[i].num_songs, albums[i].genre);
    }
}

void display_songs_by_album(int album_id) {
    if(album_id < 1 || album_id > num_albums) {
        printf("Invalid album ID. Cannot display songs.\n");
    } else {
        printf("ID\tName\t\tDuration (in seconds)\n");
        printf("----------------------------------\n");
        for(int i=0; i<num_songs; i++) {
            if(songs[i].album_id == album_id) {
                printf("%d\t%-15s\t%d\n", songs[i].id, songs[i].name, songs[i].duration);
            }
        }
    }
}

void display_songs_by_artist(char artist[]) {
    printf("ID\tName\t\tArtist\t\tDuration (in seconds)\n");
    printf("----------------------------------------------\n");
    for(int i=0; i<num_songs; i++) {
        if(strcmp(albums[songs[i].album_id-1].artist, artist) == 0) {
            printf("%d\t%-15s\t%-15s\t%d\n", songs[i].id, songs[i].name, artist, songs[i].duration);
        }
    }
}

int main() {
    int choice;
    char album_name[50];
    char album_artist[50];
    int album_num_songs;
    char album_genre[50];
    char song_name[50];
    int song_duration;
    int album_id;
    char artist_name[50];

    while(1) {
        printf("\nC Music Library Management System\n");
        printf("1. Add album\n");
        printf("2. Add song\n");
        printf("3. Display albums\n");
        printf("4. Display songs by album\n");
        printf("5. Display songs by artist\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter album name: ");
                scanf("%s", album_name);
                printf("Enter artist name: ");
                scanf("%s", album_artist);
                printf("Enter number of songs: ");
                scanf("%d", &album_num_songs);
                printf("Enter genre: ");
                scanf("%s", album_genre);
                add_album(album_name, album_artist, album_num_songs, album_genre);
                break;
            case 2:
                printf("Enter song name: ");
                scanf("%s", song_name);
                printf("Enter duration (in seconds): ");
                scanf("%d", &song_duration);
                printf("Enter album ID: ");
                scanf("%d", &album_id);
                add_song(song_name, song_duration, album_id);
                break;
            case 3:
                display_albums();
                break;
            case 4:
                printf("Enter album ID: ");
                scanf("%d", &album_id);
                display_songs_by_album(album_id);
                break;
            case 5:
                printf("Enter artist name: ");
                scanf("%s", artist_name);
                display_songs_by_artist(artist_name);
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}