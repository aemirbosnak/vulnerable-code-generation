//FormAI DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define a struct to hold movie information */

struct movie {
    char title[100];
    char director[100];
    int year;
    float rating;
};

/* function to print out a movie's information */

void printMovie(struct movie m) {
    printf("%s, directed by %s, released in %d, rated %.1f/10\n", m.title, m.director, m.year, m.rating);
}

/* function to add a movie to the system */

void addMovie(struct movie* movies, int* numMovies) {
    /* ask user for movie details */
    printf("Enter movie title: ");
    scanf("%s", movies[*numMovies].title);
    printf("Enter director name: ");
    scanf("%s", movies[*numMovies].director);
    printf("Enter year of release: ");
    scanf("%d", &movies[*numMovies].year);
    printf("Enter rating (out of 10): ");
    scanf("%f", &movies[*numMovies].rating);
    printf("\n");
    /* increment number of movies in the system */
    (*numMovies)++;
}

/* function to display the average rating of all movies */

void displayAverageRating(struct movie* movies, int numMovies) {
    float sum = 0.0;
    for (int i = 0; i < numMovies; i++) {
        sum += movies[i].rating;
    }
    float averageRating = sum / numMovies;
    printf("The average rating of all movies is %.1f/10\n", averageRating);
}

/* function to display the highest rated movie */

void displayHighestRatedMovie(struct movie* movies, int numMovies) {
    int highestIndex = 0;
    float highestRating = movies[0].rating;
    for (int i = 1; i < numMovies; i++) {
        if (movies[i].rating > highestRating) {
            highestIndex = i;
            highestRating = movies[i].rating;
        }
    }
    printf("The highest rated movie is ");
    printMovie(movies[highestIndex]);
}

/* function to display the lowest rated movie */

void displayLowestRatedMovie(struct movie* movies, int numMovies) {
    int lowestIndex = 0;
    float lowestRating = movies[0].rating;
    for (int i = 1; i < numMovies; i++) {
        if (movies[i].rating < lowestRating) {
            lowestIndex = i;
            lowestRating = movies[i].rating;
        }
    }
    printf("The lowest rated movie is ");
    printMovie(movies[lowestIndex]);
}

/* main function */

int main() {
    /* initialize variables */
    struct movie movies[100];
    int numMovies = 0;
    int choice;
    /* display menu until user exits */
    while (1) {
        printf("Enter 1 to add a movie to the system\n");
        printf("Enter 2 to display the average rating of all movies\n");
        printf("Enter 3 to display the highest rated movie\n");
        printf("Enter 4 to display the lowest rated movie\n");
        printf("Enter 5 to exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                displayAverageRating(movies, numMovies);
                break;
            case 3:
                displayHighestRatedMovie(movies, numMovies);
                break;
            case 4:
                displayLowestRatedMovie(movies, numMovies);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}