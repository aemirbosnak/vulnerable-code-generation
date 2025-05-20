//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[100];
    float rating;
};

void menu() {
    printf("-------C MOVIE RATING SYSTEM-------\n");
    printf("1. Add Movie\n");
    printf("2. Show All Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
}

int main() {
    int choice = 0, movieCount = 0, found = 0, i = 0, index;
    char search[100];
    struct movie m[100];

    while (choice != 5) {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nADD MOVIE:\n");
                printf("Enter movie title: ");
                scanf(" %[^\n]s", m[movieCount].title);
                printf("Add movie rating (out of 10): ");
                scanf("%f", &m[movieCount].rating);
                movieCount++;
                break;

            case 2:
                printf("\nALL MOVIES:\n");
                if (movieCount == 0) {
                    printf("No movies available!\n");
                } else {
                    for (i = 0; i < movieCount; i++) {
                        printf("%d. %s - %.1f/10\n", i + 1, m[i].title, m[i].rating);
                    }
                }
                break;

            case 3:
                printf("\nSEARCH MOVIE:\n");
                printf("Enter movie title: ");
                scanf(" %[^\n]s", search);
                for (i = 0; i < movieCount; i++) {
                    if (strcmp(search, m[i].title) == 0) {
                        printf("%s - %.1f/10\n", m[i].title, m[i].rating);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("Movie not found!\n");
                }
                break;

            case 4:
                printf("\nDELETE MOVIE:\n");
                printf("Enter movie title: ");
                scanf(" %[^\n]s", search);
                for (i = 0; i < movieCount; i++) {
                    if (strcmp(search, m[i].title) == 0) {
                        index = i;
                        found = 1;
                        break;
                    }
                }
                if (found == 1) {
                    for (i = index; i < movieCount - 1; i++) {
                        m[i] = m[i + 1];
                    }
                    movieCount--;
                    printf("%s deleted successfully!\n", search);
                } else {
                    printf("Movie not found!\n");
                }
                break;

            case 5:
                printf("\nExiting....");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}