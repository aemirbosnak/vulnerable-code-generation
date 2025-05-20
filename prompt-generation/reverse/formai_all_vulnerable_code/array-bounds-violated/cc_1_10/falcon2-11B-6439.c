//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

struct movie {
    char title[50];
    float rating;
    int ratings[MAX_RATINGS];
    int num_ratings;
};

int main(int argc, char *argv[]) {
    int num_movies = 0;
    int num_ratings = 0;
    struct movie movies[MAX_MOVIES];
    int num_movies_read = 0;
    int num_ratings_read = 0;
    int movie_index = 0;
    int rating_index = 0;
    int rating;

    while (scanf("%d %d", &num_movies, &num_ratings)!= EOF) {
        num_movies_read += num_movies;
        num_ratings_read += num_ratings;

        for (int i = 0; i < num_movies; i++) {
            movies[i].num_ratings = 0;
            memset(movies[i].ratings, 0, sizeof(int) * MAX_RATINGS);
            scanf("%s", movies[i].title);
            printf("Enter rating for %s (1-5): ", movies[i].title);
            scanf("%f", &movies[i].rating);
            for (int j = 0; j < num_ratings; j++) {
                scanf("%d", &rating_index);
                movies[i].ratings[rating_index]++;
            }
            movies[i].num_ratings++;
        }

        for (int i = 0; i < num_movies_read; i++) {
            for (int j = 0; j < num_ratings_read; j++) {
                printf("Movie %d: %s - Rating: %0.2f (%.2f) - Ratings: %d\n",
                       movie_index, movies[movie_index].title, movies[movie_index].rating,
                       movies[movie_index].rating / movies[movie_index].num_ratings,
                       movies[movie_index].num_ratings);
                movie_index++;
            }
        }

        printf("\n");
    }

    return 0;
}