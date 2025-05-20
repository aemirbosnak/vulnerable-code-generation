//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 50
#define MAX_ARTIST 50

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    float duration;
    int year;
} MusicRecord;

typedef struct {
    MusicRecord collection[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
    printf("The library's shadows have awakened, ready to dance.\n");
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("The library has succumbed to the weight of time, unable to hold more music.\n");
        return;
    }

    MusicRecord newMusic;

    printf("Inhale the essence of a title: ");
    scanf(" %[^\n]s", newMusic.title);
    printf("Summon the artist’s spirit: ");
    scanf(" %[^\n]s", newMusic.artist);
    printf("Weigh the song's duration in minutes: ");
    scanf("%f", &newMusic.duration);
    printf("What year did the melody arrive? ");
    scanf("%d", &newMusic.year);

    library->collection[library->count] = newMusic;
    library->count++;
    
    printf("A new tune has slipped through the cracks of reality, added to the library.\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The library is a barren desert, void of any musical oasis.\n");
        return;
    }

    printf("\nIn the theater of the mind, behold the music collection:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s | Artist: %s | Duration: %.2f mins | Year: %d\n",
               i + 1, library->collection[i].title, library->collection[i].artist,
               library->collection[i].duration, library->collection[i].year);
    }
}

void searchMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("Whispers in the void reveal that no music resides here.\n");
        return;
    }
    
    char searchTitle[MAX_TITLE];
    printf("Enter the title floating in your dreams: ");
    scanf(" %[^\n]s", searchTitle);

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->collection[i].title, searchTitle) == 0) {
            printf("Found a shimmering gem: Title: %s | Artist: %s | Duration: %.2f mins | Year: %d\n",
                   library->collection[i].title, library->collection[i].artist,
                   library->collection[i].duration, library->collection[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("The echo of your search fades away, for no music appears.\n");
    }
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("With hollow whispers, the library reveals it has nothing left to give.\n");
        return;
    }

    int index;
    printf("Which number would you let fall into the abyss? (1 to %d): ", library->count);
    scanf("%d", &index);
    
    if (index < 1 || index > library->count) {
        printf("The spectral hand falters, unable to grasp the right tune.\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;
    
    printf("One melody has been unmade, fading into the vast unknown.\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;
    do {
        printf("\nChoose your adventure:\n");
        printf("1. Add music\n2. Display music\n3. Search music\n4. Delete music\n5. Evoke the void\n");
        printf("Your decision echoes: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addMusic(&library); break;
            case 2: displayMusic(&library); break;
            case 3: searchMusic(&library); break;
            case 4: deleteMusic(&library); break;
            case 5: printf("The void means to silence. Ending journey.\n"); break;
            default: printf("An inexplicable choice has been made, try again.\n");
        }
    } while (choice != 5);
    
    printf("You have danced with the echoes of music; farewell.\n");
    return 0;
}