//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIE_TITLE_LENGTH 100
#define MAX_MOVIE_DIRECTOR_LENGTH 50
#define MAX_MOVIE_ACTOR_LENGTH 50
#define MAX_MOVIE_PLOT_LENGTH 200
#define MAX_MOVIE_GENRE_LENGTH 50
#define MAX_MOVIE_RATING_LENGTH 10

typedef struct {
    char title[MAX_MOVIE_TITLE_LENGTH];
    char director[MAX_MOVIE_DIRECTOR_LENGTH];
    char actor[MAX_MOVIE_ACTOR_LENGTH];
    char plot[MAX_MOVIE_PLOT_LENGTH];
    char genre[MAX_MOVIE_GENRE_LENGTH];
    char rating[MAX_MOVIE_RATING_LENGTH];
} Movie;

int main() {
    Movie movie;
    char ch;
    int i = 0;

    printf("Enter the movie title: ");
    while ((ch = getchar())!= '\n') {
        movie.title[i++] = tolower(ch);
    }
    movie.title[i] = '\0';

    printf("Enter the movie director: ");
    while ((ch = getchar())!= '\n') {
        movie.director[i++] = tolower(ch);
    }
    movie.director[i] = '\0';

    printf("Enter the movie actor: ");
    while ((ch = getchar())!= '\n') {
        movie.actor[i++] = tolower(ch);
    }
    movie.actor[i] = '\0';

    printf("Enter the movie plot: ");
    while ((ch = getchar())!= '\n') {
        movie.plot[i++] = tolower(ch);
    }
    movie.plot[i] = '\0';

    printf("Enter the movie genre: ");
    while ((ch = getchar())!= '\n') {
        movie.genre[i++] = tolower(ch);
    }
    movie.genre[i] = '\0';

    printf("Enter the movie rating: ");
    while ((ch = getchar())!= '\n') {
        movie.rating[i++] = tolower(ch);
    }
    movie.rating[i] = '\0';

    printf("You have entered:\n");
    printf("Movie Title: %s\n", movie.title);
    printf("Movie Director: %s\n", movie.director);
    printf("Movie Actor: %s\n", movie.actor);
    printf("Movie Plot: %s\n", movie.plot);
    printf("Movie Genre: %s\n", movie.genre);
    printf("Movie Rating: %s\n", movie.rating);

    return 0;
}