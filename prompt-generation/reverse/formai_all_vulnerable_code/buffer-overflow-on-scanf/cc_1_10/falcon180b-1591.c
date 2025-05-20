//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 1000
#define MAX_RATINGS 1000

typedef struct {
    char title[100];
    char director[100];
    char actors[100];
    int year;
    int length;
    float rating;
} Movie;

typedef struct {
    char name[100];
    int age;
    int rating;
} Critic;

Movie movies[MAX_MOVIES];
Critic critics[MAX_RATINGS];

int numMovies = 0;
int numCritics = 0;

void addMovie() {
    if (numMovies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }

    printf("Enter movie title: ");
    scanf("%s", movies[numMovies].title);

    printf("Enter movie director: ");
    scanf("%s", movies[numMovies].director);

    printf("Enter movie actors: ");
    scanf("%s", movies[numMovies].actors);

    printf("Enter movie year: ");
    scanf("%d", &movies[numMovies].year);

    printf("Enter movie length (in minutes): ");
    scanf("%d", &movies[numMovies].length);

    printf("Enter movie rating (out of 5): ");
    scanf("%f", &movies[numMovies].rating);

    numMovies++;
}

void addCritic() {
    if (numCritics >= MAX_RATINGS) {
        printf("Error: Maximum number of critics reached.\n");
        return;
    }

    printf("Enter critic name: ");
    scanf("%s", critics[numCritics].name);

    printf("Enter critic age: ");
    scanf("%d", &critics[numCritics].age);

    printf("Enter critic rating (out of 5): ");
    scanf("%d", &critics[numCritics].rating);

    numCritics++;
}

void displayMovies() {
    printf("\nMovie List:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d)\n", movies[i].title, movies[i].rating);
    }
}

void displayCritics() {
    printf("\nCritic List:\n");
    for (int i = 0; i < numCritics; i++) {
        printf("%s (%d)\n", critics[i].name, critics[i].rating);
    }
}

void calculateAverageRating() {
    float totalRating = 0;

    for (int i = 0; i < numCritics; i++) {
        totalRating += critics[i].rating;
    }

    float averageRating = totalRating / numCritics;

    printf("\nAverage Rating: %.2f\n", averageRating);
}

int main() {
    printf("Welcome to the C Movie Rating System!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add Movie\n");
        printf("2. Add Critic\n");
        printf("3. Display Movies\n");
        printf("4. Display Critics\n");
        printf("5. Calculate Average Rating\n");
        printf("6. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addMovie();
            break;

        case 2:
            addCritic();
            break;

        case 3:
            displayMovies();
            break;

        case 4:
            displayCritics();
            break;

        case 5:
            calculateAverageRating();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}