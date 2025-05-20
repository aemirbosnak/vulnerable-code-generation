//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int numMovies;
    Movie movies[100];

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie #%d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (0-5): ");
        scanf("%d", &movies[i].rating);
        printf("Review: ");
        fgets(movies[i].review, MAX_REVIEW_LENGTH, stdin);
    }

    printf("\nMovie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s - %s\n", movies[i].title, movies[i].review);
    }

    return 0;
}