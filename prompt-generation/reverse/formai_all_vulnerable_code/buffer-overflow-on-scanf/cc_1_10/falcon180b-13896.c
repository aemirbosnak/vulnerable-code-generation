//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_RATINGS 5

typedef struct {
    char title[50];
    float rating;
} Movie;

void addMovie(Movie movies[], int numMovies) {
    printf("Enter movie title: ");
    scanf("%s", &movies[numMovies].title);
    printf("Enter movie rating: ");
    scanf("%f", &movies[numMovies].rating);
    numMovies++;
}

void printMovies(Movie movies[], int numMovies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s - %.2f\n", movies[i].title, movies[i].rating);
    }
}

void sortMovies(Movie movies[], int numMovies) {
    for (int i = 0; i < numMovies - 1; i++) {
        for (int j = 0; j < numMovies - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    addMovie(movies, numMovies);
    printf("Do you want to add another movie? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        addMovie(movies, numMovies);
        printf("Do you want to add another movie? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Movie Ratings:\n");
    printMovies(movies, numMovies);
    sortMovies(movies, numMovies);
    printf("\nSorted Movie Ratings:\n");
    printMovies(movies, numMovies);

    return 0;
}