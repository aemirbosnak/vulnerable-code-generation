//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char review[MAX_REVIEW_LENGTH];
    int rating; // Rating scale from 1 to 10
} Movie;

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // clear newline leftover
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter your review: ");
    fgets(movies[*count].review, MAX_REVIEW_LENGTH, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0; // Remove newline

    printf("Rate the movie (1-10): ");
    scanf("%d", &movies[*count].rating);
    
    if (movies[*count].rating < 1 || movies[*count].rating > 10) {
        printf("Invalid rating! Setting rating to 0.\n");
        movies[*count].rating = 0; 
    }

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display!\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Review: %s\n", movies[i].review);
        printf("Rating: %d\n", movies[i].rating);
        printf("------------------------\n");
    }
}

void findMovieByTitle(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies in the list!\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the movie title to search: ");
    getchar(); // clear newline leftover
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Found Movie!\n");
            printf("Title: %s\n", movies[i].title);
            printf("Review: %s\n", movies[i].review);
            printf("Rating: %d\n", movies[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found!\n");
    }
}

void deleteMovie(Movie *movies, int *count) {
    if (*count == 0) {
        printf("No movies to delete!\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the movie title to delete: ");
    getchar(); // clear newline leftover
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie by Title\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                findMovieByTitle(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}