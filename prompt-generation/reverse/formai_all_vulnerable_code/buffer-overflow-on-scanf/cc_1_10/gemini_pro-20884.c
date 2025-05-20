//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_CHARACTERS 255

struct Movie {
    char title[MAX_CHARACTERS];
    int year;
    int rating;
};

struct MovieDatabase {
    struct Movie movies[MAX_MOVIES];
    int numMovies;
};

int main() {
    // Create a movie database
    struct MovieDatabase database;
    database.numMovies = 0;

    // Initialize the database with some movies
    struct Movie movie1 = {"The Shawshank Redemption", 1994, 9.3};
    struct Movie movie2 = {"The Godfather", 1972, 9.2};
    struct Movie movie3 = {"The Dark Knight", 2008, 9.0};
    struct Movie movie4 = {"12 Angry Men", 1957, 9.0};
    struct Movie movie5 = {"Schindler's List", 1993, 8.9};

    database.movies[database.numMovies++] = movie1;
    database.movies[database.numMovies++] = movie2;
    database.movies[database.numMovies++] = movie3;
    database.movies[database.numMovies++] = movie4;
    database.movies[database.numMovies++] = movie5;

    // Get the user's input
    char input[MAX_CHARACTERS];
    printf("Enter a movie title or 'quit' to exit: ");
    scanf("%s", input);

    // Loop until the user enters 'quit'
    while (strcmp(input, "quit") != 0) {
        // Find the movie in the database
        int found = 0;
        for (int i = 0; i < database.numMovies; i++) {
            if (strcmp(input, database.movies[i].title) == 0) {
                found = 1;
                printf("Title: %s\n", database.movies[i].title);
                printf("Year: %d\n", database.movies[i].year);
                printf("Rating: %.1f\n", database.movies[i].rating);
                break;
            }
        }

        // If the movie was not found, print an error message
        if (!found) {
            printf("Movie not found.\n");
        }

        // Get the next movie title from the user
        printf("Enter a movie title or 'quit' to exit: ");
        scanf("%s", input);
    }

    return 0;
}