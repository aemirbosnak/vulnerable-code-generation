//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a movie
typedef struct Movie {
    char title[100];
    char genre[50];
    int rating; // Scale from 1 to 10
    char review[256];
} Movie;

// Function prototypes
void addMovie(Movie *movies, int *count);
void displayMovies(Movie *movies, int count);
void searchMovie(Movie *movies, int count);
void editMovie(Movie *movies, int count);
void deleteMovie(Movie *movies, int *count);
void displayMenu();

int main() {
    Movie movies[100]; // Array to hold movies
    int movieCount = 0; // Current number of movies
    int choice;
    
    // Sherlock Holmes opening statement
    printf("Welcome to the Sherlock Holmes Movie Rating System!\n");
    
    // Menu loop
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                addMovie(movies, &movieCount); 
                break;
            case 2: 
                displayMovies(movies, movieCount); 
                break;
            case 3: 
                searchMovie(movies, movieCount); 
                break;
            case 4: 
                editMovie(movies, movieCount); 
                break;
            case 5: 
                deleteMovie(movies, &movieCount); 
                break;
            case 6: 
                printf("Exiting...\n"); 
                break;
            default: 
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Sherlock Holmes Movie Rating System ---\n");
    printf("1. Add a Movie\n");
    printf("2. Display All Movies\n");
    printf("3. Search for a Movie\n");
    printf("4. Edit a Movie\n");
    printf("5. Delete a Movie\n");
    printf("6. Exit\n");
}

// Function to add a new movie
void addMovie(Movie *movies, int *count) {
    if (*count >= 100) {
        printf("Movie list is full!\n");
        return;
    }
    
    printf("Enter the movie title: ");
    getchar(); // To consume newline from previous input
    fgets(movies[*count].title, sizeof(movies[*count].title), stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter the movie genre: ");
    fgets(movies[*count].genre, sizeof(movies[*count].genre), stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = 0; // Remove newline

    printf("Enter your rating (1-10): ");
    scanf("%d", &movies[*count].rating);
    
    printf("Enter your review: ");
    getchar(); // To consume newline from previous input
    fgets(movies[*count].review, sizeof(movies[*count].review), stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0; // Remove newline
    
    (*count)++;
    printf("Movie added successfully!\n");
}

// Function to display all movies
void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n--- List of Movies ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d\n", movies[i].rating);
        printf("Review: %s\n", movies[i].review);
        printf("----------------------\n");
    }
}

// Function to search for a movie
void searchMovie(Movie *movies, int count) {
    char searchTitle[100];
    printf("Enter the title of the movie to search: ");
    getchar(); // To consume newline
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Rating: %d\n", movies[i].rating);
            printf("Review: %s\n", movies[i].review);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}

// Function to edit a movie
void editMovie(Movie *movies, int count) {
    char editTitle[100];
    printf("Enter the title of the movie to edit: ");
    getchar(); // To consume newline
    fgets(editTitle, sizeof(editTitle), stdin);
    editTitle[strcspn(editTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, editTitle) == 0) {
            printf("Editing movie: %s\n", movies[i].title);
            printf("Enter new genre: ");
            fgets(movies[i].genre, sizeof(movies[i].genre), stdin);
            movies[i].genre[strcspn(movies[i].genre, "\n")] = 0; // Remove newline

            printf("Enter new rating (1-10): ");
            scanf("%d", &movies[i].rating);
            
            printf("Enter new review: ");
            getchar(); // To consume newline
            fgets(movies[i].review, sizeof(movies[i].review), stdin);
            movies[i].review[strcspn(movies[i].review, "\n")] = 0; // Remove newline
            
            found = 1;
            printf("Movie updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}

// Function to delete a movie
void deleteMovie(Movie *movies, int *count) {
    char deleteTitle[100];
    printf("Enter the title of the movie to delete: ");
    getchar(); // To consume newline
    fgets(deleteTitle, sizeof(deleteTitle), stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(movies[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1]; // Shift movies down
            }
            (*count)--; // Reduce count
            printf("Movie deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}