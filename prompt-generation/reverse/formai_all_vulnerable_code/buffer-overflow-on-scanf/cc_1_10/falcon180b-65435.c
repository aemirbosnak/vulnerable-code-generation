//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 30
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH + 1];
    char director[MAX_DIRECTOR_LENGTH + 1];
    char actor[MAX_ACTOR_LENGTH + 1];
    char genre[MAX_GENRE_LENGTH + 1];
    int rating;
} Movie;

int main() {
    int num_movies;
    Movie movies[100];
    char input[100];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie #%d:\n", i + 1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actor: ");
        scanf("%s", movies[i].actor);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating);
    }

    printf("Enter a movie title to search for: ");
    scanf("%s", input);

    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, input) == 0) {
            printf("Movie found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Actor: %s\n", movies[i].actor);
            printf("Genre: %s\n", movies[i].genre);
            printf("Rating: %d\n", movies[i].rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }

    return 0;
}