//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SONGS 100
#define MAX_THREADS 10

// Song data structure
typedef struct {
    char title[100];
    char artist[100];
    int duration;
} Song;

// Music library data structure
typedef struct {
    int num_songs;
    Song songs[MAX_SONGS];
} MusicLibrary;

// Thread data structure
typedef struct {
    MusicLibrary *lib;
    int song_index;
} ThreadData;

// Function to play a song
void *play_song(void *data) {
    ThreadData *thread_data = (ThreadData *) data;
    MusicLibrary *lib = thread_data->lib;
    Song *song = &lib->songs[thread_data->song_index];

    printf("Playing %s by %s (%d seconds)\n", song->title, song->artist, song->duration);
}

// Function to add a song to the music library
void add_song(MusicLibrary *lib) {
    printf("Enter song title: ");
    scanf("%s", lib->songs[lib->num_songs].title);
    printf("Enter artist: ");
    scanf("%s", lib->songs[lib->num_songs].artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &lib->songs[lib->num_songs].duration);
    lib->num_songs++;
}

// Main function
int main() {
    MusicLibrary lib;
    lib.num_songs = 0;

    // Initialize the music library with some songs
    add_song(&lib);
    add_song(&lib);
    add_song(&lib);

    // Create threads to play the songs
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    int i;
    for (i = 0; i < MAX_THREADS && i < lib.num_songs; i++) {
        thread_data[i].lib = &lib;
        thread_data[i].song_index = i;
        pthread_create(&threads[i], NULL, play_song, (void *) &thread_data[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < MAX_THREADS && i < lib.num_songs; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}