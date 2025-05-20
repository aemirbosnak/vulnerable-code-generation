//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define SONG_NAME_LENGTH 50
#define ARTIST_NAME_LENGTH 50

typedef struct Song {
    char name[SONG_NAME_LENGTH];
    char artist[ARTIST_NAME_LENGTH];
} Song;

Song library[MAX_SONGS];
int num_songs = 0;

void add_song(char* name, char* artist) {
    if (num_songs >= MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }
    strcpy(library[num_songs].name, name);
    strcpy(library[num_songs].artist, artist);
    num_songs++;
}

void print_library() {
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].name, library[i].artist);
    }
}

int search_song(char* name, char* artist) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].name, name) == 0 && strcmp(library[i].artist, artist) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char command[10];
    char name[SONG_NAME_LENGTH], artist[ARTIST_NAME_LENGTH];
    int index;

    while (1) {
        printf("\nC Music Library Management System\n");
        printf("Commands:\n");
        printf("  add <name> <artist>\n");
        printf("  list\n");
        printf("  search <name> <artist>\n");
        printf("  quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter song name: ");
            scanf("%s", name);
            printf("Enter artist name: ");
            scanf("%s", artist);
            add_song(name, artist);
        } else if (strcmp(command, "list") == 0) {
            print_library();
        } else if (strcmp(command, "search") == 0) {
            printf("Enter song name: ");
            scanf("%s", name);
            printf("Enter artist name: ");
            scanf("%s", artist);
            index = search_song(name, artist);
            if (index != -1) {
                printf("Song found: %s by %s\n", library[index].name, library[index].artist);
            } else {
                printf("Song not found.\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}