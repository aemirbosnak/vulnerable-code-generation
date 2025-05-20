//FormAI DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float duration;
};

int main()
{
    int choice, i, num_songs = 0;
    struct song library[100];
    char search[50];

    do {
        printf("\nMENU\n");
        printf("1. Add song to library\n");
        printf("2. Search for song\n");
        printf("3. Print entire library\n");
        printf("4. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter song title: ");
                scanf("%s", library[num_songs].title);
                printf("Enter artist name: ");
                scanf("%s", library[num_songs].artist);
                printf("Enter album name: ");
                scanf("%s", library[num_songs].album);
                printf("Enter year of release: ");
                scanf("%d", &library[num_songs].year);
                printf("Enter duration in minutes: ");
                scanf("%f", &library[num_songs].duration);
                num_songs++;
                printf("\nSong added successfully!\n");
                break;
            case 2:
                printf("\nEnter search term: ");
                scanf("%s", search);
                printf("\nSearch results:\n");
                for (i = 0; i < num_songs; i++) {
                    if (strstr(library[i].title, search) != NULL ||
                        strstr(library[i].artist, search) != NULL ||
                        strstr(library[i].album, search) != NULL) {
                        printf("%d. %s - %s (%s, %d)\n", i+1, library[i].title, library[i].artist, library[i].album, library[i].year);
                    }
                }
                break;
            case 3:
                printf("\nLibrary contents:\n");
                for (i = 0; i < num_songs; i++) {
                    printf("%d. %s - %s (%s, %d) [%0.2f minutes]\n", i+1, library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
                }
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}