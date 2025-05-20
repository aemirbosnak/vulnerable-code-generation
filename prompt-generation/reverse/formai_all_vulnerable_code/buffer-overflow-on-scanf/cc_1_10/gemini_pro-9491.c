//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 128
#define MAX_MOVIES 100

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17,
    UNRATED
} Rating;

// Define the movie struct
typedef struct {
    char title[MAX_TITLE_LEN];
    Rating rating;
} Movie;

// Function to print the movie rating system
void print_rating_system() {
    printf("Movie Rating System:\n");
    printf("G: General Audiences\n");
    printf("PG: Parental Guidance Suggested\n");
    printf("PG13: Parents Strongly Cautioned\n");
    printf("R: Restricted\n");
    printf("NC17: No One 17 and Under Admitted\n");
    printf("UNRATED: Not Rated\n");
}

// Function to get the movie rating from the user
Rating get_rating() {
    char rating_str[10];

    // Get the rating from the user
    printf("Enter the movie rating (G, PG, PG13, R, NC17, UNRATED): ");
    scanf("%s", rating_str);

    // Convert the rating to uppercase
    for (int i = 0; i < strlen(rating_str); i++) {
        rating_str[i] = toupper(rating_str[i]);
    }

    // Return the rating
    if (strcmp(rating_str, "G") == 0) {
        return G;
    } else if (strcmp(rating_str, "PG") == 0) {
        return PG;
    } else if (strcmp(rating_str, "PG13") == 0) {
        return PG13;
    } else if (strcmp(rating_str, "R") == 0) {
        return R;
    } else if (strcmp(rating_str, "NC17") == 0) {
        return NC17;
    } else {
        return UNRATED;
    }
}

// Function to get the movie title from the user
void get_title(char *title) {
    // Get the title from the user
    printf("Enter the movie title: ");
    scanf("%s", title);
}

// Function to add a movie to the array
void add_movie(Movie *movies, int *num_movies) {
    // Get the movie title
    char title[MAX_TITLE_LEN];
    get_title(title);

    // Get the movie rating
    Rating rating = get_rating();

    // Add the movie to the array
    movies[*num_movies].rating = rating;
    strcpy(movies[*num_movies].title, title);

    // Increment the number of movies
    (*num_movies)++;
}

// Function to print the movies in the array
void print_movies(Movie *movies, int num_movies) {
    // Print the movies
    for (int i = 0; i < num_movies; i++) {
        printf("%s (%s)\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    // Print the movie rating system
    print_rating_system();

    // Create an array of movies
    Movie movies[MAX_MOVIES];

    // Initialize the number of movies
    int num_movies = 0;

    // Add movies to the array
    add_movie(movies, &num_movies);
    add_movie(movies, &num_movies);
    add_movie(movies, &num_movies);

    // Print the movies
    print_movies(movies, num_movies);

    return 0;
}