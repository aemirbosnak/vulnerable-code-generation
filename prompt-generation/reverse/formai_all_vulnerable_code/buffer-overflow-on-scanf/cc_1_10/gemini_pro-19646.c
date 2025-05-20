//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the movie structure
typedef struct {
    char *title;
    Rating rating;
    int release_year;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, int release_year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    movie->release_year = release_year;
    return movie;
}

// Free a movie
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Print a movie
void print_movie(Movie *movie) {
    printf("%s (%d) - %s\n", movie->title, movie->release_year, movie->rating == G ? "G" : movie->rating == PG ? "PG" : movie->rating == PG13 ? "PG-13" : movie->rating == R ? "R" : "NC-17");
}

// Compare two movies by title
int compare_movies_by_title(const void *a, const void *b) {
    Movie *movie1 = *(Movie **)a;
    Movie *movie2 = *(Movie **)b;
    return strcmp(movie1->title, movie2->title);
}

// Compare two movies by rating
int compare_movies_by_rating(const void *a, const void *b) {
    Movie *movie1 = *(Movie **)a;
    Movie *movie2 = *(Movie **)b;
    return movie1->rating - movie2->rating;
}

// Compare two movies by release year
int compare_movies_by_release_year(const void *a, const void *b) {
    Movie *movie1 = *(Movie **)a;
    Movie *movie2 = *(Movie **)b;
    return movie1->release_year - movie2->release_year;
}

// Get the user's input
void get_user_input(char *input) {
    printf("Enter a movie title, rating, and release year (e.g., The Shawshank Redemption, PG-13, 1994): ");
    fgets(input, 256, stdin);
}

// Parse the user's input
Movie *parse_user_input(char *input) {
    char *title, *rating, *release_year;
    title = strtok(input, ",");
    rating = strtok(NULL, ",");
    release_year = strtok(NULL, ",");
    return create_movie(title, rating == strcasestr(rating, "G") ? G : rating == strcasestr(rating, "PG") ? PG : rating == strcasestr(rating, "PG-13") ? PG13 : rating == strcasestr(rating, "R") ? R : NC17, atoi(release_year));
}

// Get the number of movies from the user
int get_number_of_movies() {
    int number_of_movies;
    printf("Enter the number of movies you want to add: ");
    scanf("%d", &number_of_movies);
    return number_of_movies;
}

// Create an array of movies
Movie **create_movie_array(int number_of_movies) {
    Movie **movies = malloc(sizeof(Movie *) * number_of_movies);
    return movies;
}

// Add a movie to the array
void add_movie_to_array(Movie **movies, Movie *movie, int index) {
    movies[index] = movie;
}

// Print the array of movies
void print_movie_array(Movie **movies, int number_of_movies) {
    for (int i = 0; i < number_of_movies; i++) {
        print_movie(movies[i]);
    }
}

// Sort the array of movies by title
void sort_movies_by_title(Movie **movies, int number_of_movies) {
    qsort(movies, number_of_movies, sizeof(Movie *), compare_movies_by_title);
}

// Sort the array of movies by rating
void sort_movies_by_rating(Movie **movies, int number_of_movies) {
    qsort(movies, number_of_movies, sizeof(Movie *), compare_movies_by_rating);
}

// Sort the array of movies by release year
void sort_movies_by_release_year(Movie **movies, int number_of_movies) {
    qsort(movies, number_of_movies, sizeof(Movie *), compare_movies_by_release_year);
}

// Get the user's choice
int get_user_choice() {
    int choice;
    printf("Enter your choice (1 to print movies, 2 to sort movies by title, 3 to sort movies by rating, 4 to sort movies by release year, 5 to exit): ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    // Get the number of movies from the user
    int number_of_movies = get_number_of_movies();

    // Create an array of movies
    Movie **movies = create_movie_array(number_of_movies);

    // Add movies to the array
    for (int i = 0; i < number_of_movies; i++) {
        char input[256];
        get_user_input(input);
        Movie *movie = parse_user_input(input);
        add_movie_to_array(movies, movie, i);
    }

    // Print the array of movies
    print_movie_array(movies, number_of_movies);

    // Get the user's choice
    int choice;
    while ((choice = get_user_choice()) != 5) {
        switch (choice) {
            case 1:
                // Print the array of movies
                print_movie_array(movies, number_of_movies);
                break;
            case 2:
                // Sort the array of movies by title
                sort_movies_by_title(movies, number_of_movies);
                break;
            case 3:
                // Sort the array of movies by rating
                sort_movies_by_rating(movies, number_of_movies);
                break;
            case 4:
                // Sort the array of movies by release year
                sort_movies_by_release_year(movies, number_of_movies);
                break;
        }
    }

    // Free the array of movies
    for (int i = 0; i < number_of_movies; i++) {
        free_movie(movies[i]);
    }
    free(movies);

    return 0;
}