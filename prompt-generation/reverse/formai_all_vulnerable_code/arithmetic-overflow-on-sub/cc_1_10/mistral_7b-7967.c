//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[50];
    double ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void read_movie(Movie* movie, char* title) {
    strcpy(movie->title, title);
    movie->num_ratings = 0;
}

void add_rating(Movie* movie, double rating) {
    if (movie->num_ratings < MAX_RATINGS) {
        movie->ratings[movie->num_ratings] = rating;
        movie->num_ratings++;
    }
}

double average_rating(Movie movie) {
    double sum = 0;
    int i;

    for (i = 0; i < movie.num_ratings; i++) {
        sum += movie.ratings[i];
    }

    return sum / movie.num_ratings;
}

void print_movie(Movie movie) {
    double avg_rating = average_rating(movie);

    printf("%s: %.2f\n", movie.title, avg_rating);
}

int main() {
    Movie movies[MAX_MOVIES];
    char titles[MAX_MOVIES][50];
    int num_movies = 0;

    while (1) {
        printf("Enter movie title (or 'quit' to exit): ");
        scanf("%s", titles[num_movies]);

        if (strcmp(titles[num_movies], "quit") == 0) {
            break;
        }

        read_movie(&movies[num_movies], titles[num_movies]);

        num_movies++;

        printf("Enter ratings for the movie (%d max): ", MAX_RATINGS - movies[num_movies].num_ratings);

        while (movies[num_movies].num_ratings < MAX_RATINGS) {
            double rating;
            scanf("%lf", &rating);
            add_rating(&movies[num_movies], rating);

            printf("Enter another rating? (y/n): ");
            char input;
            scanf("%c", &input);

            if (input != 'y') {
                break;
            }
        }
    }

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}