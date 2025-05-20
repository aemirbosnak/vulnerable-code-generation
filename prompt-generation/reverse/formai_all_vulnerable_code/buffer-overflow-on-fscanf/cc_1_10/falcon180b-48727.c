//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char director[MAX_LENGTH];
    int year;
    int rating;
} Movie;

void loadMovies(Movie* movies, int count) {
    FILE* file = fopen("movies.txt", "r");
    if (!file) {
        printf("Error loading movies from file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s %d %d\n", movies[i].title, movies[i].director, &movies[i].year, &movies[i].rating) == 4 && i < count) {
        i++;
    }

    fclose(file);
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;

    loadMovies(movies, MAX_MOVIES);

    char title[MAX_LENGTH];
    printf("Enter movie title to search for:\n");
    scanf("%s", title);

    int matchCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %d\n\n", movies[i].rating);
            matchCount++;
        }
    }

    if (matchCount == 0) {
        printf("No movies found.\n");
    }

    return 0;
}