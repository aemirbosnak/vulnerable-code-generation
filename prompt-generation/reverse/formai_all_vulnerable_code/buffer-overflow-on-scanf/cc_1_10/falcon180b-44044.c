//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5
#define MAX_RATING_VALUE 5
#define MAX_RATING_CATEGORIES 5

typedef struct {
    char name[50];
    int rating[MAX_RATING_CATEGORIES];
} Movie;

void print_movie(Movie movie) {
    printf("Movie name: %s\n", movie.name);
    printf("Ratings:\n");
    for (int i = 0; i < MAX_RATING_CATEGORIES; i++) {
        printf("Category %d: %d\n", i+1, movie.rating[i]);
    }
}

int main() {
    int num_movies, num_ratings;
    scanf("%d %d", &num_movies, &num_ratings);

    Movie movies[num_movies];
    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].name);
        for (int j = 0; j < num_ratings; j++) {
            scanf("%d", &movies[i].rating[j]);
        }
    }

    int num_categories;
    scanf("%d", &num_categories);

    char categories[MAX_RATING_CATEGORIES][50];
    for (int i = 0; i < num_categories; i++) {
        scanf("%s", categories[i]);
    }

    int total_ratings = 0;
    for (int i = 0; i < num_movies; i++) {
        for (int j = 0; j < num_categories; j++) {
            total_ratings += movies[i].rating[j];
        }
    }

    printf("Total ratings: %d\n", total_ratings);

    printf("Movies:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}