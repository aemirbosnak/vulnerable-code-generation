//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_RATING_LENGTH 100

typedef struct {
    char name[MAX_RATING_LENGTH];
    int rating;
} rating_t;

int main() {
    int num_ratings;
    rating_t ratings[MAX_RATINGS];
    int i, j;
    char input[MAX_RATING_LENGTH];

    // Read in number of ratings
    printf("Enter number of ratings: ");
    scanf("%d", &num_ratings);

    // Read in ratings
    for (i = 0; i < num_ratings; i++) {
        printf("Enter name for rating %d: ", i + 1);
        scanf("%s", input);
        strncpy(ratings[i].name, input, MAX_RATING_LENGTH);
        printf("Enter rating for %s: ", ratings[i].name);
        scanf("%d", &ratings[i].rating);
    }

    // Sort ratings by rating
    for (i = 0; i < num_ratings - 1; i++) {
        for (j = i + 1; j < num_ratings; j++) {
            if (ratings[j].rating > ratings[i].rating) {
                rating_t temp = ratings[i];
                ratings[i] = ratings[j];
                ratings[j] = temp;
            }
        }
    }

    // Print ratings
    printf("\nMovie Ratings:\n");
    for (i = 0; i < num_ratings; i++) {
        printf("%s: %d\n", ratings[i].name, ratings[i].rating);
    }

    return 0;
}