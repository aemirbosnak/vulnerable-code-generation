//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void addMovie(Movie *movies, int *movieCount);
void rateMovie(Movie *movies, int movieCount);
void displayRatings(Movie *movies, int movieCount);
void poeticDisplay(Movie *movies, int movieCount);

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    printf("In fair Verona, where we lay our scene,\n");
    printf("Welcome to the Movie Rating System, oh so serene!\n");

    while (1) {
        printf("\n1. Add Movie\n2. Rate Movie\n3. Display Ratings\n4. Exit\n");
        printf("Choose thy fate (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                poeticDisplay(movies, movieCount);
                break;
            case 4:
                printf("Parting is such sweet sorrow, we bid thee farewell!\n");
                exit(0);
            default:
                printf("A rose by any other name, but choose wisely!\n");
        }
    }

    return 0;
}

void addMovie(Movie *movies, int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("The stage is too full, no more films can be added!\n");
        return;
    }

    printf("What light through yonder window breaks? Enter movie title: ");
    getchar();  // consume newline
    fgets(movies[*movieCount].title, MAX_TITLE_LENGTH, stdin);
    movies[*movieCount].title[strcspn(movies[*movieCount].title, "\n")] = 0; // remove newline

    movies[*movieCount].rating = 0.0; // Initialize with zero rating
    strcpy(movies[*movieCount].review, ""); // No review initially

    (*movieCount)++;
    printf("A new movie has entered the realm!\n");
}

void rateMovie(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("Alas, no movie to rate! Add a movie first.\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s\n", i + 1, movies[i].title);
    }

    int chosenMovie;
    printf("Choose a movie to bestow a rating upon (1-%d): ", movieCount);
    scanf("%d", &chosenMovie);

    if (chosenMovie < 1 || chosenMovie > movieCount) {
        printf("O, misfortune hath struck! Choose wisely!\n");
        return;
    }

    float newRating;
    printf("Enter thy rating (0.0 - 10.0): ");
    scanf("%f", &newRating);

    if (newRating < 0.0 || newRating > 10.0) {
        printf("Beware, for thy rating must be in the range of 0.0 and 10.0!\n");
        return;
    }

    strcpy(movies[chosenMovie - 1].review, "A love that transcends all boundaries.");
    movies[chosenMovie - 1].rating = (movies[chosenMovie - 1].rating + newRating) / 2.0; // Average rating
    printf("The rating hath been bestowed, and love doth flourish!\n");
}

void poeticDisplay(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No heart to cherish, no ratings to reveal!\n");
        return;
    }

    printf("\n\nOh, the tales of our honored films:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("For the film '%s', thy rating is: %.2f\n", movies[i].title, movies[i].rating);
        printf("Review: %s\n", movies[i].review);
    }
}