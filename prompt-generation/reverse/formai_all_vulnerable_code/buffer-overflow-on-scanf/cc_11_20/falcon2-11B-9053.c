//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 100
#define MAX_MOVIES 100

typedef struct {
    char *title;
    int rating;
} Movie;

typedef struct {
    char *title;
    int rating;
} Rating;

int main() {
    int numMovies, numRatings;
    Movie movies[MAX_MOVIES];
    Rating ratings[MAX_RATINGS];
    int i, j, movieID, ratingID;

    // Create movies and ratings
    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);
    for (i = 0; i < numMovies; i++) {
        printf("Enter movie title: ");
        scanf("%s", movies[i].title);
        printf("Enter movie rating: ");
        scanf("%d", &movies[i].rating);
    }
    printf("Enter the number of ratings: ");
    scanf("%d", &numRatings);
    for (i = 0; i < numRatings; i++) {
        printf("Enter rating title: ");
        scanf("%s", ratings[i].title);
        printf("Enter rating value: ");
        scanf("%d", &ratings[i].rating);
    }

    // Display all movies and ratings
    printf("\nMovies:\n");
    for (i = 0; i < numMovies; i++) {
        printf("%s (%d)\n", movies[i].title, movies[i].rating);
    }
    printf("\nRatings:\n");
    for (i = 0; i < numRatings; i++) {
        printf("%s (%d)\n", ratings[i].title, ratings[i].rating);
    }

    // Calculate average rating
    int totalRating = 0;
    for (i = 0; i < numRatings; i++) {
        totalRating += ratings[i].rating;
    }
    float averageRating = (float)totalRating / numRatings;
    printf("\nAverage rating: %.2f\n", averageRating);

    // Sort movies by rating
    for (i = 0; i < numMovies; i++) {
        for (j = 0; j < numRatings; j++) {
            if (movies[i].rating > ratings[j].rating) {
                movieID = movies[i].rating;
                ratingID = ratings[j].rating;
                movies[i].rating = ratingID;
                ratings[j].rating = movieID;
                break;
            }
        }
    }

    // Display sorted movies
    printf("\nSorted movies by rating:\n");
    for (i = 0; i < numMovies; i++) {
        printf("%s (%d)\n", movies[i].title, movies[i].rating);
    }

    // Display most rated movie
    Movie mostRatedMovie = movies[0];
    for (i = 1; i < numMovies; i++) {
        if (movies[i].rating > movies[0].rating) {
            mostRatedMovie = movies[i];
        }
    }
    printf("\nMost rated movie: %s (%d)\n", mostRatedMovie.title, mostRatedMovie.rating);

    return 0;
}