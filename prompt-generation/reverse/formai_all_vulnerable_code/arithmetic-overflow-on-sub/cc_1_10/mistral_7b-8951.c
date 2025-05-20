//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define SONG_TITLE_LENGTH 50
#define ARTIST_NAME_LENGTH 50

typedef struct Song {
    char title[SONG_TITLE_LENGTH];
    char artist[ARTIST_NAME_LENGTH];
    int play_count;
} Song;

Song library[MAX_SONGS];
int num_songs = 0;

void add_song(const char *title, const char *artist) {
    if (num_songs >= MAX_SONGS) {
        printf("Music Library is Full!\n");
        return;
    }

    strcpy(library[num_songs].title, title);
    strcpy(library[num_songs].artist, artist);
    library[num_songs++].play_count = 0;
}

void play_song(int index) {
    if (index >= 0 && index < num_songs) {
        library[index].play_count++;
        printf("Playing %s by %s\n", library[index].title, library[index].artist);
    } else {
        printf("Invalid Song Index!\n");
    }
}

void print_library() {
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (Played %d times)\n", i + 1, library[i].title, library[i].artist, library[i].play_count);
    }
}

int main() {
    char title[SONG_TITLE_LENGTH];
    char artist[ARTIST_NAME_LENGTH];

    while (1) {
        printf("\n1. Add Song\n2. Play Song\n3. Print Library\n4. Quit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Title: ");
                scanf("%s", title);
                printf("Enter Artist: ");
                scanf("%s", artist);
                add_song(title, artist);
                break;
            case 2:
                printf("Enter Song Index: ");
                int index;
                scanf("%d", &index);
                play_song(index - 1);
                break;
            case 3:
                print_library();
                break;
            case 4:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}