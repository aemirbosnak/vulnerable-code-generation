//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_LENGTH 50

typedef struct {
    char title[MAX_LENGTH];
    char actor[MAX_LENGTH];
    int rating;
} Movie;

int main() {
    FILE *fp;
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int total_rating = 0;
    char choice;

    fp = fopen("movies.txt", "w+");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    do {
        printf("\nEnter movie title (enter 'q' to quit): ");
        scanf("%s", movies[num_movies].title);
        if (strlen(movies[num_movies].title) > MAX_LENGTH - 1) {
            printf("Title too long.\n");
            continue;
        }

        printf("Enter actor name: ");
        scanf("%s", movies[num_movies].actor);
        if (strlen(movies[num_movies].actor) > MAX_LENGTH - 1) {
            printf("Actor name too long.\n");
            continue;
        }

        printf("Enter rating (1-10): ");
        scanf("%d", &movies[num_movies].rating);
        if (movies[num_movies].rating < 1 || movies[num_movies].rating > 10) {
            printf("Invalid rating.\n");
            continue;
        }

        total_rating += movies[num_movies].rating;
        fwrite(&movies[num_movies], sizeof(Movie), 1, fp);
        num_movies++;

        printf("Do you want to add another movie? (y/n): ");
        scanf("%c", &choice);
    } while (choice != 'n' && choice != 'q');

    fclose(fp);

    if (num_movies > 0) {
        fp = fopen("movies.txt", "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }

        Movie temp_movie;
        int count = 0;
        int sum_rating = 0;

        while (fread(&temp_movie, sizeof(Movie), 1, fp) > 0) {
            sum_rating += temp_movie.rating;
            count++;
        }

        fclose(fp);

        double avg_rating = (double) sum_rating / count;

        printf("\nAverage rating for all movies: %.2f\n", avg_rating);
    }

    return 0;
}