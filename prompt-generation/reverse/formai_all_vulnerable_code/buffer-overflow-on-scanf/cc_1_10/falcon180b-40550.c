//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LEN 100
#define MAX_RATING_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char rating[MAX_RATING_LEN];
} Movie;

void addMovie(Movie* movies, int size, char* name, char* rating) {
    if (size >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached\n");
        exit(1);
    }
    strcpy(movies[size].name, name);
    strcpy(movies[size].rating, rating);
    size++;
}

void printMovies(Movie* movies, int size) {
    printf("Movies:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s\n", movies[i].name, movies[i].rating);
    }
}

void searchMovie(Movie* movies, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            printf("Movie found!\n");
            printf("Name: %s\n", movies[i].name);
            printf("Rating: %s\n", movies[i].rating);
            break;
        }
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int size = 0;

    addMovie(movies, size, "The Godfather", "10/10");
    addMovie(movies, size, "The Shawshank Redemption", "9/10");
    addMovie(movies, size, "The Dark Knight", "8/10");

    printMovies(movies, size);

    char searchName[MAX_NAME_LEN];
    printf("Enter a movie name to search: ");
    scanf("%s", searchName);
    searchMovie(movies, size, searchName);

    return 0;
}