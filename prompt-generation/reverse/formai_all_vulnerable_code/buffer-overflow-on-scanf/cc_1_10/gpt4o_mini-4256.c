//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MAX_RATING_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* addMovie(void* arg) {
    Movie* movie = (Movie*)arg;

    pthread_mutex_lock(&mutex);
    if (movieCount < MAX_MOVIES) {
        movies[movieCount++] = *movie;
        printf("Movie added: %s with rating: %s\n", movie->name, movie->rating);
    } else {
        printf("Movie list is full!\n");
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* printMovies(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d: %s - %s\n", i + 1, movies[i].name, movies[i].rating);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* updateRating(void* arg) {
    char* movieName = (char*)arg;
    char newRating[MAX_RATING_LENGTH];

    printf("Enter new rating for %s: ", movieName);
    scanf("%s", newRating);

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].name, movieName) == 0) {
            strcpy(movies[i].rating, newRating);
            printf("Updated %s to new rating: %s\n", movieName, newRating);
            break;
        }
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[100];
    char command[100];

    while (1) {
        printf("\nCommands:\n");
        printf("1. Add movie\n");
        printf("2. Print movie list\n");
        printf("3. Update movie rating\n");
        printf("4. Exit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "1") == 0) { // Add movie
            Movie movie;
            printf("Enter movie name: ");
            scanf(" %[^\n]", movie.name);
            printf("Enter movie rating: ");
            scanf("%s", movie.rating);
            pthread_create(&threads[movieCount], NULL, addMovie, (void*)&movie);

        } else if (strcmp(command, "2") == 0) { // Print movie list
            pthread_create(&threads[movieCount], NULL, printMovies, NULL);

        } else if (strcmp(command, "3") == 0) { // Update rating
            char movieName[MAX_NAME_LENGTH];
            printf("Enter movie name to update: ");
            scanf(" %[^\n]", movieName);
            pthread_create(&threads[movieCount], NULL, updateRating, (void*)movieName);

        } else if (strcmp(command, "4") == 0) { // Exit
            printf("Exiting program...\n");
            break;

        } else {
            printf("Invalid command. Please try again.\n");
        }

        // Wait for all threads to finish
        for (int i = 0; i < movieCount; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    return 0;
}