//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAX_MOVIES 100
#define MIN_RATING 0
#define MAX_RATING 10

typedef struct {
    char title[50];
    int rating;
} Movie;

void add_movie(Movie movies[], int *num_movies, const char *title, int rating) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Error: maximum number of movies reached.\n");
        return;
    }
    strcpy(movies[*num_movies].title, title);
    movies[*num_movies].rating = rating;
    (*num_movies)++;
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    add_movie(movies, &num_movies, "The Shawshank Redemption", 9);
    add_movie(movies, &num_movies, "The Godfather", 10);
    add_movie(movies, &num_movies, "The Dark Knight", 9);
    add_movie(movies, &num_movies, "12 Angry Men", 8);
    add_movie(movies, &num_movies, "Schindler's List", 9);

    printf("Movie Rating System\n");
    printf("--------------------\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s - %d\n", i + 1, movies[i].title, movies[i].rating);
    }

    int user_rating;
    char user_title[50];

    printf("\nPlease enter the title of the movie you want to rate: ");
    scanf("%s", user_title);

    printf("Please enter the rating (from 0 to 10): ");
    scanf("%d", &user_rating);

    if (user_rating < MIN_RATING || user_rating > MAX_RATING) {
        printf("Error: rating must be between 0 and 10.\n");
        return 1;
    }

    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, user_title) == 0) {
            movies[i].rating += user_rating;
            printf("Movie %s rating updated to %d.\n", user_title, movies[i].rating);
            break;
        }
    }

    return 0;
}