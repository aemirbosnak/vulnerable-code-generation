//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

struct Movie {
    char title[50];
    int ratings[MAX_RATINGS];
    int numRatings;
};

void initializeRatings(struct Movie* movie) {
    for (int i = 0; i < MAX_RATINGS; i++) {
        movie->ratings[i] = 0;
    }
    movie->numRatings = 0;
}

void addRating(struct Movie* movie, int rating) {
    if (movie->numRatings >= MAX_RATINGS) {
        printf("Error: Movie has too many ratings.\n");
        return;
    }
    movie->ratings[movie->numRatings] = rating;
    movie->numRatings++;
}

double calculateAverage(struct Movie* movie) {
    int sum = 0;
    for (int i = 0; i < movie->numRatings; i++) {
        sum += movie->ratings[i];
    }
    return (double) sum / movie->numRatings;
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int numMovies = 0;

    char choice;
    do {
        printf("C Movie Rating System\n");
        printf("1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. View ratings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the title of the movie: ");
                scanf("%s", movies[numMovies].title);
                initializeRatings(&movies[numMovies]);
                numMovies++;
                printf("Movie added successfully.\n");
                break;
            case '2':
                printf("Enter the title of the movie to rate: ");
                scanf("%s", movies[numMovies].title);
                printf("Enter the rating (1-5): ");
                scanf("%d", &movies[numMovies].ratings[movies[numMovies].numRatings - 1]);
                movies[numMovies].numRatings++;
                printf("Rating added successfully.\n");
                break;
            case '3':
                printf("Enter the title of the movie to view ratings: ");
                scanf("%s", movies[numMovies].title);
                double avgRating = calculateAverage(&movies[numMovies]);
                printf("Average rating for %s: %.2f\n", movies[numMovies].title, avgRating);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}