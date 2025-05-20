//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MOVIE_MAX_TITLE_LEN 100
#define MOVIE_MAX_REVIEW_LEN 1000

typedef struct movie {
    char title[MOVIE_MAX_TITLE_LEN];
    char review[MOVIE_MAX_REVIEW_LEN];
    int rating;
} movie_t;

int main() {
    // Create an array of movies
    movie_t movies[] = {
        { "The Shawshank Redemption", "A heartwarming story about a man who finds hope in a prison." },
        { "The Godfather", "A classic film about a powerful family." },
        { "The Dark Knight", "A thrilling film about a superhero." },
        { "12 Angry Men", "A courtroom drama about a jury trying to reach a verdict." },
        { "Schindler's List", "A powerful film about the Holocaust." },
        { "Pulp Fiction", "A quirky film about a group of criminals." },
        { "Fight Club", "A thought-provoking film about a man who starts a fight club." },
        { "The Matrix", "A sci-fi film about a computer-generated world." },
        { "The Lord of the Rings: The Return of the King", "A fantasy film about a group of hobbits who journey to destroy an evil ring." },
        { "Inception", "A mind-bending film about a man who enters people's dreams." }
    };

    // Get the number of movies in the array
    int num_movies = sizeof(movies) / sizeof(movie_t);

    // Get the user's input
    int rating;
    char title[MOVIE_MAX_TITLE_LEN];
    printf("Enter the title of the movie you want to rate: ");
    scanf("%s", title);
    printf("Enter the rating (1-5): ");
    scanf("%d", &rating);

    // Find the movie in the array
    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            found = 1;
            movies[i].rating = rating;
            break;
        }
    }

    // If the movie was found, print the new rating
    if (found) {
        printf("The new rating for %s is %d.\n", title, rating);
    } else {
        printf("Movie not found.\n");
    }

    return 0;
}