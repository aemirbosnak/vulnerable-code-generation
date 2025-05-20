//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Structure to store movie details
struct Movie {
    char title[50];
    int year;
    char director[50];
    int rating;
};

// Function to display movie details
void displayMovie(struct Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Year: %d\n", movie.year);
    printf("Director: %s\n", movie.director);
    printf("Rating: %d\n", movie.rating);
}

// Function to add a movie to the database
void addMovie(struct Movie *movie) {
    printf("Enter the title of the movie: ");
    scanf("%s", movie->title);
    printf("Enter the year of release: ");
    scanf("%d", &movie->year);
    printf("Enter the name of the director: ");
    scanf("%s", movie->director);
    printf("Enter the rating of the movie: ");
    scanf("%d", &movie->rating);
}

// Function to search for a movie in the database
struct Movie *searchMovie(struct Movie *movies, int n, char *title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return &movies[i];
        }
    }
    return NULL;
}

// Function to delete a movie from the database
void deleteMovie(struct Movie *movies, int n, char *title) {
    struct Movie *movie = searchMovie(movies, n, title);
    if (movie != NULL) {
        for (int i = 0; i < n; i++) {
            if (strcmp(movies[i].title, title) == 0) {
                for (int j = i; j < n - 1; j++) {
                    movies[j] = movies[j + 1];
                }
                break;
            }
        }
    }
}

// Function to update the rating of a movie in the database
void updateMovieRating(struct Movie *movies, int n, char *title, int rating) {
    struct Movie *movie = searchMovie(movies, n, title);
    if (movie != NULL) {
        movie->rating = rating;
    }
}

int main() {
    // Initialize the movie database
    struct Movie movies[100];
    int n = 0;

    // Add some movies to the database
    addMovie(&movies[n++]);
    addMovie(&movies[n++]);
    addMovie(&movies[n++]);

    // Search for a movie in the database
    struct Movie *movie = searchMovie(movies, n, "The Shawshank Redemption");
    if (movie != NULL) {
        displayMovie(*movie);
    } else {
        printf("Movie not found.\n");
    }

    // Delete a movie from the database
    deleteMovie(movies, n, "The Shawshank Redemption");
    n--;

    // Update the rating of a movie in the database
    updateMovieRating(movies, n, "The Dark Knight", 9);

    // Display the updated movie database
    for (int i = 0; i < n; i++) {
        displayMovie(movies[i]);
    }

    return 0;
}