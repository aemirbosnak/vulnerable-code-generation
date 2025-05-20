//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_LENGTH 50

typedef struct {
    char title[MAX_LENGTH];
    int rating;
} Movie;

int main() {
    FILE *file;
    int total_movies = 0;
    int total_rating = 0;
    Movie movies[MAX_MOVIES];

    if ((file = fopen("movies.txt", "r")) != NULL) {
        while (fscanf(file, "%s %d", movies[total_movies].title, &movies[total_movies].rating) != EOF) {
            total_movies++;
            total_rating += movies[total_movies - 1].rating;
        }
        fclose(file);
    }

    char title[MAX_LENGTH];
    int rating;

    while (1) {
        printf("\nEnter a movie title (or type 'quit' to exit): ");
        scanf("%s", title);

        if (strcmp(title, "quit") == 0) {
            break;
        }

        printf("Enter a rating (1-10): ");
        scanf("%d", &rating);

        if (total_movies < MAX_MOVIES) {
            strcpy(movies[total_movies].title, title);
            movies[total_movies].rating = rating;
            total_movies++;
            total_rating += rating;
        } else {
            printf("Max movies limit reached.\n");
        }
    }

    printf("\nTotal movies rated: %d\n", total_movies);
    printf("Average rating: %.2f\n", (float)total_rating / total_movies);

    file = fopen("movies.txt", "w");
    for (int i = 0; i < total_movies; i++) {
        fprintf(file, "%s %d\n", movies[i].title, movies[i].rating);
    }
    fclose(file);

    return 0;
}