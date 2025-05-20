//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 250

// Structure to hold movie information
typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

// Global array to store movies
Movie movies[MAX_MOVIES];
int movie_count = 0;

// Function prototypes
void addMovie();
void displayMovies();
void rateMovie();
void searchMovie();
void deleteMovie();
void saveMovies();
void loadMovies();

int main() {
    int choice;
    loadMovies(); // Load movies from file at the start

    while (1) {
        printf("\n--- C Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Rate Movie\n");
        printf("4. Search Movie\n");
        printf("5. Delete Movie\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                rateMovie();
                break;
            case 4:
                searchMovie();
                break;
            case 5:
                deleteMovie();
                break;
            case 6:
                saveMovies();
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addMovie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // Clear newline character from buffer
    fgets(movies[movie_count].title, MAX_TITLE_LENGTH, stdin);
    
    // Remove trailing newline character from title
    movies[movie_count].title[strcspn(movies[movie_count].title, "\n")] = 0;

    movies[movie_count].rating = 0.0f; // Initialize rating to 0
    strcpy(movies[movie_count].review, ""); // Initialize review to empty string
    
    movie_count++;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movie_count == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("%d. Title: %s\n", i + 1, movies[i].title);
        printf("   Rating: %.1f\n", movies[i].rating);
        printf("   Review: %s\n", movies[i].review[0] ? movies[i].review : "No review");
    }
}

void rateMovie() {
    int index;
    float rating;

    printf("Enter the movie number to rate: ");
    scanf("%d", &index);

    if (index < 1 || index > movie_count) {
        printf("Invalid movie number!\n");
        return;
    }

    printf("Enter rating (0.0 to 10.0): ");
    scanf("%f", &rating);

    if (rating < 0.0f || rating > 10.0f) {
        printf("Rating must be between 0.0 and 10.0!\n");
        return;
    }

    movies[index - 1].rating = rating;

    printf("Rating updated!\n");
}

void searchMovie() {
    char search_title[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    getchar(); // Clear newline from buffer
    fgets(search_title, MAX_TITLE_LENGTH, stdin);

    search_title[strcspn(search_title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < movie_count; i++) {
        if (strstr(movies[i].title, search_title) != NULL) {
            printf("Found Movie: %s, Rating: %.1f\n", movies[i].title, movies[i].rating);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No movies found with that title.\n");
    }
}

void deleteMovie() {
    int index;

    printf("Enter the movie number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > movie_count) {
        printf("Invalid movie number!\n");
        return;
    }

    for (int i = index - 1; i < movie_count - 1; i++) {
        movies[i] = movies[i + 1];
    }

    movie_count--;
    printf("Movie deleted successfully!\n");
}

void saveMovies() {
    FILE *file = fopen("movies.dat", "w");
    if (file == NULL) {
        printf("Error saving movies!\n");
        return;
    }

    for (int i = 0; i < movie_count; i++) {
        fprintf(file, "%s\n%.1f\n%s\n", movies[i].title, movies[i].rating, movies[i].review);
    }

    fclose(file);
    printf("Movies saved successfully!\n");
}

void loadMovies() {
    FILE *file = fopen("movies.dat", "r");
    if (file == NULL) {
        return; // No saved movies found
    }

    while (fscanf(file, "%[^\n]\n%f\n%[^\n]\n", movies[movie_count].title, &movies[movie_count].rating, movies[movie_count].review) != EOF) {
        movie_count++;
    }

    fclose(file);
    printf("Movies loaded successfully!\n");
}