//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void print_menu() {
    printf("\nMovie Rating System\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_movie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    printf("Enter movie title: ");
    scanf(" %[^\n]s", movies[*count].title);
    movies[*count].rating = 0.0;
    strcpy(movies[*count].review, "No review entered.");
    (*count)++;
    printf("Movie added successfully!\n");
}

void view_movies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Movie %d: %s\n", i + 1, movies[i].title);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }
}

void rate_movie(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies found. Please add a movie first.\n");
        return;
    }
    
    int index;
    printf("Enter the movie number to rate (1-%d): ", count);
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid movie number!\n");
        return;
    }
    
    index--; // Adjust for zero-based indexing
    float rating;
    printf("Enter rating (0.0 - 5.0): ");
    scanf("%f", &rating);
    
    if (rating < 0.0 || rating > 5.0) {
        printf("Invalid rating! Rating should be between 0.0 to 5.0.\n");
        return;
    }

    movies[index].rating = rating;

    char review[MAX_REVIEW_LENGTH];
    printf("Enter your review: ");
    scanf(" %[^\n]s", review);
    strcpy(movies[index].review, review);
    printf("Rating updated successfully!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movie_count = 0;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie(movies, &movie_count);
                break;
            case 2:
                view_movies(movies, movie_count);
                break;
            case 3:
                rate_movie(movies, movie_count);
                break;
            case 4:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}