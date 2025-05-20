//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RATINGS 5

typedef struct {
    char name[50];
    int rating;
    int count;
} Movie;

void addRating(Movie *movies, int n, int rating) {
    for (int i = 0; i < n; i++) {
        if (strcmp(movies[i].name, "") == 0) {
            strcpy(movies[i].name, "New Movie");
            movies[i].rating = rating;
            movies[i].count = 1;
            return;
        }
    }
    printf("Maximum number of movies reached.\n");
}

void displayRatings(Movie movies[], int n) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(movies[i].name, "")!= 0) {
            printf("%s - %.1f (based on %d ratings)\n", movies[i].name, (float)movies[i].rating / movies[i].count, movies[i].count);
        }
    }
}

int main() {
    Movie movies[MAX_RATINGS];
    int n = 0;

    while (n < MAX_RATINGS) {
        char name[50];
        int rating;

        printf("Enter the name of the movie: ");
        scanf("%s", name);

        printf("Enter the rating (1 to 5): ");
        while ((scanf("%d", &rating)!= 1) || (rating < 1) || (rating > 5)) {
            printf("Invalid rating. Please enter a rating between 1 and 5: ");
        }

        addRating(movies, n, rating);
        n++;
    }

    displayRatings(movies, n);

    return 0;
}