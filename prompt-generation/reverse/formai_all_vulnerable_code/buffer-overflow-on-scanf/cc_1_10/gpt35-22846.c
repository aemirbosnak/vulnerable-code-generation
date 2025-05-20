//FormAI DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the Movie struct */
typedef struct {
   char title[100];
   char director[100];
   char rating[10];
} Movie;

/* Function declaration */
void addMovie(Movie* movies, int* numMovies);
void viewMovies(Movie* movies, int numMovies);

/* Main function */
int main(void)
{
    int numMovies = 0;
    Movie* movies = (Movie*) malloc(sizeof(Movie));

    int choice;

    do {
        /* Display menu options */
        printf("\n---C Movie Rating System---\n");
        printf("1. Add Movie\n");
        printf("2. View Movies\n");
        printf("3. Quit\n\n");

        /* Get user input */
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Handle user choice */
        switch (choice) {
          case 1:
            addMovie(movies, &numMovies);
            break;
          case 2:
            viewMovies(movies, numMovies);
            break;
          case 3:
            printf("Exiting program...\n");
            break;
          default:
            printf("Invalid option, please try again.\n");
        }

    } while (choice != 3);

    free(movies);
    return 0;
}

/* Function implementation to add a movie */
void addMovie(Movie* movies, int* numMovies)
{
    /* Get movie details from user */
    printf("\nEnter the movie title: ");
    scanf("%s", movies[*numMovies].title);
    printf("Enter the movie director: ");
    scanf("%s", movies[*numMovies].director);
    printf("Enter the movie rating (out of 10): ");
    scanf("%s", movies[*numMovies].rating);

    /* Increase the number of movies */
    *numMovies = *numMovies + 1;

    /* Allocate memory for the next movie */
    movies = (Movie*) realloc(movies, (*numMovies + 1) * sizeof(Movie));
}

/* Function implementation to view all movies */
void viewMovies(Movie* movies, int numMovies)
{
    /* Check if there are movies in the list */
    if (numMovies == 0) {
        printf("\nNo movies to display.\n");
        return;
    }

    printf("\n---List of Movies---\n");
    printf("%-30s %-20s %s\n", "Title", "Director", "Rating");

    /* Loop through all movies */
    for (int i = 0; i < numMovies; i++) {
        printf("%-30s %-20s %s\n", 
                movies[i].title, movies[i].director, movies[i].rating);
    }
}