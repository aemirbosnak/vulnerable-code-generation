//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000

typedef struct {
    char title[50];
    int year;
    double rating;
} Movie;

int main() {
    int numMovies, numRatings;
    Movie movies[MAX_MOVIES];
    double ratings[MAX_RATINGS];

    printf("Enter number of movies: ");
    scanf("%d", &numMovies);

    printf("Enter number of ratings: ");
    scanf("%d", &numRatings);

    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie title: ");
        scanf("%s", movies[i].title);
        printf("Enter movie year: ");
        scanf("%d", &movies[i].year);
        movies[i].rating = 0;
    }

    for (int i = 0; i < numRatings; i++) {
        printf("Enter movie title: ");
        char movieTitle[50];
        scanf("%s", movieTitle);
        int movieIndex = -1;
        for (int j = 0; j < numMovies; j++) {
            if (strcmp(movies[j].title, movieTitle) == 0) {
                movieIndex = j;
                break;
            }
        }
        if (movieIndex == -1) {
            printf("Movie not found.\n");
            continue;
        }
        printf("Enter rating: ");
        scanf("%lf", &ratings[i]);
        movies[movieIndex].rating += ratings[i];
    }

    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d): %.2lf\n", movies[i].title, movies[i].year, movies[i].rating);
    }

    return 0;
}