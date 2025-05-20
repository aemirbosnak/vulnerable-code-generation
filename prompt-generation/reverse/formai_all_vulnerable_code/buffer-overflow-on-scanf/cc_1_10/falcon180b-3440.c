//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_GENRES 50
#define MAX_RATINGS 5
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

int main() {
    int numMovies, i, j, choice;
    char input[MAX_TITLE_LENGTH];
    Movie movies[MAX_MOVIES];

    printf("Welcome to the Movie Rating System!\n");
    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);

    // Get user input for each movie
    for (i = 0; i < numMovies; i++) {
        printf("\nEnter movie #%d:\n", i+1);
        printf("Title: ");
        scanf("%s", input);
        strcpy(movies[i].title, input);

        printf("Director: ");
        scanf("%s", input);
        strcpy(movies[i].director, input);

        printf("Actor: ");
        scanf("%s", input);
        strcpy(movies[i].actor, input);

        printf("Genre: ");
        scanf("%s", input);
        strcpy(movies[i].genre, input);

        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating);
    }

    // Main menu loop
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Rate a movie\n");
        printf("2. View movie ratings\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter movie title to rate: ");
                scanf("%s", input);
                for (i = 0; i < numMovies; i++) {
                    if (strcmp(input, movies[i].title) == 0) {
                        printf("\nRate this movie (1-5): ");
                        scanf("%d", &movies[i].rating);
                        break;
                    }
                }
                break;

            case 2:
                // View movie ratings
                for (i = 0; i < numMovies; i++) {
                    printf("\n%s - %s (%d)\n", movies[i].title, movies[i].director, movies[i].rating);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}