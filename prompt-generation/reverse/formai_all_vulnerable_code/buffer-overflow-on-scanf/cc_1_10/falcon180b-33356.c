//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_SYNOPSIS_LENGTH 500
#define MAX_RATING_LENGTH 20
#define MAX_REVIEW_LENGTH 1000
#define MAX_USER_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char synopsis[MAX_SYNOPSIS_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
    char user_name[MAX_USER_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Synopsis: %s\n", movie->synopsis);
    printf("Rating: %s\n", movie->rating);
    printf("Review: %s\n", movie->review);
    printf("User name: %s\n", movie->user_name);
    printf("Date: %s\n", movie->date);
    printf("Time: %s\n", movie->time);
}

int main() {
    Movie movie;

    printf("Enter the title of the movie: ");
    scanf("%s", movie.title);

    printf("Enter the name of the director: ");
    scanf("%s", movie.director);

    printf("Enter the names of the actors (separated by commas): ");
    scanf("%s", movie.actors);

    printf("Enter the genre of the movie: ");
    scanf("%s", movie.genre);

    printf("Enter the synopsis of the movie: ");
    scanf("%s", movie.synopsis);

    printf("Enter the rating of the movie (out of 10): ");
    scanf("%s", movie.rating);

    printf("Enter your review of the movie: ");
    scanf("%s", movie.review);

    printf("Enter your name: ");
    scanf("%s", movie.user_name);

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", movie.date);

    printf("Enter the time (hh:mm): ");
    scanf("%s", movie.time);

    printf("\nMovie details:\n");
    print_movie(&movie);

    return 0;
}