//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[50];
    float rating;
} Movie;

int main() {
    int numMovies, numRatings;
    Movie movies[MAX_MOVIES];
    float ratings[MAX_RATINGS];
    char filename[50];

    // Read in number of movies
    printf("Enter number of movies: ");
    scanf("%d", &numMovies);

    // Read in movie titles
    printf("Enter movie titles:\n");
    for (int i = 0; i < numMovies; i++) {
        scanf("%s", movies[i].title);
    }

    // Read in number of ratings
    printf("Enter number of ratings: ");
    scanf("%d", &numRatings);

    // Read in ratings
    printf("Enter ratings:\n");
    for (int i = 0; i < numRatings; i++) {
        scanf("%f", &ratings[i]);
    }

    // Calculate average ratings
    for (int i = 0; i < numRatings; i++) {
        for (int j = 0; j < numMovies; j++) {
            if (strcmp(movies[j].title, filename) == 0) {
                movies[j].rating += ratings[i];
                break;
            }
        }
    }

    // Display ratings
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s - %.1f\n", movies[i].title, movies[i].rating);
    }

    return 0;
}