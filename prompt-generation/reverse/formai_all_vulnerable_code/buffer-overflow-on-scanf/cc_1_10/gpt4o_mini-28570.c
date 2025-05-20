//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 100
#define MAX_GENRE 50
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE];
    char genre[MAX_GENRE];
    int year;
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies, limit reached!\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar(); // Clears the newline character left by previous input
    fgets(movies[*count].title, MAX_TITLE, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter movie genre: ");
    fgets(movies[*count].genre, MAX_GENRE, stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = 0;

    printf("Enter year of release: ");
    scanf("%d", &movies[*count].year);

    printf("Enter your rating (1.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);
    
    printf("Enter your review: ");
    getchar(); // Clears the newline character
    fgets(movies[*count].review, MAX_REVIEW_LENGTH, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0; 

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie *movies, int count) {
    printf("\n--- Movies List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Movie %d:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("Review: %s\n", movies[i].review);
        printf("-----------------\n");
    }
}

void searchMovie(Movie *movies, int count) {
    char searchTitle[MAX_TITLE];
    
    printf("Enter the title of the movie to search: ");
    getchar(); // Clears the newline character
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; 

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            printf("Movie Found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("Review: %s\n", movies[i].review);
            return;
        }
    }
    
    printf("Movie not found!\n");
}

void deleteMovie(Movie *movies, int *count) {
    char deleteTitle[MAX_TITLE];

    printf("Enter the title of the movie to delete: ");
    getchar(); // Clears the newline character
    fgets(deleteTitle, MAX_TITLE, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; 

    for (int i = 0; i < *count; i++) {
        if (strcmp(movies[i].title, deleteTitle) == 0) {
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1]; // Shift movies left
            }
            (*count)--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }

    printf("Movie not found for deletion!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}