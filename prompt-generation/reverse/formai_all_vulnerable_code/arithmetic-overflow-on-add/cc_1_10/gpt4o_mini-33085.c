//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int year;
    float rating;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieRatingSystem;

void initializeSystem(MovieRatingSystem *system) {
    system->count = 0;
}

void addMovie(MovieRatingSystem *system) {
    if (system->count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    Movie *newMovie = &system->movies[system->count];
    
    printf("Enter the title of the movie: ");
    getchar(); // clear newline buffer
    fgets(newMovie->title, TITLE_LENGTH, stdin);
    newMovie->title[strcspn(newMovie->title, "\n")] = 0; // remove newline

    printf("Enter the year of the movie: ");
    scanf("%d", &newMovie->year);

    printf("Enter your rating for the movie (0 to 10): ");
    scanf("%f", &newMovie->rating);

    if (newMovie->rating < 0.0 || newMovie->rating > 10.0) {
        printf("Rating must be between 0 and 10!\n");
        return;
    }

    system->count++;
    printf("Movie added!\n");
}

void showMovies(const MovieRatingSystem *system) {
    if (system->count == 0) {
        printf("No movies rated yet.\n");
        return;
    }
    printf("\n--- Movies Rated ---\n");
    for (int i = 0; i < system->count; i++) {
        printf("Title: %s | Year: %d | Rating: %.1f\n", 
            system->movies[i].title, 
            system->movies[i].year, 
            system->movies[i].rating);
    }
}

void searchMovie(const MovieRatingSystem *system) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // clear newline buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    for (int i = 0; i < system->count; i++) {
        if (strcmp(system->movies[i].title, searchTitle) == 0) {
            printf("Movie found: %s | Year: %d | Rating: %.1f\n",
                system->movies[i].title,
                system->movies[i].year,
                system->movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void deleteMovie(MovieRatingSystem *system) {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // clear newline buffer
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // remove newline

    for (int i = 0; i < system->count; i++) {
        if (strcmp(system->movies[i].title, deleteTitle) == 0) {
            for (int j = i; j < system->count - 1; j++) {
                system->movies[j] = system->movies[j + 1];
            }
            system->count--;
            printf("Movie deleted successfully.\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void overallRating(const MovieRatingSystem *system) {
    if (system->count == 0) {
        printf("No movies to calculate overall rating.\n");
        return;
    }
    float sum = 0.0;
    for (int i = 0; i < system->count; i++) {
        sum += system->movies[i].rating;
    }
    printf("Overall rating: %.2f\n", sum / system->count);
}

void displayMenu() {
    printf("---- Movie Rating System ----\n");
    printf("1. Add Movie\n");
    printf("2. Show Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Overall Rating\n");
    printf("6. Exit\n");
    printf("------------------------------\n");
}

int main() {
    MovieRatingSystem system;
    initializeSystem(&system);
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(&system);
                break;
            case 2:
                showMovies(&system);
                break;
            case 3:
                searchMovie(&system);
                break;
            case 4:
                deleteMovie(&system);
                break;
            case 5:
                overallRating(&system);
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}