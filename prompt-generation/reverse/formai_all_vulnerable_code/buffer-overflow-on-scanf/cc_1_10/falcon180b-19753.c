//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5

typedef struct {
    char title[50];
    char director[50];
    int year;
    int ratings[MAX_RATINGS];
    float avg_rating;
    int num_ratings;
} Movie;

void init_ratings(Movie* movie) {
    for (int i = 0; i < MAX_RATINGS; i++) {
        movie->ratings[i] = 0;
    }
    movie->num_ratings = 0;
    movie->avg_rating = 0;
}

void add_rating(Movie* movie, int rating) {
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
    movie->avg_rating = (movie->avg_rating * movie->num_ratings + rating) / (movie->num_ratings + 1);
}

void print_movie_info(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Year: %d\n", movie->year);
    printf("Average Rating: %.2f\n", movie->avg_rating);
}

int main() {
    Movie movie;
    init_ratings(&movie);

    int choice;
    do {
        printf("\nMovie Rating System\n");
        printf("1. Add a rating\n");
        printf("2. Print movie info\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your rating (1-5): ");
            int rating = scanf("%d", &rating);
            add_rating(&movie, rating);
            break;
        case 2:
            print_movie_info(&movie);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}