//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>

//Function declarations
void displayMenu();
void addMovie();
void viewMovie();
void rateMovie();

//Global variables
int numOfMovies = 0;
char movieNames[100][100];
float movieRatings[100] = {0};

//Main function
int main() {
    int choice;
    char runProgram = 'y';
    
    printf("Welcome to Unique C Movie Rating System!\n");
    
    while (runProgram == 'y') {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovie();
                break;
            case 3:
                rateMovie();
                break;
            case 4:
                printf("Thank you for using Unique C Movie Rating System!\n");
                runProgram = 'n';
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}

//Function to display the main menu
void displayMenu() {
    printf("---- MENU ----\n");
    printf("1. Add movie\n");
    printf("2. View movies\n");
    printf("3. Rate a movie\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

//Function to add a movie
void addMovie() {
    printf("Enter the name of the movie: ");
    scanf("%s", movieNames[numOfMovies]);
    numOfMovies++;
    printf("%s has been added successfully!\n", movieNames[numOfMovies - 1]);
}

//Function to view movies and their ratings
void viewMovie() {
    if (numOfMovies == 0) {
        printf("There are no movies in the system.\n");
        return;
    }
    printf("Movie\t\t\tRating\n");
    for (int i = 0; i < numOfMovies; i++) {
        printf("%s\t\t\t%.1f\n", movieNames[i], movieRatings[i]);
    }
}

//Function to rate a movie
void rateMovie() {
    if (numOfMovies == 0) {
        printf("There are no movies in the system.\n");
        return;
    }
    char movieToRate[100];
    float ratingToAdd;
    printf("Enter the name of the movie to rate: ");
    scanf("%s", movieToRate);
    for (int i = 0; i < numOfMovies; i++) {
        if (strcmp(movieToRate, movieNames[i]) == 0) {
            printf("Enter your rating (0-10) for %s: ", movieNames[i]);
            scanf("%f", &ratingToAdd);
            if (ratingToAdd >= 0 && ratingToAdd <= 10) {
                movieRatings[i] = ((movieRatings[i] * (float)numOfMovies) + ratingToAdd) / ((float)numOfMovies + 1);
                printf("Your rating of %.1f has been added to %s.\n", ratingToAdd, movieNames[i]);
            } else {
                printf("Invalid rating. Try again.\n");
            }
            return;
        }
    }
    printf("Movie not found. Try again.\n");
}