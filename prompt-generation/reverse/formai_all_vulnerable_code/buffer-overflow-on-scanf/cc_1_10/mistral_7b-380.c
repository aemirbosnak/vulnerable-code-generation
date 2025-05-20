//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTISTS 100
#define MAX_ALBUMS 50
#define MAX_TRACKS 10
#define MAX_TITLES 50

typedef struct {
    char artist[MAX_ARTISTS];
    char album[MAX_ALBUMS][MAX_ALBUMS];
    int num_tracks;
    struct track {
        char title[MAX_TITLES];
        float length;
    } tracks[MAX_TRACKS];
} library;

void print_library(library *lib) {
    int i, j;
    printf("Artist: %s\n", lib->artist);
    printf("Albums:\n");
    for (i = 0; i < lib->num_tracks; i++) {
        printf("  %s: ", lib->album[i]);
        printf("%s\n", lib->tracks[i].title);
        printf("    Length: %.2f minutes\n", lib->tracks[i].length);
    }
}

void add_track(library *lib, int index, char *title, float length) {
    strcpy(lib->tracks[index].title, title);
    lib->tracks[index].length = length;

    if (lib->num_tracks < MAX_TRACKS) {
        lib->num_tracks++;
    } else {
        printf("Error: Maximum number of tracks reached.\n");
    }
}

int main() {
    library my_library;
    int i;
    char artist[MAX_ARTISTS];
    char title[MAX_TITLES];
    float length;

    printf("Enter artist name: ");
    scanf("%s", artist);
    strcpy(my_library.artist, artist);

    for (i = 0; i < MAX_TRACKS; i++) {
        printf("Enter album name %d: ", i + 1);
        scanf("%s", my_library.album[i]);
        printf("Enter track title %d: ", i + 1);
        scanf("%s", title);
        printf("Enter track length %d (in minutes): ", i + 1);
        scanf("%f", &length);
        add_track(&my_library, i, title, length);
    }

    print_library(&my_library);

    return 0;
}