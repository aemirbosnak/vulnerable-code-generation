//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: brave
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

void initialize_movies(Movie movies[], int *movie_count) {
    *movie_count = 0;
}

int add_movie(Movie movies[], int *movie_count) {
    if (*movie_count >= MAX_MOVIES) {
        printf("Maximum movie limit reached.\n");
        return 0;
    }
    
    Movie new_movie;
    printf("Enter movie title: ");
    fgets(new_movie.title, TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = '\0'; // Remove newline

    new_movie.rating_count = 0;
    movies[*movie_count] = new_movie;
    (*movie_count)++;
    printf("Movie '%s' added.\n", new_movie.title);
    return 1;
}

int rate_movie(Movie movies[], int movie_count) {
    char title[TITLE_LENGTH];
    printf("Enter movie title to rate: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (movies[i].rating_count >= MAX_RATINGS) {
                printf("Maximum ratings for this movie reached.\n");
                return 0;
            }
            float rating;
            printf("Enter rating (0.0 to 10.0): ");
            scanf("%f", &rating);
            while (getchar() != '\n'); // Clear input buffer

            if (rating < 0.0 || rating > 10.0) {
                printf("Invalid rating. Rating should be between 0.0 and 10.0.\n");
                return 0;
            }
            movies[i].ratings[movies[i].rating_count++] = rating;
            printf("Rating %.1f added for movie '%s'.\n", rating, movies[i].title);
            return 1;
        }
    }

    printf("Movie '%s' not found.\n", title);
    return 0;
}

void display_movie_info(Movie movies[], int movie_count) {
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s\n", movies[i].title);
        if (movies[i].rating_count == 0) {
            printf("No ratings yet.\n");
            continue;
        }

        float sum = 0.0;
        for (int j = 0; j < movies[i].rating_count; j++) {
            sum += movies[i].ratings[j];
        }
        float average = sum / movies[i].rating_count;

        printf("Average Rating: %.1f\n", average);
    }
}

void display_menu() {
    printf("=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. Display Movie Information\n");
    printf("4. Exit\n");
    printf("===========================\n");
    printf("Choose an option: ");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movie_count;
    initialize_movies(movies, &movie_count);
    
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                add_movie(movies, &movie_count);
                break;
            case 2:
                rate_movie(movies, movie_count);
                break;
            case 3:
                display_movie_info(movies, movie_count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}