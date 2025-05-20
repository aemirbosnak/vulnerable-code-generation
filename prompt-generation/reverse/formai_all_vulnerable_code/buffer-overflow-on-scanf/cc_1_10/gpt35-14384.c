//FormAI DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 50
#define MAX_ARTIST_LEN 30
#define MAX_ALBUM_LEN 30
#define MAX_TRACKS 20

struct Song {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    int trackNumber;
};

struct SongCollection {
    struct Song songs[MAX_TRACKS];
    int numSongs;
};

void addSongToCollection(struct SongCollection* collection, struct Song song) {
    if (collection->numSongs < MAX_TRACKS) {
        collection->songs[collection->numSongs] = song;
        collection->numSongs++;
        printf("Song Added!\n");
    }
    else {
        printf("Collection is full!\n");
    }
}

void displayCollection(struct SongCollection collection) {
    printf("Song Collection:\n");
    for (int i = 0; i < collection.numSongs; i++) {
        printf("Title: %s, Artist: %s, Album: %s, Track Number: %d\n", 
            collection.songs[i].title, collection.songs[i].artist, 
            collection.songs[i].album, collection.songs[i].trackNumber);
    }
}

int main() {
    struct SongCollection myCollection = {0};
    int choice = 0;
    struct Song currentSong;
    
    do {
        printf("\nMusic Library Management System\n");
        printf("1 - Add Song to Collection\n");
        printf("2 - Display Collection\n");
        printf("3 - Quit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the song title: ");
                scanf("%s", currentSong.title);
                printf("Enter the artist name: ");
                scanf("%s", currentSong.artist);
                printf("Enter the album name: ");
                scanf("%s", currentSong.album);
                printf("Enter the track number: ");
                scanf("%d", &currentSong.trackNumber);
                addSongToCollection(&myCollection, currentSong);
                break;
            case 2:
                displayCollection(myCollection);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}