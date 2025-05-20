//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold movie details
typedef struct {
    char title[100];
    char genre[50];
    int year;
    int rating; // Rating out of 10
} Movie;

// Function prototypes
void addMovie(Movie* movies, int* count);
void displayMovies(Movie* movies, int count);
void findMovieByTitle(Movie* movies, int count);
void averageRating(Movie* movies, int count);
void sortMoviesByRating(Movie* movies, int count);

int main() {
    Movie movies[100];
    int count = 0;
    int choice;

    do {
        printf("Welcome to the Movie Rating System!\n");
        printf("1. Add a Movie\n");
        printf("2. Display Movies\n");
        printf("3. Find Movie by Title\n");
        printf("4. Calculate Average Rating\n");
        printf("5. Sort Movies by Rating\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch(choice) {
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
                averageRating(movies, count);
                break;
            case 5:
                sortMoviesByRating(movies, count);
                displayMovies(movies, count); // Show sorted list
                break;
            case 6:
                printf("Thank you for using the Movie Rating System! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to add a new movie
void addMovie(Movie* movies, int* count) {
    if (*count < 100) {
        printf("Enter movie title: ");
        fgets(movies[*count].title, sizeof(movies[*count].title), stdin);
        strtok(movies[*count].title, "\n"); // Remove newline character

        printf("Enter movie genre: ");
        fgets(movies[*count].genre, sizeof(movies[*count].genre), stdin);
        strtok(movies[*count].genre, "\n"); // Remove newline character

        printf("Enter movie year: ");
        scanf("%d", &movies[*count].year);
        
        printf("Enter movie rating (0-10): ");
        scanf("%d", &movies[*count].rating);
        
        (*count)++;
        printf("Movie added successfully!\n");
    } else {
        printf("Movie list is full! Cannot add more movies.\n");
    }
}

// Function to display all movies
void displayMovies(Movie* movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Genre: %s | Year: %d | Rating: %d/10\n", 
               movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
    printf("\n");
}

// Function to find a movie by title
void findMovieByTitle(Movie* movies, int count) {
    char searchTitle[100];
    printf("Enter movie title to search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    strtok(searchTitle, "\n"); // Remove newline character

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            printf("Movie found: Title: %s | Genre: %s | Year: %d | Rating: %d/10\n", 
                   movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Movie not found in the list.\n");
    }
}

// Function to calculate average rating
void averageRating(Movie* movies, int count) {
    if (count == 0) {
        printf("No ratings available to calculate average.\n");
        return;
    }
    
    int totalRating = 0;
    for (int i = 0; i < count; i++) {
        totalRating += movies[i].rating;
    }
    
    double average = (double)totalRating / count;
    printf("Average movie rating: %.2f/10\n", average);
}

// Function to sort movies by rating (bubble sort)
void sortMoviesByRating(Movie* movies, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}