//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_DIRECTOR_LENGTH 30
#define MAX_RATING_LENGTH 3
#define MAX_REVIEW_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
    time_t timestamp;
} Movie;

void print_movie(Movie movie) {
    printf("%s (%s)\n", movie.title, movie.director);
    printf("Rating: %s\n", movie.rating);
    printf("Review: %s\n", movie.review);
    printf("Timestamp: %s\n", ctime(&movie.timestamp));
    printf("\n------------------------\n");
}

void add_movie(Movie movies[], int* num_movies, char title[], char director[], char rating[], char review[]) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Error: Max number of movies reached.\n");
        return;
    }

    strcpy(movies[*num_movies].title, title);
    strcpy(movies[*num_movies].director, director);

    for (int i = 0; i < strlen(rating); i++) {
        rating[i] = toupper(rating[i]);
    }

    strcpy(movies[*num_movies].rating, rating);
    strcpy(movies[*num_movies].review, review);
    movies[*num_movies].timestamp = time(NULL);
    (*num_movies)++;
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];

    printf("*********************************************************\n");
    printf("*                                                       *\n");
    printf("*           WELCOME TO THE SHOCKED MOVIE RATING SYSTEM! *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n");

    while (1) {
        printf("\nPlease enter the movie title (or 'quit' to exit): ");
        scanf("%s", title);

        if (strcmp(title, "quit") == 0) {
            break;
        }

        printf("\nPlease enter the movie director: ");
        scanf("%s", director);

        printf("\nPlease enter the movie rating (A, B, C, D, or E): ");
        scanf("%s", rating);

        printf("\nPlease enter the movie review: ");
        scanf("%[^\n]", review);

        add_movie(movies, &num_movies, title, director, rating, review);
    }

    printf("\nTotal number of movies added: %d\n", num_movies);

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}