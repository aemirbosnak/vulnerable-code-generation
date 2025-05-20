//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_RATING_LENGTH 50

struct rating {
    char movie[MAX_RATING_LENGTH];
    int score;
};

void add_rating(struct rating* ratings, int num_ratings, char* movie, int score) {
    if (num_ratings >= MAX_RATINGS) {
        printf("Error: Maximum number of ratings reached.\n");
        return;
    }

    for (int i = 0; i < num_ratings; i++) {
        if (strcmp(movie, ratings[i].movie) == 0) {
            printf("Movie already rated.\n");
            return;
        }
    }

    strcpy(ratings[num_ratings].movie, movie);
    ratings[num_ratings].score = score;
    num_ratings++;
}

void print_ratings(struct rating* ratings, int num_ratings) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("%s: %d\n", ratings[i].movie, ratings[i].score);
    }
}

int main() {
    struct rating ratings[MAX_RATINGS];
    int num_ratings = 0;

    while (1) {
        printf("Enter movie name: ");
        char movie[MAX_RATING_LENGTH];
        scanf("%s", movie);

        printf("Enter rating (1 to 10): ");
        int score;
        scanf("%d", &score);

        add_rating(ratings, num_ratings, movie, score);

        if (num_ratings == 0) {
            printf("No ratings yet.\n");
        } else {
            print_ratings(ratings, num_ratings);
        }
    }

    return 0;
}