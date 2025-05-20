//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a movie
typedef struct {
    char title[100];
    char genre[50];
    int year;
    float rating; // Rating out of 10
} Movie;

// Function declarations
void addMovie(Movie *movies, int *count);
void listMovies(Movie *movies, int count);
void searchMovie(Movie *movies, int count);
void rateMovie(Movie *movies, int count);
void displayMenu();

int main() {
    Movie *movies = NULL;
    int movieCount = 0;
    int capacity = 5;
    movies = (Movie *)malloc(capacity * sizeof(Movie));

    if (movies == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int choice;
    // Main program loop
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                if (movieCount >= capacity) {
                    capacity *= 2; // Increase capacity if needed
                    movies = realloc(movies, capacity * sizeof(Movie));
                    if (movies == NULL) {
                        printf("Memory reallocation failed.\n");
                        return 1;
                    }
                }
                break;
            case 2:
                listMovies(movies, movieCount);
                break;
            case 3:
                searchMovie(movies, movieCount);
                break;
            case 4:
                rateMovie(movies, movieCount);
                break;
            case 5:
                free(movies);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    free(movies);
    return 0;
}

void addMovie(Movie *movies, int *count) {
    Movie newMovie;

    printf("Enter movie title: ");
    getchar(); // to consume newline character left in the buffer
    fgets(newMovie.title, sizeof(newMovie.title), stdin);
    strtok(newMovie.title, "\n"); // Remove trailing newline

    printf("Enter movie genre: ");
    fgets(newMovie.genre, sizeof(newMovie.genre), stdin);
    strtok(newMovie.genre, "\n");

    printf("Enter release year: ");
    scanf("%d", &newMovie.year);
    
    newMovie.rating = 0.0; // Initial rating is zero

    movies[*count] = newMovie; // Add movie to the list
    (*count)++;
    printf("Movie added successfully!\n");
}

void listMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies in the list.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Genre: %s, Year: %d, Rating: %.1f\n", 
               movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

void searchMovie(Movie *movies, int count) {
    char title[100];
    printf("Enter movie title to search: ");
    getchar(); // consume newline left by previous scanf
    fgets(title, sizeof(title), stdin);
    strtok(title, "\n");

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Movie found: Title: %s, Genre: %s, Year: %d, Rating: %.1f\n",
                   movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void rateMovie(Movie *movies, int count) {
    char title[100];
    printf("Enter movie title to rate: ");
    getchar(); // consume newline left by previous scanf
    fgets(title, sizeof(title), stdin);
    strtok(title, "\n");

    float newRating;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Enter new rating (0-10): ");
            scanf("%f", &newRating);
            if (newRating >= 0 && newRating <= 10) {
                movies[i].rating = newRating;
                printf("Rating updated successfully!\n");
            } else {
                printf("Invalid rating. Please provide a value between 0 and 10.\n");
            }
            return;
        }
    }
    printf("Movie not found.\n");
}

void displayMenu() {
    printf("\nC Movie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. List Movies\n");
    printf("3. Search Movie\n");
    printf("4. Rate Movie\n");
    printf("5. Exit\n");
}