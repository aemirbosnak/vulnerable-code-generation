//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_GENRES 10
#define MAX_ACTORS 20
#define MAX_DIRECTORS 20
#define MAX_RATINGS 100
#define MAX_REVIEWS 100

typedef struct {
    char title[100];
    int year;
    char genre[20];
    char actors[20];
    char directors[20];
    int rating;
    char review[100];
} Movie;

int main() {
    int numMovies, numGenres, numActors, numDirectors;
    char input[100];
    Movie movies[MAX_MOVIES];

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    printf("Enter the number of genres: ");
    scanf("%d", &numGenres);

    printf("Enter the number of actors: ");
    scanf("%d", &numActors);

    printf("Enter the number of directors: ");
    scanf("%d", &numDirectors);

    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Directors: ");
        scanf("%s", movies[i].directors);
        printf("Rating (out of 10): ");
        scanf("%d", &movies[i].rating);
        printf("Review: ");
        scanf("%s", movies[i].review);
    }

    return 0;
}