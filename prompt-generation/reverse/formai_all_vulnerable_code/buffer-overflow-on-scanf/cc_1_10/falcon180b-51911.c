//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void print_movie(Movie *movie) {
    printf("Movie: %s\n", movie->title);
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("  Rating %d: %d\n", i + 1, movie->ratings[i]);
    }
}

int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    Movie movies[MAX_MOVIES];
    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i + 1);
        printf("  Title: ");
        scanf("%s", movies[i].title);

        int num_ratings;
        printf("  Number of ratings: ");
        scanf("%d", &num_ratings);

        for (int j = 0; j < num_ratings; j++) {
            printf("  Rating %d: ", j + 1);
            scanf("%d", &movies[i].ratings[j]);
        }

        movies[i].num_ratings = num_ratings;
    }

    printf("List of movies:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}