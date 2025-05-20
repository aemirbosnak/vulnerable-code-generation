//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Film;

void addFilm(Film* films, int numFilms) {
    printf("Enter film title: ");
    scanf("%s", &films[numFilms].title);
    printf("Enter film director: ");
    scanf("%s", &films[numFilms].director);
    printf("Enter film actors (comma-separated): ");
    scanf("%s", &films[numFilms].actors);
    printf("Enter film genre: ");
    scanf("%s", &films[numFilms].genre);
    printf("Enter film rating (1-5): ");
    scanf("%d", &films[numFilms].rating);
}

void printFilms(Film* films, int numFilms) {
    for (int i = 0; i < numFilms; i++) {
        printf("%s\n", films[i].title);
        printf("Director: %s\n", films[i].director);
        printf("Actors: %s\n", films[i].actors);
        printf("Genre: %s\n", films[i].genre);
        printf("Rating: %d\n\n", films[i].rating);
    }
}

int main() {
    Film films[MAX_FILMS];
    int numFilms = 0;

    while (numFilms < MAX_FILMS) {
        addFilm(films, numFilms);
        numFilms++;
    }

    printFilms(films, numFilms);

    return 0;
}