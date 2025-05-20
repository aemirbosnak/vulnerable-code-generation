//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 50
#define MAX_RATING_LEN 3

typedef struct {
    char title[MAX_TITLE_LEN];
    char rating[MAX_RATING_LEN];
} Movie;

void titleToLower(char* title) {
    for (int i = 0; title[i]; i++) {
        title[i] = tolower(title[i]);
    }
}

int compareMovies(const void* a, const void* b) {
    Movie* movieA = (Movie*) a;
    Movie* movieB = (Movie*) b;

    int titleCmp = strcmp(movieA->title, movieB->title);
    if (titleCmp != 0) {
        return titleCmp;
    }

    int ratingCmp = strcmp(movieA->rating, movieB->rating);
    return ratingCmp;
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    printf("Welcome to the Celestial Cinema!\n");
    printf("Please enter the title of a movie followed by its rating (max 2 digits) and press enter.\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printf("\nMovie Title: ");
        scanf("%s", movies[numMovies].title);
        titleToLower(movies[numMovies].title);

        printf("Movie Rating: ");
        scanf("%s", movies[numMovies].rating);

        if (strcmp("quit", movies[numMovies].title) == 0) {
            break;
        }

        numMovies++;
    }

    qsort(movies, numMovies, sizeof(Movie), compareMovies);

    printf("\nMovie Ratings Sorted Alphabetically:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s - %s\n", movies[i].title, movies[i].rating);
    }

    return 0;
}