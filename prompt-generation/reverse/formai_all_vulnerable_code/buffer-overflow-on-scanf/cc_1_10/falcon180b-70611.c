//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int numMovies;
    Movie movies[100];

    printf("Welcome to the Cheerful Movie Rating System!\n");
    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);

    for (int i = 0; i < numMovies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movies[i].title);

        printf("Enter the director of movie %d: ", i+1);
        scanf("%s", movies[i].director);

        printf("Enter the actors of movie %d separated by commas: ", i+1);
        scanf("%s", movies[i].actors);

        printf("Enter the genre of movie %d: ", i+1);
        scanf("%s", movies[i].genre);

        printf("Enter the rating for movie %d (1-5): ", i+1);
        scanf("%d", &movies[i].rating);

        printf("Enter a review for movie %d (up to 500 characters): ", i+1);
        scanf("%[^\n]", movies[i].review);
        movies[i].review[strcspn(movies[i].review, "\n")] = '\0'; // remove newline character
    }

    printf("\nHere are your movie ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }

    return 0;
}