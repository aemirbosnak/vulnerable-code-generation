//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SONGS 1000

typedef struct {
    char title[100];
    char artist[100];
    int duration;
    bool is_favorite;
} Song;

void add_song(Song *songs, int num_songs, Song new_song) {
    if (num_songs >= MAX_SONGS) {
        printf("Error: Library is full.\n");
        return;
    }
    songs[num_songs] = new_song;
    num_songs++;
}

void print_songs(Song *songs, int num_songs) {
    printf("Library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (%d seconds)\n", i+1, songs[i].title, songs[i].artist, songs[i].duration);
    }
}

void search_songs(Song *songs, int num_songs, char *query) {
    printf("Search results:\n");
    for (int i = 0; i < num_songs; i++) {
        if (strstr(songs[i].title, query)!= NULL || strstr(songs[i].artist, query)!= NULL) {
            printf("%d. %s - %s (%d seconds)\n", i+1, songs[i].title, songs[i].artist, songs[i].duration);
        }
    }
}

int main() {
    Song songs[MAX_SONGS];
    int num_songs = 0;

    add_song(songs, num_songs, (Song) {"Bohemian Rhapsody", "Queen", 360, false});
    add_song(songs, num_songs, (Song) {"Stairway to Heaven", "Led Zeppelin", 540, false});
    add_song(songs, num_songs, (Song) {"Sweet Child O' Mine", "Guns N' Roses", 360, false});
    add_song(songs, num_songs, (Song) {"November Rain", "Guns N' Roses", 720, false});
    add_song(songs, num_songs, (Song) {"Don't Stop Believin'", "Journey", 300, false});

    print_songs(songs, num_songs);

    char query[100];
    printf("Enter a search query: ");
    scanf("%s", query);
    search_songs(songs, num_songs, query);

    return 0;
}