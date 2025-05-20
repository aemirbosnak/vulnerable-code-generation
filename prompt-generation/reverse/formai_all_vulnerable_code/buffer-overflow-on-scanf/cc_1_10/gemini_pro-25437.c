//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: cheerful
// Let's dance with data and twirl with indexes! 🩰💃🕺
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a database of cheerful tunes with some groovy fields 🎵🎶
typedef struct Song {
    char name[100]; // The tune's title, where melody flows
    char artist[100]; // The artist behind the musical show
    int year; // When the song graced the world with its presence
    char genre[50]; // The musical category where the song finds its essence
} Song;

// And now, our very own database filled with musical treasures! 💿✨
Song songs[] = {
    {"Happy", "Pharrell Williams", 2013, "Pop"},
    {"Don't Stop Believin'", "Journey", 1981, "Rock"},
    {"I Will Survive", "Gloria Gaynor", 1978, "Disco"},
    {"Dancing Queen", "ABBA", 1976, "Pop"},
    {"Bohemian Rhapsody", "Queen", 1975, "Rock"},
    {"Imagine", "John Lennon", 1971, "Rock"},
    {"Strawberry Fields Forever", "The Beatles", 1967, "Rock"},
    {"What a Wonderful World", "Louis Armstrong", 1967, "Jazz"},
    {"My Heart Will Go On", "Celine Dion", 1997, "Pop"},
    {"Billie Jean", "Michael Jackson", 1982, "Pop"},
};

// Let's create an index for quick song lookups by name 🔍
typedef struct NameIndex {
    char name[100];
    int songIndex;
} NameIndex;

// Time to build our index, making song retrieval a breeze! 索引
NameIndex nameIndex[10];

void buildNameIndex() {
    for (int i = 0; i < 10; i++) {
        strcpy(nameIndex[i].name, songs[i].name);
        nameIndex[i].songIndex = i;
    }
}

// Ready to find songs by name in the blink of a musical eye! 👀
int findSongByName(char *name) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(nameIndex[i].name, name) == 0) {
            return nameIndex[i].songIndex;
        }
    }
    return -1;
}

int main() {
    // Let's get our index ready for the dance party! 💃🕺
    buildNameIndex();

    // Showcase time! Let's search for a song by name, shall we? 🔍
    char searchName[100];
    printf("Enter the name of the song you seek, music lover: ");
    scanf("%s", searchName);

    // Presto! We've found the song's index through our nifty index! 🪄
    int songIndex = findSongByName(searchName);

    // Time to unveil the musical gem! 🎶💎
    if (songIndex >= 0) {
        printf("Your musical treasure: %s\n", songs[songIndex].name);
        printf("Artist: %s\n", songs[songIndex].artist);
        printf("Year of release: %d\n", songs[songIndex].year);
        printf("Genre: %s\n", songs[songIndex].genre);
    } else {
        printf("Oops! Seems like that song is hiding in another playlist. Try again?");
    }

    return 0;
}