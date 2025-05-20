//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_RATING 1
#define MAX_RATING 5

typedef struct {
    char title[50];
    int rating;
} Movie;

void printMovie(Movie movie) {
    printf("%s: %d\n", movie.title, movie.rating);
}

int main() {
    Movie movies[] = {
        {"The Shawshank Redemption", 5},
        {"The Godfather", 5},
        {"The Dark Knight", 5},
        {"12 Angry Men", 5},
        {"Schindler's List", 5},
        {"Pulp Fiction", 5},
        {"Forrest Gump", 5},
        {"The Matrix", 5},
        {"Goodfellas", 5},
        {"Raging Bull", 5}
    };

    int numMovies = sizeof(movies) / sizeof(Movie);

    printf("These are the movies in our database:\n");
    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
    }

    printf("\nWhat movie would you like to rate? ");
    char title[50];
    scanf("%s", title);

    Movie* movie = NULL;
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(title, movies[i].title) == 0) {
            movie = &movies[i];
            break;
        }
    }

    if (movie == NULL) {
        printf("That movie is not in our database.\n");
        return 1;
    }

    printf("What rating would you like to give %s? ", movie->title);
    int rating;
    scanf("%d", &rating);

    if (rating < MIN_RATING || rating > MAX_RATING) {
        printf("Invalid rating. Please enter a rating between 1 and 5.\n");
        return 1;
    }

    movie->rating = rating;

    printf("Thank you for rating %s. Your rating has been saved.\n", movie->title);

    return 0;
}