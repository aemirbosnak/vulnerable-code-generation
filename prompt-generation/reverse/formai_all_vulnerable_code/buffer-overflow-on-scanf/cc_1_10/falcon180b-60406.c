//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 50
#define MAX_GENRE_LEN 20
#define MAX_YEAR_LEN 4

typedef struct song {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    char year[MAX_YEAR_LEN];
} Song;

Song library[MAX_SONGS];
int num_songs;

void add_song() {
    printf("Enter song name: ");
    scanf("%s", library[num_songs].name);
    printf("Enter artist name: ");
    scanf("%s", library[num_songs].artist);
    printf("Enter album name: ");
    scanf("%s", library[num_songs].album);
    printf("Enter genre: ");
    scanf("%s", library[num_songs].genre);
    printf("Enter year: ");
    scanf("%s", library[num_songs].year);
    num_songs++;
}

void search_song_by_name() {
    char search_name[MAX_NAME_LEN];
    printf("Enter song name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].name, search_name) == 0) {
            printf("Song found:\n");
            printf("Name: %s\n", library[i].name);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Genre: %s\n", library[i].genre);
            printf("Year: %s\n", library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found.\n");
    }
}

void display_library() {
    printf("Library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("Song %d:\n", i+1);
        printf("Name: %s\n", library[i].name);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Genre: %s\n", library[i].genre);
        printf("Year: %s\n", library[i].year);
        printf("\n");
    }
}

int main() {
    num_songs = 0;
    printf("Welcome to the Music Library Management System!\n");
    while (1) {
        printf("\n");
        printf("1. Add song\n");
        printf("2. Search song by name\n");
        printf("3. Display library\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song_by_name();
                break;
            case 3:
                display_library();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}