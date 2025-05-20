//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char title[100];
    char director[100];
    char actors[300];
    int runtime;
    char genre[50];
    int rating;
} Movie;

int main() {
    int numMovies, i;
    scanf("%d", &numMovies);
    Movie movies[numMovies];

    for(i = 0; i < numMovies; i++) {
        scanf("%s", movies[i].title);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].genre);
        scanf("%d", &movies[i].runtime);
        scanf("%s", movies[i].actors);
        scanf("%d", &movies[i].rating);
    }

    char searchActor[100];
    scanf("%s", searchActor);

    int count = 0;
    for(i = 0; i < numMovies; i++) {
        if(strstr(movies[i].actors, searchActor)) {
            printf("Movie %d:\n", i+1);
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Genre: %s\n", movies[i].genre);
            printf("Runtime: %d minutes\n", movies[i].runtime);
            printf("Actors: %s\n", movies[i].actors);
            printf("Rating: %d\n\n", movies[i].rating);
            count++;
        }
    }

    if(count == 0) {
        printf("No movies found with that actor.\n");
    }

    return 0;
}