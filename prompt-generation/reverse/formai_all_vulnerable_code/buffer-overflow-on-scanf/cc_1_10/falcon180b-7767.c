//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_RATING_LENGTH 100
#define MAX_MOVIE_LENGTH 100

struct Rating {
    char movie[MAX_MOVIE_LENGTH];
    char rater[MAX_RATING_LENGTH];
    int rating;
};

struct Rating ratings[MAX_RATINGS];
int num_ratings = 0;

void add_rating() {
    if (num_ratings >= MAX_RATINGS) {
        printf("Error: Maximum number of ratings reached.\n");
        return;
    }

    printf("Enter the name of the movie: ");
    scanf("%s", ratings[num_ratings].movie);

    printf("Enter your name: ");
    scanf("%s", ratings[num_ratings].rater);

    printf("Enter your rating (1-5): ");
    scanf("%d", &ratings[num_ratings].rating);

    num_ratings++;
}

void print_ratings() {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("%s - %s - %d\n", ratings[i].movie, ratings[i].rater, ratings[i].rating);
    }
}

int main() {
    printf("Welcome to the Movie Rating System!\n");

    while (1) {
        printf("\n");
        printf("1. Add a rating\n");
        printf("2. Print ratings\n");
        printf("3. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_rating();
                break;
            case 2:
                print_ratings();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}