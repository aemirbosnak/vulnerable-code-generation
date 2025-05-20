//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 256
#define MAX_DIRECTOR_LENGTH 256
#define MAX_ACTOR_LENGTH 256
#define MAX_ACTORS 10
#define MAX_GENRE_LENGTH 256
#define MAX_GENRES 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    char genres[MAX_GENRE_LENGTH];
    int runtime;
    int rating;
    int gross_revenue;
} Movie;

int main() {
    int num_movies;
    Movie movies[MAX_ACTORS];

    printf("Welcome to the C Movie Rating System!\n");
    printf("How many movies do you want to rate? ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movies[i].title);

        printf("Enter the director of movie %d: ", i+1);
        scanf("%s", movies[i].director);

        printf("Enter the actors of movie %d (comma separated): ", i+1);
        scanf("%s", movies[i].actors);

        printf("Enter the genres of movie %d (comma separated): ", i+1);
        scanf("%s", movies[i].genres);

        printf("Enter the runtime of movie %d (in minutes): ", i+1);
        scanf("%d", &movies[i].runtime);

        printf("Enter the rating of movie %d (out of 10): ", i+1);
        scanf("%d", &movies[i].rating);

        printf("Enter the gross revenue of movie %d (in millions): ", i+1);
        scanf("%d", &movies[i].gross_revenue);
    }

    printf("\nThank you for rating movies!\n");

    return 0;
}