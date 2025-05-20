//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// struct for movies
typedef struct movie {
    char title[50];
    char genre[20];
    int rating;
} movie;

// function to get user input for movie details
void getMovieDetails(movie* m) {
    printf("Enter Movie Title: ");
    scanf("%s", m->title);
    printf("Enter Movie Genre: ");
    scanf("%s", m->genre);
    printf("Enter Movie Rating (0-10): ");
    scanf("%d", &m->rating);
}

// function to display all movies
void displayAllMovies(movie* movies, int count) {
    printf("Title\t\tGenre\t\tRating\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

// main function
int main() {
    // declare and initialize variables
    int count = 0;
    movie* movies = (movie*) malloc(sizeof(movie));

    // while loop to keep getting user input for movies
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {
        // get movie details from user input
        getMovieDetails(&movies[count]);
        // increase count and allocate more memory for possible more movies
        count++;
        movies = (movie*) realloc(movies, (count + 1) * sizeof(movie));
        // ask user if they want to input another movie
        printf("Do you want to input another movie? (Y/N): ");
        scanf("%s", &choice);
    }

    // display all movies using displayAllMovies function
    displayAllMovies(movies, count);

    // free allocated memory
    free(movies);

    return 0;
}