//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int rating;
};

struct SongCollection {
    struct Song songs[MAX_SONGS];
    int count;
};

void addSong(struct SongCollection *collection, struct Song song) {
    if (collection->count == MAX_SONGS) {
        printf("Error: Maximum number of songs reached.\n");
        return;
    }
    collection->songs[collection->count++] = song;
    printf("Song added successfully.\n");
}

void displaySongs(struct SongCollection *collection) {
    printf("Title\tArtist\tAlbum\tYear\tRating\n");
    for (int i = 0; i < collection->count; i++) {
        printf("%s\t%s\t%s\t%d\t%d\n", collection->songs[i].title, collection->songs[i].artist, collection->songs[i].album, collection->songs[i].year, collection->songs[i].rating);
    }
}

int main() {
    struct SongCollection collection;
    collection.count = 0;

    int choice;
    struct Song song;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song details:\n");
                printf("Title: ");
                scanf("%s", song.title);
                printf("Artist: ");
                scanf("%s", song.artist);
                printf("Album: ");
                scanf("%s", song.album);
                printf("Year: ");
                scanf("%d", &song.year);
                printf("Rating: ");
                scanf("%d", &song.rating);
                addSong(&collection, song);
                break;
            case 2:
                displaySongs(&collection);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}