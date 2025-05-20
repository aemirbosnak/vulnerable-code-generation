//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int num_ratings;
} Movie;

void read_movie_data(Movie *movies, int capacity, FILE *fp) {
    char title[100];
    float rating;

    for (int i = 0; i < capacity; i++) {
        fscanf(fp, "%s %f", title, &rating);
        strcpy(movies[i].title, title);
        movies[i].rating = rating;
        movies[i].num_ratings = 1;
    }
}

void update_rating(Movie *movies, int movie_index, float new_rating) {
    movies[movie_index].rating = (movies[movie_index].rating * movies[movie_index].num_ratings + new_rating) / (movies[movie_index].num_ratings + 1);
    movies[movie_index].num_ratings++;
}

int main() {
    const int capacity = 10;
    Movie movies[capacity];
    FILE *fp = fopen("movies.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_movie_data(movies, capacity, fp);
    fclose(fp);

    int choice, movie_index;
    float new_rating;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Rate a movie\n");
        printf("2. Display movie ratings\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", movies[0].title);
                printf("Enter new rating: ");
                scanf("%f", &new_rating);

                for (int i = 0; i < capacity; i++) {
                    if (strcmp(movies[i].title, movies[0].title) == 0) {
                        movie_index = i;
                        update_rating(movies, movie_index, new_rating);
                        break;
                    }
                }
                break;
            case 2:
                printf("\nMovie Ratings:\n");
                for (int i = 0; i < capacity; i++) {
                    printf("%s: %.2f\n", movies[i].title, movies[i].rating);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}