//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_RATING_VALUE 5

typedef struct {
    char title[100];
    char director[100];
    char actors[200];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_rating(Movie *movie) {
    int rating;
    printf("Enter rating (0-5): ");
    scanf("%d", &rating);
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

int get_average_rating(Movie *movie) {
    int sum = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        sum += movie->ratings[i];
    }
    return sum / movie->num_ratings;
}

int main() {
    Movie movie;
    strcpy(movie.title, "");
    strcpy(movie.director, "");
    strcpy(movie.actors, "");
    movie.num_ratings = 0;

    printf("Enter movie title: ");
    scanf("%s", movie.title);

    printf("Enter director name: ");
    scanf("%s", movie.director);

    printf("Enter actors (separated by commas): ");
    scanf("%s", movie.actors);

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add rating\n");
        printf("2. View ratings\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_rating(&movie);
                break;
            case 2:
                if (movie.num_ratings == 0) {
                    printf("No ratings yet.\n");
                } else {
                    printf("Average rating: %d\n", get_average_rating(&movie));
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}