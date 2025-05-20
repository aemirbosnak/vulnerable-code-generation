//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 100
#define MAX_ACTORS_LENGTH 500
#define MAX_GENRE_LENGTH 100
#define MAX_RATING_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

int main() {
    int num_movies;
    Movie movies[100];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter the title of movie #%d: ", i+1);
        scanf("%s", movies[i].title);
        printf("Enter the director of movie #%d: ", i+1);
        scanf("%s", movies[i].director);
        printf("Enter the actors of movie #%d (comma-separated): ", i+1);
        scanf("%s", movies[i].actors);
        printf("Enter the genre of movie #%d: ", i+1);
        scanf("%s", movies[i].genre);
        printf("Enter the rating of movie #%d (out of 10): ", i+1);
        scanf("%s", movies[i].rating);
    }

    printf("\nMovie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("Movie #%d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n\n", movies[i].rating);
    }

    return 0;
}