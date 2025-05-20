//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

typedef struct song_t {
    char title[100];
    char artist[100];
    char album[100];
    int duration;
} Song;

Song songs[MAX_SONGS];
int num_songs;

void add_song() {
    printf("Enter song title: ");
    scanf("%s", songs[num_songs].title);

    printf("Enter artist name: ");
    scanf("%s", songs[num_songs].artist);

    printf("Enter album name: ");
    scanf("%s", songs[num_songs].album);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &songs[num_songs].duration);

    num_songs++;
}

void play_song(int index) {
    printf("Playing %s by %s from the album %s (%d seconds)\n",
           songs[index].title, songs[index].artist, songs[index].album,
           songs[index].duration);
}

void search_song(char *query) {
    int i;
    for (i = 0; i < num_songs; i++) {
        if (strstr(songs[i].title, query) ||
            strstr(songs[i].artist, query) ||
            strstr(songs[i].album, query)) {
            play_song(i);
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add song\n");
        printf("2. Play song\n");
        printf("3. Search song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;

            case 2:
                printf("Enter song index: ");
                scanf("%d", &choice);
                play_song(choice);
                break;

            case 3:
                printf("Enter search query: ");
                char query[100];
                scanf("%s", query);
                search_song(query);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}