//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_REVIEWS 5

typedef struct {
    char title[50];
    float rating[MAX_REVIEWS];
    int num_reviews;
} Movie;

void read_movie(Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);

    printf("This movie has %d reviews maximum. Enter %d reviews:\n", MAX_REVIEWS, MAX_REVIEWS);
    for (int i = 0; i < MAX_REVIEWS; i++) {
        printf("Review %d: ", i + 1);
        scanf("%f", &(movie->rating[i]));
    }

    movie->num_reviews = MAX_REVIEWS;
}

void print_movie(const Movie *movie) {
    printf("\nTitle: %s\n", movie->title);
    printf("Ratings:\n");
    for (int i = 0; i < movie->num_reviews; i++) {
        printf("- Review %d: %.2f\n", i + 1, movie->rating[i]);
    }
    printf("Average rating: %.2f\n", movie->rating[0]);
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        Movie *current_movie = &(movies[num_movies]);
        read_movie(current_movie);

        num_movies++;

        if (num_movies % 5 == 0) {
            printf("\n-------------------------------------\n");
            printf("Top 5 movies with highest average rating:\n");

            Movie top_movies[5];
            int top_index = 0;
            float max_rating = -1;

            for (int i = 0; i < num_movies; i++) {
                Movie *movie = &(movies[i]);

                float sum_rating = 0;
                for (int j = 0; j < movie->num_reviews; j++) {
                    sum_rating += movie->rating[j];
                }

                movie->rating[0] = sum_rating / movie->num_reviews;

                if (movie->rating[0] > max_rating && top_index < 5) {
                    top_index++;
                    memcpy(top_movies + top_index, movie, sizeof(Movie));
                    max_rating = movie->rating[0];
                }
            }

            for (int i = 0; i < 5 && i < top_index; i++) {
                print_movie(top_movies + i);
            }
        }
    }

    return 0;
}