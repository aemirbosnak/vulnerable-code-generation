//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 50

typedef struct {
    char title[NAME_LENGTH];
    int rating; // on a scale of 1 to 5
    int year;
    char review[256];
} Movie;

// A function to display the menu options
void displayMenu() {
    printf("Welcome to the Post-Apocalyptic Movie Rating System\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Delete a Movie\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

// A function to add a movie
void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("No more space for new movies!\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // clear newline from buffer
    fgets(newMovie.title, NAME_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // remove newline

    printf("Enter movie year: ");
    scanf("%d", &newMovie.year);

    printf("Give it a rating (1-5): ");
    scanf("%d", &newMovie.rating);
    
    if (newMovie.rating < 1 || newMovie.rating > 5) {
        printf("Rating must be between 1 and 5!\n");
        return;
    }

    printf("Write a brief review: ");
    getchar(); // clear newline from buffer
    fgets(newMovie.review, 256, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0; // remove newline

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

// A function to view all movies
void viewMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display!\n");
        return;
    }
    
    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Year: %d | Rating: %d | Review: %s\n",
               movies[i].title, movies[i].year, movies[i].rating, movies[i].review);
    }
}

// A function to rate an existing movie
void rateMovie(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies available to rate!\n");
        return;
    }

    char title[NAME_LENGTH];
    printf("Enter the title of the movie you want to rate: ");
    getchar(); // clear newline from buffer
    fgets(title, NAME_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Current rating for '%s': %d\n", movies[i].title, movies[i].rating);
            printf("Provide new rating (1-5): ");
            int newRating;
            scanf("%d", &newRating);
            if (newRating < 1 || newRating > 5) {
                printf("Rating must be between 1 and 5!\n");
                return;
            }
            movies[i].rating = newRating;
            printf("Rating updated successfully!\n");
            return;
        }
    }

    printf("Movie not found!\n");
}

// A function to delete a movie
void deleteMovie(Movie *movies, int *count) {
    if (*count == 0) {
        printf("No movies available to delete!\n");
        return;
    }

    char title[NAME_LENGTH];
    printf("Enter the title of the movie you want to delete: ");
    getchar(); // clear newline from buffer
    fgets(title, NAME_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            // Shift movies down to delete
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }

    printf("Movie not found!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                viewMovies(movies, movieCount);
                break;
            case 3:
                rateMovie(movies, movieCount);
                break;
            case 4:
                deleteMovie(movies, &movieCount);
                break;
            case 5:
                printf("Thank you for using the Post-Apocalyptic Movie Rating System. Stay safe!\n");
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}