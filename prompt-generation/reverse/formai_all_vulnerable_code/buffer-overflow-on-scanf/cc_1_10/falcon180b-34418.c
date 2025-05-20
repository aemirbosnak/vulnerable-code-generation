//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 100
#define MAX_GENRE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 100
#define MAX_ACTORS_LENGTH 100
#define MAX_RATING 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies;

void add_movie() {
    if (num_movies >= MAX_MOVIES) {
        printf("Cannot add more movies.\n");
        return;
    }

    printf("Enter movie name: ");
    scanf(" %[^\n]", movies[num_movies].name);

    printf("Enter movie genre: ");
    scanf(" %[^\n]", movies[num_movies].genre);

    printf("Enter movie director: ");
    scanf(" %[^\n]", movies[num_movies].director);

    printf("Enter movie actors: ");
    scanf(" %[^\n]", movies[num_movies].actors);

    printf("Enter movie rating (1-5): ");
    scanf("%d", &movies[num_movies].rating);

    num_movies++;
}

void display_movies() {
    printf("Movie Name\tGenre\tDirector\tActors\tRating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%s\t%s\t%s\t%d\n", movies[i].name, movies[i].genre, movies[i].director, movies[i].actors, movies[i].rating);
    }
}

void search_movies() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter movie name to search: ");
    scanf(" %[^\n]", search_name);

    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, search_name) == 0) {
            printf("Movie found:\n");
            printf("Name: %s\n", movies[i].name);
            printf("Genre: %s\n", movies[i].genre);
            printf("Director: %s\n", movies[i].director);
            printf("Actors: %s\n", movies[i].actors);
            printf("Rating: %d\n\n", movies[i].rating);
        }
    }
}

int main() {
    num_movies = 0;

    add_movie();
    add_movie();
    add_movie();

    display_movies();

    search_movies();

    return 0;
}