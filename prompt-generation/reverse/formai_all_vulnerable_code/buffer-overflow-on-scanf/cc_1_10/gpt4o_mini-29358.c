//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define RATING_LENGTH 10

typedef struct {
    char title[TITLE_LENGTH];
    char genre[TITLE_LENGTH];
    float rating;
} Movie;

void add_movie(Movie *movies, int *count);
void view_movies(Movie *movies, int count);
void search_movie(Movie *movies, int count);
void delete_movie(Movie *movies, int *count);
void rate_movie(Movie *movies, int count);
void display_menu();

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline after entering choice

        switch (choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                view_movies(movies, count);
                break;
            case 3:
                search_movie(movies, count);
                break;
            case 4:
                delete_movie(movies, &count);
                break;
            case 5:
                rate_movie(movies, count);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 6);

    return 0;
}

void display_menu() {
    printf("======== Movie Rating System ========\n");
    printf("1. Add Movie\n");
    printf("2. View All Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Rate Movie\n");
    printf("6. Exit\n");
    printf("======================================\n");
}

void add_movie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    strtok(movies[*count].title, "\n"); // Remove newline character

    printf("Enter movie genre: ");
    fgets(movies[*count].genre, TITLE_LENGTH, stdin);
    strtok(movies[*count].genre, "\n"); // Remove newline character

    movies[*count].rating = 0.0; // Initialize rating to 0.0
    (*count)++;
    printf("Movie added successfully!\n");
}

void view_movies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available to display.\n");
        return;
    }

    printf("List of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Genre: %s | Rating: %.1f\n", 
            movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void search_movie(Movie *movies, int count) {
    char title[TITLE_LENGTH];
    printf("Enter movie title to search: ");
    fgets(title, TITLE_LENGTH, stdin);
    strtok(title, "\n"); // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Movie found!\nTitle: %s | Genre: %s | Rating: %.1f\n", 
                movies[i].title, movies[i].genre, movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void delete_movie(Movie *movies, int *count) {
    char title[TITLE_LENGTH];
    printf("Enter movie title to delete: ");
    fgets(title, TITLE_LENGTH, stdin);
    strtok(title, "\n"); // Remove newline character

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            // Shift movies down
            for (int j = i; j < (*count) - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void rate_movie(Movie *movies, int count) {
    char title[TITLE_LENGTH];
    float new_rating;

    printf("Enter movie title to rate: ");
    fgets(title, TITLE_LENGTH, stdin);
    strtok(title, "\n"); // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Current rating: %.1f\n", movies[i].rating);
            printf("Enter new rating (0.0 to 10.0): ");
            scanf("%f", &new_rating);
            getchar(); // To consume newline
            if (new_rating >= 0.0 && new_rating <= 10.0) {
                movies[i].rating = new_rating;
                printf("Rating updated successfully!\n");
            } else {
                printf("Invalid rating. Please enter a value between 0.0 and 10.0.\n");
            }
            return;
        }
    }
    printf("Movie not found.\n");
}