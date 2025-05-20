//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char genre[20];
    int rating;
} Movie;

void print_movies(Movie movies[], int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (%s) - %d\n", i+1, movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void rate_movie(Movie movies[], int num_movies) {
    char title[50];
    int rating;

    printf("Enter the title of the movie you want to rate: ");
    scanf("%s", title);

    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Enter your rating (out of 10): ");
            scanf("%d", &rating);
            movies[i].rating = rating;
            printf("Thank you for your rating.\n");
            break;
        }
    }

    if (i == num_movies) {
        printf("Movie not found.\n");
    }

    printf("\n");
}

int main() {
    int num_movies;
    printf("How many movies do you want to rate? ");
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movies[i].title);
        printf("Enter the genre of movie %d: ", i+1);
        scanf("%s", movies[i].genre);
        movies[i].rating = -1;
    }

    while (1) {
        printf("What do you want to do?\n");
        printf("1. View all movies\n");
        printf("2. Rate a movie\n");
        printf("3. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_movies(movies, num_movies);
                break;
            case 2:
                rate_movie(movies, num_movies);
                break;
            case 3:
                printf("Thank you for using the Movie Rating System.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}