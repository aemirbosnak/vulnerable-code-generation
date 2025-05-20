//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATING 10

typedef struct {
    char title[50];
    float rating;
} Movie;

void add_movie(Movie movies[], int *num_movies, char *title, float rating);
float get_average_rating(Movie movies[], int num_movies);
void print_movies(Movie movies[], int num_movies);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (1) {
        printf("1. Add Movie\n");
        printf("2. Get Average Rating\n");
        printf("3. Print Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char title[50];
                float rating;
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter rating: ");
                scanf("%f", &rating);
                add_movie(movies, &num_movies, title, rating);
                break;
            }
            case 2: {
                float avg_rating = get_average_rating(movies, num_movies);
                printf("Average rating: %.2f\n", avg_rating);
                break;
            }
            case 3: {
                print_movies(movies, num_movies);
                break;
            }
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_movie(Movie movies[], int *num_movies, char *title, float rating) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Cannot add movie. Maximum movies reached.\n");
        return;
    }

    strcpy(movies[*num_movies].title, title);
    movies[*num_movies].rating = rating;
    (*num_movies)++;
}

float get_average_rating(Movie movies[], int num_movies) {
    float sum = 0.0;
    for (int i = 0; i < num_movies; i++) {
        sum += movies[i].rating;
    }
    return sum / num_movies;
}

void print_movies(Movie movies[], int num_movies) {
    printf("Title\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%.2f\n", movies[i].title, movies[i].rating);
    }
}