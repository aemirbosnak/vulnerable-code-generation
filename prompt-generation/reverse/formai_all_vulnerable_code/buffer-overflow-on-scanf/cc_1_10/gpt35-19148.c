//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song song_t;
typedef struct Playlist playlist_t;

struct Song {
    char title[50];
    char artist[50];
    int year;
    double duration;
    song_t *next;
};

struct Playlist {
    char name[50];
    int length;
    song_t *head;
};

void add_song(playlist_t *p);
void remove_song(playlist_t *p);
void display_playlist(playlist_t *p);
void display_song(song_t *s);

int main() {
    int choice;
    playlist_t playlist;
    playlist.length = 0;
    playlist.head = NULL;

    do {
        printf("\n\nC Music Library Management System\n");
        printf("1. Add Song\n2. Remove Song\n3. Display Playlist\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(&playlist);
                break;
            case 2:
                remove_song(&playlist);
                break;
            case 3:
                display_playlist(&playlist);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input. Try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}

void add_song(playlist_t *p) {
    song_t *new_song = (song_t*) malloc(sizeof(song_t));
    if(new_song == NULL) {
        printf("\nMemory allocation failed. Song could not be added.\n");
        return;
    }

    printf("\nEnter song title: ");
    scanf("%s", new_song->title);
    printf("Enter artist: ");
    scanf("%s", new_song->artist);
    printf("Enter year of release: ");
    scanf("%d", &new_song->year);
    printf("Enter duration (in minutes): ");
    scanf("%lf", &new_song->duration);
    new_song->next = NULL;

    if(p->head == NULL) {
        p->head = new_song;
    }
    else {
        song_t *current = p->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_song;
    }

    printf("\nSong added successfully to playlist %s.\n", p->name);
    p->length++;
}

void remove_song(playlist_t *p) {
    if(p->head == NULL) {
        printf("\nPlaylist is empty. Cannot remove song.\n");
        return;
    }

    char title[50];
    printf("\nEnter title of song to be removed: ");
    scanf("%s", title);

    song_t *current = p->head;
    song_t *previous = NULL;

    while(current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("\nSong not found in playlist.\n");
        return;
    }

    if(previous == NULL) {
        p->head = current->next;
    }
    else {
        previous->next = current->next;
    }

    free(current);
    printf("\nSong removed successfully from playlist %s.\n", p->name);
    p->length--;
}

void display_playlist(playlist_t *p) {
    printf("\n%s (%d songs):\n", p->name, p->length);

    if(p->head == NULL) {
        printf("Empty playlist.\n");
        return;
    }

    song_t *current = p->head;

    while(current != NULL) {
        display_song(current);
        current = current->next;
    }
}

void display_song(song_t *s) {
    printf("\nTitle: %s\n", s->title);
    printf("Artist: %s\n", s->artist);
    printf("Year of release: %d\n", s->year);
    printf("Duration: %.2lf minutes\n", s->duration);
}