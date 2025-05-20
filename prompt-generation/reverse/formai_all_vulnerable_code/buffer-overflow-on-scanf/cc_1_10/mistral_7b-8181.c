//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    int year;
    float rating;
    char genre[20];
} Movie;

void readMovie(Movie* movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter movie year: ");
    scanf("%d", &movie->year);
    printf("Enter movie genre: ");
    scanf("%s", movie->genre);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movie->rating);
}

void displayMovie(Movie movie) {
    printf("\nTitle: %s\n", movie.title);
    printf("Year: %d\n", movie.year);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %.2f\n", movie.rating);
}

int main() {
    int n, i;
    Movie movies[10];

    printf("Enter number of movies: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        readMovie(&movies[i]);
    }

    printf("\nMovie List:\n");
    for(i = 0; i < n; i++) {
        displayMovie(movies[i]);
    }

    Movie highestRated;
    Movie lowestRated;

    highestRated.rating = 0.0;
    lowestRated.rating = 10.0;

    for(i = 0; i < n; i++) {
        if(movies[i].rating > highestRated.rating) {
            highestRated = movies[i];
        }

        if(movies[i].rating < lowestRated.rating) {
            lowestRated = movies[i];
        }
    }

    printf("\nHighest Rated Movie:\n");
    displayMovie(highestRated);

    printf("\nLowest Rated Movie:\n");
    displayMovie(lowestRated);

    float totalRating = 0.0;
    for(i = 0; i < n; i++) {
        totalRating += movies[i].rating;
    }

    float avgRating = totalRating / n;

    printf("\nAverage Rating: %.2f", avgRating);

    return 0;
}