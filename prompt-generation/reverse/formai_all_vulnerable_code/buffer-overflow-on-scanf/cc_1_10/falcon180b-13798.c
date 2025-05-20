//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_GENRES 10
#define MAX_RATINGS 5

typedef struct {
    char title[100];
    char genre[50];
    int rating;
} Movie;

void addMovie(Movie movies[], int numMovies, char *title, char *genre, int rating) {
    if (numMovies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }
    strcpy(movies[numMovies].title, title);
    strcpy(movies[numMovies].genre, genre);
    movies[numMovies].rating = rating;
    numMovies++;
}

void displayMovies(Movie movies[], int numMovies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%s) - %d stars\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

int main() {
    int numMovies = 0;
    Movie movies[MAX_MOVIES];
    char title[100];
    char genre[50];
    int rating;

    printf("Welcome to the Movie Rating System!\n");
    while (1) {
        printf("Enter movie title: ");
        scanf("%s", title);
        if (strcmp(title, "quit") == 0) {
            break;
        }
        printf("Enter movie genre: ");
        scanf("%s", genre);
        printf("Enter movie rating (1-5 stars): ");
        scanf("%d", &rating);
        addMovie(movies, numMovies, title, genre, rating);
        numMovies++;
    }

    printf("\nMovie Ratings:\n");
    displayMovies(movies, numMovies);

    return 0;
}