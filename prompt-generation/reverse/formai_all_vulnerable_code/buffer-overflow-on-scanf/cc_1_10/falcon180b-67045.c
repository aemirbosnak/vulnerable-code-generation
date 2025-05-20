//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 50
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

void display_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actor: %s\n", movie->actor);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n\n", movie->rating);
}

int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    Movie *movies = (Movie *)malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie #%d details:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actor: ");
        scanf("%s", movies[i].actor);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating: ");
        scanf("%d", &movies[i].rating);
    }

    int min_rating = MAX_RATING;
    int max_rating = 0;

    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating < min_rating) {
            min_rating = movies[i].rating;
        }
        if (movies[i].rating > max_rating) {
            max_rating = movies[i].rating;
        }
    }

    printf("Minimum rating: %d\n", min_rating);
    printf("Maximum rating: %d\n", max_rating);

    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating >= min_rating && movies[i].rating <= max_rating) {
            display_movie(&movies[i]);
        }
    }

    free(movies);
    return 0;
}