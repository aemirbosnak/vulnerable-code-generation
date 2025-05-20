//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct Movie {
    char title[256];
    int year;
    float rating;
} Movie;

int main() {
    Movie movies[10] = {
        {"The Shawshank Redemption", 1994, 9.3},
        {"The Godfather Part II", 1974, 9.2},
        {"The Dark Knight Rises", 2008, 8.8},
        {"The Matrix Reloaded", 2003, 8.6},
        {"Spider-Man", 2002, 8.3},
        {"Avengers: Endgame", 2019, 8.2},
        {"Batman Begins", 2005, 8.1},
        {"Iron Man", 2008, 8.0},
        {"The Matrix", 1999, 8.0},
        {"Back to the Future", 1985, 7.8}
    };

    int num_movies = 10;

    // Create a futuristic movie rating system
    printf("Welcome to the Future of Film Reviews!\n");
    printf("Please select a movie from the list below:\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (%.1f)\n", i + 1, movies[i].title, movies[i].rating);
    }

    int movie_choice = 0;

    printf("Enter your choice: ");
    scanf("%d", &movie_choice);

    if (movie_choice > num_movies || movie_choice <= 0) {
        printf("Invalid choice.\n");
    } else {
        Movie chosen_movie = movies[movie_choice - 1];

        printf("Movie Title: %s\n", chosen_movie.title);
        printf("Year: %d\n", chosen_movie.year);
        printf("Rating: %.1f\n", chosen_movie.rating);

        printf("Please rate the movie on a scale of 1-10: ");
        int rating = 0;

        scanf("%d", &rating);

        if (rating > 10 || rating <= 0) {
            printf("Invalid rating.\n");
        } else {
            chosen_movie.rating = rating;

            printf("Thank you for your review!\n");

            printf("Updated Movie Rating:\n");
            printf("%s (%.1f)\n", chosen_movie.title, chosen_movie.rating);
        }
    }

    return 0;
}