//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 100

typedef struct song {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int duration;
} Song;

Song library[MAX_SONGS];
int num_songs;

void add_song(char *name, char *artist, char *album, int duration) {
    if (num_songs >= MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }
    strcpy(library[num_songs].name, name);
    strcpy(library[num_songs].artist, artist);
    strcpy(library[num_songs].album, album);
    library[num_songs].duration = duration;
    num_songs++;
}

void play_song(int index) {
    if (index < 0 || index >= num_songs) {
        printf("Invalid song index.\n");
        return;
    }
    printf("Playing %s by %s from the album %s (%d seconds).\n", library[index].name, library[index].artist, library[index].album, library[index].duration);
}

void search_song(char *query) {
    int i;
    for (i = 0; i < num_songs; i++) {
        if (strstr(library[i].name, query) || strstr(library[i].artist, query) || strstr(library[i].album, query)) {
            printf("Found song: %s by %s from the album %s (%d seconds).\n", library[i].name, library[i].artist, library[i].album, library[i].duration);
        }
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int duration;

    do {
        printf("1. Add song\n2. Play song\n3. Search song\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter song name: ");
            scanf("%s", name);
            printf("Enter artist name: ");
            scanf("%s", artist);
            printf("Enter album name: ");
            scanf("%s", album);
            printf("Enter song duration (in seconds): ");
            scanf("%d", &duration);
            add_song(name, artist, album, duration);
            break;
        case 2:
            printf("Enter song index: ");
            scanf("%d", &choice);
            play_song(choice);
            break;
        case 3:
            printf("Enter search query: ");
            scanf("%s", name);
            search_song(name);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}