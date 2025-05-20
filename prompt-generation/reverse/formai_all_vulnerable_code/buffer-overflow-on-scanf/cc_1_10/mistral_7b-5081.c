//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MAX_RATING_LENGTH 3

typedef struct {
    char title[MAX_NAME_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void addMovie(Movie movies[], int* numMovies, char title[], char rating[]) {
    if (*numMovies >= MAX_MOVIES) {
        printf("Error: Max number of movies reached.\n");
        return;
    }

    strcpy(movies[*numMovies].title, title);
    strcpy(movies[*numMovies].rating, rating);
    (*numMovies)++;
}

void printMovies(Movie movies[], int numMovies) {
    printf("\nMovie Rating System:\n");
    printf("----------------------\n");

    for (int i = 0; i < numMovies; i++) {
        printf("%d. %s - %s\n", i + 1, movies[i].title, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    while (1) {
        char choice[5];
        char title[MAX_NAME_LENGTH];
        char rating[MAX_RATING_LENGTH];

        printf("\nC Movie Rating System\n");
        printf("----------------------\n");
        printf("1. Add movie\n");
        printf("2. Print movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);

        switch (choice[0]) {
            case '1':
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie rating (max 3 characters): ");
                scanf("%s", rating);
                addMovie(movies, &numMovies, title, rating);
                break;
            case '2':
                printMovies(movies, numMovies);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}