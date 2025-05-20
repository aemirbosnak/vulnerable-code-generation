//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Movie {
    char title[50];
    char director[50];
    char actors[100];
    char genre[50];
    int runtime;
    time_t release_date;
};

int hash(char* str) {
    int sum = 0;
    int i = 0;
    while(str[i]) {
        sum += str[i];
        i++;
    }
    return sum % 10;
}

void addMovie(struct Movie* movies, int numMovies, char* title, char* director, char* actors, char* genre, int runtime, time_t release_date) {
    int index = hash(title);
    while(movies[index].title[0]!= '\0') {
        index = (index + 1) % numMovies;
    }
    strcpy(movies[index].title, title);
    strcpy(movies[index].director, director);
    strcpy(movies[index].actors, actors);
    strcpy(movies[index].genre, genre);
    movies[index].runtime = runtime;
    movies[index].release_date = release_date;
}

void printMovie(struct Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Runtime: %d minutes\n", movie.runtime);
    printf("Release Date: %s\n", ctime(&movie.release_date));
}

int main() {
    struct Movie movies[10];
    int numMovies = 0;
    char title[50];
    char director[50];
    char actors[100];
    char genre[50];
    int runtime;
    time_t release_date;

    printf("Welcome to the Movie Rating System!\n");

    while(1) {
        printf("Enter movie title: ");
        scanf("%s", title);
        printf("Enter movie director: ");
        scanf("%s", director);
        printf("Enter movie actors (comma-separated): ");
        scanf("%s", actors);
        printf("Enter movie genre: ");
        scanf("%s", genre);
        printf("Enter movie runtime (in minutes): ");
        scanf("%d", &runtime);
        printf("Enter movie release date (YYYY-MM-DD): ");
        scanf("%s", genre);

        time_t now = time(NULL);
        struct tm* tm = localtime(&now);
        strftime(genre, 50, "%Y-%m-%d", tm);

        addMovie(movies, numMovies, title, director, actors, genre, runtime, now);
        numMovies++;
    }

    return 0;
}