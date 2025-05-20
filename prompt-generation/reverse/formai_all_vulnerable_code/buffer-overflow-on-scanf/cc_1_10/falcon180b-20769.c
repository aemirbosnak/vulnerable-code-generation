//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_RATING_LEN 10
#define MAX_REVIEW_LEN 500

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    char rating[MAX_RATING_LEN];
    char review[MAX_REVIEW_LEN];
} Movie;

int main() {
    int numMovies;
    Movie movies[100];
    char input[1000];

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie %d information:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (1-10): ");
        scanf("%s", movies[i].rating);
        printf("Review (optional): ");
        fgets(input, sizeof(input), stdin);
        strcpy(movies[i].review, input);
        printf("\n");
    }

    printf("Movie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s:\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n", movies[i].rating);
        printf("Review: %s\n", movies[i].review);
        printf("\n");
    }

    return 0;
}