//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a struct to hold movie details
typedef struct {
    char title[100];
    float rating;
    bool is_watched;
} Movie;

// Function to add a new movie to the system
void add_movie(Movie* movies, int size, const char* title, float rating) {
    int i;
    Movie* new_movie = (Movie*)malloc(sizeof(Movie));
    strcpy(new_movie->title, title);
    new_movie->rating = rating;
    new_movie->is_watched = false;
    for (i = 0; i < size; i++) {
        if (strcmp(new_movie->title, movies[i].title) == 0) {
            free(new_movie);
            return;
        }
    }
    movies[size] = *new_movie;
    size++;
}

// Function to remove a movie from the system
void remove_movie(Movie* movies, int size, const char* title) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (int j = i; j < size - 1; j++) {
                movies[j] = movies[j + 1];
            }
            size--;
            free(movies[i].title);
            return;
        }
    }
    printf("Movie not found.\n");
}

// Function to rate a movie
void rate_movie(Movie* movies, int size, const char* title, float rating) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating = rating;
            return;
        }
    }
    printf("Movie not found.\n");
}

// Function to check if a movie has been watched
bool is_watched(Movie* movies, int size, const char* title) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return movies[i].is_watched;
        }
    }
    return false;
}

// Function to display all movies in the system
void display_movies(Movie* movies, int size) {
    int i;
    printf("Movie Title\tRating\tWatched\n");
    for (i = 0; i < size; i++) {
        printf("%s\t%f\t%s\n", movies[i].title, movies[i].rating, is_watched(movies, size, movies[i].title)? "Yes" : "No");
    }
}

// Main function
int main() {
    Movie movies[100];
    int size = 0;
    while (true) {
        printf("1. Add a new movie\n2. Remove a movie\n3. Rate a movie\n4. Check if a movie has been watched\n5. Display all movies\n6. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(movies[size].title, sizeof(movies[size].title), stdin);
                printf("Enter movie rating: ");
                scanf("%f", &movies[size].rating);
                size++;
                break;
            case 2:
                printf("Enter movie title to remove: ");
                fgets(movies[size].title, sizeof(movies[size].title), stdin);
                remove_movie(movies, size, movies[size].title);
                break;
            case 3:
                printf("Enter movie title to rate: ");
                fgets(movies[size].title, sizeof(movies[size].title), stdin);
                printf("Enter movie rating: ");
                scanf("%f", &movies[size].rating);
                size++;
                break;
            case 4:
                printf("Enter movie title to check: ");
                fgets(movies[size].title, sizeof(movies[size].title), stdin);
                printf("%s\n", is_watched(movies, size, movies[size].title)? "Yes" : "No");
                break;
            case 5:
                display_movies(movies, size);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}