//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_GENRES 50
#define MAX_DIRECTORS 50
#define MAX_ACTORS 50
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor1[MAX_ACTOR_LENGTH];
    char actor2[MAX_ACTOR_LENGTH];
    char actor3[MAX_ACTOR_LENGTH];
    int rating;
} Movie;

int main() {
    int num_movies, i, j;
    char input[MAX_TITLE_LENGTH];
    Movie movies[MAX_MOVIES];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actor 1: ");
        scanf("%s", movies[i].actor1);
        printf("Actor 2: ");
        scanf("%s", movies[i].actor2);
        printf("Actor 3: ");
        scanf("%s", movies[i].actor3);
        printf("Rating (1-10): ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s (%s) - %s - %s\n", movies[i].title, movies[i].genre, movies[i].director, movies[i].actor1);
        printf("Actors: %s, %s, %s\n", movies[i].actor1, movies[i].actor2, movies[i].actor3);
        printf("Rating: %d\n\n", movies[i].rating);
    }

    return 0;
}