//FormAI DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct music {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

int main() {
    int choice, i, j, k, n;
    char searchTitle[50], searchArtist[50];
    struct music library[100];

    printf("**** Welcome to C Music Library Management System ****\n");
    printf("Please select an option:\n");
    printf("1. Add a music to library\n");
    printf("2. Display all musics\n");
    printf("3. Search and display music by title\n");
    printf("4. Search and display music by artist\n");
    printf("5. Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the number of musics to add: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    printf("\nEnter music title: ");
                    scanf("%s", library[i].title);

                    printf("Enter artist name: ");
                    scanf("%s", library[i].artist);

                    printf("Enter music genre: ");
                    scanf("%s", library[i].genre);

                    printf("Enter music release year: ");
                    scanf("%d", &library[i].year);
                }

                printf("\n%d music(s) added to library successfully.", n);
                break;

            case 2:
                printf("\nList of all musics:\n\n");
                printf("Title\t\tArtist\t\tGenre\t\tYear\n");

                for(i = 0; i < n; i++) {
                    printf("%s\t\t%s\t\t%s\t\t%d\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
                }

                break;

            case 3:
                printf("\nEnter the title to search: ");
                scanf("%s", searchTitle);

                for(i = 0; i < n; i++) {
                    if(strcmp(searchTitle, library[i].title) == 0) {
                        printf("\nMusic found!\n\n");
                        printf("Title\t\tArtist\t\tGenre\t\tYear\n");
                        printf("%s\t\t%s\t\t%s\t\t%d\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
                        break;
                    }
                }

                if(i == n) {
                    printf("\nSorry, there is no music with title '%s'.\n", searchTitle);
                }

                break;

            case 4:
                printf("\nEnter the artist to search: ");
                scanf("%s", searchArtist);

                for(i = 0; i < n; i++) {
                    if(strcmp(searchArtist, library[i].artist) == 0) {
                        printf("\nMusic found!\n\n");
                        printf("Title\t\tArtist\t\tGenre\t\tYear\n");
                        printf("%s\t\t%s\t\t%s\t\t%d\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
                    }
                }

                if(i == n) {
                    printf("\nSorry, there is no music by artist '%s'.\n", searchArtist);
                }

                break;

            case 5:
                printf("\nThank you for using C Music Library Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice, please enter a valid choice.\n");
        }
    }

    return 0;
}