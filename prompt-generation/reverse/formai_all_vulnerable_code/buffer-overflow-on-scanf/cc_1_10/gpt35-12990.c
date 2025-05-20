//FormAI DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100

// Type definition of Movie
typedef struct {
    char title[100];
    char rating[10];
} Movie;

// Global variables
Movie movieList[MAX_MOVIES];
int numMovies = 0;

// Function prototypes
void addMovie();
void rateMovie();
void listMovies();

// Main function
int main() {
    int option;

    // Display menu options
    while (1) {
        printf("\nWelcome to the Movie Rating System!");
        printf("\n1. Add a movie");
        printf("\n2. Rate a movie");
        printf("\n3. List all movies");
        printf("\n4. Exit");
        printf("\n\nEnter your option (1-4): ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                listMovies();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a movie to the list
void addMovie() {
    char title[100];
    printf("\nEnter the title of the movie: ");
    scanf("%s", title);
    
    // Check if the movie already exists in the list
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(title, movieList[i].title) == 0) {
            printf("\nMovie already exists in the list.\n");
            return;
        }
    }
    
    // Add the movie to the list
    strcpy(movieList[numMovies].title, title);
    strcpy(movieList[numMovies].rating, "N/A");
    numMovies++;
    printf("\nMovie added successfully!\n");
}

// Function to rate a movie
void rateMovie() {
    char title[100];
    printf("\nEnter the title of the movie: ");
    scanf("%s", title);
    
    // Find the movie in the list
    int index = -1;
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(title, movieList[i].title) == 0) {
            index = i;
            break;
        }
    }
    
    // Check if the movie was found
    if (index == -1) {
        printf("\nMovie not found in the list.\n");
        return;
    }
    
    // Rate the movie
    printf("\nEnter the rating for the movie (1-10): ");
    scanf("%s", movieList[index].rating);
    printf("\nMovie rated successfully!\n");
}

// Function to list all movies
void listMovies() {
    printf("\n%-30s %-10s\n", "Title", "Rating");

    for (int i = 0; i < numMovies; i++) {
        printf("%-30s %-10s\n", movieList[i].title, movieList[i].rating);
    }
}