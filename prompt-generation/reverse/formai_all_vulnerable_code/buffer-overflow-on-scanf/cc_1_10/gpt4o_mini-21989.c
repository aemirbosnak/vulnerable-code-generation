//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int ratings;
    float averageRating;
} Movie;

Movie* movies[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies!\n");
        return;
    }
    Movie* newMovie = (Movie*)malloc(sizeof(Movie));
    printf("Enter movie title: ");
    scanf(" %[^\n]s", newMovie->title);
    newMovie->ratings = 0;
    newMovie->averageRating = 0.0;
    movies[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void rateMovie() {
    char title[TITLE_LENGTH];
    printf("Enter movie title to rate: ");
    scanf(" %[^\n]s", title);
    
    for (int i = 0; i < movieCount; ++i) {
        if (strcmp(movies[i]->title, title) == 0) {
            int rating;
            printf("Enter your rating (1-5): ");
            scanf("%d", &rating);
            if (rating < 1 || rating > 5) {
                printf("Invalid rating. Rating must be between 1 and 5.\n");
                return;
            }
            movies[i]->ratings += rating;
            movies[i]->averageRating = (float)movies[i]->ratings / (movieCount + 1);
            printf("Rating added successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("Movies:\n");
    printf("Title\t\t\tAverage Rating\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < movieCount; ++i) {
        printf("%-20s\t%.2f\n", movies[i]->title, movies[i]->averageRating);
    }
}

void saveMoviesToFile() {
    FILE* file = fopen("movies.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < movieCount; ++i) {
        fprintf(file, "%s %d %.2f\n", movies[i]->title, movies[i]->ratings, movies[i]->averageRating);
    }
    fclose(file);
    printf("Movies saved to file successfully!\n");
}

void loadMoviesFromFile() {
    FILE* file = fopen("movies.txt", "r");
    if (!file) {
        printf("Could not open file for reading. Starting fresh!\n");
        return;
    }
    
    while (!feof(file) && movieCount < MAX_MOVIES) {
        Movie* newMovie = (Movie*)malloc(sizeof(Movie));
        fscanf(file, " %[^0123456789] %d %f", newMovie->title, &(newMovie->ratings), &(newMovie->averageRating));
        movies[movieCount++] = newMovie;
    }
    fclose(file);
    printf("Movies loaded from file successfully!\n");
}

int main() {
    int choice;
    loadMoviesFromFile();
    
    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Save Movies to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                saveMoviesToFile();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory
    for (int i = 0; i < movieCount; i++) {
        free(movies[i]);
    }
    
    return 0;
}