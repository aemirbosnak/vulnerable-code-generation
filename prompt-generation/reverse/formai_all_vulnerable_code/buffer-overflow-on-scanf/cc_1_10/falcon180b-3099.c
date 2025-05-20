//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct for movie details
typedef struct {
    char title[100];
    char genre[50];
    char director[50];
    int year;
    int length;
    char rating[20];
} Movie;

// Function to display menu
void displayMenu() {
    printf("\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Exit\n");
    printf("\n");
}

// Function to add a movie
void addMovie() {
    Movie movie;

    printf("\nEnter Movie Title: ");
    scanf("%s", movie.title);

    printf("Enter Movie Genre: ");
    scanf("%s", movie.genre);

    printf("Enter Movie Director: ");
    scanf("%s", movie.director);

    printf("Enter Movie Year: ");
    scanf("%d", &movie.year);

    printf("Enter Movie Length: ");
    scanf("%d", &movie.length);

    printf("Enter Movie Rating: ");
    scanf("%s", movie.rating);

    // Add movie to list
}

// Function to display movies
void displayMovies() {
    // Display list of movies
}

// Function to search for a movie
void searchMovie() {
    char searchTitle[100];

    printf("\nEnter Movie Title to Search: ");
    scanf("%s", searchTitle);

    // Search for movie in list
}

// Main function
int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);

    return 0;
}