//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold movie data
typedef struct movie {
    char* title;
    int year;
    float rating;
} movie;

// Mutex to protect shared data
pthread_mutex_t mutex;

// Condition variable to signal when a movie has been rated
pthread_cond_t cond;

// Array of movies
movie movies[] = {
    {"The Shawshank Redemption", 1994, 0.0},
    {"The Godfather", 1972, 0.0},
    {"The Dark Knight", 2008, 0.0},
    {"12 Angry Men", 1957, 0.0},
    {"Schindler's List", 1993, 0.0}
};

// Number of movies
int num_movies = sizeof(movies) / sizeof(movie);

// Thread function to rate a movie
void* rate_movie(void* arg) {
    // Get the movie to rate
    movie* m = (movie*)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait until the movie has been rated
    while (m->rating == 0.0) {
        pthread_cond_wait(&cond, &mutex);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Print the movie rating
    printf("%s: %.1f\n", m->title, m->rating);

    return NULL;
}

int main() {
    // Initialize the mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    // Create a thread for each movie
    pthread_t threads[num_movies];
    for (int i = 0; i < num_movies; i++) {
        pthread_create(&threads[i], NULL, rate_movie, &movies[i]);
    }

    // Get user input for each movie
    for (int i = 0; i < num_movies; i++) {
        float rating;
        printf("Enter a rating for %s: ", movies[i].title);
        scanf("%f", &rating);

        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Set the movie rating
        movies[i].rating = rating;

        // Signal that the movie has been rated
        pthread_cond_signal(&cond);

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    // Join the threads
    for (int i = 0; i < num_movies; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}