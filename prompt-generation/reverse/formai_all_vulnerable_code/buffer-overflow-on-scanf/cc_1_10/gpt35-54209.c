//FormAI DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void displayHeader();
float getMovieRating(int index);
void printMovieDetails(int index);
void displayMovieList();
void setMovieRating(int index, float rating);

#define MOVIE_COUNT 10
#define MIN_RATING 0.0
#define MAX_RATING 10.0

char *movie_names[MOVIE_COUNT] = {
    "The Godfather",
    "The Shawshank Redemption",
    "Forrest Gump",
    "The Dark Knight",
    "Pulp Fiction",
    "The Lord of the Rings: Return of the King",
    "Star Wars: Episode IV - A New Hope",
    "Terminator 2: Judgment Day",
    "The Matrix",
    "Goodfellas"
};
float movie_ratings[MOVIE_COUNT] = {
    9.2,
    9.3,
    8.8,
    9.0,
    8.9,
    9.0,
    8.7,
    8.5,
    8.7,
    8.7
};

int main() {
    displayHeader();
    displayMovieList();
    int choice;
    do {
        printf("\nEnter movie number to view details and rate (1-%d) or 0 to exit: ", MOVIE_COUNT);
        scanf("%d", &choice);
        if (choice == 0) break;

        printMovieDetails(choice - 1);
        float rating;
        do {
            printf("\nEnter rating from %.1f to %.1f: ", MIN_RATING, MAX_RATING);
            scanf("%f", &rating);
        } while (rating < MIN_RATING || rating > MAX_RATING);

        setMovieRating(choice - 1, rating);
    } while (1);

    displayMovieList();
    return 0;
}

void displayHeader() {
    printf("+-----------------------------------------------------------+\n");
    printf("|              Welcome to the Movie Rating System            |\n");
    printf("+-----------------------------------------------------------+\n");
}

float getMovieRating(int index) {
    return movie_ratings[index];
}

void printMovieDetails(int index) {
    printf("\n%s\nRating: %.1f\n", movie_names[index], movie_ratings[index]);
}

void displayMovieList() {
    printf("\nList of Movies\n");
    for (int i = 0; i < MOVIE_COUNT; i++) {
        printf("%d. %s\n", i+1, movie_names[i]);
    }
}

void setMovieRating(int index, float rating) {
    movie_ratings[index] = rating;
    printf("\nYou rated %s %.1f out of %.1f\n", movie_names[index], rating, MAX_RATING);
}