//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void initialize();
void displayMenu();
void rateMovie();
void viewRatings();
void exitProgram();

// global variables
char movies[5][50] = {"The Road", "Mad Max: Fury Road", "Blade Runner 2049", "Children of Men", "I Am Legend"};
int ratings[5][5] = {0};

int main() {
    initialize(); // initialize ratings to 0
    srand(time(0)); // seed for random number generator
    
    printf("Welcome to the Post-Apocalyptic Movie Rating System!\n\n");
    
    // run the program until the user exits
    while (1) {
        displayMenu();
        int choice;
        printf("Enter a choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                rateMovie();
                break;
            case 2:
                viewRatings();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    return 0;
}

// initialize the ratings to 0
void initialize() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ratings[i][j] = 0;
        }
    }
}

// display the main menu with choices
void displayMenu() {
    printf("\n");
    printf("1. Rate a movie\n");
    printf("2. View movie ratings\n");
    printf("3. Exit program\n");
}

// get user input to rate a movie
void rateMovie() {
    printf("Which movie would you like to rate?\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, movies[i]);
    }
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 5) {
        printf("Invalid choice. Try again.\n");
        return;
    }
    
    printf("What rating would you like to give %s?\n", movies[choice-1]);
    printf("Enter a number from 1-5: ");
    int rating;
    scanf("%d", &rating);
    if (rating < 1 || rating > 5) {
        printf("Invalid rating. Try again.\n");
        return;
    }
    
    // randomly adjust the rating based on the post-apocalyptic setting
    int adjustment = rand() % 5; // randomly generates a number from 0-4
    rating += adjustment - 2; // add or subtract a number from -2 to 2
    
    ratings[choice-1][rating-1]++;
    
    printf("Thank you for rating %s!\n", movies[choice-1]);
}

// display the current ratings of each movie
void viewRatings() {
    printf("Here are the current ratings for each movie:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: ", movies[i]);
        for (int j = 0; j < 5; j++) {
            printf("%d-star: %d\t", j+1, ratings[i][j]);
        }
        printf("\n");
    }
}

// exit the program
void exitProgram() {
    printf("Thank you for using the Post-Apocalyptic Movie Rating System!\n");
    exit(0);
}