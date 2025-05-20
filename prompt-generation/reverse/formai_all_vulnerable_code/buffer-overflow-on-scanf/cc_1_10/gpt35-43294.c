//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_MOVIES 10

typedef struct {
    char name[20];
    float ratings[MAX_RATINGS];
    int numRatings;
} Movie;

Movie movies[MAX_MOVIES];
int numMovies = 0;

void addMovie(char *name) {
    if (numMovies >= MAX_MOVIES) {
        printf("Error: maximum number of movies reached\n");
        return;
    }

    Movie newMovie;
    strcpy(newMovie.name, name);
    newMovie.numRatings = 0;
    movies[numMovies] = newMovie;
    numMovies++;
}

void addRating(char *name, float rating) {
    int i, index = -1;

    for (i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: movie not found\n");
        return;
    }

    if (movies[index].numRatings >= MAX_RATINGS) {
        printf("Error: maximum number of ratings reached for this movie\n");
        return;
    }

    movies[index].ratings[movies[index].numRatings] = rating;
    movies[index].numRatings++;
}

void printMovieRatings(char *name) {
    int i, index = -1;
    float sum = 0, avg;

    for (i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: movie not found\n");
        return;
    }

    printf("Ratings for %s:\n", name);
    for (i = 0; i < movies[index].numRatings; i++) {
        printf("%.1f\n", movies[index].ratings[i]);
        sum += movies[index].ratings[i];
    }

    if (movies[index].numRatings > 0) {
        avg = sum / movies[index].numRatings;
        printf("Average rating: %.1f\n", avg);
    } else {
        printf("No ratings\n");
    }
}

int main() {
    int choice;
    char name[20];
    float rating;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add movie\n");
        printf("2. Add rating for movie\n");
        printf("3. Print movie ratings\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie name: ");
                scanf("%s", name);
                addMovie(name);
                break;
            case 2:
                printf("Enter movie name: ");
                scanf("%s", name);
                printf("Enter rating: ");
                scanf("%f", &rating);
                addRating(name, rating);
                break;
            case 3:
                printf("Enter movie name: ");
                scanf("%s", name);
                printMovieRatings(name);
                break;
            case 4:
                return 0;
            default:
                printf("Error: invalid choice\n");
        }
    }
}