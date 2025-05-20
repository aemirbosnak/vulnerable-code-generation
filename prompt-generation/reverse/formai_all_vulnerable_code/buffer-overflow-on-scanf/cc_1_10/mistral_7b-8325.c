//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_TITLE 50
#define MAX_RATING 10

typedef struct {
    char title[MAX_TITLE];
    int rating;
} Movie;

void getMovieDetails(Movie *movie) {
    printf("Enter movie title: ");
    fgets(movie->title, MAX_TITLE, stdin);
    movie->title[strcspn(movie->title, "\n")] = '\0';
    printf("Enter movie rating (1-10): ");
    scanf("%d", &movie->rating);
}

void addMovie(Movie movies[MAX_MOVIES], int *numMovies) {
    if (*numMovies < MAX_MOVIES) {
        getMovieDetails(&movies[*numMovies]);
        (*numMovies)++;
    } else {
        printf("Maximum number of movies reached.\n");
    }
}

void displayMovies(Movie movies[MAX_MOVIES], int numMovies) {
    printf("\nMovie Rating System\n");
    for (int i = 0; i < numMovies; i++) {
        printf("\n%s - %d", movies[i].title, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    while (1) {
        int choice;
        printf("\n1. Add movie\n2. Display movies\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                displayMovies(movies, numMovies);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}