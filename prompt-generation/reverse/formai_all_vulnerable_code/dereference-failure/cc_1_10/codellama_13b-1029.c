//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: introspective
/*
 * C Movie Rating System
 *
 * This program takes in a movie title and rating as input and stores it in a
 * structure. It then uses a linked list to store the movie information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store movie information
typedef struct movie {
    char title[50];
    int rating;
    struct movie *next;
} movie_t;

// Function to add a new movie to the list
void add_movie(movie_t *list, char *title, int rating) {
    // Allocate memory for the new movie
    movie_t *new_movie = (movie_t *)malloc(sizeof(movie_t));

    // Copy the title and rating to the new movie
    strcpy(new_movie->title, title);
    new_movie->rating = rating;

    // Add the new movie to the end of the list
    new_movie->next = NULL;
    if (list == NULL) {
        list = new_movie;
    } else {
        movie_t *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_movie;
    }
}

// Function to print the movie list
void print_movie_list(movie_t *list) {
    if (list == NULL) {
        printf("No movies in the list.\n");
        return;
    }
    movie_t *current = list;
    while (current != NULL) {
        printf("Movie: %s, Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
}

int main() {
    // Initialize the movie list
    movie_t *movie_list = NULL;

    // Add some movies to the list
    add_movie(movie_list, "The Shawshank Redemption", 9);
    add_movie(movie_list, "The Godfather", 9);
    add_movie(movie_list, "The Dark Knight", 8);

    // Print the movie list
    print_movie_list(movie_list);

    return 0;
}