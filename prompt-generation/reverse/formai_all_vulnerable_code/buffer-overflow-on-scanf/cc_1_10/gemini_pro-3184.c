//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: futuristic
// Welcome to the Zenith Music Library, Traveler!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our collection of celestial melodies
typedef struct Music {
    int id;
    char *title;
    char *artist;
    char *album;
    char *genre;
    int year;
} Music;

// The vault where our music resides
Music *library;
int librarySize = 0;

// Command control center
void commandCenter() {
    char command[100];
    int id;
    char *title;
    char *artist;
    char *album;
    char *genre;
    int year;

    printf("\n*** Zenith Music Library ***\n");
    while (1) {
        printf("\nCommand> ");
        scanf("%s", command);

        // Summon a new melody
        if (strcmp(command, "add") == 0) {
            printf("Title: ");
            scanf(" %[^\n]%*c", title);
            printf("Artist: ");
            scanf(" %[^\n]%*c", artist);
            printf("Album: ");
            scanf(" %[^\n]%*c", album);
            printf("Genre: ");
            scanf(" %[^\n]%*c", genre);
            printf("Year: ");
            scanf("%d", &year);

            Music *newMusic = (Music*)malloc(sizeof(Music));
            newMusic->id = librarySize++;
            newMusic->title = title;
            newMusic->artist = artist;
            newMusic->album = album;
            newMusic->genre = genre;
            newMusic->year = year;

            library = (Music*)realloc(library, librarySize * sizeof(Music));
            library[librarySize - 1] = *newMusic;

            printf("Music added!\n");
        }

        // Play a symphony by its ID
        else if (strcmp(command, "play") == 0) {
            printf("ID: ");
            scanf("%d", &id);

            if (id >= 0 && id < librarySize) {
                Music m = library[id];
                printf("Now playing: %s - %s\n", m.title, m.artist);
            } else {
                printf("Melody not found!\n");
            }
        }

        // Discover music by genre
        else if (strcmp(command, "genre") == 0) {
            printf("Genre: ");
            scanf(" %[^\n]%*c", genre);

            int count = 0;
            for (int i = 0; i < librarySize; i++) {
                Music m = library[i];
                if (strcmp(m.genre, genre) == 0) {
                    printf("%s - %s\n", m.title, m.artist);
                    count++;
                }
            }

            if (count == 0) {
                printf("No songs found in that genre!\n");
            }
        }

        // Farewell, traveler
        else if (strcmp(command, "quit") == 0) {
            printf("May your journey be filled with cosmic melodies!\n");
            break;
        }

        // Unknown command
        else {
            printf("Command not recognized!\n");
        }
    }
}

// Orchestrate the celestial symphony
int main() {
    library = (Music*)malloc(0);

    // Command Center is now operational
    commandCenter();

    // Farewell, traveler
    free(library);
    return 0;
}