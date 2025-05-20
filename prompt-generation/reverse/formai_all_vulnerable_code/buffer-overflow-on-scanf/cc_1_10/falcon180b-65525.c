//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 100
#define MAX_GENRE_LEN 100
#define MAX_ACTORS_LEN 100
#define MAX_LENGTH 100
#define MAX_RATING 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char genre[MAX_GENRE_LEN];
    char actors[MAX_ACTORS_LEN];
    int length;
    int rating;
} Movie;

int main() {
    int numMovies, i;
    Movie movies[MAX_MOVIES];

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter the number of movies you would like to rate:\n");
    scanf("%d", &numMovies);

    for (i = 0; i < numMovies; i++) {
        printf("Enter movie %d information:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Length (in minutes): ");
        scanf("%d", &movies[i].length);
        printf("Rating (out of 10): ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie Ratings:\n");
    for (i = 0; i < numMovies; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Genre: %s\n", movies[i].genre);
        printf("Actors: %s\n", movies[i].actors);
        printf("Length: %d minutes\n", movies[i].length);
        printf("Rating: %d/10\n\n", movies[i].rating);
    }

    return 0;
}