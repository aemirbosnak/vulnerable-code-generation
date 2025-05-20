//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define ALBUM_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
} Song;

Song library[MAX_SONGS];
int currentSongCount = 0;

void addSong();
void deleteSong();
void viewSongs();
void randomMusicFact();
void displayMenu();

const char* musicFacts[] = {
    "Did you know? The longest recorded song is 'The Rise and Fall of Bossanova'!",
    "Surprise! The first recorded song was 'Mary Had a Little Lamb'!",
    "Whoa! Beethoven was completely deaf when he composed his later works!",
    "What? A day without music is like a day without life!",
    "Amazing! The first music video ever made was for 'Video Killed the Radio Star'!",
    "Mind-blowing! An estimated 75% of all music is never released commercially!",
    "Unbelievable! The word 'music' comes from the Greek word 'mousike'!",
    "Shockingly! Mozart wrote his first piece of music at the age of five!"
};

void addSong() {
    if (currentSongCount >= MAX_SONGS) {
        printf("Library is full! Can't add more songs!\n");
        return;
    }
    Song newSong;
    printf("Enter song title: ");
    scanf(" %[^\n]%*c", newSong.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", newSong.artist);
    printf("Enter album name: ");
    scanf(" %[^\n]%*c", newSong.album);
    
    library[currentSongCount++] = newSong;
    printf("Song added successfully!\n");
    randomMusicFact();
}

void deleteSong() {
    if (currentSongCount == 0) {
        printf("No songs in the library to delete!\n");
        return;
    }
    viewSongs();
    int songIndex;
    printf("Enter the index of the song to delete: ");
    scanf("%d", &songIndex);
    
    if (songIndex < 0 || songIndex >= currentSongCount) {
        printf("Invalid index! Can't delete.\n");
    } else {
        for (int i = songIndex; i < currentSongCount - 1; i++) {
            library[i] = library[i + 1];
        }
        currentSongCount--;
        printf("Song deleted successfully!\n");
        randomMusicFact();
    }
}

void viewSongs() {
    if (currentSongCount == 0) {
        printf("No songs in the library!\n");
        return;
    }
    printf("Songs in the Library:\n");
    for (int i = 0; i < currentSongCount; i++) {
        printf("%d. %s by %s (Album: %s)\n", i, library[i].title, library[i].artist, library[i].album);
    }
    randomMusicFact();
}

void randomMusicFact() {
    srand(time(0));
    int randomIndex = rand() % (sizeof(musicFacts) / sizeof(musicFacts[0]));
    printf("%s\n", musicFacts[randomIndex]);
}

void displayMenu() {
    int choice;
    do {
        printf("\n=== Music Library Management System ===\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. View Songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3:
                viewSongs();
                break;
            case 4:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    displayMenu();
    return 0;
}