//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000
#define NUM_THREADS 4

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void *thread_func(void *arg) {
    int i, j, rating;
    Movie *movies = (Movie *) arg;

    for (i = 0; i < MAX_RATINGS; i++) {
        rating = rand() % 5;
        movies[i].ratings[i] = rating;
        movies[i].num_ratings++;
    }

    return NULL;
}

int main() {
    int i, j, num_movies;
    Movie movies[MAX_MOVIES];
    pthread_t threads[NUM_THREADS];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movies[i].title);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &movies[i*MAX_RATINGS/NUM_THREADS]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_movies; i++) {
        printf("Movie %s has an average rating of %.1f\n", movies[i].title, (float)movies[i].num_ratings/MAX_RATINGS);
    }

    return 0;
}