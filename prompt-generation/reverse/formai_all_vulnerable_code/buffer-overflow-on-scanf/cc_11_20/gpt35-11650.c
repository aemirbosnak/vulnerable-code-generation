//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>

typedef struct songInfo { // Song information structure
    char songTitle[100];
    char artist[100];
    char album[100];
    int releaseYear;
    float duration;
} songInfo;

int main() {

    int numSongs = 0; // Counter for the number of songs in the library
    songInfo library[100]; // Array to hold song information

    while (1) {

        printf("1 - Add Song\n");
        printf("2 - Remove Song\n");
        printf("3 - List Songs\n");
        printf("4 - Quit\n\n");

        int option;

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {

            case 1:
                printf("Enter the song title: ");
                scanf("%s", library[numSongs].songTitle);

                printf("Enter the artist name: ");
                scanf("%s", library[numSongs].artist);

                printf("Enter the album name: ");
                scanf("%s", library[numSongs].album);

                printf("Enter the release year: ");
                scanf("%d", &library[numSongs].releaseYear);

                printf("Enter the duration of the song (in seconds): ");
                scanf("%f", &library[numSongs].duration);

                numSongs++;
                printf("Song added successfully!\n\n");
                break;

            case 2:
                if (numSongs == 0) { // No songs in the library
                    printf("Library is empty\n\n");
                }
                else {
                    int removeSongIndex;

                    printf("Enter the index of the song to remove: ");
                    scanf("%d", &removeSongIndex);

                    if (removeSongIndex >= numSongs || removeSongIndex < 0) { // Invalid index
                        printf("Invalid index\n\n");
                    }
                    else {
                        for (int i = removeSongIndex; i < numSongs - 1; i++) { // Shift all elements after the removed song to fill the gap
                            library[i] = library[i+1];
                        }
                        numSongs--;
                        printf("Song removed successfully!\n\n");
                    }
                }
                break;

            case 3:
                if (numSongs == 0) { // No songs in the library
                    printf("Library is empty\n\n");
                }
                else {
                    printf("%-30s %-30s %-30s %-10s %-10s\n", "Title", "Artist", "Album", "Year", "Duration"); // Print table header
                    printf("============================================================================\n"); // Print separator line

                    for (int i = 0; i < numSongs; i++) { // Loop through all songs in the library and print their information in a table format
                        printf("%-30s %-30s %-30s %-10d %-10.2fs\n", library[i].songTitle, library[i].artist, library[i].album, library[i].releaseYear, library[i].duration);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid option\n\n");
        }
    }

    return 0;
}