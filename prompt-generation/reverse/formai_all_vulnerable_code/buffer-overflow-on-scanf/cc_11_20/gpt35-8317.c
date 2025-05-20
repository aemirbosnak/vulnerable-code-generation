//FormAI DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

int main() {
    int option, num_songs = 0;
    struct song library[100];
    char input[50];

    printf("Welcome to the C Music Library Management System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. View all songs\n");
        printf("4. Search for a song\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &option);

        if (option == 1) {
            printf("\nEnter the song title: ");
            scanf("%s", input);
            strcpy(library[num_songs].title, input);
            printf("Enter the artist name: ");
            scanf("%s", input);
            strcpy(library[num_songs].artist, input);
            printf("Enter the album name: ");
            scanf("%s", input);
            strcpy(library[num_songs].album, input);
            printf("Enter the year of release: ");
            scanf("%d", &library[num_songs].year);
            num_songs++;
            printf("\nSong added successfully!\n");
        } else if (option == 2) {
            printf("\nEnter the title of the song to remove: ");
            scanf("%s", input);
            int i, found = 0;
            for (i = 0; i < num_songs; i++) {
                if (strcmp(library[i].title, input) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                for (int j = i; j < num_songs; j++) {
                    library[j] = library[j+1];
                }
                num_songs--;
                printf("\nSong removed successfully!\n");
            } else {
                printf("\nSong not found in the library!\n");
            }
        } else if (option == 3) {
            printf("\nAll songs:\n");
            if (num_songs == 0) {
                printf("No songs in the library yet!\n");
            } else {
                for (int i = 0; i < num_songs; i++) {
                    printf("%d. %s by %s from the album %s (%d)\n",
                            i+1, library[i].title, library[i].artist,
                            library[i].album, library[i].year);
                }
            }
        } else if (option == 4) {
            printf("\nEnter a keyword to search for: ");
            scanf("%s", input);
            printf("\nSearch results:\n");
            int found = 0;
            for (int i = 0; i < num_songs; i++) {
                if (strstr(library[i].title, input) != NULL ||
                        strstr(library[i].artist, input) != NULL ||
                        strstr(library[i].album, input) != NULL) {
                    printf("%d. %s by %s from the album %s (%d)\n",
                            i+1, library[i].title, library[i].artist,
                            library[i].album, library[i].year);
                    found = 1;
                }
            }
            if (!found) {
                printf("No matching songs found!\n");
            }
        } else if (option == 5) {
            printf("\nExiting C Music Library Management System...\n");
            break;
        } else {
            printf("\nInvalid option selected!\n");
        }
    }

    return 0;
}