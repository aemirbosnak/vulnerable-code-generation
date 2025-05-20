//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MIN_RATING 1
#define MAX_RATING 10

typedef struct {
    char title[MAX_NAME_LENGTH];
    int num_ratings;
    int total_rating;
} Movie;

Movie movies[MAX_MOVIES];

int main() {
    int choice, i, j;
    char name[MAX_NAME_LENGTH];
    int movie_index = -1, rating;

    while (1) {
        printf("\n1. Rate a movie\n");
        printf("2. Display movie ratings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the title of the movie: ");
                scanf("%s", name);

                for (i = 0; i < MAX_MOVIES && movies[i].title[0] != '\0'; i++) {
                    if (strcmp(movies[i].title, name) == 0) {
                        movie_index = i;
                        break;
                    }
                }

                if (movie_index == -1) {
                    printf("Movie not found. Adding new movie.\n");
                    strcpy(movies[MAX_MOVIES - 1].title, name);
                    movies[MAX_MOVIES - 1].num_ratings = 1;
                    movies[MAX_MOVIES - 1].total_rating = rating;
                    movie_index = MAX_MOVIES - 1;
                } else {
                    printf("Enter your rating (1-10): ");
                    scanf("%d", &rating);

                    if (rating < MIN_RATING || rating > MAX_RATING) {
                        printf("Invalid rating. Please enter a rating between %d and %d.\n", MIN_RATING, MAX_RATING);
                        continue;
                    }

                    movies[movie_index].total_rating += rating;
                    movies[movie_index].num_ratings++;
                }
                break;

            case 2:
                printf("\nMovie Ratings:\n");
                for (i = 0; i < MAX_MOVIES && movies[i].title[0] != '\0'; i++) {
                    printf("%s: Average rating %.2f\n", movies[i].title, (float)movies[i].total_rating / movies[i].num_ratings);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}