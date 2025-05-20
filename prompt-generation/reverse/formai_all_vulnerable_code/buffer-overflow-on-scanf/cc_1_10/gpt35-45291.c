//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>

// Struct for storing movie information
struct Movie {
    int id;
    char title[100];
    char genre[50];
    float rating;
};

// Function to print a movie's details
void printMovie(struct Movie movie) {
    printf("ID: %d\nTitle: %s\nGenre: %s\nRating: %.1f\n", movie.id, movie.title, movie.genre, movie.rating);
}

int main() {
    struct Movie movies[5];  // Array to store 5 movies
    
    // Getting movie details from user input
    for (int i = 0; i < 5; i++) {
        printf("Enter details for movie %d:\n", i + 1);
        movies[i].id = i + 1;
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
        printf("\n");
    }
    
    // Printing movie details
    printf("Details of all movies:\n\n");
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
        printf("\n");
    }
    
    // Finding highest rated movie
    float highestRating = 0;
    struct Movie highestRatedMovie;
    for (int i = 0; i < 5; i++) {
        if (movies[i].rating > highestRating) {
            highestRating = movies[i].rating;
            highestRatedMovie = movies[i];
        }
    }
    printf("The highest rated movie is:\n");
    printMovie(highestRatedMovie);
    
    return 0;
}