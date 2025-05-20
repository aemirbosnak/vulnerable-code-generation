//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_RATING_LENGTH 10

struct movie_t {
    char title[MAX_RATING_LENGTH];
    int rating;
    char ratings[MAX_RATINGS][MAX_RATING_LENGTH];
    int num_ratings;
};

void add_rating(struct movie_t *movie, char *rating) {
    if (movie->num_ratings == MAX_RATINGS) {
        printf("Error: Maximum number of ratings reached.\n");
        return;
    }

    strcpy(movie->ratings[movie->num_ratings], rating);
    movie->num_ratings++;
}

void print_ratings(struct movie_t *movie) {
    printf("Ratings for %s:\n", movie->title);
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("%s\n", movie->ratings[i]);
    }
}

int main() {
    struct movie_t movie;

    printf("Enter movie title: ");
    scanf("%s", movie.title);

    printf("Enter initial rating (1-10): ");
    scanf("%d", &movie.rating);

    while (1) {
        char input[MAX_RATING_LENGTH];
        printf("Enter rating (1-10) or 'q' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        int rating = atoi(input);
        if (rating < 1 || rating > 10) {
            printf("Error: Invalid rating.\n");
            continue;
        }

        add_rating(&movie, input);
    }

    print_ratings(&movie);

    return 0;
}