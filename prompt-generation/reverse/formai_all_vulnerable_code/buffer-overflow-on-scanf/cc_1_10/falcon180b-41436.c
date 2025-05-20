//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct {
    char title[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_rating(Movie* movie, int rating) {
    if (movie->num_ratings < MAX_RATINGS) {
        movie->ratings[movie->num_ratings++] = rating;
    }
}

int calculate_average(Movie* movie) {
    int sum = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        sum += movie->ratings[i];
    }
    return sum / movie->num_ratings;
}

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Average rating: %d\n", calculate_average(movie));
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    char input[100];
    while (1) {
        printf("Enter a movie title (or type 'quit' to exit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        if (num_movies >= MAX_MOVIES) {
            printf("Maximum number of movies reached.\n");
            continue;
        }
        strcpy(movies[num_movies].title, input);
        num_movies++;
    }

    while (1) {
        printf("Enter a movie title to rate (or type 'quit' to exit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        int movie_index = -1;
        for (int i = 0; i < num_movies; i++) {
            if (strcmp(movies[i].title, input) == 0) {
                movie_index = i;
                break;
            }
        }
        if (movie_index == -1) {
            printf("Movie not found.\n");
            continue;
        }
        printf("Enter a rating (1-5): ");
        scanf("%d", &movies[movie_index].ratings[movies[movie_index].num_ratings++]);
    }

    printf("Movie ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}