//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the menu
void printMenu() {
    printf("\nWelcome to the Movie Rating System!\n");
    printf("Please choose an option:\n");
    printf("1. Add a new movie\n");
    printf("2. View all movies\n");
    printf("3. Search for a movie\n");
    printf("4. Rate a movie\n");
    printf("5. Exit\n");
}

// Function to add a new movie
void addMovie(char* movieName, char* movieGenre, int movieRating) {
    printf("Enter movie details:\n");
    printf("Movie Name: ");
    scanf("%s", movieName);
    printf("Movie Genre: ");
    scanf("%s", movieGenre);
    printf("Movie Rating: ");
    scanf("%d", &movieRating);

    // Add the movie to the database
    printf("Added movie '%s' to the database!\n", movieName);
}

// Function to view all movies
void viewMovies() {
    printf("Here is a list of all movies in the database:\n");
    printf("Movie Name\tMovie Genre\tMovie Rating\n");

    // Read the movies from the database
    FILE* file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Print the movie details
    char movieName[50];
    char movieGenre[50];
    int movieRating;

    while (fscanf(file, "%s %s %d", movieName, movieGenre, &movieRating) == 3) {
        printf("%s\t%s\t%d\n", movieName, movieGenre, movieRating);
    }

    fclose(file);
}

// Function to search for a movie
void searchMovie(char* movieName) {
    printf("Searching for movie '%s':\n", movieName);

    // Read the movies from the database
    FILE* file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Search for the movie
    char movieName2[50];
    int movieRating;

    while (fscanf(file, "%s %d", movieName2, &movieRating) == 2) {
        if (strcmp(movieName2, movieName) == 0) {
            printf("%s\t%d\n", movieName2, movieRating);
            break;
        }
    }

    fclose(file);
}

// Function to rate a movie
void rateMovie(char* movieName, int rating) {
    printf("Enter movie rating: ");
    scanf("%d", &rating);

    // Update the movie rating in the database
    FILE* file = fopen("movies.txt", "r+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char movieName2[50];
    int movieRating2;

    while (fscanf(file, "%s %d", movieName2, &movieRating2) == 2) {
        if (strcmp(movieName2, movieName) == 0) {
            printf("Updating movie rating for '%s'...\n", movieName);
            fseek(file, 0, SEEK_SET);
            fprintf(file, "%s %d\n", movieName2, rating);
            break;
        }
    }

    fclose(file);
}

int main() {
    char movieName[50];
    char movieGenre[50];
    int movieRating;

    // Welcome message
    printf("Welcome to the Movie Rating System!\n");

    // Loop until the user chooses to exit
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &movieRating);

        // Handle the user's choice
        switch (movieRating) {
            case 1:
                printf("Enter movie details:\n");
                printf("Movie Name: ");
                scanf("%s", movieName);
                printf("Movie Genre: ");
                scanf("%s", movieGenre);
                printf("Movie Rating: ");
                scanf("%d", &movieRating);
                addMovie(movieName, movieGenre, movieRating);
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                printf("Enter movie name: ");
                scanf("%s", movieName);
                searchMovie(movieName);
                break;
            case 4:
                printf("Enter movie name: ");
                scanf("%s", movieName);
                printf("Enter movie rating: ");
                scanf("%d", &movieRating);
                rateMovie(movieName, movieRating);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}