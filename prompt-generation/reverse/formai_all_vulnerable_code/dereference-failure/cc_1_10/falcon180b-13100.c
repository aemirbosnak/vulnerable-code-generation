//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_RATING 5
#define MAX_REVIEW_LEN 500

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
    char review[MAX_REVIEW_LEN];
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
    printf("Review: %s\n", movie->review);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie* movies = malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i+1);
        scanf(" %[^\n]", movies[i].title);
        movies[i].title[strcspn(movies[i].title, "\n")] = '\0';

        printf("Enter director:\n");
        scanf(" %[^\n]", movies[i].director);
        movies[i].director[strcspn(movies[i].director, "\n")] = '\0';

        printf("Enter actors:\n");
        scanf(" %[^\n]", movies[i].actors);
        movies[i].actors[strcspn(movies[i].actors, "\n")] = '\0';

        printf("Enter genre:\n");
        scanf(" %[^\n]", movies[i].genre);
        movies[i].genre[strcspn(movies[i].genre, "\n")] = '\0';

        printf("Enter rating (1-5):\n");
        scanf("%d", &movies[i].rating);

        printf("Enter review:\n");
        fgets(movies[i].review, MAX_REVIEW_LEN, stdin);
        movies[i].review[strcspn(movies[i].review, "\n")] = '\0';
    }

    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    free(movies);
    return 0;
}