//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: rigorous
// movie_rating_system.c

#include <stdio.h>

// define a struct to store movie information
typedef struct {
    char title[50];
    int year;
    int rating;
} movie_t;

// define a function to display a movie
void display_movie(movie_t *movie) {
    printf("%s (%d) - %d\n", movie->title, movie->year, movie->rating);
}

// define a function to rate a movie
void rate_movie(movie_t *movie) {
    printf("Enter rating for %s (1-5): ", movie->title);
    scanf("%d", &movie->rating);
}

// define a function to search for a movie
movie_t *search_movie(movie_t *movies, int n, char *title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return &movies[i];
        }
    }
    return NULL;
}

int main() {
    movie_t movies[5] = {
        {"The Shawshank Redemption", 1994, 0},
        {"The Godfather", 1972, 0},
        {"The Godfather: Part II", 1974, 0},
        {"The Dark Knight", 2008, 0},
        {"12 Angry Men", 1957, 0}
    };

    int n = sizeof(movies) / sizeof(movie_t);

    // display all movies
    for (int i = 0; i < n; i++) {
        display_movie(&movies[i]);
    }

    // rate a movie
    movie_t *movie = search_movie(movies, n, "The Godfather");
    rate_movie(movie);

    // display all movies again
    for (int i = 0; i < n; i++) {
        display_movie(&movies[i]);
    }

    return 0;
}