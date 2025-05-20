//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define MOVIE_NAME_LENGTH 50
#define RATING_LENGTH 10

typedef struct {
    char name[MOVIE_NAME_LENGTH];
    float rating;
} Movie;

void add_movie(Movie movies[], char name[], float rating, int *num_movies);
void remove_movie(Movie movies[], char name[], int *num_movies);
void display_movies(const Movie movies[], int num_movies);
float calculate_average_rating(const Movie movies[], int num_movies);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    char input_name[MOVIE_NAME_LENGTH];
    float input_rating;
    char command;

    while (1) {
        printf("Enter command (A)dd, (R)emove, (D)isplay, (Q)uit: ");
        scanf(" %c", &command);

        switch (command) {
            case 'A':
                printf("Enter movie name: ");
                scanf("%s", input_name);
                printf("Enter movie rating: ");
                scanf("%f", &input_rating);
                add_movie(movies, input_name, input_rating, &num_movies);
                break;

            case 'R':
                printf("Enter movie name to remove: ");
                scanf("%s", input_name);
                remove_movie(movies, input_name, &num_movies);
                break;

            case 'D':
                display_movies(movies, num_movies);
                break;

            case 'Q':
                exit(0);

            default:
                printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}

void add_movie(Movie movies[], char name[], float rating, int *num_movies) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }

    strcpy(movies[*num_movies].name, name);
    movies[*num_movies].rating = rating;
    (*num_movies)++;
}

void remove_movie(Movie movies[], char name[], int *num_movies) {
    int i;

    for (i = 0; i < *num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            for (int j = i; j < *num_movies - 1; j++) {
                strcpy(movies[j].name, movies[j + 1].name);
                movies[j].rating = movies[j + 1].rating;
            }
            (*num_movies)--;
            break;
        }
    }

    if (i == *num_movies) {
        printf("Movie not found.\n");
    }
}

void display_movies(const Movie movies[], int num_movies) {
    printf("\nMovie List:\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s - %s\n", i + 1, movies[i].name, movies[i].rating > 0 ? "(Rated)" : "(Unrated)");
    }

    printf("\nAverage Rating: %f\n", calculate_average_rating(movies, num_movies));
}

float calculate_average_rating(const Movie movies[], int num_movies) {
    float sum = 0;
    int count = 0;

    for (int i = 0; i < num_movies; i++) {
        sum += movies[i].rating;
        count++;
    }

    return sum / count;
}