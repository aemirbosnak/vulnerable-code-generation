//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char artist[50];
    int genre;
} Music;

int main() {
    Music library[100];
    int num_songs = 0;
    int choice, i;

    printf("Welcome to the Music Library Management System!\n");
    printf("1. Add a song to the library\n");
    printf("2. Remove a song from the library\n");
    printf("3. List all songs in the library\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                printf("Enter the song's name: ");
                scanf("%s", library[num_songs].name);
                printf("Enter the artist's name: ");
                scanf("%s", library[num_songs].artist);
                printf("Enter the genre (1-10): ");
                scanf("%d", &library[num_songs].genre);
                num_songs++;
                break;

            case 2:
                printf("Enter the song's name: ");
                scanf("%s", library[num_songs].name);
                printf("Do you want to remove this song? (y/n): ");
                char remove_choice;
                scanf(" %c", &remove_choice);
                if (remove_choice == 'y') {
                    for (i = num_songs - 1; i >= 0; i--) {
                        if (strcmp(library[i].name, library[num_songs].name) == 0) {
                            for (int j = i; j < num_songs - 1; j++) {
                                strcpy(library[j].name, library[j + 1].name);
                                strcpy(library[j].artist, library[j + 1].artist);
                                library[j].genre = library[j + 1].genre;
                            }
                            num_songs--;
                            break;
                        }
                    }
                }
                break;

            case 3:
                printf("List of songs in the library:\n");
                for (i = 0; i < num_songs; i++) {
                    printf("%s - %s (Genre: %d)\n", library[i].name, library[i].artist, library[i].genre);
                }
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("Thank you for using the Music Library Management System!\n");
    return 0;
}