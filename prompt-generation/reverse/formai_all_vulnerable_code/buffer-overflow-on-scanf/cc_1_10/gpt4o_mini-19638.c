//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int rating; // Scale 1 to 5
    int year;
} Movie;

void displayMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Delete a Movie\n");
    printf("5. Exit\n");
    printf("===========================\n");
    printf("Please select an option (1-5): ");
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies, the limit has been reached!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // To consume the newline character
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &newMovie.year);
    
    newMovie.rating = 0; // Initial rating
    movies[*count] = newMovie;
    (*count)++;
    printf("Movie \"%s\" added successfully!\n", newMovie.title);
}

void viewMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies in the list.\n");
        return;
    }
    
    printf("\n=== List of Movies ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. \"%s\" (%d) - Rating: %s\n", 
               i + 1, 
               movies[i].title, 
               movies[i].year, 
               movies[i].rating > 0 ? "⭐️⭐️⭐️⭐️⭐️" + (5 - movies[i].rating) : "Not Rated");
    }
    printf("======================\n");
}

void rateMovie(Movie *movies, int count) {
    int index;
    printf("Enter the number of the movie you want to rate: ");
    scanf("%d", &index);
    
    if(index < 1 || index > count) {
        printf("Invalid movie number!\n");
        return;
    }

    int rating;
    printf("Enter your rating (1-5): ");
    scanf("%d", &rating);
    
    if (rating < 1 || rating > 5) {
        printf("Rating must be between 1 and 5!\n");
        return;
    }

    movies[index - 1].rating = rating;
    printf("You rated \"%s\" with a rating of %d!\n", movies[index - 1].title, rating);
}

void deleteMovie(Movie *movies, int *count) {
    int index;
    printf("Enter the number of the movie you want to delete: ");
    scanf("%d", &index);

    if(index < 1 || index > *count) {
        printf("Invalid movie number!\n");
        return;
    }

    for (int i = index - 1; i < (*count) - 1; i++) {
        movies[i] = movies[i + 1];
    }
    (*count)--;
    printf("Movie \"%s\" deleted successfully!\n", movies[index - 1].title);
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}