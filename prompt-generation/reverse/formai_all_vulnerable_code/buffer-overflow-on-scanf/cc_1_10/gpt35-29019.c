//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTIST_NAME 50
#define MAX_ALBUM_TITLE 50
#define MAX_SONG_TITLE 50
#define MAX_SONG_DURATION 10

struct Song {
    char title[MAX_SONG_TITLE];
    char duration[MAX_SONG_DURATION];
    struct Song *next;
};

struct Album {
    char title[MAX_ALBUM_TITLE];
    char artist[MAX_ARTIST_NAME];
    struct Song *songs;
    struct Album *next;
};

struct Artist {
    char name[MAX_ARTIST_NAME];
    struct Album *albums;
    struct Artist *next;
};

struct Artist *artists = NULL;

void add_artist() {
    struct Artist *new_artist = (struct Artist*)malloc(sizeof(struct Artist));
    new_artist->next = NULL;

    printf("Enter artist name: ");
    scanf("%s", new_artist->name);

    if(artists == NULL) {
        artists = new_artist;
    } else {
        struct Artist *current_artist = artists;
        while(current_artist->next != NULL) {
            current_artist = current_artist->next;
        }
        current_artist->next = new_artist;
    }

    printf("Artist '%s' has been added successfully!\n", new_artist->name);
}

void add_album() {
    char artist_name[MAX_ARTIST_NAME];
    printf("Enter artist name for the album: ");
    scanf("%s", artist_name);

    struct Artist *current_artist = artists;
    while(current_artist != NULL) {
        if(strcmp(current_artist->name, artist_name) == 0) {
            struct Album *new_album = (struct Album*)malloc(sizeof(struct Album));
            new_album->next = NULL;
            strncpy(new_album->artist, artist_name, MAX_ARTIST_NAME);

            printf("Enter album title: ");
            scanf("%s", new_album->title);

            if(current_artist->albums == NULL) {
                current_artist->albums = new_album;
            } else {
                struct Album *current_album = current_artist->albums;
                while(current_album->next != NULL) {
                    current_album = current_album->next;
                }
                current_album->next = new_album;
            }

            printf("Album '%s' for artist '%s' has been added successfully!\n", new_album->title, artist_name);
            return;
        }
        current_artist = current_artist->next;
    }

    printf("Artist '%s' does not exist!\n", artist_name);
}

void add_song() {
    char artist_name[MAX_ARTIST_NAME];
    printf("Enter artist name for the song: ");
    scanf("%s", artist_name);

    struct Artist *current_artist = artists;
    while(current_artist != NULL) {
        if(strcmp(current_artist->name, artist_name) == 0) {
            char album_title[MAX_ALBUM_TITLE];
            printf("Enter album title for the song (or enter 'none' if it's a single): ");
            scanf("%s", album_title);

            if(strcmp(album_title, "none") == 0) {
                struct Song *new_song = (struct Song*)malloc(sizeof(struct Song));
                new_song->next = NULL;
                printf("Enter song title: ");
                scanf("%s", new_song->title);
                printf("Enter song duration (in mm:ss format): ");
                scanf("%s", new_song->duration);

                if(current_artist->albums == NULL) {
                    current_artist->albums = (struct Album*)malloc(sizeof(struct Album));
                    current_artist->albums->next = NULL;
                    strncpy(current_artist->albums->title, "<single>", MAX_ALBUM_TITLE);
                    strncpy(current_artist->albums->artist, artist_name, MAX_ARTIST_NAME);
                    current_artist->albums->songs = new_song;
                } else {
                    struct Album *current_album = current_artist->albums;
                    while(current_album->next != NULL) {
                        current_album = current_album->next;
                    }
                    current_album->next = (struct Album*)malloc(sizeof(struct Album));
                    current_album->next->next = NULL;
                    strncpy(current_album->next->title, "<single>", MAX_ALBUM_TITLE);
                    strncpy(current_album->next->artist, artist_name, MAX_ARTIST_NAME);
                    current_album->next->songs = new_song;
                }

                printf("Song '%s' for artist '%s' has been added successfully!\n", new_song->title, artist_name);
                return;
            } else {
                struct Album *current_album = current_artist->albums;
                while(current_album != NULL) {
                    if(strcmp(current_album->title, album_title) == 0) {
                        struct Song *new_song = (struct Song*)malloc(sizeof(struct Song));
                        new_song->next = NULL;
                        printf("Enter song title: ");
                        scanf("%s", new_song->title);
                        printf("Enter song duration (in mm:ss format): ");
                        scanf("%s", new_song->duration);

                        if(current_album->songs == NULL) {
                            current_album->songs = new_song;
                        } else {
                            struct Song *current_song = current_album->songs;
                            while(current_song->next != NULL) {
                                current_song = current_song->next;
                            }
                            current_song->next = new_song;
                        }

                        printf("Song '%s' for album '%s' by '%s' has been added successfully!\n", new_song->title, album_title, artist_name);
                        return;
                    }
                    current_album = current_album->next;
                }
                printf("Album '%s' does not exist for artist '%s'!\n", album_title, artist_name);
                return;
            }
        }
        current_artist = current_artist->next;
    }

    printf("Artist '%s' does not exist!\n", artist_name);
}

