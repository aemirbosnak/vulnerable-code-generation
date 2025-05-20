//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RATINGS 100
#define MAX_FILM_NAME 50
#define RATING_MIN 0
#define RATING_MAX 10

typedef struct {
    char film_name[MAX_FILM_NAME];
    int rating;
} Movie;

void read_movies(Movie movies[], int size);
void print_movies(Movie movies[], int size);
void sort_movies(Movie movies[], int size);

int main() {
    Movie movies[MAX_RATINGS];
    int num_movies = 0;
    char command[10];

    while (1) {
        printf("Enter command (add/list/quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (num_movies >= MAX_RATINGS) {
                printf("Maximum number of movies reached.\n");
                continue;
            }
            printf("Enter film name: ");
            scanf("%s", movies[num_movies].film_name);
            printf("Enter film rating (0-10): ");
            scanf("%d", &movies[num_movies].rating);
            num_movies++;
        } else if (strcmp(command, "list") == 0) {
            read_movies(movies, num_movies);
            sort_movies(movies, num_movies);
            print_movies(movies, num_movies);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

void read_movies(Movie movies[], int size) {
    printf("\nMovies:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s (%d)\n", i + 1, movies[i].film_name, movies[i].rating);
    }
}

void print_movies(Movie movies[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s (%d)\n", movies[i].film_name, movies[i].rating);
    }
}

void sort_movies(Movie movies[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}