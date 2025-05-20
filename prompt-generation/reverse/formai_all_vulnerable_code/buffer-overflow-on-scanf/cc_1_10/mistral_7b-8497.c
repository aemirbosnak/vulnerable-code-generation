//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATING 10
#define MAX_NAME_LEN 50

typedef struct {
    char title[MAX_NAME_LEN];
    int rating;
} Movie;

void print_menu();
void add_movie(Movie movies[], int *num_movies);
void display_movies(Movie movies[], int num_movies);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

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
                exit(0);
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("\n--------------- MOVIE RATING SYSTEM ---------------");
    printf("\n1. Add a movie");
    printf("\n2. Display movies and ratings");
    printf("\n3. Exit");
    printf("\n--------------- MOVIE RATING SYSTEM ---------------");
    printf("\nEnter your choice: ");
}

void add_movie(Movie movies[], int *num_movies) {
    if (*num_movies == MAX_MOVIES) {
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
    printf("\n--------------- MOVIES AND RATINGS ---------------");
    printf("\n%-50s %-5s", "Movie Title", "Rating");
    printf("\n--------------- MOVIES AND RATINGS ---------------");

    for (int i = 0; i < num_movies; i++) {
        printf("\n%-50s %-5d", movies[i].title, movies[i].rating);
    }
}