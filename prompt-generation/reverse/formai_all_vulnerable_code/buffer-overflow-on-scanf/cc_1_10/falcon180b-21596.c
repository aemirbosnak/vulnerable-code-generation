//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void generate_random_movie_ratings(Movie *movie, int num_ratings) {
    srand(time(NULL));
    for (int i = 0; i < num_ratings; i++) {
        int rating = rand() % 5 + 1;
        movie->ratings[i] = rating;
    }
    movie->num_ratings = num_ratings;
}

void print_movie_ratings(Movie *movie) {
    printf("Movie: %s\n", movie->title);
    printf("Ratings:\n");
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("  Rating %d: %d stars\n", i+1, movie->ratings[i]);
    }
    printf("\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        char title[100];
        printf("Enter a movie title: ");
        scanf("%s", title);

        int movie_index = -1;
        for (int i = 0; i < num_movies; i++) {
            if (strcmp(movies[i].title, title) == 0) {
                movie_index = i;
                break;
            }
        }

        if (movie_index == -1) {
            if (num_movies >= MAX_MOVIES) {
                printf("Error: Maximum number of movies reached.\n");
            } else {
                strcpy(movies[num_movies].title, title);
                generate_random_movie_ratings(&movies[num_movies], 0);
                num_movies++;
            }
        } else {
            int rating;
            printf("Enter a rating (1-5 stars): ");
            scanf("%d", &rating);

            movies[movie_index].ratings[movies[movie_index].num_ratings++] = rating;
        }
    }

    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie_ratings(&movies[i]);
    }

    return 0;
}