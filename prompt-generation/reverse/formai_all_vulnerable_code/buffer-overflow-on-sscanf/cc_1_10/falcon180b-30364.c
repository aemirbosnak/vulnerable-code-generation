//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 100

typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int duration;
} music_track;

int read_tracks(music_track *tracks) {
    FILE *fp;
    char line[200];
    int count = 0;

    fp = fopen("tracks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_TITLES) {
            printf("Maximum number of tracks reached.\n");
            break;
        }
        sscanf(line, "%s %s %s %d %d", tracks[count].title, tracks[count].artist, tracks[count].album, &tracks[count].year, &tracks[count].duration);
        count++;
    }

    fclose(fp);
    return count;
}

void display_tracks(music_track *tracks, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%s - %s (%d)\n", tracks[i].artist, tracks[i].title, tracks[i].year);
        printf("Album: %s\n", tracks[i].album);
        printf("Duration: %d seconds\n\n", tracks[i].duration);
    }
}

int main() {
    music_track tracks[MAX_TITLES];
    int count;

    count = read_tracks(tracks);
    display_tracks(tracks, count);

    return 0;
}