//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>

// Struct to store details of a movie
struct movie {
    char title[50]; // Stores movie title
    char director[50]; // Stores director's name
    int release_year; // Stores release year of the movie
    float rating; // Stores the overall rating of the movie
};

// Function to get input from user and store it in movie struct
void get_movie_details(struct movie *m) {
    printf("Enter the title of the movie: ");
    scanf("%s", m->title);
    fflush(stdin);

    printf("Enter the director of the movie: ");
    scanf("%s", m->director);
    fflush(stdin);

    printf("Enter the release year of the movie: ");
    scanf("%d", &m->release_year);

    printf("Enter the overall rating of the movie (out of 10): ");
    scanf("%f", &m->rating);
}

// Function to display details of a movie
void display_movie(struct movie m) {
    printf("\nTitle: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Release Year: %d\n", m.release_year);
    printf("Overall Rating: %.1f/10\n", m.rating);
}

int main() {
    // Declare array of 10 movies
    struct movie movies[10];

    // Get details of 10 movies from user
    for (int i = 0; i < 10; i++) {
        printf("\nEnter details of Movie %d\n", i+1);
        get_movie_details(&movies[i]);
    }

    // Display details of movies with rating >= 8
    printf("\n\nMovies with overall rating of 8 or above:\n");
    for (int i = 0; i < 10; i++) {
        if (movies[i].rating >= 8) {
            display_movie(movies[i]);
        }
    }

    return 0;
}