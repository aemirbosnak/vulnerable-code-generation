//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of movies
#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100
#define MAX_GENRE_LEN 30

// Structure to represent a movie
typedef struct {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    float rating;
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *count);
void displayMovies(const Movie movies[], int count);
void searchByGenre(const Movie movies[], int count);
void rateMovie(Movie movies[], int count);
void displayMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;
    
    do {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline after input
        
        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                searchByGenre(movies, movieCount);
                break;
            case 4:
                rateMovie(movies, movieCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        
    } while (choice != 5);
    
    return 0;
}

// Function to add a movie to the list
void addMovie(Movie movies[], int *count) {
    if (*count < MAX_MOVIES) {
        printf("Enter movie title: ");
        fgets(movies[*count].title, MAX_TITLE_LEN, stdin);
        movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline
        
        printf("Enter movie genre: ");
        fgets(movies[*count].genre, MAX_GENRE_LEN, stdin);
        movies[*count].genre[strcspn(movies[*count].genre, "\n")] = 0; // Remove newline
        
        printf("Enter movie rating (0.0 - 10.0): ");
        scanf("%f", &movies[*count].rating);
        getchar(); // Consume newline
        
        (*count)++;
        printf("Movie added successfully!\n");
    } else {
        printf("Movie list is full!\n");
    }
}

// Function to display all movies
void displayMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("\nMovie List:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Genre: %s | Rating: %.1f\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
    printf("\n");
}

// Function to search movies by genre
void searchByGenre(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies in the list.\n");
        return;
    }

    char genre[MAX_GENRE_LEN];
    printf("Enter genre to search: ");
    fgets(genre, MAX_GENRE_LEN, stdin);
    genre[strcspn(genre, "\n")] = 0; // Remove newline
    
    printf("\nMovies in genre '%s':\n", genre);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, genre) == 0) {
            printf("Title: %s | Rating: %.1f\n", movies[i].title, movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in this genre.\n");
    }
}

// Function to rate a movie
void rateMovie(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies in the list to rate.\n");
        return;
    }

    char title[MAX_TITLE_LEN];
    printf("Enter the title of the movie to rate: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            float newRating;
            printf("Current rating is %.1f. Enter new rating (0.0 - 10.0): ", movies[i].rating);
            scanf("%f", &newRating);
            getchar(); // Consume newline
            
            // Update rating only if valid
            if (newRating >= 0.0 && newRating <= 10.0) {
                movies[i].rating = newRating;
                printf("Rating updated successfully!\n");
            } else {
                printf("Invalid rating! Please enter a value between 0.0 and 10.0.\n");
            }
            return;
        }
    }
    printf("Movie not found!\n");
}

// Function to display menu
void displayMenu() {
    printf("\n----- Movie Rating System -----\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search by Genre\n");
    printf("4. Rate Movie\n");
    printf("5. Exit\n");
}