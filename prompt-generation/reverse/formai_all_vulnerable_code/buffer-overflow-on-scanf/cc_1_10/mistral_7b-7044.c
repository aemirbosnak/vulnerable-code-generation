//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATING 10
#define MAX_NAME_LENGTH 50

struct Movie {
    char title[MAX_NAME_LENGTH];
    float rating;
};

void readMovies(struct Movie movies[MAX_MOVIES], int* numMovies);
float calculateAverageRating(struct Movie movies[], int numMovies);
void printMovies(struct Movie movies[], int numMovies, float avgRating);

int main() {
    struct Movie movies[MAX_MOVIES];
    int numMovies;

    readMovies(movies, &numMovies);

    if (numMovies == 0) {
        printf("No movies found.\n");
        return 0;
    }

    float avgRating = calculateAverageRating(movies, numMovies);
    printMovies(movies, numMovies, avgRating);

    return 0;
}

void readMovies(struct Movie movies[], int* numMovies) {
    char title[MAX_NAME_LENGTH];
    float rating;

    *numMovies = 0;

    printf("Enter movie title and rating (-1 to quit):\n");

    while (scanf("%s%f", title, &rating) == 2) {
        strcpy(movies[*numMovies].title, title);
        movies[*numMovies].rating = rating;
        (*numMovies)++;

        if (*numMovies >= MAX_MOVIES) {
            printf("Too many movies. Max is %d.\n", MAX_MOVIES);
            break;
        }
    }
}

float calculateAverageRating(struct Movie movies[], int numMovies) {
    float sum = 0;

    for (int i = 0; i < numMovies; i++) {
        sum += movies[i].rating;
    }

    return sum / numMovies;
}

void printMovies(struct Movie movies[], int numMovies, float avgRating) {
    printf("\nMovie titles with rating above average (%0.1f):\n", avgRating);

    for (int i = 0; i < numMovies; i++) {
        if (movies[i].rating > avgRating) {
            printf("%s (%0.1f)\n", movies[i].title, movies[i].rating);
        }
    }
}