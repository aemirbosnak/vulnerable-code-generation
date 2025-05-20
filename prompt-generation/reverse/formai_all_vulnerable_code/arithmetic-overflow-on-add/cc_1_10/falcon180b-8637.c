//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RATING_COUNT 5

typedef struct {
    char name[50];
    int ratings[RATING_COUNT];
    float averageRating;
} Movie;

void initMovie(Movie* movie) {
    strcpy(movie->name, "");
    for (int i = 0; i < RATING_COUNT; i++) {
        movie->ratings[i] = 0;
    }
    movie->averageRating = 0.0;
}

void printMovie(Movie* movie) {
    printf("Movie Name: %s\n", movie->name);
    for (int i = 0; i < RATING_COUNT; i++) {
        printf("Rating %d: %d\n", i+1, movie->ratings[i]);
    }
    printf("Average Rating: %.2f\n\n", movie->averageRating);
}

int main() {
    srand(time(NULL));

    Movie myMovie;
    initMovie(&myMovie);

    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Rate the movie\n");
        printf("2. View ratings\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your rating (1-5): ");
                int rating = rand() % 6;
                myMovie.ratings[rating-1]++;
                myMovie.averageRating = (float)myMovie.averageRating + (float)rating;
                break;
            case 2:
                printMovie(&myMovie);
                break;
            case 3:
                printf("Thank you for using the Romantic Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}