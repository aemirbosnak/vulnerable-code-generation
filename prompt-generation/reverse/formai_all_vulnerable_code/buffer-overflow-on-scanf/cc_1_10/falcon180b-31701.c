//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATERS 1000
#define MAX_RATING 5
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int num_raters;
    int total_rating;
} Movie;

typedef struct {
    char name[MAX_NAME];
    int rating;
} Rater;

int main() {
    int num_movies, num_raters;
    scanf("%d", &num_movies);
    scanf("%d", &num_raters);

    Movie movies[num_movies];
    Rater raters[num_raters];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].name);
        movies[i].num_raters = 0;
        movies[i].total_rating = 0;
    }

    for (int i = 0; i < num_raters; i++) {
        scanf("%s", raters[i].name);
    }

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Rate a movie\n");
        printf("2. View movie ratings\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the movie:\n");
                char movie_name[MAX_NAME];
                scanf("%s", movie_name);

                printf("Enter your rating (1-5):\n");
                int rating;
                scanf("%d", &rating);

                for (int i = 0; i < num_movies; i++) {
                    if (strcmp(movies[i].name, movie_name) == 0) {
                        movies[i].num_raters++;
                        movies[i].total_rating += rating;
                        printf("Rating submitted successfully.\n");
                        break;
                    }
                }

                break;

            case 2:
                printf("Movie Ratings:\n");
                for (int i = 0; i < num_movies; i++) {
                    printf("%s:\n", movies[i].name);
                    printf("Number of raters: %d\n", movies[i].num_raters);
                    printf("Average rating: %.2f\n\n", (float)movies[i].total_rating / movies[i].num_raters);
                }

                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}