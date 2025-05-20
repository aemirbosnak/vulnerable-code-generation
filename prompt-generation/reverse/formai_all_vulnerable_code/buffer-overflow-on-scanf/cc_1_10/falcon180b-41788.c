//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_VALUE 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} movie;

void print_movie(movie m) {
    printf("Title: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Actors: %s\n", m.actors);
    printf("Genre: %s\n", m.genre);
    printf("Rating: %d\n\n", m.rating);
}

int main() {
    int num_movies;
    movie movies[100];

    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    for(int i = 0; i < num_movies; i++) {
        printf("Enter title for movie %d: ", i+1);
        scanf("%s", movies[i].title);

        printf("Enter director for movie %d: ", i+1);
        scanf("%s", movies[i].director);

        printf("Enter actors for movie %d: ", i+1);
        scanf("%s", movies[i].actors);

        printf("Enter genre for movie %d: ", i+1);
        scanf("%s", movies[i].genre);

        printf("Enter rating for movie %d (1-10): ", i+1);
        scanf("%d", &movies[i].rating);
    }

    printf("Movie Ratings:\n");
    for(int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}