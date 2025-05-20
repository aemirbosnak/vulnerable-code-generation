//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare movie objects
    struct Movie {
        char title[50];
        int rating;
    };
    struct Movie movie1, movie2, movie3, movie4;

    // Prompt user for movie information
    printf("Enter movie title: ");
    scanf("%s", movie1.title);
    printf("Enter movie rating: ");
    scanf("%d", &movie1.rating);

    printf("Enter movie title: ");
    scanf("%s", movie2.title);
    printf("Enter movie rating: ");
    scanf("%d", &movie2.rating);

    printf("Enter movie title: ");
    scanf("%s", movie3.title);
    printf("Enter movie rating: ");
    scanf("%d", &movie3.rating);

    printf("Enter movie title: ");
    scanf("%s", movie4.title);
    printf("Enter movie rating: ");
    scanf("%d", &movie4.rating);

    // Sort movies by rating in descending order
    struct Movie *sortedMovies = malloc(4 * sizeof(struct Movie));
    int i, j;
    for (i = 0; i < 4; i++) {
        sortedMovies[i] = movie1;
    }
    for (i = 1; i < 4; i++) {
        for (j = i; j > 0 && sortedMovies[j-1].rating < sortedMovies[j].rating; j--) {
            sortedMovies[j] = sortedMovies[j-1];
        }
        sortedMovies[j] = movie2;
    }
    for (i = 2; i < 4; i++) {
        for (j = i; j > 0 && sortedMovies[j-1].rating < sortedMovies[j].rating; j--) {
            sortedMovies[j] = sortedMovies[j-1];
        }
        sortedMovies[j] = movie3;
    }
    for (i = 3; i < 4; i++) {
        for (j = i; j > 0 && sortedMovies[j-1].rating < sortedMovies[j].rating; j--) {
            sortedMovies[j] = sortedMovies[j-1];
        }
        sortedMovies[j] = movie4;
    }

    // Display sorted movies
    printf("Sorted Movies by Rating (descending):\n");
    for (i = 0; i < 4; i++) {
        printf("%s (%d)\n", sortedMovies[i].title, sortedMovies[i].rating);
    }

    // Free memory
    free(sortedMovies);

    return 0;
}