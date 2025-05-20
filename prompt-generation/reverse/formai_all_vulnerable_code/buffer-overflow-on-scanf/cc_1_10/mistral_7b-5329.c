//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 50
#define MAX_RATING 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    int rating;
} Movie;

void addMovie(Movie movies[], int* numMovies, char* title, int rating);
void printMovies(Movie movies[], int numMovies);
void printMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    char title[MAX_NAME_LENGTH];
    int choice, rating;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie rating (1-10): ");
                scanf("%d", &rating);
                addMovie(movies, &numMovies, title, rating);
                break;
            case 2:
                printMovies(movies, numMovies);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void addMovie(Movie movies[], int* numMovies, char* title, int rating) {
    if (*numMovies >= MAX_MOVIES) {
        printf("Maximum number of movies reached!\n");
        return;
    }

    strcpy(movies[*numMovies].title, title);
    movies[*numMovies].rating = rating;
    (*numMovies)++;
}

void printMovies(Movie movies[], int numMovies) {
    int i;

    printf("\nMovie List:\n");
    for (i = 0; i < numMovies; i++) {
        printf("%d. %s - %d\n", i+1, movies[i].title, movies[i].rating);
    }
}

void printMenu() {
    printf("\nMovie Rating System Menu:\n");
    printf("1. Add Movie\n");
    printf("2. List Movies\n");
    printf("3. Exit\n");
}