//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a structure to store the movie information
typedef struct movie {
    char title[50];
    int year;
    char genre[20];
    float rating;
} Movie;

// Create an array of movies
Movie movies[] = {
    {"The Shawshank Redemption", 1994, "Drama", 9.3},
    {"The Godfather", 1972, "Crime", 9.2},
    {"The Dark Knight", 2008, "Action", 9.0},
    {"12 Angry Men", 1957, "Drama", 9.0},
    {"Schindler's List", 1993, "Drama", 8.9},
    {"The Lord of the Rings: The Return of the King", 2003, "Fantasy", 8.9},
    {"Pulp Fiction", 1994, "Crime", 8.9},
    {"Forrest Gump", 1994, "Drama", 8.8},
    {"The Matrix", 1999, "Sci-Fi", 8.7},
    {"Goodfellas", 1990, "Crime", 8.7}
};

// Create a function to print the movie information
void printMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Year: %d\n", movie.year);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %.1f\n\n", movie.rating);
}

// Create a function to compare two movies
int compareMovies(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;

    return strcmp(movie1->title, movie2->title);
}

// Create a function to get the user's input
int getRating() {
    int rating;

    printf("Enter a rating (1-5): ");
    scanf("%d", &rating);

    return rating;
}

// Create a function to print the movie ratings
void printRatings() {
    int i;

    printf("Movie Ratings:\n");
    for (i = 0; i < 10; i++) {
        printf("%s: %.1f\n", movies[i].title, movies[i].rating);
    }
}

// Main function
int main() {
    int i;
    int rating;

    // Sort the movies by title
    qsort(movies, 10, sizeof(Movie), compareMovies);

    // Print the movie information
    for (i = 0; i < 10; i++) {
        printMovie(movies[i]);
    }

    // Get the user's input
    rating = getRating();

    // Print the movie ratings
    printRatings();

    return 0;
}