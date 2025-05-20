//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIE_COUNT 100
#define MAX_TITLE_LENGTH 50
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_COUNT 10
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 50
#define MAX_REVIEW_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_COUNT][MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int num_movies;
    Movie movies[MAX_MOVIE_COUNT];

    printf("Welcome to the Movie Rating System!\n");
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie #%d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors (separated by commas): ");
        scanf("%s", movies[i].actors[0]);
        for (int j = 1; j < MAX_ACTOR_COUNT; j++) {
            char actor[MAX_ACTOR_LENGTH];
            scanf("%s", actor);
            strcpy(movies[i].actors[j], actor);
        }
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (out of 5): ");
        scanf("%s", movies[i].rating);
        printf("Review: ");
        scanf("%[^\n]", movies[i].review);
    }

    printf("\nThank you for rating your movies.\n");
    for (int i = 0; i < num_movies; i++) {
        printf("Movie #%d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: ");
        for (int j = 0; j < MAX_ACTOR_COUNT; j++) {
            if (movies[i].actors[j][0]!= '\0') {
                printf("%s ", movies[i].actors[j]);
            }
        }
        printf("\n");
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }

    return 0;
}