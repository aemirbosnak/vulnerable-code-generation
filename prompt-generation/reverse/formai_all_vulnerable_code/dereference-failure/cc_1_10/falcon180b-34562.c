//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 50

// Song structure
typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    int year;
    int duration;
} Song;

// Library structure
typedef struct {
    Song songs[MAX_SONGS];
    int numSongs;
} Library;

// Function prototypes
Library* libraryCreate();
void libraryAddSong(Library* lib, Song* song);
void libraryPrint(Library* lib);
void libraryFree(Library* lib);

// Main function
int main() {
    Library* lib = libraryCreate();
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 240};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 420};
    Song song3 = {"Wonderwall", "Oasis", "What's the Story Morning Glory?", 1995, 270};
    libraryAddSong(lib, &song1);
    libraryAddSong(lib, &song2);
    libraryAddSong(lib, &song3);
    libraryPrint(lib);
    libraryFree(lib);
    return 0;
}

// Library creation
Library* libraryCreate() {
    Library* lib = (Library*) malloc(sizeof(Library));
    memset(lib->songs, 0, sizeof(Song) * MAX_SONGS);
    lib->numSongs = 0;
    return lib;
}

// Song addition
void libraryAddSong(Library* lib, Song* song) {
    if (lib->numSongs >= MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }
    for (int i = 0; i < lib->numSongs; i++) {
        if (strcmp(lib->songs[i].title, song->title) == 0) {
            printf("Song already exists.\n");
            return;
        }
    }
    memcpy(&lib->songs[lib->numSongs], song, sizeof(Song));
    lib->numSongs++;
}

// Library printing
void libraryPrint(Library* lib) {
    printf("Library:\n");
    printf("---------\n");
    for (int i = 0; i < lib->numSongs; i++) {
        printf("%d. %s - %s (%s) [Duration: %d]\n", i+1, lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].duration);
    }
    printf("\n");
}

// Library freeing
void libraryFree(Library* lib) {
    free(lib);
}