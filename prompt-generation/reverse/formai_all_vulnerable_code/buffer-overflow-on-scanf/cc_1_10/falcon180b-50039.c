//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 30
#define MAX_YEAR_LEN 10
#define MAX_RATING_LEN 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    int year;
    float rating;
} Movie;

int main() {
    int num_movies, i;
    Movie movies[100];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("\nEnter movie %d details:\n", i+1);

        printf("Title: ");
        scanf("%s", movies[i].title);

        printf("Director: ");
        scanf("%s", movies[i].director);

        printf("Actors: ");
        scanf("%s", movies[i].actors);

        printf("Genre: ");
        scanf("%s", movies[i].genre);

        printf("Year: ");
        scanf("%d", &movies[i].year);

        printf("Rating: ");
        scanf("%f", &movies[i].rating);
    }

    printf("\nMovie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%-20s %-20s %-20s %-10s %-10d %-10.2f\n",
                movies[i].title, movies[i].director, movies[i].actors,
                movies[i].genre, movies[i].year, movies[i].rating);
    }

    return 0;
}