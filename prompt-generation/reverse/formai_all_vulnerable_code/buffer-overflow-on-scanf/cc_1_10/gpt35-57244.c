//FormAI DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Store movie data
typedef struct {
    char title[50];
    char director[50];
    int year;
    int rating;
} Movie;

// Print movie data
void printMovie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Year: %d\n", movie->year);
    printf("Rating: %d out of 10\n", movie->rating);
}

int main() {
    int numMovies, i;

    printf("How many movies do you want to rate?\n");
    scanf("%d", &numMovies);

    // Allocate memory for movie struct array
    Movie *movies = malloc(numMovies * sizeof(Movie));

    // Collect movie data and calculate rating
    for (i = 0; i < numMovies; i++) {
        printf("Enter the title of movie number %d:\n", i+1);
        scanf("%s", movies[i].title);

        printf("Enter the director of movie number %d:\n", i+1);
        scanf("%s", movies[i].director);

        printf("Enter the year of movie number %d:\n", i+1);
        scanf("%d", &movies[i].year);

        printf("Enter your rating for movie number %d out of 10:\n", i+1);
        scanf("%d", &movies[i].rating);
    }

    // Print out movie data
    printf("\nMovie Ratings:\n");
    for (i = 0; i < numMovies; i++) {
        printf("\nMovie number %d:\n", i+1);
        printMovie(&movies[i]);
    }

    // Free memory allocated for movie struct array
    free(movies);

    return 0;
}