//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 300

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void add_movie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Maximum number of movies reached. Cannot add more.\n");
        return;
    }

    printf("Enter movie title: ");
    getchar();  // clear the newline character from the input buffer
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0;  // remove newline

    printf("Enter your rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);

    printf("Enter your review: ");
    getchar();  // clear buffer again
    fgets(movies[*count].review, MAX_REVIEW_LENGTH, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0;  // remove newline

    (*count)++;
    printf("Movie added successfully!\n");
}

void list_movies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, movies[i].title);
        printf("   Rating: %.1f\n", movies[i].rating);
        printf("   Review: %s\n\n", movies[i].review);
    }
}

void sort_movies(Movie *movies, int count) {
    Movie temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                // Swap movies[j] and movies[j + 1]
                temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
    printf("Movies sorted by rating!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice = 0;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. List Movies\n");
        printf("3. Sort Movies by Rating\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                list_movies(movies, count);
                break;
            case 3:
                sort_movies(movies, count);
                break;
            case 4:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please choose again.\n");
        }
    }

    return 0;
}