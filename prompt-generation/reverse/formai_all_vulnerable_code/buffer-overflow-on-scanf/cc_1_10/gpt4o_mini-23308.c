//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100
#define BUFFER_SIZE 256

typedef struct {
    char title[MAX_TITLE_LEN];
    char genre[MAX_TITLE_LEN];
    int year;
    float rating;
} Movie;

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add a movie\n");
    printf("2. Display all movies\n");
    printf("3. Find movie by title\n");
    printf("4. Rate a movie\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
    printf("Choose an option: ");
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    printf("Enter movie title: ");
    fgets(movies[*count].title, MAX_TITLE_LEN, stdin);
    strtok(movies[*count].title, "\n"); // Remove trailing newline

    printf("Enter genre: ");
    fgets(movies[*count].genre, MAX_TITLE_LEN, stdin);
    strtok(movies[*count].genre, "\n"); 

    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);

    printf("Enter initial rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);
    
    // Clear input buffer
    while(getchar() != '\n');

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Genre: %s, Year: %d, Rating: %.1f\n", 
               movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

void findMovieByTitle(Movie *movies, int count) {
    char title[MAX_TITLE_LEN];
    printf("Enter movie title to search: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    strtok(title, "\n");
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie found:\n");
            printf("Title: %s, Genre: %s, Year: %d, Rating: %.1f\n", 
                   movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
            return;
        }
    }
    printf("Movie not found!\n");
}

void rateMovie(Movie *movies, int count) {
    char title[MAX_TITLE_LEN];
    float rating;
    printf("Enter movie title to rate: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    strtok(title, "\n");
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Current rating: %.1f\n", movies[i].rating);
            printf("Enter new rating (0.0 - 10.0): ");
            scanf("%f", &rating);
            
            // Clear input buffer
            while(getchar() != '\n');

            if (rating >= 0.0 && rating <= 10.0) {
                movies[i].rating = rating;
                printf("Rating updated successfully!\n");
            } else {
                printf("Invalid rating! Must be between 0.0 and 10.0.\n");
            }
            return;
        }
    }
    printf("Movie not found!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        // Clear input buffer
        while(getchar() != '\n');

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                findMovieByTitle(movies, movieCount);
                break;
            case 4:
                rateMovie(movies, movieCount);
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}