void list_artists() {
    if(artists == NULL) {
        printf("No artists found!\n");
        return;
    }

    printf("List of artists:\n");
    struct Artist *current_artist = artists;
    while(current_artist != NULL) {
        printf("%s\n", current_artist->name);
        current_artist = current_artist->next;
    }
}

void list_albums() {
    char artist_name[MAX_ARTIST_NAME];
    printf("Enter artist name: ");
    scanf("%s", artist_name);

    struct Artist *current_artist = artists;
    while(current_artist != NULL) {
        if(strcmp(current_artist->name, artist_name) == 0) {
            if(current_artist->albums == NULL) {
                printf("No albums found for artist '%s'!\n", artist_name);
                return;
            }
            printf("List of albums for artist '%s':\n", artist_name);
            struct Album *current_album = current_artist->albums;
            while(current_album != NULL) {
                printf("%s\n", current_album->title);
                current_album = current_album->next;
            }
            return;
        }
        current_artist = current_artist->next;
    }

    printf("Artist '%s' does not exist!\n", artist_name);
}

void list_songs() {
    char artist_name[MAX_ARTIST_NAME];
    printf("Enter artist name: ");
    scanf("%s", artist_name);

    struct Artist *current_artist = artists;
    while(current_artist != NULL) {
        if(strcmp(current_artist->name, artist_name) == 0) {
            printf("List of songs for artist '%s':\n", artist_name);
            if(current_artist->albums != NULL) {
                struct Album *current_album = current_artist->albums;
                while(current_album != NULL) {
                    printf("%s album:\n", current_album->title);
                    if(current_album->songs != NULL) {
                        struct Song *current_song = current_album->songs;
                        while(current_song != NULL) {
                            printf("\t%s (%s)\n", current_song->title, current_song->duration);
                            current_song = current_song->next;
                        }
                    } else {
                        printf("\tNo songs found for this album!\n");
                    }
                    current_album = current_album->next;
                }
            }
            struct Song *current_song = current_artist->albums->songs;
            while(current_song != NULL) {
                printf("\t%s (%s)\n", current_song->title, current_song->duration);
                current_song = current_song->next;
            }
            return;
        }
        current_artist = current_artist->next;
    }

    printf("Artist '%s' does not exist!\n", artist_name);
}

int main() {
    printf("Welcome to the Music Library Management System!\n");
    printf("1. Add Artist\n");
    printf("2. Add Album\n");
    printf("3. Add Song\n");
    printf("4. List Artists\n");
    printf("5. List Albums\n");
    printf("6. List Songs\n");
    printf("0. Exit\n");
    int option;
    while(1) {
        printf("\nEnter Option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: add_artist(); break;
            case 2: add_album(); break;
            case 3: add_song(); break;
            case 4: list_artists(); break;
            case 5: list_albums(); break;
            case 6: list_songs(); break;
            case 0: exit(0); break;
            default: printf("Invalid option!\n"); break;
        }
    }
    return 0;
}