//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100

struct Movie {
    char title[50];
    char director[50];
    char actors[100];
    int year;
    float rating;
};

void addMovie(struct Movie movies[], int numMovies) {
    printf("Enter movie title: ");
    scanf("%s", movies[numMovies].title);

    printf("Enter movie director: ");
    scanf("%s", movies[numMovies].director);

    printf("Enter movie actors (separated by commas): ");
    scanf("%s", movies[numMovies].actors);

    printf("Enter movie release year: ");
    scanf("%d", &movies[numMovies].year);

    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movies[numMovies].rating);
}

void displayMovies(struct Movie movies[], int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        printf("\nMovie %d:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Release Year: %d\n", movies[i].year);
        printf("Rating: %.2f/10\n\n", movies[i].rating);
    }
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int numMovies = 0;

    printf("Welcome to the Movie Rating System!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numMovies >= MAX_MOVIES) {
                printf("Maximum number of movies reached. Please remove a movie to add a new one.\n");
            } else {
                addMovie(movies, numMovies);
                numMovies++;
            }
            break;

        case 2:
            if (numMovies == 0) {
                printf("No movies added yet.\n");
            } else {
                displayMovies(movies, numMovies);
            }
            break;

        case 3:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}