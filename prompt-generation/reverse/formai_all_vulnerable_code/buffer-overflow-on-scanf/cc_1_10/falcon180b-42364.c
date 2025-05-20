//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_NUM_OF_SONGS 100
#define MAX_NUM_OF_PLAYLISTS 10

typedef struct {
    char title[50];
    char artist[50];
    char album[100];
    int duration;
} Song;

typedef struct {
    char name[50];
    int num_of_songs;
    Song songs[MAX_NUM_OF_SONGS];
} Playlist;

void *add_song_to_playlist(void *arg) {
    Playlist *playlist = (Playlist *) arg;
    Song *song = (Song *) malloc(sizeof(Song));

    printf("Enter song title: ");
    scanf("%s", song->title);
    printf("Enter song artist: ");
    scanf("%s", song->artist);
    printf("Enter song album: ");
    scanf("%s", song->album);
    printf("Enter song duration: ");
    scanf("%d", &song->duration);

    playlist->songs[playlist->num_of_songs++] = *song;
    free(song);

    pthread_exit(NULL);
}

void *play_song_from_playlist(void *arg) {
    Playlist *playlist = (Playlist *) arg;
    int song_index;

    printf("Which song do you want to play? ");
    scanf("%d", &song_index);

    Song *song = &playlist->songs[song_index];
    printf("Playing %s by %s from album %s (%d seconds)\n", song->title, song->artist, song->album, song->duration);

    pthread_exit(NULL);
}

int main() {
    Playlist playlist;
    pthread_t threads[2];

    printf("Enter playlist name: ");
    scanf("%s", playlist.name);

    playlist.num_of_songs = 0;

    pthread_create(&threads[0], NULL, add_song_to_playlist, &playlist);
    pthread_create(&threads[1], NULL, play_song_from_playlist, &playlist);

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}