//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATING 10
#define MIN_RATING 0

typedef struct {
    char title[50];
    int rating[MAX_RATING];
    int num_ratings;
} Movie;

void shocking_error(const char *msg) {
    printf("\n");
    for (int i = 0; i < 50; ++i) {
        printf("%c", 174);
    }
    printf(" %s\n", msg);
    for (int i = 0; i < 50; ++i) {
        printf("%c", 175);
    }
    printf("\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (1) {
        printf("Enter movie title (or type 'quit' to exit): ");
        scanf("%s", movies[num_movies].title);
        if (strcmp(movies[num_movies].title, "quit") == 0) {
            break;
        }

        printf("Enter number of ratings for %s: ", movies[num_movies].title);
        scanf("%d", &movies[num_movies].num_ratings);

        if (movies[num_movies].num_ratings <= 0 ||
            movies[num_movies].num_ratings > MAX_RATING) {
            shocking_error("Invalid number of ratings!");
            continue;
        }

        for (int i = 0; i < movies[num_movies].num_ratings; ++i) {
            int rating;
            printf("Enter rating %d for %s: ", i + 1, movies[num_movies].title);
            scanf("%d", &rating);

            if (rating < MIN_RATING || rating > MAX_RATING) {
                shocking_error("Invalid rating!");
                i--; // Decrement i because we don't want to process this rating
                continue;
            }

            movies[num_movies].rating[i] = rating;
        }

        num_movies++;
    }

    printf("\nMovie Ratings:\n");

    for (int i = 0; i < num_movies; ++i) {
        printf("%s: ", movies[i].title);
        for (int j = 0; j < movies[i].num_ratings; ++j) {
            printf("%d ", movies[i].rating[j]);
        }
        printf("\n");
    }

    return 0;
}