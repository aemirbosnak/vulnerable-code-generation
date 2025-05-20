//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRES_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH+1];
    char director[MAX_DIRECTOR_LENGTH+1];
    char actors[MAX_ACTORS_LENGTH+1];
    char genres[MAX_GENRES_LENGTH+1];
    int rating;
} movie_t;

void print_movie(movie_t* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genres: %s\n", movie->genres);
    printf("Rating: %d\n", movie->rating);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    movie_t* movies = malloc(num_movies * sizeof(movie_t));

    for (int i=0; i<num_movies; i++) {
        printf("Enter movie %d:\n", i+1);
        scanf(" %[^\n]", movies[i].title);
        getchar(); // consume newline

        printf("Enter director:\n");
        scanf(" %[^\n]", movies[i].director);
        getchar(); // consume newline

        printf("Enter actors:\n");
        scanf(" %[^\n]", movies[i].actors);
        getchar(); // consume newline

        printf("Enter genres:\n");
        scanf(" %[^\n]", movies[i].genres);
        getchar(); // consume newline

        printf("Enter rating (0-5):\n");
        scanf("%d", &movies[i].rating);
    }

    int total_rating = 0;
    for (int i=0; i<num_movies; i++) {
        total_rating += movies[i].rating;
    }

    double average_rating = (double)total_rating / num_movies;

    printf("Average rating: %.2f\n", average_rating);

    for (int i=0; i<num_movies; i++) {
        print_movie(&movies[i]);
    }

    free(movies);
    return 0;
}