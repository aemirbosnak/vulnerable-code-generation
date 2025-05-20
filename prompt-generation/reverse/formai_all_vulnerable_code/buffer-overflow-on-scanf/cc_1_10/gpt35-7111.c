//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_ARTISTS 50

struct Album {
    char title[50];
    char artist[30];
    int release_year;
    float rating;
};

struct Artist {
    char name[30];
    struct Album albums[MAX_ALBUMS];
    int num_albums;
};

struct MusicLibrary {
    struct Artist artists[MAX_ARTISTS];
    int num_artists;
};

void add_album(struct Artist *artist, struct Album *album) {
    artist->albums[artist->num_albums] = *album;
    artist->num_albums++;
}

int main() {
    struct MusicLibrary library = {0};
    int option;

    do {
        printf("\n\n-- Music Library Management System --\n");
        printf("\nChoose an option:\n1. Add artist\n2. Add album\n3. Display library\n4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                struct Artist artist = {0};
                printf("\nEnter artist name: ");
                scanf("%s", artist.name);
                library.artists[library.num_artists] = artist;
                library.num_artists++;
                printf("\nArtist added successfully!\n");
                break;
            }

            case 2: {
                char artist_name[30];
                printf("\nEnter artist name: ");
                scanf("%s", artist_name);

                struct Album album = {0};
                printf("\nEnter album title: ");
                scanf("%s", album.title);
                printf("\nEnter release year: ");
                scanf("%d", &album.release_year);
                printf("\nEnter rating (out of 5): ");
                scanf("%f", &album.rating);

                int artist_index = -1;
                for (int i = 0; i < library.num_artists; i++) {
                    if (strcmp(artist_name, library.artists[i].name) == 0) {
                        artist_index = i;
                        break;
                    }
                }

                if (artist_index == -1) {
                    printf("\nArtist not found!\n");
                } else {
                    add_album(&library.artists[artist_index], &album);
                    printf("\nAlbum added successfully!\n");
                }
                break;
            }

            case 3: {
                printf("\n\n-- Music Library --\n");
                for (int i = 0; i < library.num_artists; i++) {
                    printf("\n* %s\n", library.artists[i].name);
                    for (int j = 0; j < library.artists[i].num_albums; j++) {
                        printf("\t- %s (%d), Rating: %.2f\n", library.artists[i].albums[j].title, library.artists[i].albums[j].release_year, library.artists[i].albums[j].rating);
                    }
                }
                break;
            }

            case 4: {
                printf("\nExiting the program...\n");
                break;
            }

            default: {
                printf("\nInvalid option!\n");
                break;
            }
        }
    } while (option != 4);

    return 0;
}