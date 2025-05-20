//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Defining the structure for movies */
struct Movie {
    char title[100];
    char genre[50];
    float rating;
};

/* Function to display the details of a movie */
void displayMovie(struct Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %0.1f\n", movie.rating);
    printf("------------------------------\n");
}

/* Function to rate a movie */
void rateMovie(struct Movie *movie) {
    float newRating;
    printf("Please enter a new rating (out of 10) for %s: ", movie->title);
    scanf("%f", &newRating);
    movie->rating = newRating;
    printf("\nRating updated successfully!\n");
    printf("------------------------------\n");
}

/* Main function */
int main() {
    int n, i, option, movieIndex;
    printf("Enter the number of movies: ");
    scanf("%d", &n);
    struct Movie movies[n];

    /* Getting details of all the movies */
    for (i = 0; i < n; i++) {
        printf("\nEnter the details of Movie %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
        printf("\n");
    }

    printf("\nWelcome to the Movie Rating System!\n\n");

    /* Displaying the options for the user */
    do {
        printf("Please select an option:\n");
        printf("1. View all movies\n");
        printf("2. Rate a movie\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                /* Displaying details of all movies */
                printf("\nMovie List:\n");
                for (i = 0; i < n; i++) {
                    displayMovie(movies[i]);
                }
                break;

            case 2:
                /* Updating rating of a movie */
                printf("\nEnter the index of the movie you want to rate: ");
                scanf("%d", &movieIndex);
                if (movieIndex < 1 || movieIndex > n) {
                    printf("\nInvalid index! Please try again.\n");
                    printf("------------------------------\n");
                } else {
                    rateMovie(&movies[movieIndex - 1]);
                }
                break;

            case 3:
                /* Exiting the program */
                printf("Thanks for using the Movie Rating System!\n");
                return 0;
                break;

            default:
                /* Handling invalid options */
                printf("\nInvalid option! Please select again.\n");
                printf("------------------------------\n");
        }
    } while (option != 3);

    return 0;
}