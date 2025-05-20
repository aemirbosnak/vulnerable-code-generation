//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_NAME_LENGTH 50

int current_num_movies = 0;

typedef enum {
    G = 0,
    PG,
    PG13,
    R,
    NC17
} Rating;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Rating rating;
    int year;
    float imdb_rating;
} Movie;

Movie movies[MAX_MOVIES];

void add_movie() {
    if (current_num_movies >= MAX_MOVIES) {
        printf("Movie database is full.\n");
        return;
    }
    Movie new_movie;
    printf("Enter name of the movie: ");
    fgets(new_movie.name, MAX_NAME_LENGTH, stdin);
    new_movie.name[strcspn(new_movie.name, "\n")] = 0;
    printf("Enter movie rating (G, PG, PG13, R, NC17): ");
    char rating_input[MAX_NAME_LENGTH];
    fgets(rating_input, MAX_NAME_LENGTH, stdin);
    rating_input[strcspn(rating_input, "\n")] = 0;
    if (strcmp(rating_input, "G") == 0) {
        new_movie.rating = G;
    } else if (strcmp(rating_input, "PG") == 0) {
        new_movie.rating = PG;
    } else if (strcmp(rating_input, "PG13") == 0) {
        new_movie.rating = PG13;
    } else if (strcmp(rating_input, "R") == 0) {
        new_movie.rating = R;
    } else if (strcmp(rating_input, "NC17") == 0) {
        new_movie.rating = NC17;
    } else {
        printf("Invalid rating. Movie not added.\n");
        return;
    }
    printf("Enter year of the movie: ");
    scanf("%d", &new_movie.year);
    printf("Enter IMDB rating of the movie: ");
    scanf("%f", &new_movie.imdb_rating);
    getchar(); // Ignore remaining newline character
    movies[current_num_movies] = new_movie;
    current_num_movies++;
    printf("Movie added successfully.\n");
}

void print_movie(Movie movie) {
    printf("%s (%d) - %0.1f/10.0 - ", movie.name, movie.year, movie.imdb_rating);
    switch (movie.rating) {
        case G:
            printf("G\n");
            break;
        case PG:
            printf("PG\n");
            break;
        case PG13:
            printf("PG13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC17:
            printf("NC17\n");
            break;
    }
}

void list_movies() {
    if (current_num_movies == 0) {
        printf("Movie database is empty.\n");
        return;
    }
    for (int i = 0; i < current_num_movies; i++) {
        print_movie(movies[i]);
    }
}

int main() {
    int choice = -1;
    while (choice != 0) {
        printf("\nEnter choice:\n");
        printf("1. Add movie\n");
        printf("2. List movies\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        getchar(); // Ignore remaining newline character
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                list_movies();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }  
    return 0;
}