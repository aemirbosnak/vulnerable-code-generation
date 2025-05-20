//FormAI DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[100];
    int year;
    float rating;
};

int main() {
    int numMovies;
    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);
    struct movie *movies = malloc(numMovies * sizeof(struct movie)); // dynamically allocate memory for movies array

    for (int i = 0; i < numMovies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movies[i].title);
        printf("Enter the year of movie %d: ", i+1);
        scanf("%d", &movies[i].year);
        printf("Enter the rating of movie %d (out of 10): ", i+1);
        scanf("%f", &movies[i].rating);

        // Check for valid rating
        while (movies[i].rating < 0 || movies[i].rating > 10) {
            printf("Invalid input. Enter a rating between 0 and 10: ");
            scanf("%f", &movies[i].rating);
        }
    }

    // Find highest rated movie
    float highestRating = 0;
    int highestIndex = 0;
    for (int i = 0; i < numMovies; i++) {
        if (movies[i].rating > highestRating) {
            highestRating = movies[i].rating;
            highestIndex = i;
        }
    }

    // Display movie ratings
    printf("\n------------\n");
    printf("MOVIE RATINGS\n");
    printf("------------\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d): %.1f/10\n", movies[i].title, movies[i].year, movies[i].rating);
    }

    // Display highest rated movie
    printf("\n------------\n");
    printf("HIGH RATING\n");
    printf("------------\n");
    printf("%s (%d): %.1f/10\n", movies[highestIndex].title, movies[highestIndex].year, movies[highestIndex].rating);

    // Free allocated memory
    free(movies);

    return 0;
}