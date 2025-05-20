//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    int duration;
} Song;

int num_songs = 0;
Song songs[MAX_SONGS];

void add_song() {
    if (num_songs >= MAX_SONGS) {
        printf("Error: Song library is full.\n");
        return;
    }

    Song* new_song = &songs[num_songs];

    printf("Enter song name: ");
    scanf("%s", new_song->name);

    printf("Enter artist name: ");
    scanf("%s", new_song->artist);

    printf("Enter album name: ");
    scanf("%s", new_song->album);

    printf("Enter genre: ");
    scanf("%s", new_song->genre);

    printf("Enter song duration in seconds: ");
    scanf("%d", &new_song->duration);

    num_songs++;
}

void print_library() {
    printf("\nSong library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s\n", i+1, songs[i].name, songs[i].artist);
    }
}

void search_by_name() {
    char search_name[MAX_NAME_LEN];

    printf("\nEnter song name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_songs; i++) {
        if (strcmp(search_name, songs[i].name) == 0) {
            printf("\nSong found:\n");
            printf("%s - %s\n", songs[i].name, songs[i].artist);
            break;
        }
    }
}

int main() {
    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add song\n");
        printf("2. Print library\n");
        printf("3. Search by name\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                print_library();
                break;
            case 3:
                search_by_name();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}