//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 50
#define MAX_RATING 10

typedef struct {
    char title[MAX_TITLE];
    int rating;
} Movie;

void print_menu();
void add_movie(Movie movies[], int *num_movies);
void display_movies(Movie movies[], int num_movies);

int main() {
    int num_movies = 0;
    Movie movies[MAX_MOVIES];

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                display_movies(movies, num_movies);
                break;
            case 3:
                printf("Exiting the movie rating system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n-------------------------------------------------\n");
    printf("| Welcome to the Retro Movie Rating System!      |\n");
    printf("|------------------------------------------------|\n");
    printf("| 1. Add a movie                               |\n");
    printf("| 2. Display all movies and their ratings        |\n");
    printf("| 3. Exit                                      |\n");
    printf("|------------------------------------------------|\n");
}

void add_movie(Movie movies[], int *num_movies) {
    if (*num_movies >= MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }

    printf("Enter movie title: ");
    scanf("%s", movies[*num_movies].title);
    printf("Enter movie rating (1-10): ");
    scanf("%d", &movies[*num_movies].rating);

    (*num_movies)++;
}

void display_movies(Movie movies[], int num_movies) {
    printf("\n-------------------------------------------------\n");
    printf("|                 Movie List                     |\n");
    printf("|------------------------------------------------|\n");

    for (int i = 0; i < num_movies; i++) {
        printf("| %d. %s - %d/10                             |\n", i+1, movies[i].title, movies[i].rating);
    }

    printf("|------------------------------------------------|\n");
}