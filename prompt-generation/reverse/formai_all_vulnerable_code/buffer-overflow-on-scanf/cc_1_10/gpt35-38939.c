//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

int movie_cnt;
char movies[MAX_MOVIES][50];
int ratings[MAX_MOVIES][MAX_RATINGS];
int rating_cnt[MAX_MOVIES];
int total_ratings[MAX_MOVIES];
float avg_ratings[MAX_MOVIES];

void *add_movie(void *arg) {
    char *movie_title = (char *)arg;
    strncpy(movies[movie_cnt], movie_title, 50);
    rating_cnt[movie_cnt] = 0;
    total_ratings[movie_cnt] = 0;
    avg_ratings[movie_cnt] = 0.0;
    movie_cnt++;
    printf("Movie '%s' added to the database.\n", movie_title);
    pthread_exit(NULL);
}

void *add_rating(void *arg) {
    int *rating_args = (int *)arg;
    int movie_index = rating_args[0];
    int rating = rating_args[1];
    if (movie_index < 0 || movie_index >= movie_cnt) {
        printf("Invalid movie index.\n");
        pthread_exit(NULL);
    }
    if (rating < 1 || rating > 10) {
        printf("Invalid rating.\n");
        pthread_exit(NULL);
    }
    ratings[movie_index][rating_cnt[movie_index]] = rating;
    rating_cnt[movie_index]++;
    total_ratings[movie_index] += rating;
    avg_ratings[movie_index] = (float)total_ratings[movie_index] / rating_cnt[movie_index];
    printf("Rating %d added for movie '%s'.\n", rating, movies[movie_index]);
    pthread_exit(NULL);
}

void *print_movie_ratings(void *arg) {
    int movie_index = *(int *)arg;
    if (movie_index < 0 || movie_index >= movie_cnt) {
        printf("Invalid movie index.\n");
        pthread_exit(NULL);
    }
    printf("Movie: %s\n", movies[movie_index]);
    printf("Total Ratings: %d\n", rating_cnt[movie_index]);
    printf("Average Rating: %.2f\n", avg_ratings[movie_index]);
    for (int i = 0; i < rating_cnt[movie_index]; i++) {
        printf("Rating %d: %d\n", i+1, ratings[movie_index][i]);
    }
    pthread_exit(NULL);
}

int main() {
    char command[50];
    while (1) {
        printf("Enter a command ('add', 'rate', 'get', 'exit'): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char movie_title[50];
            printf("Enter movie title: ");
            scanf("%s", movie_title);
            pthread_t add_movie_thread;
            pthread_create(&add_movie_thread, NULL, add_movie, (void *)movie_title);
            pthread_join(add_movie_thread, NULL);
        } else if (strcmp(command, "rate") == 0) {
            int movie_index, rating;
            printf("Enter movie index and rating (separated by spaces): ");
            scanf("%d %d", &movie_index, &rating);
            int args[2] = {movie_index, rating};
            pthread_t add_rating_thread;
            pthread_create(&add_rating_thread, NULL, add_rating, (void *)args);
            pthread_join(add_rating_thread, NULL);
        } else if (strcmp(command, "get") == 0) {
            int movie_index;
            printf("Enter movie index: ");
            scanf("%d", &movie_index);
            pthread_t print_movie_ratings_thread;
            pthread_create(&print_movie_ratings_thread, NULL, print_movie_ratings, (void *)&movie_index);
            pthread_join(print_movie_ratings_thread, NULL);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    printf("Goodbye!\n");
    return 0;
}