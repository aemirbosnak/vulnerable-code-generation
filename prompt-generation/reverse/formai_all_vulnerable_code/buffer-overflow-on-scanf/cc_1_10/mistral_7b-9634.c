//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 50

typedef struct {
    char title[50];
    char director[30];
    int year;
    float rating;
} Movie;

void print_movie(Movie movie) {
    printf("%s (%d) - %.1f\n", movie.title, movie.year, movie.rating);
}

void add_movie(Movie movies[], int* num_movies, char* title, char* director, int year, float rating) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Error: Too many movies.\n");
        return;
    }

    strcpy(movies[*num_movies].title, title);
    strcpy(movies[*num_movies].director, director);
    movies[*num_movies].year = year;
    movies[*num_movies].rating = rating;

    (*num_movies)++;
}

float average_rating(Movie movies[], int num_movies) {
    int i;
    float sum = 0.0;

    for (i = 0; i < num_movies; i++) {
        sum += movies[i].rating;
    }

    return sum / num_movies;
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (1) {
        printf("1. Add movie\n");
        printf("2. Calculate average rating\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char title[50], director[30];
                int year;
                float rating;

                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie director: ");
                scanf("%s", director);
                printf("Enter movie year: ");
                scanf("%d", &year);
                printf("Enter movie rating: ");
                scanf("%f", &rating);

                add_movie(movies, &num_movies, title, director, year, rating);
                break;
            }

            case 2: {
                if (num_movies == 0) {
                    printf("Error: No movies to calculate average rating.\n");
                    break;
                }

                float avg_rating = average_rating(movies, num_movies);
                printf("The average rating of movies is: %.2f\n", avg_rating);
                break;
            }

            case 3:
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}