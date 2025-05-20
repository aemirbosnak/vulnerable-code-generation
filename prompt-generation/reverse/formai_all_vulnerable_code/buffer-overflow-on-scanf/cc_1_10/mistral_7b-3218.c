//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 20
#define MAX_NAME_LENGTH 50
#define MAX_RATING_LENGTH 2

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rating;
    int ratings_count;
} Movie;

void add_rating(Movie* movies, int movie_index, int rating) {
    movies[movie_index].rating += rating;
    movies[movie_index].ratings_count++;
}

int main() {
    Movie movies[MAX_MOVIES];
    int movie_index = 0;
    int choice;
    char movie_name[MAX_NAME_LENGTH];
    int rating;

    while (1) {
        printf("\nC Movie Rating System\n");
        printf("1. Add Rating\n");
        printf("2. Display Movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie name: ");
                scanf("%s", movie_name);

                for (int i = 0; i < movie_index; i++) {
                    if (strcmp(movies[i].name, movie_name) == 0) {
                        printf("Movie already exists.\n");
                        goto label_main;
                    }
                }

                Movie new_movie = {.name = movie_name};
                add_rating(movies, movie_index++, 1);
                printf("Enter your rating (1-10): ");
                scanf("%d", &rating);
                add_rating(movies, movie_index - 1, rating);
                printf("Rating added successfully.\n");
                break;

            case 2:
                printf("\nMovies and their ratings:\n");
                for (int i = 0; i < movie_index; i++) {
                    printf("%s: %.1f\n", movies[i].name, (float)movies[i].rating / movies[i].ratings_count);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

label_main:
        printf("\n");
    }

    return 0;
}