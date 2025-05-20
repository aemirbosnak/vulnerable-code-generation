//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[100];
    int rating;
    int review_count;
} Movie;

int main() {
    int num_movies, i, j, choice;
    char input[100];
    Movie movies[MAX_MOVIES];

    printf("Welcome to the Movie Rating System!\n");
    printf("Please enter the number of movies you would like to rate: ");
    scanf("%d", &num_movies);

    printf("Enter the title of the first movie: ");
    scanf("%s", movies[0].title);
    movies[0].rating = 0;
    movies[0].review_count = 0;

    for (i = 1; i < num_movies; i++) {
        printf("Enter the title of the next movie: ");
        scanf("%s", movies[i].title);
        movies[i].rating = 0;
        movies[i].review_count = 0;
    }

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Rate a movie\n");
        printf("2. View ratings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the title of the movie you want to rate: ");
                scanf("%s", input);

                for (i = 0; i < num_movies; i++) {
                    if (strcmp(movies[i].title, input) == 0) {
                        printf("Enter your rating (1-5): ");
                        scanf("%d", &movies[i].rating);
                        movies[i].review_count++;
                        break;
                    }
                }

                if (i == num_movies) {
                    printf("Movie not found.\n");
                }
                break;

            case 2:
                for (i = 0; i < num_movies; i++) {
                    printf("%s - Rating: %d (out of %d reviews)\n", movies[i].title, movies[i].rating, movies[i].review_count);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}