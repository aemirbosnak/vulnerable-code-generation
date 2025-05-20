//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define MAX_RATINGS 10

typedef struct {
    char title[TITLE_LENGTH];
    float ratings[MAX_RATINGS];
    int rating_count;
} Movie;

void add_movie(Movie **movies, int *movie_count) {
    if (*movie_count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie *new_movie = (Movie *)malloc(sizeof(Movie));
    if (!new_movie) {
        printf("Could not allocate memory for the new movie.\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar(); // consume the newline character left by previous input
    fgets(new_movie->title, TITLE_LENGTH, stdin);
    new_movie->title[strcspn(new_movie->title, "\n")] = 0; // Remove trailing newline
    new_movie->rating_count = 0;

    movies[*movie_count] = new_movie;
    (*movie_count)++;
    printf("Movie '%s' added successfully!\n", new_movie->title);
}

void rate_movie(Movie **movies, int movie_count) {
    char title[TITLE_LENGTH];
    float rating;
    
    printf("Enter movie title to rate: ");
    getchar();
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movies[i]->title, title) == 0) {
            if (movies[i]->rating_count >= MAX_RATINGS) {
                printf("Maximum rating count reached for '%s'. Can't add another rating.\n", title);
                return;
            }
            printf("Enter rating (0-10): ");
            scanf("%f", &rating);
            if (rating < 0 || rating > 10) {
                printf("Invalid rating! Please enter a rating between 0 and 10.\n");
                return;
            }

            movies[i]->ratings[movies[i]->rating_count] = rating;
            movies[i]->rating_count++;
            printf("Rating %.1f added for '%s'!\n", rating, title);
            return;
        }
    }
    
    printf("Movie '%s' not found!\n", title);
}

void view_movies(Movie **movies, int movie_count) {
    if (movie_count == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("Movies and their ratings:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s\n", movies[i]->title);
        if (movies[i]->rating_count == 0) {
            printf("No ratings available.\n");
        } else {
            float sum = 0;
            for (int j = 0; j < movies[i]->rating_count; j++) {
                sum += movies[i]->ratings[j];
            }
            float average = sum / movies[i]->rating_count;
            printf("Average Rating: %.2f\n", average);
        }
        printf("\n");
    }
}

void free_movies(Movie **movies, int movie_count) {
    for (int i = 0; i < movie_count; i++) {
        free(movies[i]);
    }
}

int main() {
    Movie *movies[MAX_MOVIES] = {NULL};
    int movie_count = 0;
    int choice;

    do {
        printf("Movie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. View Movies\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &movie_count);
                break;
            case 2:
                rate_movie(movies, movie_count);
                break;
            case 3:
                view_movies(movies, movie_count);
                break;
            case 4:
                free_movies(movies, movie_count);
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}