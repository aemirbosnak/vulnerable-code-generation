//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5
#define MAX_NAME_LENGTH 50
#define MAX_GENRE_LENGTH 20
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    int ratings[MAX_RATINGS];
    int numRatings;
} Movie;

void initializeMovie(Movie *movie) {
    strcpy(movie->name, "");
    strcpy(movie->genre, "");
    strcpy(movie->director, "");
    strcpy(movie->actors, "");
    movie->numRatings = 0;
}

void addRating(Movie *movie, int rating) {
    if (movie->numRatings >= MAX_RATINGS) {
        printf("Error: Cannot add more than %d ratings.\n", MAX_RATINGS);
        return;
    }
    movie->ratings[movie->numRatings] = rating;
    movie->numRatings++;
}

void printMovie(const Movie *movie) {
    printf("Name: %s\n", movie->name);
    printf("Genre: %s\n", movie->genre);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Ratings: ");
    for (int i = 0; i < movie->numRatings; i++) {
        printf("%d ", movie->ratings[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_LENGTH];
    char name[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    int choice;

    do {
        printf("Welcome to the Movie Rating System!\n");
        printf("Please enter your choice:\n");
        printf("1. Add a movie\n");
        printf("2. Print all movies\n");
        printf("3. Print a specific movie\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter movie name: ");
            scanf("%s", name);
            printf("Enter movie genre: ");
            scanf("%s", genre);
            printf("Enter movie director: ");
            scanf("%s", director);
            printf("Enter movie actors: ");
            scanf("%s", actors);
            initializeMovie(&movies[numMovies]);
            strcpy(movies[numMovies].name, name);
            strcpy(movies[numMovies].genre, genre);
            strcpy(movies[numMovies].director, director);
            strcpy(movies[numMovies].actors, actors);
            numMovies++;
            break;

        case 2:
            printf("All movies:\n");
            for (int i = 0; i < numMovies; i++) {
                printMovie(&movies[i]);
            }
            break;

        case 3:
            printf("Enter movie index: ");
            scanf("%d", &choice);
            if (choice >= 0 && choice < numMovies) {
                printMovie(&movies[choice]);
            } else {
                printf("Error: Invalid movie index.\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Error: Invalid choice.\n");
        }
    } while (1);

    return 0;
}