//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SONGS 100

struct song {
    char title[50];
    char artist[50];
    char album[50];
};

void add_song(struct song *songs, int index, const char *title, const char *artist, const char *album) {
    if (index >= MAX_SONGS) {
        printf("Error: Too many songs in library!\n");
        return;
    }

    if (index == 0) {
        strcpy(songs[index].title, title);
        strcpy(songs[index].artist, artist);
        strcpy(songs[index].album, album);
    } else {
        strcpy(songs[index].title, songs[index - 1].title);
        strcpy(songs[index].artist, songs[index - 1].artist);
        strcpy(songs[index].album, songs[index - 1].album);
    }

    printf("Added '%s' by '%s' to the library\n", title, artist);
}

void delete_song(struct song *songs, int index) {
    if (index >= MAX_SONGS) {
        printf("Error: Invalid index!\n");
        return;
    }

    if (index == MAX_SONGS - 1) {
        printf("Error: Cannot delete last song!\n");
        return;
    }

    printf("Deleted '%s' by '%s'\n", songs[index].title, songs[index].artist);
}

void print_songs(struct song *songs) {
    for (int i = 0; i < MAX_SONGS; i++) {
        printf("%d. %s by %s - %s\n", i + 1, songs[i].title, songs[i].artist, songs[i].album);
    }
}

int main() {
    struct song songs[MAX_SONGS];
    int index = 0;

    printf("Welcome to the Music Library!\n");

    while (1) {
        printf("\n1. Add a song\n2. Delete a song\n3. Print all songs\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the song title: ");
                scanf("%s", songs[index].title);

                printf("Enter the artist: ");
                scanf("%s", songs[index].artist);

                printf("Enter the album: ");
                scanf("%s", songs[index].album);

                add_song(songs, index, songs[index].title, songs[index].artist, songs[index].album);

                break;

            case 2:
                printf("Enter the index of the song to delete: ");
                scanf("%d", &index);

                delete_song(songs, index);

                break;

            case 3:
                print_songs(songs);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}