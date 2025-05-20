//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
} Music;

Music musicLibrary[MAX_MUSICS];
int musicCount = 0;

void clearBuffer() {
    while(getchar() != '\n'); // Clear the input buffer
}

void addMusic() {
    if (musicCount >= MAX_MUSICS) {
        printf("Uh-oh! The music library is bulging at the seams! Can't add more music!\n");
        return;
    }

    Music newMusic;
    printf("Time to add some musical genius!\n");

    printf("Enter the title of the song (please, no duplicates of 'This Song' or 'That Song'): ");
    fgets(newMusic.title, sizeof(newMusic.title), stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline

    printf("Now, who is the artist? (No, it can't be 'Anonymous' this time!): ");
    fgets(newMusic.artist, sizeof(newMusic.artist), stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // Remove newline

    printf("What year was this gem released? (please say something after 1900): ");
    scanf("%d", &newMusic.year);
    clearBuffer();

    musicLibrary[musicCount] = newMusic;
    musicCount++;
    printf("Hooray! Added '%s' by '%s' to the library!\n", newMusic.title, newMusic.artist);
}

void viewMusics() {
    if (musicCount == 0) {
        printf("The library is as empty as my fridge... Please add some music!\n");
        return;
    }

    printf("Here's the playlist, folks!\n");
    for (int i = 0; i < musicCount; i++) {
        printf("%d. [%d] \"%s\" by \"%s\"\n", i + 1, musicLibrary[i].year, musicLibrary[i].title, musicLibrary[i].artist);
    }
}

void searchMusic() {
    char searchTitle[MAX_TITLE_LEN];
    printf("Let's find a tune! Enter a part of the title (or all of it, no pressure): ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    printf("Searching for \"%s\"...\n", searchTitle);
    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strstr(musicLibrary[i].title, searchTitle) != NULL) {
            printf("Found! [%d] \"%s\" by \"%s\"\n", musicLibrary[i].year, musicLibrary[i].title, musicLibrary[i].artist);
            found++;
        }
    }

    if (found == 0) {
        printf("Sorry, no hits for \"%s\". Maybe look into gardening instead?\n", searchTitle);
    }
}

void deleteMusic() {
    if (musicCount == 0) {
        printf("There's nothing to delete here! No music means no problems.\n");
        return;
    }

    int choice;
    viewMusics();
    
    printf("Which song would you like to delete? (1 to %d): ", musicCount);
    scanf("%d", &choice);
    clearBuffer();

    if (choice < 1 || choice > musicCount) {
        printf("Oops! Invalid choice, just like asking someone to delete their favorite songs!\n");
        return;
    }

    for (int i = choice - 1; i < musicCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    musicCount--;
    printf("Deleted the music like a bad karaoke night! Farewell!\n");
}

void displayMenu() {
    printf("\n*** Music Library Management System ***\n");
    printf("1. Add Music\n");
    printf("2. View Musics\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer(); // Clearing buffer to prevent input issues

        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                viewMusics();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                printf("Thank you for using the Music Library Management System! Now go enjoy some tunes!\n");
                break;
            default:
                printf("Nope! That's not a valid option, just like expecting a cat to fetch the newspaper!\n");
        }
    } while (choice != 5);

    return 0;
}