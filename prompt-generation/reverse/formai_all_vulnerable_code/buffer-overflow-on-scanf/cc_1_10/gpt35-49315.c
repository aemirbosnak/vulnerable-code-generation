//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_SONGS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    double duration;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} Playlist;

void add_song(Playlist *playlist);
void remove_song(Playlist *playlist);
void display_songs(Playlist playlist);
void search_song(Playlist playlist);

int main() {
    Playlist my_playlist = { .num_songs = 0 };
    int choice;

    do {
        printf("Menu\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Display all songs\n");
        printf("4. Search for a song\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(&my_playlist);
                break;
            case 2:
                remove_song(&my_playlist);
                break;
            case 3:
                display_songs(my_playlist);
                break;
            case 4:
                search_song(my_playlist);
                break;
            case 0:
                printf("Exiting program... \n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}

void add_song(Playlist *playlist) {
    if (playlist->num_songs == MAX_SONGS) {
        printf("Playlist is full, cannot add any more songs.\n");
        return;
    }

    Song new_song;
    printf("Enter the song title: ");
    scanf(" %[^\n]", new_song.title);
    printf("Enter the artist name: ");
    scanf(" %[^\n]", new_song.artist);
    printf("Enter the song duration (in minutes): ");
    scanf("%lf", &new_song.duration);

    playlist->songs[playlist->num_songs++] = new_song;
    printf("New song has been added.\n");
}

void remove_song(Playlist *playlist) {
    if (playlist->num_songs == 0) {
        printf("Playlist is empty, cannot remove any songs.\n");
        return;
    }

    char target_title[MAX_TITLE_LENGTH];
    printf("Enter the title of the song to remove: ");
    scanf(" %[^\n]", target_title);
    
    int index = -1;
    for (int i = 0; i < playlist->num_songs; i++) {
        if (strcmp(target_title, playlist->songs[i].title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found in playlist.\n");
    } else {
        for (int i = index; i < playlist->num_songs - 1; i++) {
            playlist->songs[i] = playlist->songs[i + 1];
        }
        playlist->num_songs--;
        printf("Song has been removed.\n");
    }
}

void display_songs(Playlist playlist) {
    if (playlist.num_songs == 0) {
        printf("Playlist is empty, cannot display any songs.\n");
        return;
    }
    
    printf("Title \t- Artist \t- Duration\n");
    for (int i = 0; i < playlist.num_songs; i++) {
        printf("%s \t- %s \t- %.2f minutes\n",
            playlist.songs[i].title,
            playlist.songs[i].artist,
            playlist.songs[i].duration);
    }
}

void search_song(Playlist playlist) {
    if (playlist.num_songs == 0) {
        printf("Playlist is empty, cannot search for any songs.\n");
        return;
    }

    char target_title[MAX_TITLE_LENGTH];
    printf("Enter the title of the song to search for: ");
    scanf(" %[^\n]", target_title);
    
    int index = -1;
    for (int i = 0; i < playlist.num_songs; i++) {
        if (strcmp(target_title, playlist.songs[i].title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found in playlist.\n");
    } else {
        printf("Title \t- Artist \t- Duration\n");
        printf("%s \t- %s \t- %.2f minutes\n",
            playlist.songs[index].title,
            playlist.songs[index].artist,
            playlist.songs[index].duration);
    }
}