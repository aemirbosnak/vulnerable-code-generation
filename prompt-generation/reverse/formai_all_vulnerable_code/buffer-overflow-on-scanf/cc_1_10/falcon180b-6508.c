//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 30
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

int main() {
    int numMovies;
    Movie movies[10];

    printf("Enter the number of movies to rate: ");
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

        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Movie #%d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d\n\n", movies[i].rating);
    }

    return 0;
}