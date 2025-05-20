//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[100];
    int numRatings;
    int totalRating;
} Movie;

void addRating(Movie* movie, int rating) {
    movie->numRatings++;
    movie->totalRating += rating;
}

void printMovie(Movie* movie) {
    printf("Movie: %s\n", movie->title);
    printf("Number of ratings: %d\n", movie->numRatings);
    printf("Total rating: %d\n", movie->totalRating);
}

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    int choice;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. Print movie ratings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            if(numMovies >= MAX_MOVIES) {
                printf("Maximum number of movies reached.\n");
            } else {
                printf("Enter movie title: ");
                scanf("%s", movies[numMovies].title);
                movies[numMovies].numRatings = 0;
                movies[numMovies].totalRating = 0;
                numMovies++;
            }
            break;

        case 2:
            printf("Enter movie title: ");
            scanf("%s", movies[numMovies-1].title);
            int rating;
            printf("Enter rating (1-10): ");
            scanf("%d", &rating);
            addRating(&movies[numMovies-1], rating);
            break;

        case 3:
            printf("Movie ratings:\n");
            for(int i=0; i<numMovies; i++) {
                printMovie(&movies[i]);
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while(choice!= 4);

    return 0;
}