//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold music library data
typedef struct {
    char title[100];
    char artist[100];
    int year;
    int rating;
} Music;

// function to display menu and get user input
int getMenuChoice() {
    int choice;
    printf("Music Library Management System\n");
    printf("1. Add music\n");
    printf("2. Display all music\n");
    printf("3. Search for music by title\n");
    printf("4. Search for music by artist\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice, i, found;
    char title[100], artist[100];
    Music library[100];

    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                printf("\nEnter music title: ");
                scanf("%s", library[i].title);
                printf("Enter music artist: ");
                scanf("%s", library[i].artist);
                printf("Enter year of release: ");
                scanf("%d", &library[i].year);
                printf("Enter rating out of 5: ");
                scanf("%d", &library[i].rating);
                printf("Music added successfully.\n\n");
                i++;
                break;

            case 2:
                printf("\nAll music in library:\n");
                for (int j = 0; j < i; j++) {
                    printf("Title: %s\n", library[j].title);
                    printf("Artist: %s\n", library[j].artist);
                    printf("Year of release: %d\n", library[j].year);
                    printf("Rating out of 5: %d\n\n", library[j].rating);
                }
                break;

            case 3:
                printf("\nEnter music title to search: ");
                scanf("%s", title);
                found = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(library[j].title, title) == 0) {
                        printf("\nTitle: %s\n", library[j].title);
                        printf("Artist: %s\n", library[j].artist);
                        printf("Year of release: %d\n", library[j].year);
                        printf("Rating out of 5: %d\n\n", library[j].rating);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("\nMusic not found.\n\n");
                }
                break;

            case 4:
                printf("\nEnter music artist to search: ");
                scanf("%s", artist);
                found = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(library[j].artist, artist) == 0) {
                        printf("\nArtist: %s\n", library[j].artist);
                        printf("Title: %s\n", library[j].title);
                        printf("Year of release: %d\n", library[j].year);
                        printf("Rating out of 5: %d\n\n", library[j].rating);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("\nMusic not found.\n\n");
                }
                break;

            case 5:
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}