//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_ACTORS 10
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH][MAX_ACTORS];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors:");
    for (int i = 0; i < MAX_ACTORS; i++) {
        if (movie->actors[i][0]!= '\0') {
            printf(" %s", movie->actors[i]);
        }
    }
    printf("\n");
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
}

int main() {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH][MAX_ACTORS];
    char genre[MAX_GENRE_LENGTH];
    int rating;

    printf("Enter the movie title: ");
    scanf("%s", title);
    printf("Enter the movie director: ");
    scanf("%s", director);
    printf("Enter the movie actors (comma separated): ");
    scanf("%s", actors[0]);
    printf("Enter the movie genre: ");
    scanf("%s", genre);
    printf("Enter the movie rating (0-5): ");
    scanf("%d", &rating);

    Movie movie;
    strcpy(movie.title, title);
    strcpy(movie.director, director);
    strcpy(movie.genre, genre);
    movie.rating = rating;

    int num_actors = 0;
    char* token = strtok(actors[0], ",");
    while (token!= NULL) {
        strcpy(movie.actors[num_actors], token);
        num_actors++;
        token = strtok(NULL, ",");
    }

    print_movie(&movie);

    return 0;
}