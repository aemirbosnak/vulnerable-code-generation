//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_PLOT_LENGTH 500
#define MAX_RATING 5
#define MIN_RATING 1

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char plot[MAX_PLOT_LENGTH];
    int rating;
} Movie;

void print_movie_details(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Plot: %s\n", movie.plot);
    printf("Rating: %d\n", movie.rating);
}

int main() {
    Movie movie;

    printf("Enter the title of the movie: ");
    scanf("%s", movie.title);

    printf("Enter the name of the director: ");
    scanf("%s", movie.director);

    printf("Enter the names of the actors separated by commas: ");
    scanf("%s", movie.actors);

    printf("Enter the genre of the movie: ");
    scanf("%s", movie.genre);

    printf("Enter the plot of the movie: ");
    scanf("%s", movie.plot);

    printf("Enter the rating of the movie (1 to 5): ");
    scanf("%d", &movie.rating);

    if (movie.rating < MIN_RATING || movie.rating > MAX_RATING) {
        printf("Invalid rating. Please enter a rating between 1 and 5.\n");
        return 1;
    }

    print_movie_details(movie);

    return 0;
}