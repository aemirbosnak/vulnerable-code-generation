//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct movie {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[10];
    int year;
} Movie;

int main() {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[10];
    int year;
    int num_movies = 0;

    printf("Enter the number of movies you want to rate: ");
    scanf("%d", &num_movies);

    Movie movies[MAX_MOVIES];

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", title);
        strcpy(movies[i].title, title);

        printf("Director: ");
        scanf("%s", director);
        strcpy(movies[i].director, director);

        printf("Genre: ");
        scanf("%s", genre);
        strcpy(movies[i].genre, genre);

        printf("Rating (out of 10): ");
        scanf("%s", rating);
        strcpy(movies[i].rating, rating);

        printf("Year: ");
        scanf("%d", &year);
        movies[i].year = year;
    }

    printf("\nMovie Ratings:\n");
    printf("------------------------\n");
    printf("| Title | Director | Genre | Rating | Year |\n");
    printf("------------------------\n");

    for (int i = 0; i < num_movies; i++) {
        printf("| %s | %s | %s | %s | %d |\n", movies[i].title, movies[i].director, movies[i].genre, movies[i].rating, movies[i].year);
        printf("------------------------\n");
    }

    return 0;
}