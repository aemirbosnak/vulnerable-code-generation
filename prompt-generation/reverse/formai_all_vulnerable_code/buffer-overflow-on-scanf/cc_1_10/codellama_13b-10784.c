//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATING 10

struct Movie {
    char title[100];
    int rating;
};

void print_menu() {
    printf("Welcome to the Movie Rating System\n");
    printf("1. Add a new movie\n");
    printf("2. Remove a movie\n");
    printf("3. Update a movie's rating\n");
    printf("4. Display all movies\n");
    printf("5. Exit\n");
}

void add_movie(struct Movie movies[], int *size) {
    if (*size >= MAX_MOVIES) {
        printf("Maximum number of movies reached\n");
        return;
    }

    printf("Enter the title of the movie: ");
    scanf("%s", movies[*size].title);
    printf("Enter the rating (1-10): ");
    scanf("%d", &movies[*size].rating);

    *size += 1;
}

void remove_movie(struct Movie movies[], int *size) {
    if (*size <= 0) {
        printf("No movies to remove\n");
        return;
    }

    printf("Enter the index of the movie to remove: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        movies[i] = movies[i + 1];
    }

    *size -= 1;
}

void update_movie_rating(struct Movie movies[], int *size) {
    if (*size <= 0) {
        printf("No movies to update\n");
        return;
    }

    printf("Enter the index of the movie to update: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Invalid index\n");
        return;
    }

    printf("Enter the new rating (1-10): ");
    int rating;
    scanf("%d", &rating);

    movies[index].rating = rating;
}

void display_movies(struct Movie movies[], int size) {
    if (size <= 0) {
        printf("No movies to display\n");
        return;
    }

    printf("Movies:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s (%d)\n", i + 1, movies[i].title, movies[i].rating);
    }
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int size = 0;

    int option;
    do {
        print_menu();
        scanf("%d", &option);

        switch (option) {
        case 1:
            add_movie(movies, &size);
            break;
        case 2:
            remove_movie(movies, &size);
            break;
        case 3:
            update_movie_rating(movies, &size);
            break;
        case 4:
            display_movies(movies, size);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (option != 5);

    return 0;
}