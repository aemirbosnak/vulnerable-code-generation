//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct Movie {
    char title[50];
    int ratings[MAX_RATINGS];
    int numRatings;
};

int main() {
    struct Movie movies[MAX_MOVIES];
    int numMovies = 0;
    char choice;

    do {
        printf("\n\nMovie Rating System\n");
        printf("---------------------\n");
        printf("1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. View ratings for a movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (numMovies >= MAX_MOVIES) {
                printf("Sorry, maximum number of movies reached.\n");
            } else {
                printf("Enter the title of the movie: ");
                scanf("%s", movies[numMovies].title);
                movies[numMovies].numRatings = 0;
                printf("Movie added successfully!\n");
                numMovies++;
            }
            break;
        case '2':
            printf("Enter the title of the movie to rate: ");
            scanf("%s", movies[numMovies - 1].title);
            printf("Enter the rating (1-5): ");
            scanf("%d", &movies[numMovies - 1].ratings[movies[numMovies - 1].numRatings]);
            movies[numMovies - 1].numRatings++;
            printf("Rating added successfully!\n");
            break;
        case '3':
            printf("Enter the title of the movie to view ratings: ");
            scanf("%s", movies[numMovies - 1].title);
            printf("Ratings for %s:\n", movies[numMovies - 1].title);
            for (int i = 0; i < movies[numMovies - 1].numRatings; i++) {
                printf("%d\n", movies[numMovies - 1].ratings[i]);
            }
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}