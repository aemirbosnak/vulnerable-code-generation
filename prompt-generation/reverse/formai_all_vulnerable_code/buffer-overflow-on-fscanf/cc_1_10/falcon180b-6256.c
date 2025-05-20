//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_ALBUM_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_YEAR 4
#define MAX_TRACK_NUMBER 3
#define MAX_TRACK_LEN 100
#define MAX_FILE_PATH 200
#define MAX_PLAYLIST_NAME 50

#define TRUE 1
#define FALSE 0

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    char year[MAX_YEAR];
    char track_number[MAX_TRACK_NUMBER];
    char track[MAX_TRACK_LEN];
    char file_path[MAX_FILE_PATH];
    int track_length;
    int track_number_int;
    int year_int;
} Track;

typedef struct {
    char name[MAX_PLAYLIST_NAME];
    Track tracks[100];
    int num_tracks;
} Playlist;

void read_tracks_from_file(Track* tracks, int max_tracks, FILE* file) {
    int i = 0;
    while (i < max_tracks && fscanf(file, "%s %s %s %s %s %s %s %d %d %d\n", tracks[i].title, tracks[i].artist, tracks[i].album, tracks[i].genre, tracks[i].year, tracks[i].track_number, tracks[i].track, &tracks[i].track_length, &tracks[i].track_number_int, &tracks[i].year_int) == 10) {
        i++;
    }
    if (ferror(file)) {
        printf("Error reading tracks from file.\n");
        exit(1);
    }
}

void print_tracks(Track* tracks, int num_tracks) {
    for (int i = 0; i < num_tracks; i++) {
        printf("%s - %s\n", tracks[i].artist, tracks[i].title);
    }
}

void add_track_to_playlist(Playlist* playlist, Track track) {
    if (playlist->num_tracks >= 100) {
        printf("Playlist is full.\n");
        return;
    }
    playlist->tracks[playlist->num_tracks++] = track;
}

void print_playlist(Playlist* playlist) {
    printf("Playlist '%s':\n", playlist->name);
    for (int i = 0; i < playlist->num_tracks; i++) {
        printf("%s - %s\n", playlist->tracks[i].artist, playlist->tracks[i].title);
    }
}

int main() {
    srand(time(NULL));
    Track tracks[100];
    read_tracks_from_file(tracks, 100, stdin);
    Playlist playlist;
    strcpy(playlist.name, "Cyberpunk Vibes");
    add_track_to_playlist(&playlist, tracks[rand() % 100]);
    add_track_to_playlist(&playlist, tracks[rand() % 100]);
    add_track_to_playlist(&playlist, tracks[rand() % 100]);
    print_playlist(&playlist);
    return 0;
}