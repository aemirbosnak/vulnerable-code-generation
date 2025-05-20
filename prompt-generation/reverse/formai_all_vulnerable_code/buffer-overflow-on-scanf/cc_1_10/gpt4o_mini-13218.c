//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_REVIEW_LENGTH 200

struct Movie {
    char title[MAX_TITLE_LENGTH];
    int year;
    float rating; // Rating out of 10
    char review[MAX_REVIEW_LENGTH];
};

struct Movie collection[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Whoa! You've reached the maximum number of movies!\n");
        return;
    }
    
    struct Movie newMovie;

    printf("Enter movie title: ");
    scanf(" %[^\n]", newMovie.title); // Read string with spaces
    printf("Enter release year: ");
    scanf("%d", &newMovie.year);
    
    printf("Enter your rating (0-10): ");
    scanf("%f", &newMovie.rating);
    
    if (newMovie.rating < 0 || newMovie.rating > 10) {
        printf("Rating must be between 0 and 10!\n");
        return;
    }

    printf("Enter your review (up to 200 characters): ");
    scanf(" %[^\n]", newMovie.review);

    collection[movieCount] = newMovie;
    movieCount++;

    printf("You just added: %s (%d) with a rating of %.1f!\n", 
           newMovie.title, newMovie.year, newMovie.rating);
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies in your collection yet. Go add some!\n");
        return;
    }

    printf("\nYour Movie Collection:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. '%s' (%d) - Rating: %.1f\n", 
               i + 1, collection[i].title, collection[i].year, collection[i].rating);
        printf("   Review: %s\n", collection[i].review);
    }
}

void searchMovie() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the movie title you want to search for: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(collection[i].title, title) == 0) {
            printf("Found '%s' (%d) with a rating of %.1f!\n", 
                   collection[i].title, collection[i].year, collection[i].rating);
            printf("Review: %s\n", collection[i].review);
            return;
        }
    }

    printf("Sorry, '%s' not found in your collection.\n", title);
}

void deleteMovie() {
    displayMovies();
    int movieIndex;
    printf("Enter the number of the movie you want to delete: ");
    scanf("%d", &movieIndex);

    if (movieIndex < 1 || movieIndex > movieCount) {
        printf("Invalid selection! Please try again.\n");
        return;
    }

    for (int i = movieIndex - 1; i < movieCount - 1; i++) {
        collection[i] = collection[i + 1]; // Shift movies down
    }
    movieCount--;
    printf("You've successfully deleted the movie from your collection!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Welcome to the Movie Rating System! ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("What's your choice?: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                deleteMovie();
                break;
            case 5:
                printf("Exiting the Movie Rating System. Happy Watching!\n");
                exit(0);
            default:
                printf("Unrecognized choice! Please try again.\n");
        }
    }
    
    return 0;
}