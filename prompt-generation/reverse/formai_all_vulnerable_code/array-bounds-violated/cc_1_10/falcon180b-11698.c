//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5
#define MAX_USERS 10

typedef struct {
    char title[80];
    int year;
    char genre[20];
    int rating_count;
    double total_rating;
} Movie;

typedef struct {
    int user_id;
    int movie_id;
    int rating;
} Rating;

Movie movies[MAX_MOVIES];
Rating ratings[MAX_RATINGS];

int main() {
    srand(time(NULL));

    int num_movies = rand() % MAX_MOVIES + 1;
    for (int i = 0; i < num_movies; i++) {
        movies[i].rating_count = 0;
        movies[i].total_rating = 0;
        movies[i].title[0] = '\0';
        movies[i].year = rand() % 100 + 1900;
        movies[i].genre[0] = '\0';
    }

    int num_users = rand() % MAX_USERS + 1;
    for (int i = 0; i < num_users; i++) {
        int num_ratings = rand() % MAX_RATINGS + 1;
        for (int j = 0; j < num_ratings; j++) {
            int movie_id = rand() % num_movies;
            ratings[i * MAX_RATINGS + j].movie_id = movie_id;
            ratings[i * MAX_RATINGS + j].user_id = i;
            int rating = rand() % 6;
            ratings[i * MAX_RATINGS + j].rating = rating;
            movies[movie_id].rating_count++;
            movies[movie_id].total_rating += rating;
        }
    }

    printf("Movie Ratings\n");
    printf("=============\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (%d)\n", i + 1, movies[i].title, movies[i].year);
        printf("  Genre: %s\n", movies[i].genre);
        printf("  Average Rating: %.1f\n", movies[i].total_rating / movies[i].rating_count);
        printf("  Number of Ratings: %d\n\n", movies[i].rating_count);
    }

    return 0;
}