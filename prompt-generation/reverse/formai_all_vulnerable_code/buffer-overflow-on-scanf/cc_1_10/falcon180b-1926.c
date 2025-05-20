//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONG_COUNT 1000
#define MAX_SONG_NAME_LENGTH 100
#define MAX_ARTIST_NAME_LENGTH 100
#define MAX_ALBUM_NAME_LENGTH 100
#define MAX_GENRE_NAME_LENGTH 50

typedef struct {
    char song_name[MAX_SONG_NAME_LENGTH];
    char artist_name[MAX_ARTIST_NAME_LENGTH];
    char album_name[MAX_ALBUM_NAME_LENGTH];
    char genre_name[MAX_GENRE_NAME_LENGTH];
} Song;

Song songs[MAX_SONG_COUNT];
int song_count = 0;

void add_song() {
    char song_name[MAX_SONG_NAME_LENGTH];
    char artist_name[MAX_ARTIST_NAME_LENGTH];
    char album_name[MAX_ALBUM_NAME_LENGTH];
    char genre_name[MAX_GENRE_NAME_LENGTH];

    printf("Enter song name: ");
    scanf("%s", song_name);
    printf("Enter artist name: ");
    scanf("%s", artist_name);
    printf("Enter album name: ");
    scanf("%s", album_name);
    printf("Enter genre name: ");
    scanf("%s", genre_name);

    strcpy(songs[song_count].song_name, song_name);
    strcpy(songs[song_count].artist_name, artist_name);
    strcpy(songs[song_count].album_name, album_name);
    strcpy(songs[song_count].genre_name, genre_name);

    song_count++;
    printf("Song added successfully!\n");
}

void search_song() {
    char search_name[MAX_SONG_NAME_LENGTH];

    printf("Enter song name to search: ");
    scanf("%s", search_name);

    int i;
    for(i = 0; i < song_count; i++) {
        if(strcmp(songs[i].song_name, search_name) == 0) {
            printf("Song found!\n");
            printf("Song name: %s\n", songs[i].song_name);
            printf("Artist name: %s\n", songs[i].artist_name);
            printf("Album name: %s\n", songs[i].album_name);
            printf("Genre name: %s\n", songs[i].genre_name);
        }
    }
}

void delete_song() {
    int song_index;

    printf("Enter song index to delete: ");
    scanf("%d", &song_index);

    if(song_index >= 0 && song_index < song_count) {
        song_count--;
        printf("Song deleted successfully!\n");
    } else {
        printf("Invalid song index.\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add song\n");
        printf("2. Search song\n");
        printf("3. Delete song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                delete_song();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}