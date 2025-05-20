//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000

typedef struct {
    char title[100];
    int rating;
} Movie;

void addMovie(Movie movies[], int numMovies) {
    printf("Enter movie title: ");
    scanf("%s", &movies[numMovies].title);
    movies[numMovies].rating = 0;
    numMovies++;
}

void printMovies(Movie movies[], int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d)\n", movies[i].title, movies[i].rating);
    }
}

void addRating(Movie movies[], int numMovies, char title[]) {
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Enter rating (1-5): ");
            scanf("%d", &movies[i].rating);
            break;
        }
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    while (numMovies < MAX_MOVIES) {
        printf("1. Add movie\n2. Add rating\n3. Print movies\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addMovie(movies, numMovies);
            break;
        case 2:
            printf("Enter movie title: ");
            char title[100];
            scanf("%s", title);
            addRating(movies, numMovies, title);
            break;
        case 3:
            printMovies(movies, numMovies);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}