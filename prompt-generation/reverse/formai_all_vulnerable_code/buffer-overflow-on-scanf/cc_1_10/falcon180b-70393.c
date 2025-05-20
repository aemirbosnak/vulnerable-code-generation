//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 1000
#define MAX_RATINGS 1000000

typedef struct {
    char title[50];
    int year;
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies;

int main() {
    srand(time(NULL));

    printf("Welcome to the Movie Rating System!\n");
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        movies[i].rating = rand() % 101;
        printf("Enter movie %d's title: ", i+1);
        scanf("%s", movies[i].title);
        printf("Enter movie %d's release year: ", i+1);
        scanf("%d", &movies[i].year);
    }

    int choice;
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Rate a movie\n");
        printf("2. View movie ratings\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the movie number you would like to rate: ");
                scanf("%d", &choice);
                if (choice >= 1 && choice <= num_movies) {
                    printf("Enter your rating for %s (%d): ", movies[choice-1].title, movies[choice-1].year);
                    scanf("%d", &movies[choice-1].rating);
                } else {
                    printf("Invalid movie number.\n");
                }
                break;
            case 2:
                printf("\nMovie Ratings:\n");
                for (int i = 0; i < num_movies; i++) {
                    printf("%s (%d) - %d\n", movies[i].title, movies[i].year, movies[i].rating);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}