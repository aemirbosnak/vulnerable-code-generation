//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_DIRECTOR_LENGTH 30
#define MAX_GENRE_LENGTH 20
#define MAX_RATING 10
#define MIN_RATING 1

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

void readMovies(Movie movies[], int* numMovies) {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;

    for (; *numMovies < MAX_MOVIES; ++*numMovies) {
        printf("Enter title: ");
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';
        strcpy(movies[*numMovies].title, title);

        printf("Enter director: ");
        fgets(director, sizeof(director), stdin);
        director[strcspn(director, "\n")] = '\0';
        strcpy(movies[*numMovies].director, director);

        printf("Enter genre: ");
        fgets(genre, sizeof(genre), stdin);
        genre[strcspn(genre, "\n")] = '\0';
        strcpy(movies[*numMovies].genre, genre);

        printf("Enter rating (1-10): ");
        scanf("%d", &rating);
        if (rating < MIN_RATING || rating > MAX_RATING) {
            printf("Invalid rating. Please enter a number between 1 and 10.\n");
            --*numMovies;
            continue;
        }
        movies[*numMovies].rating = rating;
    }
}

void printMovies(Movie movies[], int numMovies) {
    for (int i = 0; i < numMovies; ++i) {
        printf("%d. %s (%s) - Rating: %d\n", i + 1, movies[i].title, movies[i].director, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    readMovies(movies, &numMovies);

    printf("\nMovie List:\n");
    printMovies(movies, numMovies);

    return 0;
}