//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct movie {
    char title[100];
    int release_year;
    int runtime;
    char director[50];
    char actors[100];
    char genre[50];
    int rating;
} Movie;

void add_movie(Movie *movies, int num_movies, Movie new_movie) {
    if (num_movies == 0) {
        movies[0] = new_movie;
        num_movies++;
    } else {
        for (int i = 0; i < num_movies; i++) {
            if (strcmp(movies[i].title, new_movie.title) == 0) {
                printf("Movie already exists.\n");
                return;
            }
        }
        movies[num_movies] = new_movie;
        num_movies++;
    }
}

void print_movies(Movie *movies, int num_movies) {
    printf("Movies:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (%d)\n", i+1, movies[i].title, movies[i].rating);
    }
}

int main() {
    int num_movies = 0;
    Movie movies[100];

    while (true) {
        printf("1. Add a movie\n2. Print movies\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Movie new_movie;
                printf("Enter movie title: ");
                scanf("%s", new_movie.title);
                printf("Enter release year: ");
                scanf("%d", &new_movie.release_year);
                printf("Enter runtime (in minutes): ");
                scanf("%d", &new_movie.runtime);
                printf("Enter director: ");
                scanf("%s", new_movie.director);
                printf("Enter actors (comma-separated): ");
                scanf("%s", new_movie.actors);
                printf("Enter genre: ");
                scanf("%s", new_movie.genre);
                printf("Enter rating (1-10): ");
                scanf("%d", &new_movie.rating);
                add_movie(movies, num_movies, new_movie);
                break;
            }
            case 2: {
                print_movies(movies, num_movies);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}