//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALBUMS 100
#define MAX_TRACKS 20
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30

typedef struct {
    char artist[MAX_ARTIST_LENGTH];
    char title[MAX_TITLE_LENGTH];
    int tracks[MAX_TRACKS];
    int num_tracks;
} Album;

Album library[MAX_ALBUMS];
int num_albums = 0;

void add_album(char *artist, char *title, int num_tracks) {
    if (num_albums >= MAX_ALBUMS) {
        printf("Music library is full.\n");
        return;
    }

    strcpy(library[num_albums].artist, artist);
    strcpy(library[num_albums].title, title);

    library[num_albums].num_tracks = num_tracks;

    for (int i = 0; i < num_tracks; i++) {
        printf("Enter track %d title: ", i + 1);
        scanf("%s", library[num_albums].tracks[i]);
    }

    num_albums++;
}

void search_title(char *title) {
    for (int i = 0; i < num_albums; i++) {
        if (strstr(library[i].title, title) != NULL) {
            printf("Album: %s by %s\n", library[i].title, library[i].artist);
            printf("Tracks:\n");

            for (int j = 0; j < library[i].num_tracks; j++) {
                printf("%d. %s\n", j + 1, library[i].tracks[j]);
            }

            return;
        }
    }

    printf("No album found with title \"%s\".\n", title);
}

void search_artist(char *artist) {
    for (int i = 0; i < num_albums; i++) {
        if (strstr(library[i].artist, artist) != NULL) {
            printf("Album: %s by %s\n", library[i].title, library[i].artist);
            printf("Tracks:\n");

            for (int j = 0; j < library[i].num_tracks; j++) {
                printf("%d. %s\n", j + 1, library[i].tracks[j]);
            }

            return;
        }
    }

    printf("No album found by artist \"%s\".\n", artist);
}

int main() {
    char command[5];
    char artist[MAX_ARTIST_LENGTH];
    char title[MAX_TITLE_LENGTH];
    int num_tracks;

    while (1) {
        printf("Enter command (add/search/quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter artist: ");
            scanf("%s", artist);
            printf("Enter title: ");
            scanf("%s", title);
            printf("Enter number of tracks: ");
            scanf("%d", &num_tracks);

            add_album(artist, title, num_tracks);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter search type (artist/title): ");
            scanf("%s", command);

            if (strcmp(command, "artist") == 0) {
                printf("Enter artist: ");
                scanf("%s", artist);
                search_artist(artist);
            } else if (strcmp(command, "title") == 0) {
                printf("Enter title: ");
                scanf("%s", title);
                search_title(title);
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}