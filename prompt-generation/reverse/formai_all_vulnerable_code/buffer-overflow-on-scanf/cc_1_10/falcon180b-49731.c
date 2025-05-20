//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 100

typedef struct {
    char title[50];
    int rating;
} Movie;

void generate_movies(Movie* movies, int num_movies) {
    srand(time(NULL));
    for (int i = 0; i < num_movies; i++) {
        sprintf(movies[i].title, "Movie %d", i + 1);
        movies[i].rating = rand() % 101; // Generate a random rating between 0 and 100
    }
}

void input_ratings(Movie* movies, int num_movies, int num_ratings) {
    for (int i = 0; i < num_ratings; i++) {
        printf("Enter the title of the movie you want to rate: ");
        scanf("%s", movies[i].title);
        printf("Enter the rating (0-100): ");
        scanf("%d", &movies[i].rating);
    }
}

void calculate_average_rating(Movie* movies, int num_movies) {
    int total_rating = 0;
    for (int i = 0; i < num_movies; i++) {
        total_rating += movies[i].rating;
    }
    printf("Average rating: %.2f\n", (float)total_rating / num_movies);
}

void sort_movies_by_rating(Movie* movies, int num_movies) {
    for (int i = 0; i < num_movies - 1; i++) {
        for (int j = i + 1; j < num_movies; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

void print_movies(Movie* movies, int num_movies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int num_ratings = 0;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    printf("Enter the number of ratings: ");
    scanf("%d", &num_ratings);

    generate_movies(movies, num_movies);
    input_ratings(movies, num_movies, num_ratings);
    calculate_average_rating(movies, num_movies);
    sort_movies_by_rating(movies, num_movies);
    print_movies(movies, num_movies);

    return 0;
}