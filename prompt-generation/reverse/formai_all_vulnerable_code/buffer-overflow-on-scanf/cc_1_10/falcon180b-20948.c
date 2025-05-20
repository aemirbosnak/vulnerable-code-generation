//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Movie {
    char title[100];
    char director[50];
    char actors[200];
    char plot[200];
    char genre[50];
    int runtime;
    int rating;
};

void addMovie(struct Movie *movies, int numMovies, char title[], char director[], char actors[], char plot[], char genre[], int runtime, int rating) {
    strcpy(movies[numMovies].title, title);
    strcpy(movies[numMovies].director, director);
    strcpy(movies[numMovies].actors, actors);
    strcpy(movies[numMovies].plot, plot);
    strcpy(movies[numMovies].genre, genre);
    movies[numMovies].runtime = runtime;
    movies[numMovies].rating = rating;
}

void displayMovies(struct Movie movies[], int numMovies) {
    printf("Movie Title\tDirector\tActors\tPlot\tGenre\tRuntime (mins)\tRating\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", movies[i].title, movies[i].director, movies[i].actors, movies[i].plot, movies[i].genre, movies[i].runtime, movies[i].rating);
    }
}

int main() {
    struct Movie movies[10];
    int numMovies = 0;
    char choice;

    do {
        printf("\nWelcome to the Movie Rating System\n");
        printf("---------------------------------\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the movie details:\n");
                printf("Title: ");
                scanf("%s", movies[numMovies].title);
                printf("Director: ");
                scanf("%s", movies[numMovies].director);
                printf("Actors: ");
                scanf("%s", movies[numMovies].actors);
                printf("Plot: ");
                scanf("%s", movies[numMovies].plot);
                printf("Genre: ");
                scanf("%s", movies[numMovies].genre);
                printf("Runtime (in minutes): ");
                scanf("%d", &movies[numMovies].runtime);
                printf("Rating (out of 10): ");
                scanf("%d", &movies[numMovies].rating);
                numMovies++;
                break;
            case '2':
                displayMovies(movies, numMovies);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}