//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50
typedef struct {
    char name[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
    int track;
    int genre;
} Song;
void add_song(Song *songs, int num_songs, Song new_song) {
    if (num_songs >= MAX_LENGTH) {
        printf("Music library is full.\n");
        return;
    }
    strcpy(songs[num_songs].name, new_song.name);
    strcpy(songs[num_songs].artist, new_song.artist);
    strcpy(songs[num_songs].album, new_song.album);
    songs[num_songs].year = new_song.year;
    songs[num_songs].track = new_song.track;
    songs[num_songs].genre = new_song.genre;
    num_songs++;
}
void print_songs(Song *songs, int num_songs) {
    for (int i = 0; i < num_songs; i++) {
        printf("Song %d:\n", i + 1);
        printf("Name: %s\n", songs[i].name);
        printf("Artist: %s\n", songs[i].artist);
        printf("Album: %s\n", songs[i].album);
        printf("Year: %d\n", songs[i].year);
        printf("Track: %d\n", songs[i].track);
        printf("Genre: %d\n", songs[i].genre);
        printf("\n");
    }
}
int main() {
    Song songs[MAX_LENGTH];
    int num_songs = 0;
    printf("Enter song information:\n");
    while (1) {
        char name[MAX_LENGTH];
        char artist[MAX_LENGTH];
        char album[MAX_LENGTH];
        int year, track, genre;
        printf("Name: ");
        fgets(name, MAX_LENGTH, stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("Artist: ");
        fgets(artist, MAX_LENGTH, stdin);
        artist[strcspn(artist, "\n")] = '\0';
        printf("Album: ");
        fgets(album, MAX_LENGTH, stdin);
        album[strcspn(album, "\n")] = '\0';
        printf("Year: ");
        scanf("%d", &year);
        printf("Track: ");
        scanf("%d", &track);
        printf("Genre: ");
        scanf("%d", &genre);
        Song new_song = {name, artist, album, year, track, genre};
        add_song(songs, num_songs, new_song);
        printf("Add another song? (y/n) ");
        char answer[MAX_LENGTH];
        fgets(answer, MAX_LENGTH, stdin);
        answer[strcspn(answer, "\n")] = '\0';
        if (answer[0] == 'n') {
            break;
        }
    }
    print_songs(songs, num_songs);
    return 0;
}