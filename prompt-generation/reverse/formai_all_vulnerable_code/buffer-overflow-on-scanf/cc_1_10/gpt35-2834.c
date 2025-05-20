//FormAI DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100 // maximum number of movies that can be stored
#define MAX_RATING 5 // maximum rating for a movie

// define a structure to store information about a movie
struct Movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

// function to add a movie to the list of movies
int addMovie(struct Movie movies[], int numMovies) {
    if (numMovies >= MAX_MOVIES) {
        printf("Cannot add more movies.\n");
        return numMovies;
    }

    printf("Enter movie title: ");
    fflush(stdout);
    scanf("%s", movies[numMovies].title);

    printf("Enter movie director: ");
    fflush(stdout);
    scanf("%s", movies[numMovies].director);

    printf("Enter movie year: ");
    fflush(stdout);
    scanf("%d", &movies[numMovies].year);

    printf("Enter movie rating: ");
    fflush(stdout);
    scanf("%f", &movies[numMovies].rating);

    if (movies[numMovies].rating > MAX_RATING) {
        movies[numMovies].rating = MAX_RATING;
    }

    printf("Added movie %s\n", movies[numMovies].title);
    return numMovies + 1;
}

// function to display all movies in the list
void displayMovies(struct Movie movies[], int numMovies) {
    printf("=========================\n");
    printf("Title\tYear\tDirector\tRating\n");
    printf("=========================\n");

    for (int i = 0; i < numMovies; i++) {
        printf("%s\t%d\t%s\t%.2f\n",
                movies[i].title, movies[i].year, movies[i].director, movies[i].rating);
    }
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int numMovies = 0;
    int choice = 0;

    while (choice != 3) {
        printf("\n1. Add movie\n");
        printf("2. Display movies\n");
        printf("3. Exit\n");
        fflush(stdout);
        printf("Enter choice: ");
        fflush(stdout);
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                numMovies = addMovie(movies, numMovies);
                break;
            case 2:
                displayMovies(movies, numMovies);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}