//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char artist[50];
    char album[50];
    char song[50];
} song_t;

int main() {
    printf("Welcome to the C Music Library Management System!\n\n");

    // Initialize array of songs
    song_t library[100];
    int num_songs = 0;

    // Main menu
    int choice = 0;
    while (choice != 4) {
        printf("What would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. View library\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_songs >= 100) {
                    printf("Sorry, the library is full!\n");
                } else {
                    printf("Enter the artist name: ");
                    scanf("%s", library[num_songs].artist);
                    printf("Enter the album name: ");
                    scanf("%s", library[num_songs].album);
                    printf("Enter the song name: ");
                    scanf("%s", library[num_songs].song);
                    printf("Song added!\n");
                    num_songs++;
                }
                break;

            case 2:
                if (num_songs == 0) {
                    printf("Sorry, the library is empty!\n");
                } else {
                    printf("Enter the song name: ");
                    char song_name[50];
                    scanf("%s", song_name);

                    int found = 0;
                    for (int i = 0; i < num_songs; i++) {
                        if (strcmp(library[i].song, song_name) == 0) {
                            found = 1;
                            for (int j = i; j < num_songs - 1; j++) {
                                strcpy(library[j].artist, library[j+1].artist);
                                strcpy(library[j].album, library[j+1].album);
                                strcpy(library[j].song, library[j+1].song);
                            }
                            num_songs--;
                            printf("Song removed!\n");
                            break;
                        }
                    }

                    if (found == 0) {
                        printf("Sorry, the song was not found in the library!\n");
                    }
                }
                break;

            case 3:
                if (num_songs == 0) {
                    printf("The library is empty!\n");
                } else {
                    printf("Library:\n");
                    for (int i = 0; i < num_songs; i++) {
                        printf("%d. %s - %s - %s\n", i+1, library[i].artist,
                               library[i].album, library[i].song);
                    }
                }
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    }

    return 0;
}