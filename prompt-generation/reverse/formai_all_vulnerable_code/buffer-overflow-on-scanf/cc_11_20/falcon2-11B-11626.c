//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 10
#define MAX_RATINGS 4

typedef struct {
    char name[50];
    int rating[MAX_RATINGS];
} movie;

movie movies[MAX_MOVIES];
int numMovies = 0;

int main() {
    int choice, i, j, rating;
    char name[50];

    // Initialize movies array
    for (i = 0; i < MAX_MOVIES; i++) {
        strcpy(movies[i].name, "Movie");
        for (j = 0; j < MAX_RATINGS; j++) {
            movies[i].rating[j] = 0;
        }
        numMovies++;
    }

    do {
        printf("Movie Rating System\n");
        printf("1. Enter a new movie\n");
        printf("2. View the highest rated movie\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the movie: ");
                scanf("%s", name);

                printf("Enter the ratings (1-4): ");
                for (i = 0; i < MAX_RATINGS; i++) {
                    scanf("%d", &rating);
                    movies[numMovies - 1].rating[i] = rating;
                }
                printf("Movie %s has been added to the system.\n", name);
                break;

            case 2:
                if (numMovies == 0) {
                    printf("No movies in the system.\n");
                } else {
                    int maxRating = 0;
                    int maxIndex = 0;

                    for (i = 0; i < numMovies; i++) {
                        for (j = 0; j < MAX_RATINGS; j++) {
                            if (movies[i].rating[j] > maxRating) {
                                maxRating = movies[i].rating[j];
                                maxIndex = i;
                            }
                        }
                    }

                    printf("The highest rated movie is %s with a rating of %d.\n", movies[maxIndex].name, maxRating);
                }
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}