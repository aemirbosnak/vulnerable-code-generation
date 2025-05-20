//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[50];
    char artist[50];
    char genre[50];
    int rating;
    int duration;
};

int main() {
    int choice, count = 0, i;
    struct Song songs[100];
    char temp[50];

    printf("Welcome to the C Music Library Management System!\n");

    while (1) {
        printf("\nPlease choose an operation:\n");
        printf("1. Add a Song\n");
        printf("2. View all Songs\n");
        printf("3. Search for a Song\n");
        printf("4. Sort Songs by Name\n");
        printf("5. Sort Songs by Artist\n");
        printf("6. Sort Songs by Rating\n");
        printf("7. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAdding a Song:\n");
                printf("Name: ");
                scanf("%s", songs[count].name);
                printf("Artist: ");
                scanf("%s", songs[count].artist);
                printf("Genre: ");
                scanf("%s", songs[count].genre);
                printf("Rating (1-10): ");
                scanf("%d", &songs[count].rating);
                printf("Duration (in seconds): ");
                scanf("%d", &songs[count].duration);
                count++;
                break;

            case 2:
                printf("\nViewing all Songs:\n");
                if (count == 0) {
                    printf("No Songs in Library\n");
                    break;
                }
                for (i = 0; i < count; i++) {
                    printf("Name: %s\n", songs[i].name);
                    printf("Artist: %s\n", songs[i].artist);
                    printf("Genre: %s\n", songs[i].genre);
                    printf("Rating: %d\n", songs[i].rating);
                    printf("Duration: %d seconds\n\n", songs[i].duration);
                }
                break;

            case 3:
                printf("\nSearching for a Song:\n");
                printf("Enter Song Name: ");
                scanf("%s", temp);
                for (i = 0; i < count; i++) {
                    if (strcmp(temp, songs[i].name) == 0) {
                        printf("Name: %s\n", songs[i].name);
                        printf("Artist: %s\n", songs[i].artist);
                        printf("Genre: %s\n", songs[i].genre);
                        printf("Rating: %d\n", songs[i].rating);
                        printf("Duration: %d seconds\n", songs[i].duration);
                        break;
                    }
                }
                if (i == count) {
                    printf("Song not found in Library\n");
                }
                break;

            case 4:
                printf("\nSorting Songs by Name:\n");
                for (i = 0; i < count - 1; i++) {
                    int j, swap = 0;
                    for (j = 0; j < count - i - 1; j++) {
                        if (strcmp(songs[j].name, songs[j+1].name) > 0) {
                            struct Song temp = songs[j];
                            songs[j] = songs[j+1];
                            songs[j+1] = temp;
                            swap = 1;
                        }
                    }
                    if (!swap) {
                        break;
                    }
                }
                printf("Songs sorted by Name\n");
                break;

            case 5:
                printf("\nSorting Songs by Artist:\n");
                for (i = 0; i < count - 1; i++) {
                    int j, swap = 0;
                    for (j = 0; j < count - i - 1; j++) {
                        if (strcmp(songs[j].artist, songs[j+1].artist) > 0) {
                            struct Song temp = songs[j];
                            songs[j] = songs[j+1];
                            songs[j+1] = temp;
                            swap = 1;
                        }
                    }
                    if (!swap) {
                        break;
                    }
                }
                printf("Songs sorted by Artist\n");
                break;

            case 6:
                printf("\nSorting Songs by Rating:\n");
                for (i = 0; i < count - 1; i++) {
                    int j, swap = 0;
                    for (j = 0; j < count - i - 1; j++) {
                        if (songs[j].rating < songs[j+1].rating) {
                            struct Song temp = songs[j];
                            songs[j] = songs[j+1];
                            songs[j+1] = temp;
                            swap = 1;
                        }
                    }
                    if (!swap) {
                        break;
                    }
                }
                printf("Songs sorted by Rating\n");
                break;

            case 7:
                printf("\nThank you for using the C Music Library Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice, please choose again\n");
        }
    }

    return 0;
}