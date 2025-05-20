//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_MOVIES 5
#define NUM_RATINGS 5

typedef struct {
    char title[50];
    int ratings[NUM_RATINGS];
    float avg_rating;
    int num_votes;
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Average Rating: %.2f\n", movie->avg_rating);
    printf("Number of Votes: %d\n", movie->num_votes);
}

void print_movies(Movie* movies, int num_movies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }
}

void sort_movies(Movie* movies, int num_movies) {
    for (int i = 0; i < num_movies - 1; i++) {
        for (int j = i + 1; j < num_movies; j++) {
            if (movies[i].avg_rating < movies[j].avg_rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

void read_movie_ratings(Movie* movies, int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("Enter the ratings for movie %d (1-10):\n", i+1);
        for (int j = 0; j < NUM_RATINGS; j++) {
            if (scanf("%d", &movies[i].ratings[j])!= 1) {
                printf("Invalid input. Please enter a number between 1 and 10.\n");
                j--;
            }
        }
        movies[i].num_votes = NUM_RATINGS;
        movies[i].avg_rating = 0;
        for (int j = 0; j < NUM_RATINGS; j++) {
            movies[i].avg_rating += movies[i].ratings[j];
        }
        movies[i].avg_rating /= NUM_RATINGS;
    }
}

int main() {
    Movie movies[NUM_MOVIES];
    char title[50];
    printf("Enter the titles of the movies:\n");
    for (int i = 0; i < NUM_MOVIES; i++) {
        scanf("%s", movies[i].title);
    }
    read_movie_ratings(movies, NUM_MOVIES);
    sort_movies(movies, NUM_MOVIES);
    print_movies(movies, NUM_MOVIES);
    return 0;
}