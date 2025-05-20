//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10

typedef struct {
    char title[50];
    float rating;
} Movie;

void add_movie(Movie movies[], int *num_movies, const char *title, float rating);
void remove_movie(Movie movies[], int *num_movies, const char *title);
void print_movies(const Movie movies[], int num_movies);
float average_rating(const Movie movies[], int num_movies);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (1) {
        printf("1. Add movie\n");
        printf("2. Remove movie\n");
        printf("3. View movies and average rating\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char title[50];
            float rating;

            printf("Enter movie title: ");
            scanf("%s", title);
            printf("Enter movie rating: ");
            scanf("%f", &rating);

            add_movie(movies, &num_movies, title, rating);
            break;
        }

        case 2: {
            char title[50];

            printf("Enter movie title to remove: ");
            scanf("%s", title);

            remove_movie(movies, &num_movies, title);
            break;
        }

        case 3: {
            print_movies(movies, num_movies);
            printf("Average rating: %.2f\n", average_rating(movies, num_movies));
            break;
        }

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}

void add_movie(Movie movies[], int *num_movies, const char *title, float rating) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Cannot add movie, list is full.\n");
        return;
    }

    strcpy(movies[*num_movies].title, title);
    movies[*num_movies].rating = rating;
    (*num_movies)++;
}

void remove_movie(Movie movies[], int *num_movies, const char *title) {
    for (int i = 0; i < *num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (int j = i; j < *num_movies - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*num_movies)--;
            return;
        }
    }

    printf("Movie not found.\n");
}

void print_movies(const Movie movies[], int num_movies) {
    printf("\nMovie titles and ratings:\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%s - %.2f\n", movies[i].title, movies[i].rating);
    }
}

float average_rating(const Movie movies[], int num_movies) {
    float sum = 0.0;

    for (int i = 0; i < num_movies; i++) {
        sum += movies[i].rating;
    }

    return sum / num_movies;
}