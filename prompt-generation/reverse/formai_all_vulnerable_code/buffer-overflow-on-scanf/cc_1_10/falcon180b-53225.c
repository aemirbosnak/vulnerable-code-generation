//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 256
#define MAX_DIRECTOR_LENGTH 256
#define MAX_ACTOR_LENGTH 256
#define MAX_GENRE_LENGTH 256
#define MAX_SYNOPSIS_LENGTH 2048
#define MAX_MOVIE_LENGTH 1000
#define MAX_USER_LENGTH 256

#define RATING_MIN 0
#define RATING_MAX 5
#define RATING_INVALID -1

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char synopsis[MAX_SYNOPSIS_LENGTH];
    int rating;
    char user[MAX_USER_LENGTH];
} Movie;

int main() {
    int num_movies, i;
    Movie movies[MAX_MOVIE_LENGTH];

    printf("Enter the number of movies to rate (up to %d): ", MAX_MOVIE_LENGTH);
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("Enter movie #%d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actor: ");
        scanf("%s", movies[i].actor);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Synopsis: ");
        scanf("%s", movies[i].synopsis);
        printf("Rating (0-5): ");
        scanf("%d", &movies[i].rating);
        printf("User: ");
        scanf("%s", movies[i].user);
    }

    printf("\nMovie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("\nMovie #%d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actor: %s\n", movies[i].actor);
        printf("Genre: %s\n", movies[i].genre);
        printf("Synopsis: %s\n", movies[i].synopsis);
        printf("Rating: %d\n", movies[i].rating);
        printf("User: %s\n", movies[i].user);
    }

    return 0;
}