//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_TITLE 50
#define MAX_RATING 10

typedef struct {
    char title[MAX_TITLE];
    int rating;
} Movie;

void addMovie(Movie movies[], int *numMovies, char title[], int rating) {
    if (*numMovies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }
    strcpy(movies[*numMovies].title, title);
    movies[*numMovies].rating = rating;
    (*numMovies)++;
}

void displayMovies(Movie movies[], int numMovies) {
    int i;
    printf("\nMovie Title\tRating\n--------------------\n");
    for (i = 0; i < numMovies; i++) {
        printf("%s\t%d\n", movies[i].title, movies[i].rating);
    }
}

void searchMovie(Movie movies[], int numMovies, char title[]) {
    int i;
    int found = 0;
    for (i = 0; i < numMovies && !found; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie '%s' found with rating %d.\n", title, movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("Error: Movie '%s' not found.\n", title);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    char title[MAX_TITLE];
    int choice, rating;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                displayMovies(movies, numMovies);
                break;
            case 3:
                printf("Enter movie title to search: ");
                scanf("%s", title);
                searchMovie(movies, numMovies, title);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}