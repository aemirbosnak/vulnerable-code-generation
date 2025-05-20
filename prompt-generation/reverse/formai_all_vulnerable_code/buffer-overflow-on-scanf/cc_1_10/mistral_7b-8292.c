//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    float rating;
} Movie;

Movie movies[MAX_MOVIES];
int numMovies = 0;

void addMovie(char *title, float rating) {
    if (numMovies >= MAX_MOVIES) {
        printf("Error: Cannot add movie. Max number of movies reached.\n");
        return;
    }

    strcpy(movies[numMovies].title, title);
    movies[numMovies].rating = rating;
    numMovies++;
}

void printMovies() {
    printf("\nList of movies and their ratings:\n");

    for (int i = 0; i < numMovies; i++) {
        printf("%s: %.1f\n", movies[i].title, movies[i].rating);
    }
}

void calculateAverage() {
    float sum = 0;

    for (int i = 0; i < numMovies; i++) {
        sum += movies[i].rating;
    }

    float avg = sum / numMovies;
    printf("\nAverage rating: %.1f\n", avg);
}

int main() {
    char title[MAX_NAME_LENGTH];
    float rating;

    while (1) {
        printf("\n1. Add movie\n");
        printf("2. Display movies and ratings\n");
        printf("3. Calculate average rating\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie rating: ");
                scanf("%f", &rating);
                addMovie(title, rating);
                break;
            case 2:
                printMovies();
                break;
            case 3:
                calculateAverage();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}