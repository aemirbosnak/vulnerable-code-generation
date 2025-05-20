//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: detailed
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

// Define a structure to represent a movie
typedef struct {
    char *title;
    int year;
    Rating rating;
} Movie;

// Create a function to print the movie rating system
void print_rating_system() {
    printf("Movie Rating System:\n");
    printf("G: General audiences\n");
    printf("PG: Parental guidance suggested\n");
    printf("PG13: Parents strongly cautioned\n");
    printf("R: Restricted\n");
    printf("NC17: No one 17 and under admitted\n");
}

// Create a function to print a movie
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Year: %d\n", movie->year);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G\n");
            break;
        case PG:
            printf("PG\n");
            break;
        case PG13:
            printf("PG13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC17:
            printf("NC17\n");
            break;
    }
}

// Create a function to get the user's input for a movie
Movie *get_movie_input() {
    Movie *movie = malloc(sizeof(Movie));
    char *title = malloc(100);
    int year;
    Rating rating;

    printf("Enter the movie title: ");
    scanf("%s", title);
    movie->title = title;

    printf("Enter the movie year: ");
    scanf("%d", &year);
    movie->year = year;

    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    char rating_str[4];
    scanf("%s", rating_str);
    if (strcmp(rating_str, "G") == 0) {
        rating = G;
    } else if (strcmp(rating_str, "PG") == 0) {
        rating = PG;
    } else if (strcmp(rating_str, "PG13") == 0) {
        rating = PG13;
    } else if (strcmp(rating_str, "R") == 0) {
        rating = R;
    } else if (strcmp(rating_str, "NC17") == 0) {
        rating = NC17;
    } else {
        printf("Invalid rating. Please enter a valid rating (G, PG, PG13, R, NC17).");
        exit(1);
    }
    movie->rating = rating;

    return movie;
}

// Create a function to main
int main() {
    // Print the movie rating system
    print_rating_system();

    // Get the user's input for a movie
    Movie *movie = get_movie_input();

    // Print the movie
    print_movie(movie);

    return 0;
}