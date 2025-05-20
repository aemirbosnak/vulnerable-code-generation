//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

int movie_rating = 0;
pthread_mutex_t mutex;

void *user_rating(void *thread_id) {
    int rating;
    printf("User %ld, please enter your rating (0-10): ", (long)thread_id);
    scanf("%d", &rating);
    while(rating < 0 || rating > 10) {
        printf("Invalid rating, please enter a rating between 0 and 10: ");
        scanf("%d", &rating);
    }
    pthread_mutex_lock(&mutex);
    movie_rating += rating;
    pthread_mutex_unlock(&mutex);
    printf("User %ld, thank you for your rating!\n", (long)thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    pthread_mutex_init(&mutex, NULL);

    for(t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, user_rating, (void *)t);
        if(rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for(t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if(rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    int average_rating = movie_rating / NUM_THREADS;
    printf("The movie's average rating is %d.\n", average_rating);
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}