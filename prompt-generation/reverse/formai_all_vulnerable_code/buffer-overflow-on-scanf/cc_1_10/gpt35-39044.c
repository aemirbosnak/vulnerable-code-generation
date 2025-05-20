//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie struct
struct movie {
    char name[50];
    int year;
    float rating;
};

// Define function prototypes
void addMovie(struct movie *movies, int index);
void printMovies(struct movie *movies, int index);
void rateMovie(struct movie *movies, int index);

int main() {
    struct movie movies[10]; // Array of movie structs
    int index = 0; // Index of the current movie

    // Show the user the menu options
    printf("Welcome to the C Movie Rating System\n");
    printf("=====================================\n");
    printf("1. Add a movie\n");
    printf("2. Print all movies\n");
    printf("3. Rate a movie\n");
    printf("4. Exit\n");

    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, index);
                index++;
                break;
            case 2:
                printMovies(movies, index);
                break;
            case 3:
                rateMovie(movies, index);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a movie to the array
void addMovie(struct movie *movies, int index) {
    printf("\nAdding a new movie...\n");

    printf("Enter the movie name: ");
    scanf("%s", &movies[index].name);

    printf("Enter the movie year: ");
    scanf("%d", &movies[index].year);

    printf("Enter the movie rating: ");
    scanf("%f", &movies[index].rating);

    printf("Movie added successfully!\n");
}

// Function to print all movies in the array
void printMovies(struct movie *movies, int index) {
    printf("\nPrinting all movies...\n");

    for (int i = 0; i < index; i++) {
        printf("%s (%d) - %.1f stars\n", movies[i].name, movies[i].year, movies[i].rating);
    }
}

// Function to rate a movie in the array
void rateMovie(struct movie *movies, int index) {
    printf("\nRating a movie...\n");

    printf("Enter the movie name: ");
    char name[50];
    scanf("%s", &name);

    // Find the movie in the array
    int movieIndex = -1;
    for (int i = 0; i < index; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            movieIndex = i;
            break;
        }
    }

    if (movieIndex == -1) {
        printf("Movie not found.\n");
        return;
    }

    printf("Enter your rating (1-5 stars): ");
    float rating;
    scanf("%f", &rating);

    movies[movieIndex].rating = (movies[movieIndex].rating + rating) / 2;

    printf("Movie rated successfully!\n");
}