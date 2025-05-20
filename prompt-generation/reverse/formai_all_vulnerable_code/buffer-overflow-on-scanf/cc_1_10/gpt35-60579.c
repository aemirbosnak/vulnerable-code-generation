//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

int main() {
    int i, n;
    printf("Enter the number of songs to add to the library: ");
    scanf("%d", &n);

    struct Song library[n];

    for(i = 0; i < n; i++) {
        printf("\nEnter the details of song %d:\n", i+1);
        printf("Title: ");
        scanf("%s", library[i].title);
        printf("Artist: ");
        scanf("%s", library[i].artist);
        printf("Album: ");
        scanf("%s", library[i].album);
        printf("Year: ");
        scanf("%d", &library[i].year);
    }

    printf("\n-----Library-----\n");
    printf("Title\tArtist\tAlbum\tYear\n");

    for(i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    // Sorting songs by year
    struct Song tempSong;
    for(i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(library[i].year > library[j].year) {
                tempSong = library[i];
                library[i] = library[j];
                library[j] = tempSong;
            }
        }
    }

    printf("\n-----Sorted By Year-----\n");
    printf("Title\tArtist\tAlbum\tYear\n");

    for(i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    return 0;
}