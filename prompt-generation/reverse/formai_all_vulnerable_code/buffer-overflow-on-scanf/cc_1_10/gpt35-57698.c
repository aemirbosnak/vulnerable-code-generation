//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MOVIES 100

// defining a structure for movie
typedef struct {
    char title[50];
    double rating;
    int year;
} Movie;

// function to add a new movie to the system
void addMovie(Movie movies[], int *numberOfMovies) {
    int i = *numberOfMovies; // getting the index for the new movie
    Movie newMovie; // creating a new movie object

    // getting input from user for the new movie
    printf("Enter movie title: ");
    scanf("%s", newMovie.title);
    printf("Enter movie rating (out of 10): ");
    scanf("%lf", &newMovie.rating);
    printf("Enter movie release year: ");
    scanf("%d", &newMovie.year);

    // adding the new movie to the movie array
    movies[i] = newMovie;
    *numberOfMovies = *numberOfMovies + 1; // updating the number of movies in the system

    printf("New movie added successfully!\n");
}

// function to remove a movie from the system
void removeMovie(Movie movies[], int *numberOfMovies, int index) {
    // shifting the movie array to remove the selected movie
    for (int i = index; i < *numberOfMovies - 1; i++) {
        movies[i] = movies[i+1];
    }
    *numberOfMovies = *numberOfMovies - 1; // updating the number of movies in the system

    printf("Movie removed successfully!\n");
}

// function to print all the movies in the system
void printAllMovies(Movie movies[], int numberOfMovies) {
    // if no movies are present in the system, print a message and return
    if (numberOfMovies == 0) {
        printf("No movies in the system!\n");
        return;
    }

    printf("\n------------------\n");
    printf("|   All Movies    |\n");
    printf("------------------\n");
    printf("| Title | Rating | Year |\n");
    printf("------------------------\n");
    for (int i = 0; i < numberOfMovies; i++) {
        printf("| %-5s | %5.2lf | %4d |\n", movies[i].title,
                                            movies[i].rating,
                                            movies[i].year);
    }
    printf("------------------\n\n");
}

// function to find and print all the movies released in a given year
void findMoviesByYear(Movie movies[], int numberOfMovies, int year) {
    int count = 0;

    printf("\n----------------------------------------\n");
    printf("| Movies released in the year %4d      |\n", year);
    printf("----------------------------------------\n");
    printf("| Title | Rating |\n");
    printf("-------------------\n");

    // iterating over all the movies in the system
    for (int i = 0; i < numberOfMovies; i++) {
        // if the movie release year matches the given year, print it
        if (movies[i].year == year) {
            printf("| %-5s | %5.2lf |\n", movies[i].title, movies[i].rating);
            count++;
        }
    }
    // if no movies are present, print a message
    if (count == 0) {
        printf("| No movies released in this year!      |\n");
        printf("----------------------------------------\n");
    }
    else {
        printf("-------------------\n");
        printf("| Total movies: %2d |\n", count);
        printf("-------------------\n");
    }
}

// main function
int main() {
    Movie movies[MAX_MOVIES]; // array to store all the movies in the system
    int numberOfMovies = 0; // variable to store the total number of movies in the system
    int choice, year, index;

    // display menu and get user input until user chooses to exit
    while (1) {
        printf("\n--------------------\n");
        printf("  Movie Rating System\n");
        printf("--------------------\n");
        printf("1. Add a movie\n");
        printf("2. Remove a movie\n");
        printf("3. Print all movies\n");
        printf("4. Find movies by year\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &choice); // getting user choice

        switch(choice) {
            case 1:
                addMovie(movies, &numberOfMovies); // adding a new movie
                break;

            case 2:
                printf("Enter the index of the movie to remove: ");
                scanf("%d", &index);
                // checking if the index is valid or not
                if (index >= 0 && index < numberOfMovies) {
                    removeMovie(movies, &numberOfMovies, index); // removing a movie
                }
                else {
                    printf("Invalid Index!\n");
                }
                break;

            case 3:
                printAllMovies(movies, numberOfMovies); // printing all the movies
                break;

            case 4:
                printf("Enter year to find movies for: ");
                scanf("%d", &year);
                findMoviesByYear(movies, numberOfMovies, year); // printing movies by year
                break;

            case 5:
                printf("Exiting...\n");
                exit(0); // exiting the program

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }

    return 0;
}