//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LENGTH 50
#define MAX_RATING 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
} Movie;

void inputMovie(Movie *movie);
void calculateAverageRating(const Movie movies[], int numMovies);

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    while (numMovies < MAX_MOVIES && gets(movies[numMovies].title) != NULL) {
        inputMovie(&movies[numMovies]);
        numMovies++;
    }

    if (numMovies > 0) {
        calculateAverageRating(movies, numMovies);
    }

    return 0;
}

void inputMovie(Movie *movie) {
    printf("Enter movie title: ");
    fgets(movie->title, MAX_TITLE_LENGTH, stdin);
    movie->title[strcspn(movie->title, "\n")] = '\0';

    printf("Enter movie rating (1-10): ");
    scanf("%d", &movie->rating);

    while (getchar() != '\n') {
        putchar(getchar());
    }
}

void calculateAverageRating(const Movie movies[], int numMovies) {
    int totalRating = 0;

    for (int i = 0; i < numMovies; i++) {
        totalRating += movies[i].rating;
    }

    double averageRating = (double)totalRating / numMovies;

    printf("The average rating for all movies entered is %.2f\n", averageRating);
}