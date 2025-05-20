//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>

// declare struct for movie details
struct Movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

// function to get user input for movie details
void inputMovieDetails(struct Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter movie director: ");
    scanf("%s", movie->director);
    printf("Enter movie year: ");
    scanf("%d", &movie->year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movie->rating);
}

// function to display movie details
void displayMovieDetails(struct Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year: %d\n", movie.year);
    printf("Rating: %.1f/10\n", movie.rating);
}

// function to get movie rating on a scale of 1 to 5
int getRating(struct Movie movie) {
    int rating = (int)(movie.rating / 2);
    printf("Enter your rating (1-5) for the movie \"%s\" directed by %s released in %d\n", movie.title, movie.director, movie.year);
    scanf("%d", &rating);
    return rating;
}

// function to display movie rating in stars
void displayRating(int rating) {
    printf("Rating: ");
    for (int i = 0; i < rating; i++) {
        printf("*");
    }
    printf("\n");
}

// main function
int main() {
    struct Movie movie1, movie2, movie3;

    printf("Enter details for movie 1:\n");
    inputMovieDetails(&movie1);
    printf("\n");

    printf("Enter details for movie 2:\n");
    inputMovieDetails(&movie2);
    printf("\n");

    printf("Enter details for movie 3:\n");
    inputMovieDetails(&movie3);
    printf("\n");

    printf("Displaying details for movie 1:\n");
    displayMovieDetails(movie1);
    printf("\n");

    printf("Displaying details for movie 2:\n");
    displayMovieDetails(movie2);
    printf("\n");

    printf("Displaying details for movie 3:\n");
    displayMovieDetails(movie3);
    printf("\n");

    int rating1 = getRating(movie1);
    printf("\n");
    displayRating(rating1);

    int rating2 = getRating(movie2);
    printf("\n");
    displayRating(rating2);

    int rating3 = getRating(movie3);
    printf("\n");
    displayRating(rating3);

    return 0;
}