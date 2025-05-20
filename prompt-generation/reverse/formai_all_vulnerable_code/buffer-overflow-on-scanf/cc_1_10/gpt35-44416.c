//FormAI DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct artist {
    char name[50];
    int id;
};

struct album {
    char title[50];
    char artist[50];
    int id;
};

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int id;
};

// function prototypes
void add_artist();
void add_album();
void add_song();
void list_artists();
void list_albums(char *artist_name);
void list_songs(char *album_title);

// global variables
struct artist artists[100];
int num_artists = 0;
struct album albums[500];
int num_albums = 0;
struct song songs[5000];
int num_songs = 0;

int main() {
    int choice;
    do {
        printf("Music Library Management System\n");
        printf("1. Add Artist\n");
        printf("2. Add Album\n");
        printf("3. Add Song\n");
        printf("4. List Artists\n");
        printf("5. List Albums\n");
        printf("6. List Songs\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_artist();
                break;
            case 2:
                add_album();
                break;
            case 3:
                add_song();
                break;
            case 4:
                list_artists();
                break;
            case 5:
                {
                    char artist_name[50];
                    printf("Enter artist name: ");
                    scanf("%s", artist_name);
                    list_albums(artist_name);
                }
                break;
            case 6:
                {
                    char album_title[50];
                    printf("Enter album title: ");
                    scanf("%s", album_title);
                    list_songs(album_title);
                }
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}

void add_artist() {
    printf("Enter artist name: ");
    scanf("%s", artists[num_artists].name);
    artists[num_artists].id = num_artists;
    num_artists++;
    printf("Artist added successfully!\n");
}

void add_album() {
    char artist_name[50];
    printf("Enter artist name: ");
    scanf("%s", artist_name);
    int found = 0;
    int artist_id = -1;
    for (int i = 0; i < num_artists; i++) {
        if (strcmp(artists[i].name, artist_name) == 0) {
            found = 1;
            artist_id = i;
            break;
        }
    }
    if (!found) {
        printf("Artist not found!\n");
        return;
    }
    printf("Enter album title: ");
    scanf("%s", albums[num_albums].title);
    strcpy(albums[num_albums].artist, artist_name);
    albums[num_albums].id = num_albums;
    num_albums++;
    printf("Album added successfully!\n");
}

void add_song() {
    char album_title[50];
    printf("Enter album title: ");
    scanf("%s", album_title);
    int found = 0;
    int album_id = -1;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(albums[i].title, album_title) == 0) {
            found = 1;
            album_id = i;
            break;
        }
    }
    if (!found) {
        printf("Album not found!\n");
        return;
    }
    char artist_name[50];
    strcpy(artist_name, albums[album_id].artist);
    strcpy(songs[num_songs].album, album_title);
    strcpy(songs[num_songs].artist, artist_name);
    printf("Enter song title: ");
    scanf("%s", songs[num_songs].title);
    songs[num_songs].id = num_songs;
    num_songs++;
    printf("Song added successfully!\n");
}

void list_artists() {
    printf("Artists:\n");
    for (int i = 0; i < num_artists; i++) {
        printf("%d. %s\n", artists[i].id, artists[i].name);
    }
}

void list_albums(char *artist_name) {
    printf("Albums by %s:\n", artist_name);
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(albums[i].artist, artist_name) == 0) {
            printf("%d. %s\n", albums[i].id, albums[i].title);
        }
    }
}

void list_songs(char *album_title) {
    printf("Songs in %s:\n", album_title);
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].album, album_title) == 0) {
            printf("%d. %s by %s\n", songs[i].id, songs[i].title, songs[i].artist);
        }
    }
}