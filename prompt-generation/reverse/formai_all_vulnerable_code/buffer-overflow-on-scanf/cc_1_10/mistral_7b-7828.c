//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 50
#define MAX_RATINGS 10

typedef struct movie {
    char title[MAX_TITLE];
    int ratings[MAX_RATINGS];
    int num_ratings;
    float avg_rating;
} movie;

void add_rating(movie* movie, int rating) {
    movie->ratings[movie->num_ratings++] = rating;
}

void calculate_avg_rating(movie* movie) {
    int sum = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        sum += movie->ratings[i];
    }
    movie->avg_rating = (float) sum / movie->num_ratings;
}

int main() {
    movie movies[MAX_MOVIES];
    char title[MAX_TITLE];
    int choice, rating;

    printf("Welcome to the C Movie Rating System!\n");

    while (1) {
        printf("\n1. Add movie rating\n");
        printf("2. Display movie ratings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);

                int movie_index = -1;
                for (int i = 0; i < MAX_MOVIES; i++) {
                    if (strcmp(movies[i].title, title) == 0) {
                        movie_index = i;
                        break;
                    }
                }

                if (movie_index == -1) {
                    printf("Movie not found. Adding new movie...\n");
                    strcpy(movies[MAX_MOVIES - 1].title, title);
                    movies[MAX_MOVIES - 1].num_ratings = 0;
                    movies[MAX_MOVIES - 1].avg_rating = 0;
                    movie_index = MAX_MOVIES - 1;
                }

                printf("Enter movie rating: ");
                scanf("%d", &rating);

                add_rating(&movies[movie_index], rating);
                calculate_avg_rating(&movies[movie_index]);

                printf("Movie rating added successfully.\n");
                break;

            case 2:
                printf("Enter movie title: ");
                scanf("%s", title);

                int index = -1;
                for (int i = 0; i < MAX_MOVIES; i++) {
                    if (strcmp(movies[i].title, title) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    printf("Movie title: %s\n", movies[index].title);
                    printf("Average rating: %.2f\n", movies[index].avg_rating);
                } else {
                    printf("Movie not found.\n");
                }
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}