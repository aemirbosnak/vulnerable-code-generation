//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char title[100];
    char artist[100];
    int year;
    int trackCount;
    int* tracks;
};

int main() {
    struct Album* albums = NULL;
    int numAlbums = 0;
    int numTracks = 0;
    int trackCount = 0;
    int trackIndex = 0;

    printf("Enter the number of albums: ");
    scanf("%d", &numAlbums);

    albums = (struct Album*) malloc(numAlbums * sizeof(struct Album));

    printf("Enter the details of each album:\n");
    for (int i = 0; i < numAlbums; i++) {
        printf("Album %d:\n", i + 1);
        fflush(stdout);

        scanf("%s %s %d", albums[i].title, albums[i].artist, &albums[i].year);
        fflush(stdin);

        printf("Enter the track count for album %s by %s (year %d): ", albums[i].title, albums[i].artist, albums[i].year);
        scanf("%d", &albums[i].trackCount);

        if (albums[i].trackCount > 0) {
            albums[i].tracks = (int*) malloc(albums[i].trackCount * sizeof(int));

            printf("Enter the track details for album %s by %s (year %d):\n", albums[i].title, albums[i].artist, albums[i].year);
            for (int j = 0; j < albums[i].trackCount; j++) {
                scanf("%d", &albums[i].tracks[j]);
                fflush(stdin);
            }
        }
    }

    printf("Albums:\n");
    for (int i = 0; i < numAlbums; i++) {
        printf("%s by %s (year %d):\n", albums[i].title, albums[i].artist, albums[i].year);
        for (int j = 0; j < albums[i].trackCount; j++) {
            printf("- %d\n", albums[i].tracks[j]);
        }
    }

    return 0;
}