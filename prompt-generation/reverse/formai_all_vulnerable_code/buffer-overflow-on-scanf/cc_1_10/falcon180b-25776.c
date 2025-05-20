//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_GENRE_LEN 30
#define MAX_RATING 5
#define MAX_REVIEW_LEN 200

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actor[MAX_ACTOR_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
    char review[MAX_REVIEW_LEN];
} Movie;

void print_movie_details(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actor: %s\n", movie->actor);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
    printf("Review: %s\n", movie->review);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie *movies = (Movie *) malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie details for movie %d:\n", i+1);
        scanf("%s", movies[i].title);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].actor);
        scanf("%s", movies[i].genre);
        scanf("%d", &movies[i].rating);
        scanf("%s", movies[i].review);
    }

    int user_rating;
    char user_genre[MAX_GENRE_LEN];
    printf("Enter your preferred genre: ");
    scanf("%s", user_genre);
    printf("Enter your preferred rating: ");
    scanf("%d", &user_rating);

    int num_matches = 0;
    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating >= user_rating && strcmp(movies[i].genre, user_genre) == 0) {
            num_matches++;
            print_movie_details(&movies[i]);
        }
    }

    if (num_matches == 0) {
        printf("No movies found matching your criteria.\n");
    }

    free(movies);
    return 0;
}