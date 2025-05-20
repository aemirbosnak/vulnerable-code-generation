//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50

typedef struct Movie {
    char title[50];
    int year;
    int rating;
} Movie;

void printMenu() {
    printf("Welcome to the Happy Movie Rating System!\n");
    printf("1. Add a movie\n");
    printf("2. Delete a movie\n");
    printf("3. View all movies\n");
    printf("4. Rate a movie\n");
    printf("5. Exit\n");
}

void addMovie(Movie *movies, int *numMovies) {
    char title[50];
    int year, rating;
    if (*numMovies == MAX_MOVIES) {
        printf("You have reached the maximum number of movies!\n");
        return;
    }
    printf("Please enter the movie title:");
    scanf("%s", title);
    printf("Please enter the movie year:");
    scanf("%d", &year);
    printf("Please enter the movie rating (out of 10):");
    scanf("%d", &rating);
    strcpy(movies[*numMovies].title, title);
    movies[*numMovies].year = year;
    movies[*numMovies].rating = rating;
    *numMovies += 1;
    printf("New movie added successfully!\n");
}

void deleteMovie(Movie *movies, int *numMovies) {
    char title[50];
    int i, found = 0;
    printf("Please enter the movie title to delete:");
    scanf("%s", title);
    for (i = 0; i < *numMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < *numMovies - 1; i++) {
            movies[i] = movies[i+1];
        }
        *numMovies -= 1;
        printf("Movie deleted successfully!\n");
    } else {
        printf("Movie not found!\n");
    }
}

void viewAllMovies(Movie *movies, int numMovies) {
    int i;
    printf("Title\tYear\tRating\n");
    for (i = 0; i < numMovies; i++) {
        printf("%s\t%d\t%d\n", movies[i].title, movies[i].year, movies[i].rating);
    }
}

void rateMovie(Movie *movies, int numMovies) {
    char title[50];
    int i, rating, found = 0;
    printf("Please enter the movie title to rate:");
    scanf("%s", title);
    for (i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Please enter the new movie rating (out of 10):");
        scanf("%d", &rating);
        movies[i].rating = rating;
        printf("Movie rated successfully!\n");
    } else {
        printf("Movie not found!\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    int choice;
    do {
        printMenu();
        printf("Please enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                deleteMovie(movies, &numMovies);
                break;
            case 3:
                viewAllMovies(movies, numMovies);
                break;
            case 4:
                rateMovie(movies, numMovies);
                break;
            case 5:
                printf("Thank you for using the Happy Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}