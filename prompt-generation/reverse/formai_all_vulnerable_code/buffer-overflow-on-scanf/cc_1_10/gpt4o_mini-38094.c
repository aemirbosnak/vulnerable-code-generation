//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define REVIEW_LENGTH 256

struct Movie {
    char title[TITLE_LENGTH];
    int year;
    float rating;
    char review[REVIEW_LENGTH];
};

struct MovieCollection {
    struct Movie movies[MAX_MOVIES];
    int count;
};

// Function to initialize the movie collection
void initializeCollection(struct MovieCollection *collection) {
    collection->count = 0;
}

// Function to add a movie to the collection
void addMovie(struct MovieCollection *collection) {
    if (collection->count >= MAX_MOVIES) {
        printf("Movie collection is full!\n");
        return;
    }
    
    struct Movie newMovie;
    
    printf("Enter movie title: ");
    getchar(); // Clear newline left by previous input
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Strip newline
    
    printf("Enter release year: ");
    scanf("%d", &newMovie.year);
    
    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &newMovie.rating);
    
    printf("Enter your review: ");
    getchar(); // Clear newline
    fgets(newMovie.review, REVIEW_LENGTH, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0; // Strip newline
    
    collection->movies[collection->count] = newMovie;
    collection->count++;
    
    printf("Movie added successfully!\n");
}

// Function to display all movies in the collection
void displayMovies(struct MovieCollection *collection) {
    if (collection->count == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    for (int i = 0; i < collection->count; i++) {
        struct Movie m = collection->movies[i];
        printf("\nMovie %d:\n", i + 1);
        printf("Title: %s\n", m.title);
        printf("Year: %d\n", m.year);
        printf("Rating: %.1f\n", m.rating);
        printf("Review: %s\n", m.review);
    }
}

// Function to find a movie by title
void findMovieByTitle(struct MovieCollection *collection) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the movie to find: ");
    getchar(); // Clear newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Strip newline
    
    for (int i = 0; i < collection->count; i++) {
        if (strcasecmp(collection->movies[i].title, title) == 0) {
            struct Movie m = collection->movies[i];
            printf("\nFound Movie:\n");
            printf("Title: %s\n", m.title);
            printf("Year: %d\n", m.year);
            printf("Rating: %.1f\n", m.rating);
            printf("Review: %s\n", m.review);
            return;
        }
    }
    
    printf("Movie not found!\n");
}

// Function to delete a movie by title
void deleteMovie(struct MovieCollection *collection) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // Clear newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Strip newline
    
    for (int i = 0; i < collection->count; i++) {
        if (strcasecmp(collection->movies[i].title, title) == 0) {
            for (int j = i; j < collection->count - 1; j++) {
                collection->movies[j] = collection->movies[j + 1];
            }
            collection->count--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    
    printf("Movie not found!\n");
}

// Function to display menu
void displayMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. Display All Movies\n");
    printf("3. Find Movie by Title\n");
    printf("4. Delete Movie by Title\n");
    printf("5. Exit\n");
    printf("===========================\n");
}

// Main function
int main() {
    struct MovieCollection collection;
    initializeCollection(&collection);
    
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(&collection);
                break;
            case 2:
                displayMovies(&collection);
                break;
            case 3:
                findMovieByTitle(&collection);
                break;
            case 4:
                deleteMovie(&collection);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}