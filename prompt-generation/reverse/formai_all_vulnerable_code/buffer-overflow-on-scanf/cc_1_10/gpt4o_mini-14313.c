//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define DIRECTOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char director[DIRECTOR_LENGTH];
    float rating;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie newMovie;

    printf("Enter movie title: ");
    getchar(); // Clear the newline character from the buffer
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline at the end

    printf("Enter director name: ");
    fgets(newMovie.director, DIRECTOR_LENGTH, stdin);
    newMovie.director[strcspn(newMovie.director, "\n")] = 0; // Remove newline at the end

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);

    movieList[movieCount++] = newMovie;

    printf("Movie added successfully!\n");
}

void viewMovies() {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("\nMovies List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Director: %s, Rating: %.1f\n", 
               movieList[i].title, 
               movieList[i].director, 
               movieList[i].rating);
    }
}

int compareMovies(const void *a, const void *b) {
    Movie *movieA = (Movie *)a;
    Movie *movieB = (Movie *)b;
    return (movieA->rating < movieB->rating) ? 1 : -1; // Sort by rating descending
}

void sortMoviesByRating() {
    if (movieCount == 0) {
        printf("No movies to sort.\n");
        return;
    }

    qsort(movieList, movieCount, sizeof(Movie), compareMovies);
    printf("Movies sorted by rating.\n");
}

void displayMenu() {
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Sort Movies by Rating\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                sortMoviesByRating();
                viewMovies();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}