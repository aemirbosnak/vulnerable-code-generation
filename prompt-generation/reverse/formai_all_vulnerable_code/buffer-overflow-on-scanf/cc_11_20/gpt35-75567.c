//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct song {
    char title[50];
    char artist[50];
    int duration; // in seconds
    bool is_favourite;
} Song;

int main() {
    Song library[100];
    int num_songs = 0;
    char menu_choice;

    while (true) {
        printf("\nWelcome to the Music Library Management System!\n");
        printf("1. Add a song\n");
        printf("2. Print library\n");
        printf("3. Toggle favourite\n");
        printf("4. Search by artist\n");
        printf("5. Quit\n");

        scanf(" %c", &menu_choice);

        switch(menu_choice) {
            case '1':
                printf("Enter song title: ");
                scanf(" %[^\n]s", library[num_songs].title);
                printf("Enter artist name: ");
                scanf(" %[^\n]s", library[num_songs].artist);
                printf("Enter song duration (in seconds): ");
                scanf("%d", &library[num_songs].duration);
                printf("Song added successfully!\n");

                num_songs++;
                break;

            case '2':
                printf("--------------- Library ----------------\n\n");
                for (int i = 0; i < num_songs; i++) {
                    printf("Title: %s | Artist: %s | Duration: %d seconds | Favourite: %s \n", 
                            library[i].title, library[i].artist, library[i].duration,
                            library[i].is_favourite ? "Yes" : "No");
                }
                printf("----------------------------------------\n");
                break;

            case '3':
                printf("Enter song title: ");
                char favourite_title[50];
                scanf(" %[^\n]s", favourite_title);

                bool found_song = false;

                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(library[i].title, favourite_title) == 0) {
                        library[i].is_favourite = !library[i].is_favourite;
                        printf("Favourite status changed successfully!\n");
                        found_song = true;
                        break;
                    }
                }

                if (!found_song) {
                    printf("Song not found!\n");
                }

                break;

            case '4':
                printf("Enter artist name: ");
                char artist_name[50];
                scanf(" %[^\n]s", artist_name);

                printf("--------------- Results ----------------\n\n");
                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(library[i].artist, artist_name) == 0) {
                        printf("Title: %s | Duration: %d seconds | Favourite: %s \n", 
                                library[i].title, library[i].duration,
                                library[i].is_favourite ? "Yes" : "No");
                    }
                }
                printf("----------------------------------------\n");

                break;

            case '5':
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}