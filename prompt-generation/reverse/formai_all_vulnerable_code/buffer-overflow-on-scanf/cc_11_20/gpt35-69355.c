//FormAI DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[100];
    char artist[100];
    int year;
    char album[100];
};

int main() {
    struct song songs[100];
    int num_songs = 0;

    int choice = 0;

    while (1) {
        printf("Welcome to the Music Library Management System!\n");
        printf("Enter the number of the action you would like to perform:\n");
        printf("1. Add a song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the song title: ");
                scanf("%s", songs[num_songs].title);
                printf("Enter the artist: ");
                scanf("%s", songs[num_songs].artist);
                printf("Enter the year: ");
                scanf("%d", &songs[num_songs].year);
                printf("Enter the album: ");
                scanf("%s", songs[num_songs].album);
                num_songs++;
                printf("Song added successfully!\n");
                break;
            case 2:
                if (num_songs == 0) {
                    printf("No songs in the library.\n");
                } else {
                    printf("%-30s %-30s %-10s %-30s\n", "Title", "Artist", "Year", "Album");
                    printf("------------------------------------------------------------------\n");
                    for (int i = 0; i < num_songs; i++) {
                        printf("%-30s %-30s %-10d %-30s\n", songs[i].title, songs[i].artist, songs[i].year, songs[i].album);
                    }
                }
                break;
            case 3:
                if (num_songs == 0) {
                    printf("No songs in the library.\n");
                } else {
                    char search_term[100];
                    printf("Enter the song title or artist to search for: ");
                    scanf("%s", search_term);
                    printf("%-30s %-30s %-10s %-30s\n", "Title", "Artist", "Year", "Album");
                    printf("------------------------------------------------------------------\n");
                    for (int i = 0; i < num_songs; i++) {
                        if (strcmp(songs[i].title, search_term) == 0 || strcmp(songs[i].artist, search_term) == 0) {
                            printf("%-30s %-30s %-10d %-30s\n", songs[i].title, songs[i].artist, songs[i].year, songs[i].album);
                        }
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}