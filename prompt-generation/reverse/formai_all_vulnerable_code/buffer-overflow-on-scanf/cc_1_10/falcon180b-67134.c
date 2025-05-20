//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 100

typedef struct {
    char title[50];
    float rating;
} movie_t;

pthread_mutex_t movie_mutex = PTHREAD_MUTEX_INITIALIZER;
movie_t movies[MAX_MOVIES];
int num_movies = 0;

void add_movie(char* title, float rating) {
    pthread_mutex_lock(&movie_mutex);
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating += rating;
            pthread_mutex_unlock(&movie_mutex);
            return;
        }
    }
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, "") == 0) {
            strcpy(movies[i].title, title);
            movies[i].rating = rating;
            num_movies++;
            pthread_mutex_unlock(&movie_mutex);
            return;
        }
    }
    pthread_mutex_unlock(&movie_mutex);
}

void print_movies() {
    pthread_mutex_lock(&movie_mutex);
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %.2f\n", movies[i].title, movies[i].rating);
    }
    pthread_mutex_unlock(&movie_mutex);
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, (void*)print_movies, NULL);
    while (1) {
        char title[50];
        float rating;
        printf("Enter movie title: ");
        scanf("%s", title);
        printf("Enter movie rating: ");
        scanf("%f", &rating);
        add_movie(title, rating);
        sleep(1);
    }
    return 0;
}