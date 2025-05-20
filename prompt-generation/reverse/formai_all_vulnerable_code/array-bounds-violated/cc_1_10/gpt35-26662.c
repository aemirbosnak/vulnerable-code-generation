//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
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
    int num_songs;
    printf("Welcome to your Music Library Management System!\n\n");
    printf("How many songs do you want to add to your library? ");
    scanf("%d", &num_songs);

    struct Song library[num_songs];
    for (int i = 0; i < num_songs; i++) {
        printf("\nEnter details for song %d:\n", i+1);
        printf("Title: ");
        fflush(stdin);
        fgets(library[i].title, 100, stdin);
        library[i].title[strlen(library[i].title)-1] = '\0';

        printf("Artist: ");
        fflush(stdin);
        fgets(library[i].artist, 100, stdin);
        library[i].artist[strlen(library[i].artist)-1] = '\0';

        printf("Album: ");
        fflush(stdin);
        fgets(library[i].album, 100, stdin);
        library[i].album[strlen(library[i].album)-1] = '\0';

        printf("Year: ");
        scanf("%d", &library[i].year);
        printf("\nSong added successfully!\n");
    }

    printf("\nYour Music Library:\n");
    printf("+-----------------------------------------------+\n");
    printf("| Title\t\tArtist\t\tAlbum\t\tYear\t|\n");
    printf("+-----------------------------------------------+\n");
    for (int i = 0; i < num_songs; i++) {
        printf("| %-15s %-15s %-15s %d\t|\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
    printf("+-----------------------------------------------+\n");

    return 0;
}