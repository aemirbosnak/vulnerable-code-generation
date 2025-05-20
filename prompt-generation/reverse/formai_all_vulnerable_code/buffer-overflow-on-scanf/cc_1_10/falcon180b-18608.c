//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie details:\n");
        printf("Title: ");
        fgets(movies[num_movies].title, MAX_TITLE_LENGTH, stdin);
        movies[num_movies].title[strcspn(movies[num_movies].title, "\n")] = '\0';

        printf("Director: ");
        fgets(movies[num_movies].director, MAX_DIRECTOR_LENGTH, stdin);
        movies[num_movies].director[strcspn(movies[num_movies].director, "\n")] = '\0';

        printf("Actors: ");
        fgets(movies[num_movies].actors, MAX_ACTORS_LENGTH, stdin);
        movies[num_movies].actors[strcspn(movies[num_movies].actors, "\n")] = '\0';

        printf("Genre: ");
        fgets(movies[num_movies].genre, MAX_GENRE_LENGTH, stdin);
        movies[num_movies].genre[strcspn(movies[num_movies].genre, "\n")] = '\0';

        printf("Rating: ");
        scanf("%d", &movies[num_movies].rating);

        num_movies++;
    }

    int total_rating = 0;
    for (int i = 0; i < num_movies; i++) {
        total_rating += movies[i].rating;
    }

    float average_rating = (float)total_rating / num_movies;

    printf("Average rating: %.2f\n", average_rating);

    return 0;
}