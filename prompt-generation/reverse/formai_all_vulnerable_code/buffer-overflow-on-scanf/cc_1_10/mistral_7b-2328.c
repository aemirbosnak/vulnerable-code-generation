//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5000
#define RATING_LENGTH 20
#define NUM_CATEGORIES 10

typedef struct {
    char title[RATING_LENGTH];
    int rating;
    char category[NUM_CATEGORIES][5];
} Movie;

void readMovies(Movie movies[], int size);
void printMenu();
void printMoviesByCategory(Movie movies[], int size, char categoryName[]);
int main() {
    Movie movies[MAX_RATINGS];
    int numMovies = 0;

    readMovies(movies, MAX_RATINGS);

    while (1) {
        printMenu();
        char choice[5];
        scanf("%s", choice);

        if (strcmp(choice, "exit") == 0) {
            break;
        }

        char categoryName[NUM_CATEGORIES][5];
        int i;

        for (i = 0; i < NUM_CATEGORIES; i++) {
            scanf("%s", categoryName[i]);
        }

        printMoviesByCategory(movies, numMovies, categoryName);
    }

    return 0;
}

void printMenu() {
    printf("\nWelcome to the Movie Rating System!\n");
    printf("1. List movies by category\n");
    printf("2. Search for a movie by title\n");
    printf("3. Add a new movie\n");
    printf("4. Update movie rating\n");
    printf("5. Display all movies\n");
    printf("6. Exit\n");
}

void readMovies(Movie movies[], int size) {
    char title[RATING_LENGTH];
    int rating;
    char category[NUM_CATEGORIES][5];

    for (int i = 0; i < size; i++) {
        printf("Enter movie title: ");
        scanf("%s", title);
        strcpy(movies[i].title, title);

        printf("Enter movie rating: ");
        scanf("%d", &rating);
        movies[i].rating = rating;

        for (int j = 0; j < NUM_CATEGORIES; j++) {
            printf("Enter movie category %d: ", j + 1);
            scanf("%s", category[j]);
            strcpy(movies[i].category[j], category[j]);
        }
    }
}

void printMoviesByCategory(Movie movies[], int size, char categoryName[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].category[0], categoryName) == 0) {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Rating: %d\n", movies[i].rating);
            for (int j = 0; j < NUM_CATEGORIES; j++) {
                printf("Category %d: %s\n", j + 1, movies[i].category[j]);
            }
        }
    }
}