//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 64
#define MAX_DIRECTOR_LEN 64
#define MAX_ACTOR_LEN 64
#define MAX_GENRE_LEN 32
#define MAX_RATING 5
#define MAX_REVIEW_LEN 1024

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTOR_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
    char review[MAX_REVIEW_LEN];
} Movie;

int main() {
    int num_movies, i;
    Movie movies[100];

    printf("Welcome to the Movie Rating System!\n");
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("Enter the title of movie %d: ", i + 1);
        scanf("%s", movies[i].title);

        printf("Enter the director of movie %d: ", i + 1);
        scanf("%s", movies[i].director);

        printf("Enter the actors of movie %d (comma-separated): ", i + 1);
        scanf("%s", movies[i].actors);

        printf("Enter the genre of movie %d: ", i + 1);
        scanf("%s", movies[i].genre);

        printf("Enter the rating of movie %d (1 to 5): ", i + 1);
        scanf("%d", &movies[i].rating);

        printf("Enter a review for movie %d: ", i + 1);
        scanf("%[^\n]", movies[i].review);
    }

    printf("\n");

    for (i = 0; i < num_movies; i++) {
        printf("Movie #%d:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }

    return 0;
}