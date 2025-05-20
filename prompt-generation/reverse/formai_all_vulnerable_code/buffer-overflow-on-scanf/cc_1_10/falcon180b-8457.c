//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5

typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
    char genre[50];
    int runtime;
} Movie;

void addMovie(Movie *movies, int numRatings, int index) {
    printf("Enter movie title: ");
    scanf("%s", movies[index].title);
    printf("Enter director: ");
    scanf("%s", movies[index].director);
    printf("Enter year: ");
    scanf("%d", &movies[index].year);
    printf("Enter rating: ");
    scanf("%f", &movies[index].rating);
    printf("Enter genre: ");
    scanf("%s", movies[index].genre);
    printf("Enter runtime: ");
    scanf("%d", &movies[index].runtime);
}

void displayMovies(Movie *movies, int numRatings) {
    for (int i = 0; i < numRatings; i++) {
        printf("\nMovie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.2f\n", movies[i].rating);
        printf("Genre: %s\n", movies[i].genre);
        printf("Runtime: %d minutes\n\n", movies[i].runtime);
    }
}

void calculateAverageRating(Movie *movies, int numRatings) {
    float sum = 0.0;
    for (int i = 0; i < numRatings; i++) {
        sum += movies[i].rating;
    }
    printf("\nAverage rating: %.2f\n", sum/numRatings);
}

int main() {
    int numRatings;
    printf("Enter number of movies: ");
    scanf("%d", &numRatings);
    Movie movies[MAX_RATINGS];
    for (int i = 0; i < numRatings; i++) {
        addMovie(movies, numRatings, i);
    }
    displayMovies(movies, numRatings);
    calculateAverageRating(movies, numRatings);
    return 0;
}