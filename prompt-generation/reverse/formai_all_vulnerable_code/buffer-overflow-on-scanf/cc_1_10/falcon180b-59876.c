//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 100
#define MAX_ACTOR_LENGTH 100
#define MAX_GENRE_LENGTH 100
#define MAX_RATING 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

int main() {
    int numMovies, i;
    Movie movies[MAX_MOVIES];
    char input[100];
    printf("Welcome to the Romantic Movie Rating System!\n");
    printf("How many movies would you like to rate? (Max %d): ", MAX_MOVIES);
    scanf("%d", &numMovies);
    printf("Enter the title of the first movie: ");
    scanf("%s", movies[0].title);
    printf("Enter the name of the director: ");
    scanf("%s", movies[0].director);
    printf("Enter the name of the lead actor: ");
    scanf("%s", movies[0].actor);
    printf("Enter the genre of the movie: ");
    scanf("%s", movies[0].genre);
    printf("Rate the movie out of 10: ");
    scanf("%d", &movies[0].rating);
    for (i = 1; i < numMovies; i++) {
        printf("Enter the title of movie %d: ", i + 1);
        scanf("%s", movies[i].title);
        printf("Enter the name of the director: ");
        scanf("%s", movies[i].director);
        printf("Enter the name of the lead actor: ");
        scanf("%s", movies[i].actor);
        printf("Enter the genre of the movie: ");
        scanf("%s", movies[i].genre);
        printf("Rate the movie out of 10: ");
        scanf("%d", &movies[i].rating);
    }
    printf("\nThank you for rating these romantic movies!\n");
    return 0;
}