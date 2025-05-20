//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    int release_year;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, int release_year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->rating = rating;
    movie->release_year = release_year;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G\n");
            break;
        case PG:
            printf("PG\n");
            break;
        case PG13:
            printf("PG-13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC17:
            printf("NC-17\n");
            break;
    }
    printf("Release year: %d\n", movie->release_year);
}

// Get the user's age
int get_user_age() {
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    return age;
}

// Check if the movie is appropriate for the user
int is_movie_appropriate(Movie *movie, int user_age) {
    if (user_age < 13) {
        return movie->rating == G || movie->rating == PG;
    } else if (user_age < 17) {
        return movie->rating == G || movie->rating == PG || movie->rating == PG13;
    } else {
        return 1;
    }
}

// Main function
int main() {
    // Create a few movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", PG13, 1994),
        create_movie("The Godfather", R, 1972),
        create_movie("The Dark Knight", PG13, 2008),
        create_movie("Schindler's List", R, 1993),
        create_movie("Pulp Fiction", R, 1994)
    };

    // Get the user's age
    int user_age = get_user_age();

    // Print the movies that are appropriate for the user
    for (int i = 0; i < 5; i++) {
        if (is_movie_appropriate(movies[i], user_age)) {
            print_movie(movies[i]);
            printf("\n");
        }
    }

    return 0;
}