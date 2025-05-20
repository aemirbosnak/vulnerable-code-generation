//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SONGS 1000
#define MAX_ARTISTS 1000
#define MAX_ALBUMS 1000
#define MAX_PLAYLISTS 1000
#define MAX_PLAYLIST_SONGS 1000

typedef struct {
    char name[MAX_WORDS];
    int genre;
} Song;

typedef struct {
    char name[MAX_WORDS];
    int num_songs;
    Song *songs;
} Album;

typedef struct {
    char name[MAX_WORDS];
    int num_albums;
    Album *albums;
} Artist;

typedef struct {
    char name[MAX_WORDS];
    int num_songs;
    Song *songs;
} Playlist;

typedef struct {
    char name[MAX_WORDS];
    int num_playlists;
    Playlist *playlists;
} User;

char *trim(char *str) {
    char *end;
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
        *end = '\0';
    }
    return str;
}

int main() {
    User user;
    user.num_playlists = 0;
    user.playlists = NULL;

    while (1) {
        printf("User Management System\n");
        printf("1. Add User\n");
        printf("2. View User\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter User Name: ");
                scanf("%s", user.name);
                user.num_playlists = 0;
                user.playlists = NULL;
                printf("User added successfully!\n");
                break;

            case 2:
                printf("User Name: %s\n", user.name);
                printf("Number of Playlists: %d\n", user.num_playlists);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}