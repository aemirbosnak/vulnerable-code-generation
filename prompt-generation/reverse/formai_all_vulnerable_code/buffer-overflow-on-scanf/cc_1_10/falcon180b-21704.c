//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5
#define MAX_NAME_LENGTH 100
#define MAX_RATING_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ratings[MAX_RATINGS][MAX_RATING_LENGTH];
    int num_ratings;
} Movie;

void print_movie(Movie movie) {
    printf("Movie: %s\n", movie.name);
    printf("Ratings:\n");
    for (int i = 0; i < movie.num_ratings; i++) {
        printf("%s\n", movie.ratings[i]);
    }
}

void add_rating(Movie* movie, char* rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Error: Movie already has %d ratings.\n", MAX_RATINGS);
        return;
    }
    strcpy(movie->ratings[movie->num_ratings], rating);
    movie->num_ratings++;
}

void main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie name (or 'done' to finish): ");
        scanf("%s", movies[num_movies].name);
        if (strcmp(movies[num_movies].name, "done") == 0) {
            break;
        }
        num_movies++;
    }

    for (int i = 0; i < num_movies; i++) {
        printf("Enter rating for %s: ", movies[i].name);
        scanf("%s", movies[i].ratings[0]);
    }

    printf("Movie ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }
}