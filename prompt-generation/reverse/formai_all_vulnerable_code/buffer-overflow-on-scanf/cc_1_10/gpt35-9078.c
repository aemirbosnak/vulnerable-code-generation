//FormAI DATASET v1.0 Category: Movie Rating System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Structure for storing movie information
typedef struct Movie {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Global variables
Movie movies[100];
int numMovies = 0;
pthread_rwlock_t lock;

void* addMovie(void* arg) {
    // Acquire write lock
    pthread_rwlock_wrlock(&lock);

    // Get movie information from user
    printf("Enter title: ");
    scanf("%s", movies[numMovies].title);
    printf("Enter director: ");
    scanf("%s", movies[numMovies].director);
    printf("Enter year: ");
    scanf("%d", &movies[numMovies].year);
    printf("Enter rating: ");
    scanf("%f", &movies[numMovies].rating);

    // Increment movie count
    numMovies++;

    // Release write lock
    pthread_rwlock_unlock(&lock);

    return NULL;
}

void* getRating(void* arg) {
    // Acquire read lock
    pthread_rwlock_rdlock(&lock);

    // Get movie title from user
    char title[50];
    printf("Enter movie title: ");
    scanf("%s", title);

    // Search for movie and print rating
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Rating for %s: %.2f\n", title, movies[i].rating);
            break;
        }
    }

    // Release read lock
    pthread_rwlock_unlock(&lock);

    return NULL;
}

int main() {
    // Initialize read/write lock
    pthread_rwlock_init(&lock, NULL);

    // Create threads to add movies
    pthread_t addThreads[3];
    for (int i = 0; i < 3; i++) {
        pthread_create(&addThreads[i], NULL, addMovie, NULL);
    }

    // Wait for add movie threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(addThreads[i], NULL);
    }

    // Create thread to get rating
    pthread_t getThread;
    pthread_create(&getThread, NULL, getRating, NULL);

    // Wait for get rating thread to finish
    pthread_join(getThread, NULL);

    // Destroy read/write lock
    pthread_rwlock_destroy(&lock);

    return 0;
}