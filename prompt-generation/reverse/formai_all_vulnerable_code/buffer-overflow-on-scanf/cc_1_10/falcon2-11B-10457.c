//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 100

typedef struct {
    char title[100];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie(char* title, int rating) {
    Movie newMovie;
    strcpy(newMovie.title, title);
    newMovie.rating = rating;

    if (movieCount < MAX_MOVIES) {
        movies[movieCount++] = newMovie;
    } else {
        printf("Maximum number of movies reached.\n");
    }
}

void removeMovie(int index) {
    if (index < movieCount && index >= 0) {
        for (int i = index; i < movieCount - 1; i++) {
            movies[i] = movies[i + 1];
        }
        movieCount--;
    } else {
        printf("Invalid movie index.\n");
    }
}

void printMovies() {
    if (movieCount == 0) {
        printf("No movies added yet.\n");
        return;
    }

    printf("Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%-20s - %d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    char title[100];
    int rating;

    printf("Add a movie:\n");
    printf("Title: ");
    fgets(title, 100, stdin);
    fgets(title, 100, stdin);

    printf("Rating (1-10): ");
    scanf("%d", &rating);

    addMovie(title, rating);

    printf("List all movies:\n");
    printMovies();

    printf("Remove movie by index (0-based): ");
    scanf("%d", &index);

    if (index < movieCount) {
        removeMovie(index);
    } else {
        printf("Invalid movie index.\n");
    }

    printf("List all movies again:\n");
    printMovies();

    return 0;
}