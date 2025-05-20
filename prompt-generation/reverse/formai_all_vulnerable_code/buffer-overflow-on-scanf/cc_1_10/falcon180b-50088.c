//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RATING 5
#define MAX_FILM_NAME_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char filmName[MAX_FILM_NAME_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} FilmReview;

void addReview(FilmReview* filmReviews, int numReviews, char* filmName, int rating, char* review) {
    if (numReviews >= MAX_FILM_NAME_LENGTH) {
        printf("Error: Maximum number of reviews reached.\n");
        return;
    }

    strcpy(filmReviews[numReviews].filmName, filmName);
    filmReviews[numReviews].rating = rating;
    strcpy(filmReviews[numReviews].review, review);

    numReviews++;
}

void displayReviews(FilmReview* filmReviews, int numReviews) {
    printf("Film Reviews:\n");
    for (int i = 0; i < numReviews; i++) {
        printf("%s - Rating: %d - Review: %s\n", filmReviews[i].filmName, filmReviews[i].rating, filmReviews[i].review);
    }
}

int main() {
    FilmReview filmReviews[MAX_FILM_NAME_LENGTH];
    int numReviews = 0;

    char input[MAX_REVIEW_LENGTH];
    char filmName[MAX_FILM_NAME_LENGTH];
    int rating;

    while (1) {
        printf("\nEnter a film name, rating (0-5) and review (Press enter to submit):\n");
        scanf("%s %d %s", filmName, &rating, input);

        if (strlen(filmName) == 0) {
            break;
        }

        addReview(filmReviews, numReviews, filmName, rating, input);
    }

    displayReviews(filmReviews, numReviews);

    return 0;
}