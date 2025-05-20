//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 100
#define MAX_MOVIES 50
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float rating;
} Movie;

struct MovieRatings {
    Movie movies[MAX_MOVIES];
    int numMovies;
};

struct MovieRatings CR_System;

void initCRSystem() {
    CR_System.numMovies = 0;
}

void addMovie(char* name) {
    if (CR_System.numMovies < MAX_MOVIES) {
        strcpy(CR_System.movies[CR_System.numMovies].name, name);
        CR_System.numMovies++;
    } else {
        printf("Error: Maximum number of movies reached.\n");
    }
}

void rateMovie(char* name, float rating) {
    int i;

    for (i = 0; i < CR_System.numMovies; i++) {
        if (strcmp(CR_System.movies[i].name, name) == 0) {
            CR_System.movies[i].rating = rating;
            return;
        }
    }

    printf("Error: Movie not found.\n");
}

void printMovieRatings() {
    int i;

    for (i = 0; i < CR_System.numMovies; i++) {
        printf("%s: %.2f\n", CR_System.movies[i].name, CR_System.movies[i].rating);
    }
}

int main() {
    char movieName[MAX_NAME_LEN];
    float rating;
    int choice;

    initCRSystem();

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Print Ratings\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie name: ");
                scanf("%s", movieName);
                addMovie(movieName);
                break;
            case 2:
                printf("Enter movie name: ");
                scanf("%s", movieName);
                printf("Enter rating: ");
                scanf("%f", &rating);
                rateMovie(movieName, rating);
                break;
            case 3:
                printMovieRatings();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}