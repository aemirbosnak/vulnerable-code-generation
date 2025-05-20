//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10
#define MAX_RATING_VALUE 5

typedef struct {
    char title[50];
    int ratings_count;
    int ratings_sum;
} Movie;

void display_movies(Movie movies[], int count) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d (%.2f)\n", movies[i].title, movies[i].ratings_sum, (float)movies[i].ratings_sum / movies[i].ratings_count);
    }
}

int main() {
    int num_movies, num_ratings;
    Movie movies[MAX_MOVIES];
    char title[50];
    int rating;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    printf("Enter the movie titles:\n");
    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].title);
    }

    printf("Enter the number of ratings for each movie:\n");
    for (int i = 0; i < num_movies; i++) {
        scanf("%d", &movies[i].ratings_count);
    }

    printf("Enter the ratings (1 to 5) for each movie:\n");
    for (int i = 0; i < num_movies; i++) {
        for (int j = 0; j < movies[i].ratings_count; j++) {
            scanf("%d", &rating);
            movies[i].ratings_sum += rating;
        }
    }

    printf("Movie Ratings:\n");
    display_movies(movies, num_movies);

    return 0;
}