//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct movie {
    char title[MAX_TITLE_LENGTH];
    int year;
    double rating;
} Movie;

void add_movie(Movie *movies, int *num_movies);
void display_movies(Movie *movies, int num_movies);
void search_movie(Movie *movies, int num_movies);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int choice;

    while (1) {
        printf("\n===== C MOVIE RATING SYSTEM =====\n");
        printf("1. Add a Movie\n");
        printf("2. Display All Movies\n");
        printf("3. Search a Movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_movie(movies, &num_movies);
                    break;
            case 2: display_movies(movies, num_movies);
                    break;
            case 3: search_movie(movies, num_movies);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void add_movie(Movie *movies, int *num_movies) {
    if (*num_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }

    Movie new_movie;

    printf("\n===== ADD A MOVIE =====\n");
    printf("Enter the title: ");
    scanf("%s", new_movie.title);
    printf("Enter the year: ");
    scanf("%d", &new_movie.year);
    printf("Enter the rating: ");
    scanf("%lf", &new_movie.rating);

    movies[*num_movies] = new_movie;
    (*num_movies)++;

    printf("\nMovie added successfully!\n");
}

void display_movies(Movie *movies, int num_movies) {
    if (num_movies == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n===== ALL MOVIES =====\n");

    for (int i = 0; i < num_movies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("\n");
    }
}

void search_movie(Movie *movies, int num_movies) {
    if (num_movies == 0) {
        printf("No movies to search.\n");
        return;
    }

    char search_title[MAX_TITLE_LENGTH];

    printf("\n===== SEARCH A MOVIE =====\n");
    printf("Enter the title: ");
    scanf("%s", search_title);

    for (int i = 0; i < num_movies; i++) {
        if (strcmp(search_title, movies[i].title) == 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("\n");
            return;
        }
    }

    printf("Movie not found.\n");
}